CC=gcc 
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = array_helpers.h # Archivos .h
OBJ = main.o array_helpers.o # Archivos .o, uno por cada archivo .c
TARGET = main # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)
