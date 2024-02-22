#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void printFileContents(const char *filename) {
    // Open the file
    int file = open(filename, O_RDONLY);

    // Check if the file can be opened
    if (file == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[4096];
    ssize_t bytesRead;

    /*int writeFile = open("output5.txt", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    dup2(writeFile, STDOUT_FILENO);
    close(writeFile);*/

    //printf("Contents of %s:\n", filename);
    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            perror("Error writing to standard output");
            exit(EXIT_FAILURE);
        }
    }

    // Close the file
    close(file);
    //close(outputFile);
}

int main(int argc, char *argv[]) {
    // Check if at least one file is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file1.txt [file2.txt ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Iterate through each provided file
    for (int i = 1; i < argc; i++) {
        printFileContents(argv[i]);
    }

    return EXIT_SUCCESS;
}