#include<stdio.h>
#include<stdlib.h>
#define INF 99999
#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(Edge edges[], int V, int E, int src){
    int dist[MAX];

    for(int i=0; i<V; i++){
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i=1; i<=V-1; i++){
        for (int j=0; j<E; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int j=0; j<E; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]){
            printf("\nGraph contains qa negative weight cycle!\n");
            return;
        }
    }
    printf("\nVertex\tDistance from Source %d\n", src);
    for(int i =0; i<V; i++){
        if(dist[i]==INF)
            printf("%d\t\tINF\n", i);
        else    
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, E;
    Edge edges[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter each edge in format (u v weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    return 0;
}