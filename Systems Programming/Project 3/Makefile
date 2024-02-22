CC = gcc
CFLAGS = -Wall -Wextra

mysh: mysh.c
	$(CC) $(CFLAGS) -o mysh mysh.c

printFiles: printFiles.c
	$(CC) $(CFLAGS) -o printFiles printFiles.c

inputTest: inputTest.c
	$(CC) $(CFLAGS) -o inputTest inputTest.c

test: test.c
	$(CC) $(CFLAGS) -o test test.c

test2: test2.c
	$(CC) $(CFLAGS) -o test2 test2.c

.PHONY: clean

clean:
	rm -f mysh
