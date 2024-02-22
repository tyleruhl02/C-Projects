#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <glob.h>

int main() {
   
   int d = 100;
   int c = fork();
   if (c == 0) {
       d = 200;
       exit(EXIT_SUCCESS);
   }
   wait(NULL);
   printf("%d\n", d);
}