#include<stdio.h>
#include<limits.h>
#define MAX 10

void prim(int graph[MAX][MAX], int n){
    int visited[MAX] = {0};
    int parent[MAX] = {-1};
    int weights[MAX] = {0};
    visited[0] = 1;
    for (int i=1; i<n; i++){
        int minW = INT_MAX;
        int minE = -1;
        for (int j=0; j<n; j++){
            if(visited[j]){
                for(int k=0; k<n; k++){
                    if(!visited[k] && graph[j][k] != 0 && graph[j][k] < minW){
                        minW = graph[j][k];
                        minE = k;
                        parent[k] = j;
                    }
                }
            }
        }
        visited[minE] = 1;
        weights[minE] = minW;
    }
    int total = 0;
    for(int i=1; i<n; i++){
        printf("%d-%d: %d\n", parent[i], i, weights[i]);
        total += weights[i];
    }
    printf("Total Weight: %d", total);
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    prim(graph, n);
    return 0;
}