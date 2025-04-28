#include<stdio.h>
#define MAX 100

void knapsack(int wt[], int b[], int n, int W){
    int sol[MAX][MAX];
    int i, w;

    for(w=0; w<=W; w++){
        sol[0][w] = 0;
    }

    for(i=0; i<=n; i++){
        sol[i][0] = 0;
    }

    for(i=1; i<=n; i++){
        for(w=1; w<=W; w++){
            if(wt[i-1]<=w){
                if(b[i-1]+sol[i-1][w-wt[i-1]] >= sol[i-1][w]){
                    sol[i][w] = b[i-1]+sol[i-1][w-wt[i-1]];
                }
                else
                    sol[i][w] = sol[i-1][w];
            }
            else
            sol[i][w] = sol[i-1][w];
        }
    }

    printf("MAximum benefit: %d\n", sol[n][W]);
}

int main(){
    int n, W;
    printf("Enter n: ");
    scanf("%d", &n);
    int wt[MAX], b[MAX];

    printf("Enter weights: ");
    for(int i=0; i<n; i++){
        scanf("%d", &wt[i]);
    }

    printf("ENter profits: ");
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(wt, b, n, W);

    return 0;
}