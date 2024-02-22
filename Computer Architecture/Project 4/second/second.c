#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int logbase2(int n) {
    if(n == 1) {
        return 0;
    }
    int i = 1;
    while(n != 2) {
        n/=2;
        i++;
    }
    return i;
}

void printInBinary(long a) {
    long b = 1;
    b += INT_MAX;
    bool startPrinting = false;
    while (b >= 1) {
        if(a - b >= 0) {
            a = a - b;
            printf("1");
            startPrinting = true;
        }
        else if(startPrinting) {
            printf("0");
        }
        if(b == 1) {
            break;
        }
        b /= 2;
    }
    if(!startPrinting) {
        printf("0");
    }
    //printf("%ld", b);
}

void printCache(long ** cache, int numOfSets, int associativity) {
    for(int i = 0; i < numOfSets*associativity; i++) {
        printf("VALID: %ld\tAGE: %ld\tTAG: ", cache[i][0], cache[i][2]);
        printInBinary(cache[i][1]);
        printf("\n");
        if((i+1) % associativity == 0 && i != numOfSets*associativity-1) {
            printf("---------------------------------------------------------\n");
        }
    }
}

int searchCache(long ** cache, long set, long tag, int associativity) {
    int startLocation = set * associativity;
    for(int i = startLocation; i < startLocation + associativity; i++) {
        if(cache[i][0] == 1 && cache[i][1] == tag) {
            return i;
        }
    }
    return -1;
}

int getOpenLocation(long ** cache, int set, int associativity) {
    int startLocation = set * associativity;
    for(int i = startLocation; i < startLocation + associativity; i++) {
        if(cache[i][0] == 0) {
            return i;
        }
    }
    return -1;
}

int getMinimumAge(long ** cache, long set, int associativity) {
    int startingLocation = set * associativity;
    int min = INT_MAX;
    int index = INT_MAX;
    for(int i = startingLocation; i < startingLocation + associativity; i++) {
        if(cache[i][0] == 1 && cache[i][2] < min) {
            min = cache[i][2];
            index = i;
        }
    }
    return index;
}

struct address {
    long tag;
    long set;
    bool valid;
};

/*void store(long ** l1cache, long l1set, long l1tag, int l1associativity, int age, long ** l2cache, long l2set, long l2tag, int l2associativity, int l1numOfSets, int l2numOfSets, int l2indexBits) {
    int index = getOpenLocation(l1cache, l1set, l1associativity);
    if(index == -1) {
        index = getMinimumAge(l1cache, l1set, l1associativity);
        long addressMinusBlockBits = l1tag*l1numOfSets+l1set;
        long newl2set = addressMinusBlockBits & (l2numOfSets-1);
        long newl2tag = addressMinusBlockBits >> l2indexBits;

        int index2 = getOpenLocation(l2cache, newl2set, l2associativity);
        if(index2 == -1) {
            index2 = getMinimumAge(l2cache, newl2set, l2associativity);
        }
        l2cache[index2][0] = 1;
        l2cache[index2][1] = newl2tag;
        l2cache[index2][2] = age;
    }
    l1cache[index][0] = 1;
    l1cache[index][1] = l1tag;
    l1cache[index][2] = age;
}*/

struct address store(int num, long ** cache, long set, long tag, int associativity, int age, int l1numOfSets, int l2numOfSets, int l2indexBits) {
    int index = getOpenLocation(cache, set, associativity);
    long addressMinusBlockBits = -1;
    struct address s;
    s.valid = false;
    if(index == -1) {
        index = getMinimumAge(cache, set, associativity);
        if(num == 1) {
            //printf("SET: %ld\n", set);
            //printf("INDEX/NUMOFSETS: %d\n", index/associativity);
            //printf("INDEX: %d\n", index);
            addressMinusBlockBits = cache[index][1]*l1numOfSets+(index/associativity);
            s.tag = addressMinusBlockBits >> l2indexBits;
            s.set = addressMinusBlockBits & (l2numOfSets-1);
            s.valid = true;
            //long newl2set = addressMinusBlockBits & (l2numOfSets-1);
            //long newl2tag = addressMinusBlockBits >> l2indexBits;
            //printf("MID: %ld\n", s.tag);
            //addressMinusBlockBits = (newl2tag >> l2indexBits) + newl2set;
        }
    }
    cache[index][0] = 1;
    cache[index][1] = tag;
    cache[index][2] = age;
    return s;
}

