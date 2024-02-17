CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra -g -no-pie
TARGET = stringc
VALGRIND = valgrind --leak-check=full 
EXAMPLE = ba abb

.PHONY: clean

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o $(TARGET) 

valgrind:
	$(VALGRIND) ./$(TARGET) $(EXAMPLE) 10

run:
	./$(TARGET) $(EXAMPLE)

clean:
	@rm -f *.o
	@rm -f main
	@rm -f *.out