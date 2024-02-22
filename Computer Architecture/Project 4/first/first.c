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
    //printf("START LOCATION: %d", startLocation);
    for(int i = startLocation; i < startLocation + associativity; i++) {
        if(cache[i][0] == 1 && cache[i][1] == tag) {
            return i;
        }
    }
    //printf("HEY NOW??")
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

void store(long ** cache, long set, long tag, int associativity, int age) {
    int index = getOpenLocation(cache, set, associativity);
    if(index == -1) {
        index = getMinimumAge(cache, set, associativity);
    }
    cache[index][0] = 1;
    cache[index][1] = tag;
    cache[index][2] = age;
}

int main(int argc, char* argv[]) {
    FILE * fp1;

    int cacheSize = atoi(argv[1]);
    int associativity;
    sscanf(argv[2], "%*[^0123456789]%d", &associativity);
    bool fifo = false;
    if(argv[3][0] == 'f') {
        fifo = true;
    }
    int blockSize = atoi(argv[4]);
    int blockBits = logbase2(blockSize);
    int numOfSets = cacheSize / (associativity*blockSize);
    int indexBits = logbase2(numOfSets);

    int memread = 0;
    int memwrite = 0;
    int cachehit = 0;
    int cachemiss = 0;

    long** cache;

    cache = malloc(numOfSets * associativity * sizeof(long *));
    // valid, tag, age
    for(int i = 0; i < numOfSets * associativity; i++) {
        cache[i] = malloc(3 * sizeof(long));
        cache[i][0] = 0;
        cache[i][1] = 0;
        cache[i][2] = 0;
    }

    fp1 = fopen(argv[5], "r+");

    char str;
    char dummy;
    long address;
    int num, num2;

    int time = 0;
    while(!feof(fp1)) {
        time++;
        num = fscanf(fp1, "%c", &str);
        num2 = fscanf(fp1, "%lx", &address);
        fscanf(fp1, "%c", &dummy);
        if(num == -1 || num2 == -1) {
            break;
        }

        long tag = address >> (indexBits + blockBits);
        long set = (address >> blockBits) & (numOfSets-1);

        //printf("tag: ")

        //printf("%c %lx\n", str, address);
        //printInBinary(tag);
        //printf("\n%ld\n", set);

        //printf("%ld\n", set);
        //printInBinary(set);

        int found = searchCache(cache, set, tag, associativity);
        if(found != -1) {
            cachehit++;
            if(!fifo) { // update LRU timestamp on a hit.
                cache[found][2] = time;
            }
        }
        else {
            cachemiss++;
            memread++;
            store(cache, set, tag, associativity, time);
        }
        if(str == 'W') {
            memwrite++;
        }

        //printCache(cache, numOfSets, associativity);
        //printf("\n");

        //long blockOffset = address & ((1 << blockBits) - 1);

        //printf("%d\n", str=='W');

        /*if(time == 400) {
            break;
        }*/
    }

    //printCache(cache, numOfSets, associativity);


    for(int i = 0; i < numOfSets * associativity; i++) {
        free(cache[i]);
    }
    free(cache);

    printf("memread:%d\nmemwrite:%d\ncachehit:%d\ncachemiss:%d\n", memread, memwrite, cachehit, cachemiss);
    //printf("CACHE SIZE: %d\nASSOCIATIVITY: %d\nCACHE POLICY: %d\nBLOCK SIZE: %d\n", cacheSize, associativity, fifo, blockSize);
    //printf("INDEX BITS: %d\nBLOCK BITS: %d\nNUM OF SETS: %d\n", indexBits, blockBits, numOfSets);
    //printf("\n\n\n%d%d", associativity, num);

    return EXIT_SUCCESS;
}