ifeq ($(DEBUG), true)
CC = gcc -g
else
CC = gcc
endif

all: main.o list.o library.o
	$(CC) -o program main.o list.o library.o
main.o: main.c library.h list.h
	$(CC) -c main.c
library.o: library.c library.h list.h
	$(CC) -c library.c
list.o: list.c list.h
	$(CC) -c list.c
run:
	./program
clean:
	rm *.o
	rm program
