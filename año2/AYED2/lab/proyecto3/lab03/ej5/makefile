CC=gcc 
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = player.h helpers.h sort.h # Archivos .h
OBJ = sort.o helpers.o main.o # Archivos .o, uno por cada archivo .c
TARGET = main # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)
