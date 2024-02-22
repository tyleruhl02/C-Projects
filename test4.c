#include "mymalloc.h"
#include <stdio.h>

void test4(){
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

    printf("Memclear? %d\n", memCleared());

}

int main() {
    test4();
}