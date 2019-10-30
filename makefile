all: main.o list.o library.o
	gcc -o program main.o list.o library.o
main.o: main.c library.h list.h
	gcc -c main.c
library.o: library.c library.h list.h
	gcc -c library.c
list.o: list.c list.h
	gcc -c list.c
run:
	./program
clean:
	rm *.o
	rm program
