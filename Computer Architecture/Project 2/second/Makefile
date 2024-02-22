TARGET = second
CC     = gcc
CFLAGS = -Wall -Wvla -Werror -std=c11 -fsanitize=address,undefined
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf $(TARGET) *.o *.a *.dylib *.dSYM
