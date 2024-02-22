#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

int power(int exp) {
    if(exp == 31) {
        return 2147483647;
    }
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= 2;
    return result;
}

int intToBinary(int num, int b, char* output) {
    if(num == 0) {
        return 0;
    }

    int magnitude = power(30);
    int outputNum = 0;
    int pointer = 0;

    if(b == 32) {
            pointer++;
    }
    while (magnitude > num) {
        magnitude /= 2;
    }
    while(magnitude != 1) {
        if(outputNum + magnitude <= num) {
            outputNum += magnitude;
            if(pointer < b) {
                output[pointer] = '1';
            }
        }
        pointer++;
        magnitude /= 2;
    }
    if(outputNum + magnitude == num && pointer < b) {
        output[pointer] = '1';
    }
    pointer++;
    return pointer;
}

void decToBinary(double dec, int b, char* output, int pointer) {
    double magnitude = 0.5;
    for(int i = pointer; i < b; i++) {
        if(dec - magnitude >= 0) {
            dec = dec - magnitude;
            output[i] = '1';
        }
        magnitude /= 2;
    }
    return;
}

int shift(char* output, int pointer, int b) {
    if(output[0] == '1') {
        return pointer;
    }
    else {
        for(int i = 0; i < b; i++) {
            if(output[i] == '1') {
                for(int j = i; j > 0; j--) {
                    for(int k = 0; k < b-1; k++) {
                        output[k] = output[k+1];
                    }
                    output[b-1] = '0';
                    pointer--;
                }
            }
        }
    }
    return pointer;
}

int main(int argc, char* argv[]) {
    FILE * fp1;
    double dec1;
    int num1, num2, num3;

    fp1 = fopen(argv[1], "r+");

    while(!feof(fp1)) {
        num3 = fscanf(fp1, "%lf", &dec1);
        if(num3 == -1) {
            break;
        }
        fscanf(fp1, "%d", &num2);

        num2++;

        num1 = (int) dec1;
        dec1 = dec1 - num1;

        char* output = malloc(num2 * sizeof(char));
        for(int i = 0; i < num2; i++) {
            output[i] = '0';
        }

        int pointer = intToBinary(num1, num2, output);

        if(pointer < num2) {
            decToBinary(dec1, num2, output, pointer);
        }

        pointer = shift(output, pointer, num2);

        printf("%c.", output[0]);
        for(int i = 1; i < num2; i++) {
            printf("%c", output[i]);
        }
        printf(" %d\n", pointer-1);
        free(output);
    }
    return EXIT_SUCCESS;
}