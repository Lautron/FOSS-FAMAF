CC=gcc 
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = strfuncs.h # Archivos .h
OBJ = strfuncs.o main.o # Archivos .o, uno por cada archivo .c
TARGET = main # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)
