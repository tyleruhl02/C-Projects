#include "mymalloc.h"
#include <stdio.h>


void test9(){
    int x;
    free(&x);
    
}


int main() {
    test9();
}