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
void addEdge(Graph *graph, char start, char end, int weight) {
    int startIndex = -1;
    int endIndex = -1;
    
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->vertices[i] == start) {
            startIndex = i;
        }
        if (graph->vertices[i] == end) {
            endIndex = i;
        }
    }
    
    if (startIndex != -1 && endIndex != -1) {
        graph->adjMatrix[startIndex][endIndex] = weight;
        graph->adjMatrix[endIndex][startIndex] = weight; // Se o grafo for não direcionado
    }
}

void displayGraph(Graph *graph) {
    int i, j;
    
    printf("Vertices: ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%c ", graph->vertices[i]);
    }
    printf("\n");
    
    printf("Edges:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] != 0) {
                printf("%c - %d - %c \n", graph->vertices[i], graph->adjMatrix[i][j] ,graph->vertices[j]);
            }
        }
    }
}

void addEdgesFromFile(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }
    
    char start, end;
    int weight;
    while (fscanf(file, " %c %c %d", &start, &end, &weight) == 3) {
        addEdge(graph, start, end, weight);
    }
    
    fclose(file);
}
