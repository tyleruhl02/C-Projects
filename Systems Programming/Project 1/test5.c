#include "mymalloc.h"
#include <stdio.h>

void test5(){
    char* ptr1 = malloc(4072);
    char* ptr2 = malloc(7);
    
    free(ptr1);
    free(ptr2);

    printf("Memclear? %d\n", memCleared());

}

int main() {
    test5();
}