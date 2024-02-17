CC = gcc
GDB = gdb
VAL = valgrind
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -std=c99 -g
VFLAGS = --leak-check=full 
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = main
ARGS = 

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$^ $(ARGS)

gdb: $(TARGET)
	$(GDB) --args ./$^ $(ARGS)
	
val: $(TARGET)
	$(VAL) $(VFLAGS) ./$^ $(ARGS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)

