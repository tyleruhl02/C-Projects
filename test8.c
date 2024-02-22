#include "mymalloc.h"
#include <stdio.h>

void test8(){
    char* ptr1 = malloc(2000);
    ptr1 += 100;
    free(ptr1);
}