CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

SRC = words.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = words

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLE)
