CC=gcc
#CC=clang
CFLAGS= -Wall -Werror
#DEFS = defs.h
OBJ = main.o
LIBS= `pkg-config --cflags --libs gtk4`

output: main.o
	$(CC) main.o -o out $(LIBS)

main.o: main.c
	$(CC) -c main.c $(LIBS)

clean:
	rm *.o
