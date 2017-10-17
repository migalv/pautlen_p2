# generation flags
CC = gcc -ansi -pedantic
CFLAGS = -Wall

all: prueba_tabla

clean:
	rm *.o prueba_tabla *.out

prueba_tabla: prueba_tabla.o tablaSimbolos.o tablaSimbolos.h
	$(CC) $(CFLAGS) -o $@ $@.o tablaSimbolos.o

prueba_tabla.o: prueba_tabla.c 
	$(CC) -c prueba_tabla.c

tablaSimbolos.o: tablaSimbolos.c tablaHash.o tablaHash.h
	$(CC) -c tablaSimbolos.c

tablaHash.o: tablaHash.c
	$(CC) -c tablaHash.c

generacion.o: generacion.c
	$(CC) -c generacion.c