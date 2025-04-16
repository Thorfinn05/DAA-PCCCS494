#include <stdio.h>
#include <limits.h>

#define MAX 10 

int findNearestCity(int graph[MAX][MAX], int visited[MAX], int n, int city) {
    int minCost = INT_MAX, nearestCity = -1;
	int i;
    for ( i = 0; i < n; i++) {
        if (!visited[i] && graph[city][i] < minCost) {
            nearestCity = i;
            minCost = graph[city][i];
        }
    }

    return nearestCity;
}

// Function to solve TSP using the Greedy Approach
void tsp(int graph[MAX][MAX], int n, int startCity) {
    int visited[MAX] = {0}; // Track visited cities
    int path[MAX]; // Store the travel path
    int totalCost = 0, city = startCity, count = 0;

    visited[city] = 1; // Mark starting city as visited
    path[count++] = city;

    // Visit all cities using the greedy approach
    while (count < n) {
        int nearestCity = findNearestCity(graph, visited, n, city);

        if (nearestCity != -1) {
            visited[nearestCity] = 1;
            path[count++] = nearestCity;
            totalCost += graph[city][nearestCity];
            city = nearestCity;
        }
    }

    // Return to the starting city
    totalCost += graph[city][startCity];
    path[count] = startCity;

    // Print the path and total cost
    printf("Optimal Path (Greedy): ");
    int i;
    for ( i = 0; i <= n; i++)
        printf("%d -> ", path[i]);
    printf("\nTotal Cost: %d\n", totalCost);
}

// Main function
int main() {
    int n, startCity;
    int graph[MAX][MAX];

    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the distance matrix:\n");
    int i,j;
    for (i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    // Input the starting city
    printf("Enter the starting city (0 to %d): ", n - 1);
    scanf("%d", &startCity);

    // Solve TSP using the greedy approach
    tsp(graph, n, startCity);

    return 0;
}