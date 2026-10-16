/*A transportation network contains cities connected by roads with different costs. Write a C
program implementing Dijkstra’s Shortest Path Algorithm that accepts the number of vertices,
weighted adjacency matrix and source vertex, computes the minimum distance from the source to
every other vertex, and displays each destination with its shortest distance. Test it using at least
five vertices.*/
#include <stdio.h>
#define MAX 100
#define INFINITY 999999
void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INFINITY;
    }
    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min_dist = INFINITY, min_index;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                min_index = v;
            }
        }

        visited[min_index] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[min_index][v] && dist[min_index] != INFINITY &&
                dist[min_index] + graph[min_index][v] < dist[v]) {
                dist[v] = dist[min_index] + graph[min_index][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    int graph[MAX][MAX], n, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the weighted adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);
    return 0;
}