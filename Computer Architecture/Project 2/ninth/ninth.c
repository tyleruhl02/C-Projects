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

    int magnitude = power(b-1);
    int outputNum = 0;
    int pointer = 0;

    if(b == 32) {
        pointer++;
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
    //printf("OUTPUTNUM: %d\n", outputNum);
    pointer++;
    return pointer;
}

/*void decToBinary(double dec, int b, char* output, int pointer) {
    double magnitude = 0.5;
    for(int i = pointer; i < b; i++) {
        if(dec - magnitude >= 0) {
            dec = dec - magnitude;
            output[i] = '1';
        }
        magnitude /= 2;
    }
    return;
}*/

/*int shift(char* output, int pointer, int b) {
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
}*/

double calculateExponent(double dec, char* output, int exponent) {
    int counter = 0;
    //printf("Hey");
    int bias = power(exponent-1)-1;
    if(dec >= 2) {
        while(dec >= 2) {
            dec /= 2;
            counter++;
        }
        intToBinary(counter+bias, exponent, output);
        return dec - 1;
        //printf("DEC: %lf\n", dec);
    }
    else if(dec < 1) {
        while(dec < 1) {
            dec *= 2;
            counter--;
        }
        //printf("Hey");
        //printf("COUNTER: %d\n", counter+bias);
        intToBinary(counter+bias, exponent, output);
        return dec - 1;
    }
    intToBinary(bias, exponent, output);
    return dec - 1;
}

bool chain(char* output, int a) {
    if(a == 1) {
        if(output[0] == '1') {
            output[0] = '0';
            return -1;
        }
        output[0] = '1';
        return false;
    }
    for(int i = a-1; i >= 0; i--) {
        if(output[i] == '1') {
            output[i] = '0';
        }
        else {
            output[i] = '1';
            return false;
            break;
        }
    }
    //printf("THIS IS THE ISSUE!!!\n");
    return true;
}

bool calculateDecimal(double dec, char* output, int mantissa) {
    //printf("START NUM: %lf\n", dec);
    double magnitude = 1;
    for(int i = 0; i < mantissa; i++) {
        //printf("i: %d", i);
        magnitude /= 2;
        if(dec - magnitude >= 0) {
            dec -= magnitude;
            output[i] = '1';
            //printf("NEW NUM: %lf\tMAG: %lf\n", dec, magnitude);
        }
    }
    double num1 = dec - magnitude;
    double num2 = dec;

    //printf("MAG: %lf\tDEC: %lf\tD1: %lf\tD2: %lf\n", magnitude, dec, num1*num1, num2*num2);

    if(num1 * num1 <= num2 * num2) {
        if(num1 * num1 == num2 * num2 && output[mantissa-1] == '0') {
            return false;
        }
        bool overflow = chain(output, mantissa);
        return overflow;
    }
    return false;
}

void calculateSubnormal(double dec, char* output, int mantissa, double barrier) {
    double magnitude = barrier;
    for(int i = 0; i < mantissa; i++) {
        magnitude /= 2;
        if(dec - magnitude >= 0) {
            dec -= magnitude;
            output[i] = '1';
        }
    }
    return;
}

int main(int argc, char* argv[]) {
    FILE * fp1;
    double dec1;
    int bits, exponent, mantissa, num5;

    fp1 = fopen(argv[1], "r+");

    while(!feof(fp1)) {
        num5 = fscanf(fp1, "%lf", &dec1);
        if(num5 == -1) {
            break;
        }
        fscanf(fp1, "%d", &bits);
        fscanf(fp1, "%d", &exponent);
        fscanf(fp1, "%d", &mantissa);

        double normalSubnormalBarrier = 1.0;
        for(int i = 0; i < ((1 << (exponent-1)) - 2); i++) {
            normalSubnormalBarrier /= 2;
        }

        char signBinary = '0';
        char* exponentBinary = malloc(exponent * sizeof(char));
        char* mantissaBinary = malloc(mantissa * sizeof(char));

        for(int i = 0; i < exponent; i++) {
            exponentBinary[i] = '0';
        }
        for(int i = 0; i < mantissa; i++) {
            mantissaBinary[i] = '0';
        }

        if(dec1 < 0) {
            signBinary = '1';
            dec1 *= -1;
        }

        //printf("%lf, %d, %d, %d\n", dec1, bits, exponent, mantissa);

        if(dec1 >= normalSubnormalBarrier) {
            dec1 = calculateExponent(dec1, exponentBinary, exponent);
            //printf()
            //printf("B");
            bool overflow = calculateDecimal(dec1, mantissaBinary, mantissa);
            if(overflow) {
                chain(exponentBinary, exponent);
            }
        }
        else {
            printf("SUBNORMAL!\n");
            calculateSubnormal(dec1, mantissaBinary, mantissa, normalSubnormalBarrier);
        }

        printf("%c", signBinary);
        for(int i = 0; i < exponent; i++) {
            printf("%c", exponentBinary[i]);
        }
        for(int i = 0; i < mantissa; i++) {
            printf("%c", mantissaBinary[i]);
        }
        printf("\n");
        free(exponentBinary);
        free(mantissaBinary);
    }
    return EXIT_SUCCESS;
}