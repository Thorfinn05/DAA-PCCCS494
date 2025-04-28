#include<stdio.h>
#define MAX 20
#define INF 1000000

int C[MAX][MAX];
int n;

int cost(int i, int D[], int dSize, int visited[], int path[], int index){
    if(dSize == 0){
        path[index] = 1;
        return C[i][1];
    }

    int minCost = INF;
    int bestCity = -1;

    for(int k=0; k<dSize; k++){
        int j=D[k];

        if(visited[j]) continue;

        visited[j] = 1;
        path[index] = j;

        int newD[MAX], newIndex = 0;
        for(int m=0; m<dSize; m++){
            if(m!=k){
                newD[newIndex++] = D[m];
            }
        }
        int newCost = C[i][j] + cost(j, newD, dSize-1, visited, path, index+1);

        if(newCost < minCost){
            minCost=newCost;
            bestCity=j;
        }
        visited[j] = 0;
    }
    return minCost;
}

int main(){
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix: \n");
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j){
                C[i][j] =0;
            }
            else{
                printf("Enter cost from %d to %d: ", i, j);
            scanf("%d", &C[i][j]);
            }
        }
    }
    int D[MAX];
    int dSize = 0;
    for(int i=2; i<n; i++){
        D[dSize++] = i;
    }

    int visited[MAX] = {0};
    visited[1] = 1;

    int path[MAX];

    int tour = cost(1, D, dSize, visited, path, 1);

    printf("\nMin tour cost: %d", tour);

    printf("Best tour sequence: 1 -> ");
    for(int i=1; i<=n-1; i++){
        printf("%d -> ", path[i]);
    }
    printf("1\n");

    return 0;
}