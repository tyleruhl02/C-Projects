/*#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "mymalloc.h"

void test1() {  //Given
    for(int i = 0; i < 120; i++) {
        char* ptr = malloc(1);
        free(ptr);
    }
    printf("MemClear? %d\n", memCleared());
}

void test2() {  //Given
    char* ptrArray[120];

    for(int i = 0; i < 120; i++) {
        ptrArray[i] = malloc(1);
    }

    for(int i = 0; i < 120; i++) {
        free(ptrArray[i]);
    }

    printf("MemClear? %d\n", memCleared());
}

#define iter 120

void test3() { //Given
    char* ptrArray[iter];
    int allocated[iter] = {0};
    int loc = 0;

    for(int i = 0; i < iter; i++) {
        if(loc == 0 || (rand() % 2 == 0 && loc < iter)) {
            //printf("alloc loc = %d\n", loc);
            ptrArray[loc] = malloc(1);
            allocated[loc] = 1;
            loc++;
        } else {
            loc--;
            //printf("free loc = %d\n", loc);
            free(ptrArray[loc]);
            allocated[loc] = 0;
        }
    } 

    //printf("Process is done.\n");

    for(int i = 0; i < iter; i++) {
        if(allocated[i] == 1) {
            free(ptrArray[i]);
        }
    }

    printf("MemClear? %d\n", memCleared());
}

void test4() {  // Tests if code will allocate memory in the middle of the heap when there is enough room.
    char* ptr1 = malloc(1024);
    char* ptr2 = malloc(2048);
    char* ptr3 = malloc(512);

    free(ptr2);

    char* ptr4 = malloc(1024);
    char* ptr5 = malloc(800);
    char* ptr6 = malloc(400);

    free(ptr1);
    free(ptr3);
    free(ptr4);
    free(ptr5);
    free(ptr6);

    char* ptr7 = malloc(16);
    free(ptr7);

    printf("MemClear? %d\n", memCleared());
}

void test5() {  // Tests if code can fill the heap.
    char* ptr1 = malloc(4072);
    char* ptr2 = malloc(7);
    free(ptr1);
    free(ptr2);

    printf("MemClear? %d\n", memCleared());
    //free(ptr1);
}

void test6() { // double freeing *PRODUCES ERROR
    char* ptr1 = malloc(5);
    free(ptr1);
    free(ptr1);

    printf("MemClear? %d\n", memCleared());
}

void test7() { // freeing NULL *PRODUCES ERROR
    free(NULL);
}

void test8() {  // freeing the middle of the heap *PRODUCES ERROR
    char* ptr1 = malloc(2000);
    ptr1 += 100;
    free(ptr1);
}

void test9() {  // freeing outside of the heap *PRODUCES ERROR
    int x;
    free(&x);
}

void test10() { // double freeing again *PRODUCES ERROR
    int *p = malloc(sizeof(int) * 100);
    int *q = p;
    free(p);
    free(q);
}

void test11() { // overflowing the heap *PRODUCES ERROR
    char* ptr1 = malloc(4072);
    char* ptr2 = malloc(7);
    char* ptr3 = malloc(7);
    free(ptr1);
    free(ptr2);
    free(ptr3);
}

int main() {
    int x;
    printf("%p\n", &x);
    printf("%d\n", (int) sizeof(void*));
    
    struct timeval tv;
    unsigned long start;
    unsigned long end;

    gettimeofday(&tv, NULL);

    printf("TEST1:\n");
    start = tv.tv_usec;
    for(int i = 0; i < 50; i++) {
        test3();
    }
    gettimeofday(&tv, NULL);
    end = tv.tv_usec;
    if(end < start) {
        end += 1000000;
    }
    printf("AVERAGE TIME: %.2f microseconds.\n", ((double) end - (double) start) / 50.0);

    printf("TEST 1: ");
    test1();
    printf("TEST 2: ");
    test2();
    printf("TEST 3: ");
    test3();
    printf("TEST 4: ");
    test4();
    printf("TEST 5: ");
    test5();
    printf("TEST 6: ");
    test6();
    printf("TEST 7: ");
    test7();
    printf("TEST 8: ");
    test8();
    printf("TEST 9: ");
    test9();
    printf("TEST 10: ");
    test10();
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "mymalloc.h"

int main(){
    srand(time(NULL));
    struct timeval start, end;
    double elapsed_time;
    
    for(int i = 0; i < 50; i++){
        gettimeofday(&start, NULL);
        for(int j = 0; j < 120; j++) { // TEST 1
            char *ptr = malloc(1);
            free(ptr);
        }

        char *ptrArray[120];  // Array to store 120 pointers

        for(int j = 0; j < 120; j++) {
            ptrArray[j] = malloc(1);  // Allocate 1 byte of memory and store the address
        }

        for(int j = 0; j < 120; j++) {
            free(ptrArray[j]);  // Release the memory
        }


        char *ptrArray2[120];  // Array to store 120 pointers                               // TEST 3
        int allocated[120] = {0};  // Initialize the memory allocation status array
        int loc = 0;  // Current location

        for(int j = 0; j < 120; j++) {
            if(loc == 0 || (rand() % 2 == 0 && loc < 120)) {
                // Allocate 1 byte of memory and store the address
                //printf("alloc loc=%d\n", loc);
                ptrArray2[loc] = malloc(1);
                allocated[loc] = 1;
                loc++;
            } else {
                // Release the memory
                loc--;
                //printf("free loc=%d\n", loc);
                free(ptrArray2[loc]);
                allocated[loc] = 0;
            }
        }

        //printf("Process is done.\n");

        // Clean up any unreleased memory
        for(int j = 0; j < 120; j++) {
            if(allocated[j] == 1) {
                free(ptrArray[j]);
            }
        }

        //Own stress case                   //TEST 4
        char* ptr8 = malloc(4072);
        char* ptr9 = malloc(7);
        free(ptr8);
        free(ptr9);
        //free(ptr);
        //Second stress case                //TEST 5
        
        char* ptr1 = malloc(1024);
        char* ptr2 = malloc(2048);
        char* ptr3 = malloc(512);

        free(ptr2);

        char* ptr4 = malloc(1024);
        char* ptr5 = malloc(800);
        char* ptr6 = malloc(400);

        free(ptr1);
        free(ptr3);
        free(ptr4);
        free(ptr5);
        free(ptr6);

        char* ptr7 = malloc(16);
        free(ptr7);

        gettimeofday(&end, NULL);
        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Elapsed time for iteration #%d: %f seconds\n",i+1, elapsed_time);
    }
}