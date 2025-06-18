#include<stdio.h>
#define MAX 10
#define INF 1000000

int prac(int graph[MAX][MAX], int dist[MAX], int n, int src){
    for(int edges=1; edges<n; edges++){
        for(int u=0; u<n; u++){
            for(int v=0; v<n; v++){
                if(graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
                    dist[v] =  dist[u] + graph[u][v];
                }
            }
        }
    }
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            if(graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
                printf("graph contain negative edge!\n");
                break;
            }
        }
    }
    printf("Shortest distance from %d vertex to all vertices.\n");
    for(int i=0; i<n; i++){
        if(dist[i] == INF){
            printf("vertex %d: INF", i);
        }
        else{
            printf("Vertex %d : %d\n", i, dist[i]);
        }
    }
}

int main(){
    int graph[MAX][MAX];
    int dist[MAX];
    int v, src;

    printf("Enter number of vertices: ");
    scanf("%d", &v);
    
    printf("Adjacency matrix: \n");
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source: ");
    scanf("%d", &src);

    for(int i=0; i<v; i++){
        dist[i] = INF;
    }
    dist[src] = 0;

    prac(graph, dist, v, src);
    return 0;
}