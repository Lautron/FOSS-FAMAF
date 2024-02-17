#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "cost.h"

/** Vertices are represented with natural numbers
*/
typedef unsigned int vertex_t;
typedef struct graph_data *graph_t;

/** Returns an empty graph
@param max_vertexs Amount of vertices this graph can contain
@note Vertices are zero-based: {0, 1, ..., max_vetexs - 1}
*/
graph_t graph_empty(unsigned int max_vertexs);

/** Returns the amount of vertices of the given graph
@param graph A graph
*/
unsigned int graph_max_vertexs(graph_t graph);

/** Adds an edge with the given cost to the graph
@param graph A graph
@param from A source vertex (assumed to be less than max_vertexs)
@param to A target vertex (assumed to be less than max_vertexs)
@param cost The cost assigned to this edge
*/
void graph_add_edge(graph_t graph, vertex_t from, vertex_t to,
                    cost_t cost);

/** Returns the cost assigned to the given edge
@param graph A graph
@param from The source vertex of the edge (assumed to be less than max_vertexs)
@param to The target vertex of the edge (assumed to be less than max_vertexs)
*/
cost_t graph_get_cost(graph_t graph, vertex_t from, vertex_t to);

/** Free memory resources
@param graph A graph
*/
graph_t graph_destroy(graph_t graph);

/** Reads a graph from a file
@param filepath The path to the file containing the graph specification
@note Expected format has the following structure:
<N+1>
<cost_00> ... <cost_0j> ... <cost_0N>
...         
<cost_N0> ... <cost_Nj> ... <cost_NN>
where N+1 = max_vertexs
*/
graph_t graph_from_file(const char *file_path);

/** Prints a graph in stdout using the same format as graph_from_file
*/
void graph_print(graph_t graph);

#endif
