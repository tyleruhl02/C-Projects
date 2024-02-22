#include <stdlib.h>
#include <stdio.h>

int main() {
    char* a = malloc(10 * sizeof(char));
    a[0] = 'H';
    a[1] = 'e';
    a[2] = 'l';
    a[3] = 'l';
    a[4] = 'o';
    a[5] = '\0';
    a[6] = 'P';
    printf("%s\n", a);
}