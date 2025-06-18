#include<stdio.h>
#define MAX 20

int isSafe(char graph[MAX][MAX], int n, int row, int col){
    for(int i=0; i<n; i++){
        if(graph[i][col] == 'Q')
            return 0;
    }
    for(int i=row, j=col; i>=0, j>=0; i--, j--){
        if(graph[i][j] == 'Q')
            return 0;
    }
    for(int i=row, j=col; i>=0, j<n; i--, j++){
        if(graph[i][j] == 'Q')
            return 0;
    }
}

void nQueensP(char graph[MAX][MAX], int n, int r){
    if(r==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%c ", graph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else{
        for(int c=0; c<n; c++){
            if(isSafe(graph, n, r, c)){
                graph[r][c] = 'Q';
                nQueensP(graph, n, r+1);
                graph[r][c] = '.';
            }
        }
    }
}

int main(){
    char graph[MAX][MAX];
    int n;  
    printf("Enter n: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graph[i][j] = '.';
        }
    }
    printf("Boards: \n");
    nQueensP(graph, n, 0);
    return 0;
}