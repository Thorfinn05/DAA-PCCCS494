#include<stdio.h>
#define MAX 16
#define INF 1000000

int n;
int dist[MAX][MAX];
int dp[MAX][1 << MAX];

int tsp(int pos, int mask){
    if(mask == (1 << n)-1){
        return dist[pos][0];
    }
    if(dp[pos][mask] != -1){
        return dp[pos][mask];
    }
    int ans = INF;
    for(int city=0; city<n; city++){
        if(mask & (1 << city) == 0){
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
            if(newAns < ans){
                ans = newAns;
            }
        }
    }
    return dp[pos][mask] = ans;
}

void initializeDP(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<(1<<MAX); j++){
            dp[i][j] = -1;
        }
    }
}

int main(){
    printf("Enter vertices number: ");
    scanf("%d", &n);

    printf("Adjacency matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j,n; j++){
            scanf("%d", dist[i][j]);
        }
    }
    initializeDP();
    int result = tsp(0,1);
    printf("min cost to visit all cities: %d", result);

    return 0;
}