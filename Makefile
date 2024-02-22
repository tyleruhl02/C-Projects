CC = gcc
CFLAGS = -g -std=c99 -Wvla -Wall -fsanitize=address,undefined

mymalloc.o: mymalloc.c mymalloc.h
	$(CC) $(CFLAGS) -c mymalloc.c

mymalloc: mymalloc.o
	$(CC) $(CFLAGS) -o mymalloc mymalloc.o

memgrind.o: memgrind.c
	$(CC) $(CFLAGS) -c memgrind.c

memgrind: mymalloc.o memgrind.o
	$(CC) $(CFLAGS) -o memgrind memgrind.o mymalloc.o

test1: mymalloc.o test1.o
	$(CC) $(CFLAGS) -o test1 test1.o mymalloc.o 

test2: mymalloc.o test2.o
	$(CC) $(CFLAGS) -o test2 test2.o mymalloc.o 

test3: mymalloc.o test3.o
	$(CC) $(CFLAGS) -o test3 test3.o mymalloc.o 

test4: mymalloc.o test4.o
	$(CC) $(CFLAGS) -o test4 test4.o mymalloc.o 

test5: mymalloc.o test5.o
	$(CC) $(CFLAGS) -o test5 test5.o mymalloc.o 

test6: mymalloc.o test6.o
	$(CC) $(CFLAGS) -o test6 test6.o mymalloc.o 

test7: mymalloc.o test7.o
	$(CC) $(CFLAGS) -o test7 test7.o mymalloc.o 

test8: mymalloc.o test8.o
	$(CC) $(CFLAGS) -o test8 test8.o mymalloc.o 

test9: mymalloc.o test9.o
	$(CC) $(CFLAGS) -o test9 test9.o mymalloc.o 

test10: mymalloc.o test10.o
	$(CC) $(CFLAGS) -o test10 test10.o mymalloc.o 

test11: mymalloc.o test11.o
	$(CC) $(CFLAGS) -o test11 test11.o mymalloc.o 

clean:
	rm -f *.o mymalloc