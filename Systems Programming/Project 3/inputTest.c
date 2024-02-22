#include <stdio.h>

int main() {
    char input[100];

    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);

    printf("You entered: %s\n", input);

    return 0;
}