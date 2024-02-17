CC=gcc # Compilador
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = array_helpers.h # Archivos .h
OBJ = array_helpers.o main.o # Archivos .o, uno por cada archivo .c
TARGET = reader # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

reader: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

