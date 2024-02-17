CC=gcc # Compilador
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = array_helpers.h sort_helpers.h sort.h # Archivos .h
OBJ = array_helpers.o sort.o sort_helpers.o main.o# Archivos .o, uno por cada archivo .c
TARGET = reader # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sorter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -no-pie

