#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6

typedef struct {
    int numVertices;
    char vertices[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *graph) {
    int i, j;
    
    graph->numVertices = 0;
    
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = '\0';
        
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addVertex(Graph *graph, char vertex) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->vertices[graph->numVertices++] = vertex;
    }
}
