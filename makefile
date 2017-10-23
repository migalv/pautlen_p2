# generation flags
CC = gcc -ansi -pedantic -g
CFLAGS = -Wall

all: prueba_tabla

clean:
	rm *.o prueba_tabla

prueba_tabla: prueba_tabla.o tablaHash.o tablaSimbolos.o tablaSimbolos.h tablaHash.h
	$(CC) $(CFLAGS) -o $@ $@.o tablaHash.o tablaSimbolos.o

prueba_tabla.o: prueba_tabla.c
	$(CC) -c prueba_tabla.c

tablaSimbolos.o: tablaSimbolos.c tablaHash.h
	$(CC) -c tablaSimbolos.c

tablaHash.o: tablaHash.c
	$(CC) -c tablaHash.c