int main(int argc, char* argv[]) {
    FILE * fp1;

    int l1cacheSize = atoi(argv[1]);
    int l1associativity;
    sscanf(argv[2], "%*[^0123456789]%d", &l1associativity);
    bool l1fifo = false;
    if(argv[3][0] == 'f') {
        l1fifo = true;
    }
    int blockSize = atoi(argv[4]);
    int blockBits = logbase2(blockSize);
    int l1numOfSets = l1cacheSize / (l1associativity*blockSize);
    int l1indexBits = logbase2(l1numOfSets);

    int l2cacheSize = atoi(argv[5]);
    int l2associativity;
    sscanf(argv[6], "%*[^0123456789]%d", &l2associativity);
    bool l2fifo = false;
    if(argv[7][0] == 'f') {
        l2fifo = true;
    }
    int l2numOfSets = l2cacheSize / (l2associativity*blockSize);
    int l2indexBits = logbase2(l2numOfSets);

    int memread = 0;
    int memwrite = 0;
    int l1cachehit = 0;
    int l1cachemiss = 0;
    int l2cachehit = 0;
    int l2cachemiss = 0;

    long** l1cache;
    l1cache = malloc(l1numOfSets * l1associativity * sizeof(long *));
    // valid, tag, age
    for(int i = 0; i < l1numOfSets * l1associativity; i++) {
        l1cache[i] = malloc(3 * sizeof(long));
        l1cache[i][0] = 0;
        l1cache[i][1] = 0;
        l1cache[i][2] = 0;
    }

    long** l2cache;
    l2cache = malloc(l2numOfSets * l2associativity * sizeof(long *));
    // valid, tag, age
    for(int i = 0; i < l2numOfSets * l2associativity; i++) {
        l2cache[i] = malloc(3 * sizeof(long));
        l2cache[i][0] = 0;
        l2cache[i][1] = 0;
        l2cache[i][2] = 0;
    }

    fp1 = fopen(argv[8], "r+");

    char str;
    char dummy;
    long address;
    int num, num2;
    long l1tag;
    long l1set;
    long l2tag;
    long l2set;

    //long l3tag;

    //long ogaddyminusblockbits;
    //long blockOffset;

    int time = 0;
    while(!feof(fp1)) {
        time++;
        num = fscanf(fp1, "%c", &str);
        num2 = fscanf(fp1, "%lx", &address);
        fscanf(fp1, "%c", &dummy);
        if(num == -1 || num2 == -1) {
            break;
        }

        l1tag = address >> (l1indexBits + blockBits);
        l1set = (address >> blockBits) & (l1numOfSets-1);
        l2tag = address >> (l2indexBits + blockBits);
        l2set = (address >> blockBits) & (l2numOfSets-1);

        //printf("OG ADDY: %ld\n", (address >> blockBits));

        //ogaddyminusblockbits = l1tag*l1numOfSets+l1set;
        //long ogl2set = ogaddyminusblockbits & (l2numOfSets-1);
        //long ogl2tag = ogaddyminusblockbits >> l2indexBits;

        /*if(ogl2set != l2set) {
            printf("UNEQUAL SETS!\n");
        }
        if(ogl2tag != l2tag) {
            printf("UNEQUAL TAGS!\n");
        }*/
        
        //printf("l1tag: %ld\nl1set: %ld\nl2tag: %ld\nl2set: %ld\n", l1tag, l1set, l2tag, l2set);

        /*if(l1indexBits >= l2indexBits) {
            l3tag = (l1tag << (l1indexBits-l2indexBits));
        }
        else {
            l3tag = (l1tag >> (l2indexBits-l1indexBits));
        }
        printf("l3tag: %ld\n", l3tag);*/

        //printf("l1indexBits: %d\nl2indexBits: %d\n", l1indexBits, l2indexBits);

        //blockOffset = address & ((1 << blockBits) - 1);

        //printf("tag: ")

        //printf("%c %lx\n", str, address);
        //printInBinary(tag);
        //printf("\n%ld\n", set);

        //printf("%ld\n", set);
        //printInBinary(set);

        //printf("NUM: %ld\nL1 TAG: %ld\tL2 TAG: %ld\n",address, l1tag, l2tag);

        int foundInL1 = searchCache(l1cache, l1set, l1tag, l1associativity);
        // FOUND IN L1
        if(foundInL1 != -1) {
            l1cachehit++;
            if(!l1fifo) { // update LRU timestamp on a hit.
                l1cache[foundInL1][2] = time;
            }
        }
        // NOT FOUND IN L1
        else {
            l1cachemiss++;

            int foundInL2 = searchCache(l2cache, l2set, l2tag, l2associativity);
            // FOUND IN L2
            if(foundInL2 != -1) {
                l2cachehit++;
                if(!l2fifo) {
                    l2cache[foundInL2][2] = time;
                }
            }
            // NOT FOUND IN L2
            else {
                l2cachemiss++;
                memread++;
            }
            // DONE WHETHER FOUND IN L2 OR NOT

            // PUT ADDRESS IN L1 CACHE
            struct address l2address;
            l2address.valid = false;
            l2address = store(1, l1cache, l1set, l1tag, l1associativity, time, l1numOfSets, l2numOfSets, l2indexBits);

            // IF IT WAS FOUND IN L2, EVICT THAT SPOT
            if(foundInL2 != -1) {
                l2cache[foundInL2][0] = 0;
            }

            // l2address SHOULD BE THE ADDRESS OF THE EVICTED ITEM FROM L1
            // IF AN ITEM WAS EVICTED FROM L1, STORE IT IN L2.
            if(l2address.valid) {
                //printf("PRE:\tL2tag:  %ld\tL2set:  %ld\n", l2tag, l2set);
                l2tag = l2address.tag;//(l2address << l2indexBits);
                l2set = l2address.set;//l2address & (l2numOfSets-1);
                //printf("POST:\tL2tag:  %ld\tL2set:  %ld\n", l2tag, l2set);
                store(2, l2cache, l2set, l2tag, l2associativity, time, l1numOfSets, l2numOfSets, l2indexBits);
            }
        }
        if(str == 'W') {
            memwrite++;
        }

        //printCache(cache, numOfSets, associativity);
        //printf("\n");

        //long blockOffset = address & ((1 << blockBits) - 1);

        //printf("%d\n", str=='W');

        // if(time == 20) {
        //     break;
        // }
    }

    /*printf("L1:\n");
    printCache(l1cache, l1numOfSets, l1associativity);
    printf("\nL2:\n");
    printCache(l2cache, l2numOfSets, l2associativity);*/


    for(int i = 0; i < l1numOfSets * l1associativity; i++) {
        free(l1cache[i]);
    }
    free(l1cache);

    for(int i = 0; i < l2numOfSets * l2associativity; i++) {
        free(l2cache[i]);
    }
    free(l2cache);

    printf("memread:%d\nmemwrite:%d\nl1cachehit:%d\nl1cachemiss:%d\nl2cachehit:%d\nl2cachemiss:%d\n", memread, memwrite, l1cachehit, l1cachemiss, l2cachehit, l2cachemiss);
    // printf("\nL1 CACHE SIZE: %d\nL1 ASSOCIATIVITY: %d\nL1 CACHE POLICY: %d\nBLOCK SIZE: %d\nL2 CACHE SIZE: %d\nL2 ASSOCIATIVITY: %d\nL2 CACHE POLICY: %d", l1cacheSize, l1associativity, l1fifo, blockSize, l2cacheSize, l2associativity, l2fifo);
    // printf("\nL1 INDEX BITS: %d\nL1 NUM OF SETS: %d\nBLOCK BITS: %d\nL2 INDEX BITS: %d\nL2 NUM OF SETS: %d\n", l1indexBits, l1numOfSets, blockBits, l2indexBits, l2numOfSets);
    //printf("\n\n\n%d%d", associativity, num);

    return EXIT_SUCCESS;
}