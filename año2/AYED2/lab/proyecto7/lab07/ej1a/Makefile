CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
OBJECTS = cost.o graph.o
TARGET = graph

BAD_GRAPH = bad_graph
BAD_OBJECTS = cost.o graph_bad.o

.PHONY: clean

all: $(TARGET)

graph_bad.o: graph_bad.c
	$(CC) $(CFLAGS) -Wno-unused -c graph_bad.c

$(BAD_GRAPH): $(BAD_OBJECTS)
	$(CC) $(CFLAGS) -o $(BAD_GRAPH) $(BAD_OBJECTS) main.c


$(TARGET): $(OBJECTS) main.c
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) main.c

valgrind: $(TARGET)
	valgrind --show-reachable=yes --leak-check=full ./$(TARGET) input/example_graph_1.in

test_bad: $(BAD_GRAPH)
	valgrind --show-reachable=yes --leak-check=full ./$(BAD_GRAPH) input/example_graph_1.in

clean:
	rm -f $(TARGET) $(OBJECTS) $(BAD_GRAPH) $(BAD_OBJECTS)



