#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct graph_data {
  cost_t** costs;
  unsigned int max_vertexs;
};

static bool invrep(graph_t g)
{
  bool res = g != NULL		  //
      && graph_max_vertexs(g) > 0 //
      && g->costs != NULL;	  //

  for (unsigned int i = 0; res && i < g->max_vertexs; ++i) {
    res = res && g->costs[i] != NULL;
  }
  return res;
}

graph_t graph_empty(unsigned int max_vertexs)
{
  graph_t graph = calloc(1, sizeof(struct graph_data));
  assert(graph != NULL);
  graph->max_vertexs = max_vertexs;
  graph->costs = calloc(max_vertexs, sizeof(cost_t*));
  // Create adjacency matrix for graph
  for (unsigned int i = 0; i < graph->max_vertexs; ++i) {
    graph->costs[i] = calloc(max_vertexs, sizeof(cost_t));
    for (unsigned int j = 0; j < graph->max_vertexs; ++j) {
      graph->costs[i][j] = cost_inf();
    }
  }
  assert(invrep(graph) && graph->costs != NULL);
  return graph;
}

unsigned int graph_max_vertexs(graph_t graph)
{
  assert(graph != NULL);
  return graph->max_vertexs;
}

void graph_add_edge(graph_t graph, vertex_t from, vertex_t to, cost_t cost)
{
  assert(graph != NULL);
  assert(from < graph->max_vertexs);
  assert(to < graph->max_vertexs);
  graph->costs[to][from] = cost;
}

cost_t graph_get_cost(graph_t graph, vertex_t from, vertex_t to)
{
  assert(graph != NULL);
  assert(from < graph->max_vertexs);
  assert(to < graph->max_vertexs);
  return graph->costs[to][from];
}

graph_t graph_destroy(graph_t graph)
{
  assert(graph != NULL);
  for (unsigned int i = 0; i < graph->max_vertexs; ++i) {
    free(graph->costs[i]);
  }
  free(graph->costs);
  free(graph);
  graph = NULL;
  assert(graph == NULL);
  return graph;
}

void graph_print(graph_t graph)
{
  assert(graph != NULL);
  printf("%u\n", graph->max_vertexs);
  for (unsigned int i = 0; i < graph->max_vertexs; ++i) {
    for (unsigned int j = 0; j < graph->max_vertexs; ++j) {
      const cost_t cost = graph_get_cost(graph, i, j);
      if (cost_is_inf(cost)) {
	printf("# ");
      } else {
	printf("%d ", cost);
      }
    }
    printf("\n");
  }
}

graph_t graph_from_file(const char* file_path)
{
  FILE* file = fopen(file_path, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }
  unsigned int tam = 0;
  fscanf(file, "%u", &tam);
  char word[256];
  const graph_t graph = graph_empty(tam);
  for (unsigned int i = 0; i < tam; ++i) {
    for (unsigned int j = 0; j < tam; ++j) {
      cost_t cost = cost_inf();
      fscanf(file, "%s", word);
      if (word[0] != '#') {
	cost = atoi(word);
      }
      graph_add_edge(graph, i, j, cost);
    }
  }
  fclose(file);
  return graph;
}
