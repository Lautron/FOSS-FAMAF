CC=gcc 
CFLAGS= -Wall -Wextra -pedantic -std=c99 # Flags a utilizar
#CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = list.h array_helpers.h # Archivos .h
OBJ = list.o array_helpers.o main.o # Archivos .o, uno por cada archivo .c
TARGET = main # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)
