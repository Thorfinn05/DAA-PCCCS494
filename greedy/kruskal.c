#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int kruskal(int edges[MAX][3], int e, int visited[]){
    int total=0, t1, t2, t3;

    // Sort edges by weight
    for(int i=0;i<e;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j][2]>edges[j+1][2]){
                t1=edges[j][0];
                edges[j][0]=edges[j+1][0];
                edges[j+1][0]=t1;
                
                t2=edges[j][1];
                edges[j][1]=edges[j+1][1];
                edges[j+1][1]=t2;
                
                t3=edges[j][2];
                edges[j][2]=edges[j+1][2];
                edges[j+1][2]=t3;
            }
        }
    }

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(visited[u] != visited[v]){ // different components
            total += w;
            printf("%d - %d : %d\n", u, v, w);

            int old_comp = visited[v];
            int new_comp = visited[u];

            // Merge components
            for(int j=0; j<v; j++){
                if(visited[j] == old_comp){
                    visited[j] = new_comp;
                }
            }
        }
    }

    return total;
}

int main(){
    int edges[MAX][3]; 
    int v, e;
    printf("Enter no. of vertices: ");
    scanf("%d", &v); 
    printf("Enter no. of edges: ");
    scanf("%d", &e);   

    int visited[MAX];
    for (int i = 0; i < v; i++) {
        visited[i]=i; // Each vertex initially in its own component
    }

    printf("Enter edges (format: u v weight):\n");
    for (int i = 0; i < e; i++) {
        for(int j = 0; j < 3; j++){
            scanf("%d", &edges[i][j]);
        }
    }

    printf("Edges in MST:\n");
    printf("Total minimum cost: %d\n", kruskal(edges, e, visited));
    return 0;
}