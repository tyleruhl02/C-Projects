#include "mymalloc.h"
#include <stdio.h>

void test7(){
    free(NULL);
}
int main() {
    test7();
}