#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./dijkstra input/example_graph_1.in\n");
        exit(EXIT_FAILURE);
    }
    graph_t graph = graph_from_file(argv[1]);
    vertex_t init = 0;
    cost_t *costs = dijkstra(graph, init);
    printf("Dijkstra Shortest Path Algorithm\n");
    for (unsigned int v = 0; v < graph_max_vertexs(graph); v++) {
        printf("Minimum cost from %d to %d: ", init, v);
        cost_print(costs[v]);
        printf("\n");
    }
    free(costs);
    graph = graph_destroy(graph);
}
