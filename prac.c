#include<stdio.h>
#define MAX 10
int x[MAX];

void nextvalue(int graph[MAX][MAX], int k, int m, int n){
    while(1){
        x[k] = x[k+1] % (m+1);
        if (x[k]==0)
            return;
        int j;
        for(int j=0; j<n; j++){
            if(graph[j][k] != 0 && x[k]==x[j])
                break;
        }
        if(j==n)
            return;
    }
}

void mColoring(int graph[MAX][MAX], int k, int m, int n){
    while(1){
        nextvalue(graph, k, m, n);
        if(x[k]==0){
            return;
        }
        if(k==n-1){
            for(int i=0; i<n; i++){
                printf("%d", x[i]);
            }
            printf("\n");
        }
        else{
            mColoring(graph, k+1, m, n);
        }
    }
}

int main(){
    int graph[MAX][MAX];
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter no. of colors: ");
    scanf("%d", &m);

    for(int i=0; i<n; i++){
        x[i] = 0;
    }

     printf("Assigned COLORS: \n");
    mColoring(graph, 0, m, n);
    return 0;
}