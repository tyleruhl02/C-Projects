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

double power2(int exp) {
    double result = 1.0;
    if (exp > 0) {
        for(int i = 0; i < exp; i++) {
            result *= 2;
        }
    }
    else if (exp < 0) {
        exp *= -1;
        for(int i = 0; i < exp; i++) {
            result /= 2;
        }
    }
    return result;
}

/*int intToBinary(long num, int b, char* output) {
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
}*/
int inputInput(int pointer, char* input, int a) {
    char arr[16][4] = { {'0', '0', '0', '0'},
                        {'0', '0', '0', '1'},
                        {'0', '0', '1', '0'},
                        {'0', '0', '1', '1'},
                        {'0', '1', '0', '0'},
                        {'0', '1', '0', '1'},
                        {'0', '1', '1', '0'},
                        {'0', '1', '1', '1'},
                        {'1', '0', '0', '0'},
                        {'1', '0', '0', '1'},
                        {'1', '0', '1', '0'},
                        {'1', '0', '1', '1'},
                        {'1', '1', '0', '0'},
                        {'1', '1', '0', '1'},
                        {'1', '1', '1', '0'},
                        {'1', '1', '1', '1'}};

    for(int i = 3; i >= 0; i--) {
        input[pointer--] = arr[a][i];
        if(pointer < 0) {
            return -1;
        }
    }
    return pointer;
}

int binaryToInt(char* input, int len) {
    int output = 0;
    int magnitude = 1;
    for(int i = len-1; i >= 0; i--) {
        if(input[i] == '1') {
            output += magnitude;
        }
        magnitude*=2;
    }
    return output;
}

double binaryToDecimal(char* input, int len) {
    double output = 0.0;
    double magnitude = 0.5;
    for(int i = 0; i < len; i++) {
        if(input[i] == '1') {
            output += magnitude;
        }
        magnitude /= 2;
    }
    return output;
}

//void print(double dec, int decPlaces) {
    //int num = (int) dec;
    //dec = dec - num;

    //printf("%d.", num);
    //printf("%.40lf\n", dec);
    /*for(int i = 0; i < decPlaces; i++) {
        dec *= 10;
        if(i == decPlaces) {
            dec += 0.5;
        }
        num = (int) dec;
        dec = dec - num;
        printf("%d", num);
    }*/
    //printf("\n");
//}

int main(int argc, char* argv[]) {
    FILE * fp1;
    //char str[15];
    //unsigned char dec;
    long dec;
    int bits, exponent, mantissa, decPlaces, num5;

    fp1 = fopen(argv[1], "r+");

    int counter = 1;

    while(!feof(fp1)) {
        num5 = fscanf(fp1, "%d", &bits);
        if(num5 == -1) {
            break;
        }
        fscanf(fp1, "%d", &exponent);
        fscanf(fp1, "%d", &mantissa);
        fscanf(fp1, "%lx", &dec);
        fscanf(fp1, "%d", &decPlaces);

        //printf("dec: %x\n", dec);
        //printf("dec: %d\n", dec);
        //printf("dec mod16: %x\n", dec % 16);
        //printf("dec mod16: %x\n", dec << 1);

        if(counter >-1) {

        char* input = malloc(bits * sizeof(char));
        for(int i = 0; i < bits; i++) {
            input[i] = '0';
        }

        int pointer = bits-1;
        while(pointer > 0) {
            //printf("dec mod 16: %ld\t", dec % 16);
            pointer = inputInput(pointer, input, dec % 16);
            dec /= 16;
        }
        if(pointer == 0) {
            pointer = inputInput(pointer, input, dec % 16);
        }

        // for(int i = 0; i < bits; i++) {
        //    printf("%c", input[i]);
        // }
        // printf("\n");

        char* exponentBinary = malloc(exponent * sizeof(char));
        char* mantissaBinary = malloc(mantissa * sizeof(char));
        char signBit = input[0];
        for(int i = 1; i < bits; i++) {
            if(i <= exponent) {
                exponentBinary[i-1] = input[i];
            }
            else {
                mantissaBinary[i-exponent-1] = input[i];
            }
        }
        free(input);

        int bigE = binaryToInt(exponentBinary, exponent);
        int bias = power(exponent-1)-1;
        int littleE = bigE - bias;
        double decimal = binaryToDecimal(mantissaBinary, mantissa);
        bool normal = false;
        for(int i = 0; i < exponent; i++) {
            if(exponentBinary[i] == '1') {
                normal = true;
                break;
            }
        }

        // printf("decimal: %.15lf\n", decimal);
        // printf("littleE: %d\n", littleE);
        // printf("power2: %.40lf\n", power2(littleE));

        double result;

        if(normal) {
            result = (1 + decimal) * power2(littleE);
        }
        else {
            result = decimal * power2(littleE+1);
        } 

        // printf("result: %0.40lf\n", result);

        if(signBit == '1') {
            //result *= -1;
            printf("-");
        }

        printf("%.*f\n", decPlaces, result);

        free(exponentBinary);
        free(mantissaBinary);
 
        }
        counter++;
    }
    return EXIT_SUCCESS;
}