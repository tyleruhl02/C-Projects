#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <glob.h>

int main() {

   const char *equation = "[ 1 -eq 1 ]";

    // Use the system function to run the equation
    int result = system(equation);

    // Check the result of the system call
    if (result == 0) {
        printf("Condition is true.\n");
    } else {
        printf("Condition is false.\n");
    }

    return 0;
}