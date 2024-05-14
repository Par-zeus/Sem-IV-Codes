#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

void graphColoringUtil(bool graph[V][V], int m, int color[], int v, int *solutionCount) {
    if (v == V) {
        printf("Solution %d:\n", ++(*solutionCount));
        printSolution(color);
        printf("\n");
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            graphColoringUtil(graph, m, color, v + 1, solutionCount);
            color[v] = 0;
        }
    }
}

void graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    int solutionCount = 0;
    graphColoringUtil(graph, m, color, 0, &solutionCount);

    if (solutionCount == 0) {
        printf("No solution exists.\n");
    } else {
        printf("Total solutions: %d\n", solutionCount);
    }
}

void printSolution(int color[]) {
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors

    graphColoring(graph, m);
    return 0;
}