#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

#define DEFAULT_CAPACITY 16

struct graph {
	int nV;
	int nE;
	struct edge *edges;
	int maxE;
};

struct edge {
	Vertex v;
	Vertex w;
};
void GraphInsertEdge(Graph g, Vertex v, Vertex w) {
    
}