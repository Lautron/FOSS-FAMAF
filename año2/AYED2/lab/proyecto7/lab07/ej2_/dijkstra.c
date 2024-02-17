#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

cost_t min(cost_t a, cost_t b)
{
  return cost_lt(a, b) ? a : b;
}

type_elem menor_costo(set C, cost_t* D, graph_t graph)
{
  type_elem result;
  bool is_result_initialized = false;
  for (type_elem i = 0; i < graph_max_vertexs(graph); ++i) {
    if (set_member(i, C) && (!is_result_initialized || D[i] < D[result])) {
      result = i;
      is_result_initialized = true;
    }
  }
  return result;
}

cost_t* dijkstra(graph_t graph, vertex_t init)
{

  type_elem max_vertexs = graph_max_vertexs(graph);
  cost_t* D = calloc(max_vertexs, sizeof(cost_t));
  type_elem c;
  set C = set_empty();

  for (type_elem i = 0; i < max_vertexs; ++i) {
    C = set_add(C, i);
  }
  C = set_elim(C, init);

  for (type_elem j = 0; j < max_vertexs; ++j) {
    D[j] = graph_get_cost(graph, init, j);
  }

  while (!set_is_empty(C)) {
    c = menor_costo(C, D, graph);
    C = set_elim(C, c);
    for (type_elem i = 0; i < max_vertexs; ++i) {
      if (set_member(i, C)) {
	D[i] = min(					//
	    D[i],					//
	    cost_sum(D[c], graph_get_cost(graph, c, i)) //
	);
      }
    }
  }
  return D;
}
