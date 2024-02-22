#include "mymalloc.h"
#include <stdio.h>

void test10(){
    int *p = malloc(sizeof(int) * 100);
    int *q = p;
    free(p);
    free(q);
}

int main() {
    test10();
}