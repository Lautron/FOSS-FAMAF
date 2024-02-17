#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "graph.h"

/** Dijkstra Algorithm
@param graph A graph represented as a cost matrix (@see graph.h)
@param init The initial vertex

@return An array of costs that contains
	for each position 'v' such that 0 <= 'v' < graph_max_size('graph'),
	the minimum cost of a path from 'init' to 'v' in the 'graph'.

@note The returned array must be freed by the user.
*/
cost_t *dijkstra(graph_t graph, vertex_t init);

#endif
