#include <stdio.h>
#include <stdlib.h>

int num;

void createMagicSquare(int** arr) {
    int rowPtr = 0;
    int columnPtr = num / 2;
    int count = 1;
    arr[rowPtr][columnPtr] = count;
    count++;

    while(count != num*num+1) {
        rowPtr = (rowPtr - 1 + num) % num;
        columnPtr = (columnPtr + 1) % num;
        if(arr[rowPtr][columnPtr] == 0) {
            arr[rowPtr][columnPtr] = count;
        }
        else {
            rowPtr = (rowPtr + 2) % num;
            columnPtr = (columnPtr - 1 + num) % num;
            arr[rowPtr][columnPtr] = count;
        }
        count++;
    }
    return;
}

void printArray(int** arr) {
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(int argc, char* argv[]) {
    sscanf(argv[1], "%d", &num);
    if(num % 2 == 0) {
        printf("error\n");
    }
    else {
        int** arr;
        arr = malloc(num * sizeof(int*));
        for(int i = 0; i < num; i++) {
            arr[i] = malloc(num * sizeof(int));
        }
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < num; j++) {
                arr[i][j] = 0;
            }
        }

        createMagicSquare(arr);
        printArray(arr);

        for(int i = 0; i < num; i++) {
            free(arr[i]);
        }
        free(arr);
        //printArray(arr);
    }

    return EXIT_SUCCESS;
}