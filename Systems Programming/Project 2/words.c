// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <dirent.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <ctype.h>

// #define MAX_WORD_LENGTH 100
// #define MAX_WORDS 10000

// int currentWordMaxMultiplier = 1;
// int currentWordLengthMultiplier = 1;

// typedef struct {
//     //char word[MAX_WORD_LENGTH];
//     char* word;
//     int count;
// } WordCount;

// void printWordCounts(WordCount *wordCounts, int wordCountSize) {
//     for(int i = 0; i < wordCountSize; i++) {
//         printf("i: %d\tword: %s:\t%d\n", i, wordCounts[i].word, wordCounts[i].count);
//     }
// }

// int compareWordCounts(const void *a, const void *b) {
//     WordCount *word1 = (WordCount *)a;
//     WordCount *word2 = (WordCount *)b;

//     if (word1->count == word2->count) {
//         return strcmp(word1->word, word2->word);
//     }
//     return word2->count - word1->count;
// }

// WordCount* processFile(const char *filename, WordCount *wordCounts, int *wordCountSize) {
//     int fd = open(filename, O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return wordCounts;
//     }

//     char* word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
//     char prevChar = '-';
//     char currentChar = '-';
//     char nextChar;
//     int i = 0;
//     read(fd, &currentChar, 1);
//     if(currentChar <= 0) {
//         close(fd);
//         return wordCounts;
//     }
    
//     while(read(fd, &nextChar, 1) > 0) {
//         if(currentChar == 39 || isalpha(currentChar) > 0 || (currentChar == '-' && isalpha(prevChar) > 0 && isalpha(nextChar) > 0)) {
//             word[i] = currentChar;
//             i++;
//             if(i >= currentWordLengthMultiplier*MAX_WORD_LENGTH) {
//                 currentWordLengthMultiplier++;
//                 word = (char*) realloc(word, currentWordLengthMultiplier*MAX_WORD_LENGTH*sizeof(char));
//             }
//         } else if(i > 0) {
//             word[i] = '\0';
//             i = 0;

//             int found = 0;
//             for (int j = 0; j < *wordCountSize; j++) {
//                 if (strcmp(word, wordCounts[j].word) == 0) {
//                     wordCounts[j].count++;
//                     found = 1;
//                     break;
//                 }
//             }
//             if (!found) {
//                 wordCounts[*wordCountSize].word = word;
//                 wordCounts[*wordCountSize].count = 1;
//                 (*wordCountSize)++;
//                 if(*wordCountSize >= currentWordMaxMultiplier*MAX_WORDS) { // THIS SHOULD RESIZE THE ARRAY
//                     currentWordMaxMultiplier++;
//                     wordCounts = (WordCount*) realloc(wordCounts, currentWordMaxMultiplier*MAX_WORDS*sizeof(WordCount));
//                 }
//             }

//             word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
//         }

//         prevChar = currentChar;
//         currentChar = nextChar;
//     }

//     if(currentChar == 39 || isalpha(currentChar) > 0) {
//         word[i] = currentChar;
//         i++;
//     }

//     if(i > 0) {
//         word[i] = '\0';
//         int found = 0;
//         for (int j = 0; j < *wordCountSize; j++) {
//             if (strcmp(word, wordCounts[j].word) == 0) {
//                 wordCounts[j].count++;
//                 found = 1;
//                 break;
//             }
//         }
//         if (!found) {
//             wordCounts[*wordCountSize].word = word;
//             wordCounts[*wordCountSize].count = 1;
//             (*wordCountSize)++;
//         }
//     }

//     close(fd);
//     return wordCounts;
// }

// void processDirectory(const char *dirname, WordCount *wordCounts, int *wordCountSize) {
//     DIR *dir = opendir(dirname);
//     if (dir == NULL) {
//         perror("Error opening directory");
//         return;
//     }

//     struct dirent *entry;
//     char path[1024]; 
//     while ((entry = readdir(dir)) != NULL) {
//         snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

//         struct stat st;
//         if (stat(path, &st) == 0) {
//             if (S_ISREG(st.st_mode) && strstr(entry->d_name, ".txt") != NULL) {
//                 wordCounts = processFile(path, wordCounts, wordCountSize);
//             } else if (S_ISDIR(st.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
//                 processDirectory(path, wordCounts, wordCountSize);
//             }
//         } else {
//             perror("Error getting file/directory information");
//         }
//     }

//     closedir(dir);
// }



// int main(int argc, char *argv[]) {
//     //if (argc < 2) {
//       //  fprintf(stderr, "Usage: %s <file/directory> [file/directory]...\n", argv[0]);
//        // return 1;
//     //}

//     //WordCount wordCounts[MAX_WORDS];
//     WordCount *wordCounts = (WordCount*) malloc(MAX_WORDS * sizeof(WordCount));
//     int wordCountSize = 0;

//     for (int i = 1; i < argc; i++) {
//         struct stat st;
//         if (stat(argv[i], &st) == 0) {
//             if (S_ISREG(st.st_mode)) {
//                 wordCounts = processFile(argv[i], wordCounts, &wordCountSize);
//             } else if (S_ISDIR(st.st_mode)) {
//                 processDirectory(argv[i], wordCounts, &wordCountSize);
//             } else {
//                 fprintf(stderr, "Unsupported file type: %s\n", argv[i]);
//             }
//         } else {
//             perror("Error getting file/directory information");
//         }
//     }


