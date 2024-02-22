#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"
#define MAXLENGTH 512
static double memory[MAXLENGTH];

#define ROUNDUP8(x) (((x) + 7) & (-8))

void printMemory() {
    for(int i = 0; i < MAXLENGTH; i++) {
        printf("%d:\t%p: %f\n", i, &memory[i], memory[i]);
    }
}

void printMemory2() {
    for(int i = 0; i < MAXLENGTH; i++) {
        int* temp = (int*) &memory[i];
        if(*temp != 0 || *(temp+1) != 0) {
            printf("%d:\t%p: %d\n", i, temp, *temp);
            printf("%d:\t%p: %d\n", i, temp+1, *(temp+1));
        }
    }
}

void printHeaders(char* location, int length) {
    int* temp = (int*) location;
    for(int i = 0; i < length; i++) {
        printf("%p: %d\n", temp+i, *(temp+i));
    }
}

void printSection(double* start, int length) {
    for(int i = 0; i < length; i++) {
        printf("%p: %f\n", &(start[i]), start[i]);
    }
}

int GetChunkSize(char* loc) {
    int* b = (int*) loc;
    int a = *b;
    return a;
}

int IsFree(char* loc) {
    int* b = (int*) loc;
    int a = *(b + 1);
    return a == 1; 
}

void SetChunkSize(char* loc, size_t size) {
    int* a = (int*) loc;
    *a = (int) size;
}

void MarkAsAllocated(char* loc) {
    int* a = (int*) loc;
    *(a + 1) = 1;
}

void MarkAsFree(char* loc) {
    int* a = (int*) loc;
    *(a + 1) = 0;
}

void SetNextChunkSize(char* start, int len) {
    int* temp = (int*) start;
    int* nextChunkStart = (int*) (start + *temp);
    *nextChunkStart = len;
}

char* GetNextChunk(char* start) {
    return start + *((int*) start);
}

int NextChunkIsUninitialized(char* start, char* max) {
    char* temp = GetNextChunk(start);
    if(temp >= max) {
        return 0;
    }
    int* nextChunkStart = (int*) temp;
    return *nextChunkStart == 0 || *(nextChunkStart+1) == 0;
}

void* mymalloc(size_t size, char* file, int line) {
    if(size == 0) {
        printf("Cannot allocate 0 bytes in file %s on line %d.\n", file, line);
        return 0;
    }

    size = ROUNDUP8(size);

    void* res = NULL;
    char* start = (char *) memory;
    char* memory_end = (char *) (((double *) memory) + MAXLENGTH);

    while(start < memory_end) {
        int chunkSize = GetChunkSize(start);
        int isFree = IsFree(start);

        if(chunkSize == 0 && isFree == 0) { //free = 0. allocated = 1.
            SetChunkSize(start, size + 8);
            MarkAsAllocated(start);
            res = (void*) (start + 8);
            isFree = 1;
            SetNextChunkSize(start, memory_end - (start + size + 8));
            return res;
        }
        if(isFree == 0 && chunkSize >= size + 8) {
            SetChunkSize(start, size + 8);
            MarkAsAllocated(start);
            res = (void*) (start + 8);
            if(NextChunkIsUninitialized(start, memory_end)) {
                SetNextChunkSize(start, chunkSize - (size + 8));
            }
            return res;
        }
        if(isFree == 1 || chunkSize < size + 8) {
            start = GetNextChunk(start);
        }
    }

    printf("Error: not enough memory! Malloc call in file %s on line %d.\n", file, line);
    return NULL;
}

void* GetMetadataStart(void* ptr) {
    double* temp = (double*) ptr;
    temp--;
    return temp;
}

int IsAdjacentAndFree(char* start, void* ptr) { // check
    double* adjacentChunk = (double*) GetNextChunk(start);
    return (adjacentChunk == GetMetadataStart(ptr)) && IsFree(start) == 0;
}

void MergeBlocks(char* start, void* metadataPtr) {
    SetChunkSize(start, GetChunkSize(start) + GetChunkSize(metadataPtr));
    MarkAsFree(start);
}

void myfree(void* ptr, char* file, int line) {
    char* start = (char *) memory;
    char* memory_end = (char *) (((double *) memory) + MAXLENGTH);

    if(ptr == NULL) {
        printf("Null Pointer Exception! Cannot free Null pointer in file %s on line %d.\n", file, line);   //ERROR
        exit(EXIT_FAILURE);
    }

    if((char*) ptr > memory_end || (char*) ptr < start) {
        printf("Pointer outside of heap in file %s on line %d.\n", file, line);                        //ERROR
        exit(EXIT_FAILURE);
    }

    if(IsFree(GetMetadataStart(ptr)) == 0) {
        printf("No pointer at this location in file %s on line %d.\n", file, line);                        //ERROR
        exit(EXIT_FAILURE);
    }

    while(start < memory_end) {
        if(IsAdjacentAndFree(start, ptr)) {
            MergeBlocks(start, GetMetadataStart(ptr));
            if(GetNextChunk(GetMetadataStart(ptr)) < memory_end) {
                if(IsFree(GetNextChunk(GetMetadataStart(ptr))) == 0) {
                    MergeBlocks(start, GetNextChunk(GetMetadataStart(ptr)));
                }
            }
            MarkAsFree(GetMetadataStart(ptr)); // invalidate pointer
            return;
        }
        if(start == GetMetadataStart(ptr)) {
            if(IsFree(GetNextChunk(GetMetadataStart(ptr))) == 0) {
                MergeBlocks(GetMetadataStart(ptr), GetNextChunk(GetMetadataStart(ptr)));
            }
            MarkAsFree(GetMetadataStart(ptr));
            return;
        }
        start = GetNextChunk(start);
    }

    printf("Pointer not in heap. Called in file %s on line %d\n", file, line);
    exit(EXIT_FAILURE);
}

int memCleared() {
    char* start = (char *) memory;
    char* memory_end = (char *) (((double *) memory) + MAXLENGTH);
    int chunkSize = GetChunkSize(start);
    int isFree = IsFree(start);

    if(chunkSize == 0 && isFree == 0) {
        return 1;
    }

    while(isFree == 0) {
        start = GetNextChunk(start);
        if(start >= memory_end) {
            return 1;
        }
        isFree = IsFree(start);
    }
    return 0;
}