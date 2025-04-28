#include<stdio.h>
#define MAX 10
#define INF 1000000

void dijkstra(int graph[MAX][MAX], int n, int source, int dist[], int visited[]){
    int i, j, u, v, min;
    for(i=0; i<n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for(i=0; i<n-1; i++){
        min = INF;
        u = -1;

        for(j=0; j<n; j++){
            if(visited[j]==0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }

        if(u==-1){
            break;
        }
        visited[u] = 1;

        for(v=0; v<n; v++){
            if(visited[v]==0 && graph[u][v]!=0){
                if(dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v]; 
                }
            }
        }
    }
    printf("Shortest distance from source %d to all vertices:\n", source);
    for(i=0; i<n; i++){
        if(dist[i] == INF){
            printf("Vertex %d: INF\n", i);
        }
        else{
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main(){
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];
    int n, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adcacency matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, n, source, dist, visited);

    return 0;
}