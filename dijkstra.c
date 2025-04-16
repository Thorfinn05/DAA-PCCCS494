#include <stdio.h>
#include <limits.h>

#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];  // Stores the shortest distance from source to each node
    int visited[MAX] = {0};  // Marks visited nodes
    int parent[MAX];  // Stores the shortest path tree

    // Initialize distances and parent array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;  // Distance to source is 0

    for (int i = 0; i < n - 1; i++) {
        int minDist = INT_MAX, minIndex = -1;

        // Find the node with the smallest distance that hasn't been visited
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;

        // Update the distances of adjacent nodes
        for (int k = 0; k < n; k++) {
            if (!visited[k] && graph[minIndex][k] && dist[minIndex] != INT_MAX && 
                dist[minIndex] + graph[minIndex][k] < dist[k]) {
                dist[k] = dist[minIndex] + graph[minIndex][k];
                parent[k] = minIndex;
            }
        }
    }

    // Print the shortest paths
    printf("Vertex   Distance from Source   Path\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i, dist[i]);
        int temp = i;
        while (parent[temp] != -1) {
            printf("%d <- ", temp);
            temp = parent[temp];
        }
        printf("%d\n", src);
    }
}

int main() {
    int n, src;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {0};

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}