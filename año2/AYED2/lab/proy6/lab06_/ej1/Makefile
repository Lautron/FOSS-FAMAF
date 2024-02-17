CC = gcc
CFLAGS = -Wall  -Wextra -pedantic -std=c99 -g
SOURCES = abb.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = readtree
VALGRIND = valgrind --leak-check=full 

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

valgrind:
	$(VALGRIND) ./$(TARGET) 10
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
