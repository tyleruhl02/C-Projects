#include <stdio.h>
#include "mymalloc.h"

void test2() {
    char *ptrArray[120];  // Array to store 120 pointers

    for(int i = 0; i < 120; i++) {
        ptrArray[i] = malloc(1);  // Allocate 1 byte of memory and store the address
    }

    for(int i = 0; i < 120; i++) {
        free(ptrArray[i]);  // Release the memory
    }

    printf("MemClear?: %d\n", memCleared());  // Check if memory is cleared
}

int main() {
    test2();
}