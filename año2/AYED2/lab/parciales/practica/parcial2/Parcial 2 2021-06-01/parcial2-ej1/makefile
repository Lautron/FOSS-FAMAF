CC=gcc 
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99 # Flags a utilizar
DEPS = stack.h # Archivos .h
OBJ = balanced.o stack.o # Archivos .o, uno por cada archivo .c
TARGET = main # nombre del ejecutable

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TARGET)
