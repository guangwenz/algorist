#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

#define MAXV	1000

typedef struct edgenode_ {
	int y;
	struct edgenode_ *next;
} edgenode;

typedef struct {
	edgenode *edges[MAXV + 1];
	int degrees[MAXV + 1];
	int nVertices;
	int nEdges;
	bool directed;
} graph;

void initialize_graph(graph *g, bool directed) {
	g -> nVertices = 0;
	g -> nEdges = 0;
	g -> directed = directed;

	for(int i=0;i<=MAXV;i++) g -> degrees[i] = 0;
	for(int i=0;i<=MAXV;i++) g -> edges[i] = NULL;
}

void print_graph(graph *g) {
	printf("vertices count: %d\n", g -> nVertices);
	printf("directed: %d\n", g -> directed);
	for (int i = 0; i < g -> nVertices; i++ ){
		printf("\n");
		printf("vertix: %d\n", i);
		edgenode *p = g -> edges[i];
		while(p != NULL) {
			printf("node: %d\n", p -> y);
			p = p -> next;
		}
	}
}

void insert_edge(graph *g, int x, int y) {
	edgenode *p;
	p = malloc(	sizeof(edgenode));
	
	p -> y = y;
	p -> next = g -> edges[x];

	g -> edges[x] = p;
	g -> degrees[x] ++;
	g -> nVertices ++;
}

void bfs(graph *g, int start) {
	printf("%s\n", "bfs searching");
	bool discovered[g -> nVertices];
	bool processed[g -> nVertices];
	int parent[g -> nVertices];

	//initialize vertex states.
	for(int i=0;i<g -> nVertices;i++) {
		discovered[i] = processed[i] =false;
		parent[i]=-1;
	}

	discovered[start] = true;
	parent[start]=-1;
	
	for(int i=0; i< g->nVertices;i++){
		edgenode *p = g -> edges[i];
		while(p != NULL) {
			int y = p -> y;
			p = p -> next;
		}
	}
}

int main(int argc, char const *argv[])
{
	graph * g = (graph *) malloc(sizeof(graph));
	initialize_graph(g, true);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_graph(g);

	bfs(g, 0);
	return 0;
}