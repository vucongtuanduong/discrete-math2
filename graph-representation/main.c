#include "GraphAdjMatrix.c"
#include <stdio.h>
int main () {
    int n;
    scanf("%d", &n);
    Graph g = GraphNew(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &g->edges[i][j]);
        }
    }
    for (Vertex i = 0; i < n; i++) {
        for (Vertex j = 0; j < n; j++){
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}