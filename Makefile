# https://www.embarcados.com.br/introducao-ao-makefile/

all: main

main: main.o bitmap.o
	gcc main.o bitmap.o -o main

main.o: main.c bitmap.h
	gcc -o main.o main.c -c -W -Wall -pedantic

bitmap.o: bitmap.c bitmap.h
	gcc -o bitmap.o bitmap.c -c -W -Wall -pedantic

clean:
	rm -rf *.o
