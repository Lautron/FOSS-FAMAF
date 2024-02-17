CC = gcc
CFLAGS = -Wall  -Wextra -pedantic -std=c99 -g
TARGET = readdict
VALGRIND = valgrind --leak-check=full 

.PHONY: clean

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o $(TARGET)

valgrind:
	$(VALGRIND) ./$(TARGET) 10

clean:
	@rm -f *.o
	@rm -f $(TARGET)
	@rm -f *.out
