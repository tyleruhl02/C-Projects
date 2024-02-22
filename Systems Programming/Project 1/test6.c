#include "mymalloc.h"
#include <stdio.h>

void test6(){
    char* ptr1 = malloc(5);
    free(ptr1);
    free(ptr1);

    printf("Memclear? %d\n", memCleared());

}

int main() {
    test6();
}