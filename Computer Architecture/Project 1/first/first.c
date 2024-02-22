#include<stdio.h>
#include<stdlib.h>

int isPrime(int a) {
    for(int i = 2; i < a; i++) {
        if((a % i) == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    FILE * fp;
    int numOfArgs = 0;

    //printf("%s", argv[1]);

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numOfArgs);
    
    int num = 3;
    int prime = 0;

    for(int i = 0; i < numOfArgs; i++) {
        fscanf(fp, "%d", &num);
        while(num != 0) {
            if(!isPrime(num)) {
                prime = 0;
                break;
            }
            num = num / 10;
            if(num == 0) {
                prime = 1;
            }
        }
        printf("%s\n", (prime == 1) ? "yes" : "no");
    }
    
    fclose(fp);

    return EXIT_SUCCESS;
}