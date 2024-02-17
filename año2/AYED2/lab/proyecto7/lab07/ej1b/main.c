#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s input/example_graph_1.in\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    graph_t graph = graph_from_file(argv[1]);
    graph_print(graph);
    graph = graph_destroy(graph);
}
