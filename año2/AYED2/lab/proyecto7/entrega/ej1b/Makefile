CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
OBJECTS = cost.o graph.o
TARGET = graph

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS) main.c
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) main.c

valgrind: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET) input/example_graph_1.in

clean:
	rm -f $(TARGET) $(OBJECTS)



