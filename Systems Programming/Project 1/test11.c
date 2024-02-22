#include "mymalloc.h"
#include <stdio.h>

void test11(){
    char* ptr1 = malloc(4072);
    char* ptr2 = malloc(7);
    char* ptr3 = malloc(7);

    free(ptr1);
    free(ptr2);
    free(ptr3);
}
int main() {
    test11();
}