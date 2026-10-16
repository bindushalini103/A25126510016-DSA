/*A network of n locations is represented as a graph. Write a C program that accepts the graph
using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, displays the visit
order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially
connected graphs.*/
#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void initialize() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

void readGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initialize();
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    readGraph();
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("DFS traversal: ");
    dfs(start);
    printf("\n");
    return 0;
}