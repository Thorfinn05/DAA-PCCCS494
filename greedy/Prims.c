#include<stdio.h>
#define MAX 10
#define INF 100000

int prims(int graph[MAX][MAX], int v, int visited[], int root){
    int total = 0;
    visited[root] = 1;
    for(int edges=0; edges<v-1; edges++){
        int min = INF;
        int u=-1, w=-1;
        for(int i=0; i<v; i++){
            if(visited[i]){
                for(int j=0; j<v; j++){
                    if(!visited[j] && graph[i][j] && graph[i][j]<min){
                        min = graph[i][j];
                        u =i; w= j;
                    }
                }
            }
        }
        if(u!=-1 && w!=-1){
            printf("%d -> %d : %d\n", u, w, graph[u][w]);
            total += graph[u][w];
            visited[w] = 1;
        }
    }
    return total;
}

int main(){
    int graph[MAX][MAX];
    int v, root;
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix: ");
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the root: ");
    scanf("%d", &root);

    int cost = prims(graph, v, visited, root);
    printf("Total Minimum Cost: %d", cost);

    return 0;
}