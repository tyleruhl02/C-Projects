#include <stdio.h>
#include <stdlib.h>

void printMatrix(int* arrPtr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d\t", arrPtr[i*size+j]);
        }
        printf("\n");
    }
}

int getDeterminant(int* arrPtr, int size) {
    if(size == 1) {
        return arrPtr[0];
    }
    else if(size == 2) {
        return (arrPtr[0]*arrPtr[3]) - (arrPtr[1]*arrPtr[2]);
    }
    else {
        int sum = 0;
        for(int i = 0; i < size; i++) {
            int* newMatrix = (int*) malloc((size-1)*(size-1) * sizeof(int));
            int counter = 0;
            for(int j = 0; j < size*size; j++) {
                if(!(j < size || j % size == i)) {
                    newMatrix[counter++] = arrPtr[j];
                }
            }
            if(i % 2 == 0) {
                sum += arrPtr[i]*getDeterminant(newMatrix, size-1);
            }
            else {
                sum -= arrPtr[i]*getDeterminant(newMatrix, size-1);
            }
            free(newMatrix);
        }
        return sum;
    }
    return -1;
}

int main(int argc, char* argv[]) {
    FILE * fp;
    int num, counter, size;
    counter = 0;

    fp = fopen(argv[1], "r+");
    fscanf(fp, "%d", &num);
    size = num;
    int* ptr = (int*) malloc(size*size * sizeof(int));

    /*for(int i = 0; i < 4; i++) {
        fscanf(fp, "%d", &num);
        ptr[counter] = num;
        counter++;
    }*/
    do {
        fscanf(fp, "%d", &ptr[counter++]);
    } while(fgetc(fp) != EOF);

    //ptr[0] = 5;

    //printMatrix(ptr, size);

    printf("%d\n", getDeterminant(ptr, size));

    free(ptr);
    return EXIT_SUCCESS;
}