//     qsort(wordCounts, wordCountSize, sizeof(WordCount), compareWordCounts);

//     for (int i = 0; i < wordCountSize; i++) {
//         printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
//         free(wordCounts[i].word);
//     }

//     free(wordCounts);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

int currentWordMaxMultiplier = 1;
int currentWordLengthMultiplier = 1;

typedef struct {
    char* word;
    int count;
} WordCount;

/*void appendIntToString(int num, char* buff) {
    int temp = num;
    int numDigits = 0;
    do {
        numDigits++;
        temp /= 10;
    } while (temp != 0);


}*/

void printWordCounts(WordCount *wordCounts, int wordCountSize) {
    char* buffer;
    for(int i = 0; i < wordCountSize; i++) {
        //printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        buffer = (char*) malloc((strlen(wordCounts[i].word) + 100) * sizeof(char));
        memcpy(buffer, wordCounts[i].word, (strlen(wordCounts[i].word))*sizeof(char));
        char intbuf[99];
        sprintf(intbuf, "%d", wordCounts[i].count);
        buffer[strlen(wordCounts[i].word)] = ':';
        buffer[strlen(wordCounts[i].word) + 1] = ' ';
        char* temp = buffer+strlen(wordCounts[i].word) + 2;
        memcpy(temp, intbuf, (strlen(intbuf)*sizeof(char)));
        buffer[strlen(wordCounts[i].word) + strlen(intbuf) + 2] = '\n';
        write(1, buffer, strlen(buffer));
    }
}

int compareWordCounts(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;

    if (word1->count == word2->count) {
        return strcmp(word1->word, word2->word);
    }
    return word2->count - word1->count;
}

WordCount* processFile(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return wordCounts;
    }

    char* word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
    char prevChar = '-';
    char currentChar = '-';
    char nextChar;
    int i = 0;
    read(fd, &currentChar, 1);
    if(currentChar <= 0) {
        close(fd);
        return wordCounts;
    }

    while(read(fd, &nextChar, 1) > 0) {
        if(currentChar == 39 || isalpha(currentChar) > 0 || (currentChar == '-' && isalpha(prevChar) > 0 && isalpha(nextChar) > 0)) {
            word[i] = currentChar;
            i++;
            if(i >= currentWordLengthMultiplier*MAX_WORD_LENGTH) {
                currentWordLengthMultiplier++;
                word = (char*) realloc(word, currentWordLengthMultiplier*MAX_WORD_LENGTH*sizeof(char));
            }
        } else if(i > 0) {
            word[i] = '\0';
            i = 0;

            int found = 0;
            for (int j = 0; j < *wordCountSize; j++) {
                if (strcmp(word, wordCounts[j].word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                wordCounts[*wordCountSize].word = word;
                wordCounts[*wordCountSize].count = 1;
                (*wordCountSize)++;
                if(*wordCountSize >= currentWordMaxMultiplier*MAX_WORDS) {
                    currentWordMaxMultiplier++;
                    wordCounts = (WordCount*) realloc(wordCounts, currentWordMaxMultiplier*MAX_WORDS*sizeof(WordCount));
                }
            }

            word = (char*) malloc(MAX_WORD_LENGTH*sizeof(char));
        }

        prevChar = currentChar;
        currentChar = nextChar;
    }
    if(currentChar == 39 || isalpha(currentChar) > 0) {
        word[i] = currentChar;
        i++;
    } 

    if(i > 0) {
        word[i] = '\0';
        int found = 0;
        for (int j = 0; j < *wordCountSize; j++) {
            if (strcmp(word, wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordCounts[*wordCountSize].word = word;
            wordCounts[*wordCountSize].count = 1;
            (*wordCountSize)++;
        }
    }

    close(fd);
    return wordCounts;
}

void processDirectory(const char *dirname, WordCount *wordCounts, int *wordCountSize) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    char path[1024];
    
    struct stat st;

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode) && strstr(entry->d_name, ".txt") != NULL) {
                wordCounts = processFile(path, wordCounts, wordCountSize);
            } else if (S_ISDIR(st.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                processDirectory(path, wordCounts, wordCountSize);
            }
        } else {
            perror("Error getting file/directory information");
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file/directory> [file/directory]...\n", argv[0]);
        return 1;
    }

    WordCount *wordCounts = (WordCount*) malloc(MAX_WORDS * sizeof(WordCount));
    int wordCountSize = 0;

    for (int i = 1; i < argc; i++) {
        struct stat st;
        if (stat(argv[i], &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                wordCounts = processFile(argv[i], wordCounts, &wordCountSize);
            } else if (S_ISDIR(st.st_mode)) {
                processDirectory(argv[i], wordCounts, &wordCountSize);
            } else {
                fprintf(stderr, "Unsupported file type: %s\n", argv[i]);
            }
        } else {
            perror("Error getting file/directory information");
        }
    }

    qsort(wordCounts, wordCountSize, sizeof(WordCount), compareWordCounts);

    printWordCounts(wordCounts, wordCountSize);

    for (int i = 0; i < wordCountSize; i++) {
        //write()
        free(wordCounts[i].word);
    }

    free(wordCounts);
    return 0;
}