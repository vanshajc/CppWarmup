CC=g++
CFLAGS=-I.

match: match.o
	$(CC) -o match match.o
