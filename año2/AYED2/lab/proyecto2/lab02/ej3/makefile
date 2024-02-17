CC=gcc 
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = sort_helpers.h array_helpers.h sort.h # Archivos .h
OBJ = sort.o array_helpers.o sort_helpers.o main.o # Archivos .o, uno por cada archivo .c
TARGET = sorter # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)
