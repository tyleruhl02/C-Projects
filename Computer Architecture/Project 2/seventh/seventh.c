#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int power(int exp) {
    if(exp >= 30) {
        return 1073741824;
    }
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= 2;
    return result;
}

void convertToTwosComplement(int a, int b) {
    char* output = malloc(b * sizeof(char));
    for(int i = 0; i < b; i++) {
        output[i] = '0';
    }
    int MAX = power(b-1) - 1;
    int MIN = power(b-1) * -1;

    //printf("MAX: %d\ta: %d\t", MAX, a);
    //printf()
    
    int magnitude = (MIN*-1) / 2;
    int outputNum = 0;
    int pointer = 1;

    if(a > MAX) {
        for(int i = 1; i < b; i++) {
            output[i] = '1';
        }
    }
    else if(a < MIN) {
        output[0] = '1';
    }
    else {
        if(a < 0) {
            output[0] = '1';
            outputNum = MIN;
            if(b == 31) {
                pointer++;
            }
            while(outputNum != a) {
                if(outputNum + magnitude <= a) {
                    outputNum += magnitude;
                    output[pointer] = '1';
                }
                pointer++;
                magnitude /= 2;
            }
        }
        else {
            if(b == 32) {
                pointer++;
            }
            while(outputNum != a) {
                if(outputNum + magnitude <= a) {
                    outputNum += magnitude;
                    output[pointer] = '1';
                }
                pointer++;
                magnitude /= 2;
            }
        }
    }
    for(int i = 0; i < b; i++) {
        printf("%c", output[i]);
    }
    printf("\n");
    free(output);
    return;
}

int charToInt(char a) {
    switch(a) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return -1;
    }
}

int main(int argc, char* argv[]) {
    FILE * fp1;
    int num1, num2, num3;
    long num4;

    fp1 = fopen(argv[1], "r+");

    while(!feof(fp1)) {
        num3 = fscanf(fp1, "%ld", &num4);
        if(num3 == -1) {
            break;
        }
        fscanf(fp1, "%d", &num2);

        if(num4 > 2147483647) {
            num1 = 2147483647;
        }
        else {
            num1 = num4;
        }

        convertToTwosComplement(num1, num2);
    }
    return EXIT_SUCCESS;
}