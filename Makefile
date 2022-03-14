CC=gcc
#CC=clang
CFLAGS= -Wall -Werror
#DEFS = defs.h
OBJ = main.o
LIBS= `pkg-config --cflags --libs gtk4`

output: 
	$(CC) main.c -o calculator $(LIBS)

clean:
	rm calculator
