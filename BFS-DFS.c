#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int stack[MAX];
int n, i, choice, front = -1, rear = -1, top = -1;

void bfs(int graph[MAX][MAX], int n, int root){
    int visited[MAX] = {0};
    front = 0; rear = 0;
    visited[root] = 1;
    queue[rear++] = root;
    while(front<rear){
        int u = queue[front++];
        printf("%d ", u);
        for(int v=0; v<n; v++){
            if(graph[u][v] == 1 && !visited[v]){
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

void dfs(int graph[MAX][MAX], int root){
    int visited[MAX] = {0};
    stack[++top] = root;
    while(top != -1){
        int u = stack[top--];
        if(!visited[u]){
            printf("%d ", u);
            visited[u] = 1;
            for(int v=n-1; v>0; v--){
                if(graph[u][v] == 1 && !visited[v]){
                    stack[++top] = v;
                }
            }
        }
    }
}
int main(){
    int graph[MAX][MAX];
    int root;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Adjacency matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter root: ");
    scanf("%d", &root);
    bfs(graph, n, root);
    printf("\n");
    dfs(graph, root);
    return 0;
}