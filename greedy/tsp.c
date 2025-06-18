#include<stdio.h>
#define MAX 100
#define INF 1000000

int tspGreedy(int cities[MAX][MAX], int visited[], int v, int start){
    int total = 0, current = start;
    visited[start] =  1;

    printf("Minimum Tour: \n");
    printf("%d", start);
    
    for (int i=1; i<v; i++){
        int min = INF;
        int nextCity = -1;
        for(int j=0; j<v; j++){
            if(!visited[j] && cities[current][j] && cities[current][j] < min){
                min = cities[current][j];
                nextCity = j;
            }
        }
        if(nextCity != -1){
            visited[nextCity] = 1;
            total += min;
            printf("-> %d ", nextCity);
            current = nextCity;
        }
    }
    total += cities[current][start];
    printf("-> %d \n", start);
    return total;
}

int main(){
    int cities[MAX][MAX];
    int v, start;
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter adjacencyn matrix: ");
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            scanf("%d", &cities[i][j]);
        }
    }

    printf("Enter starting point: ");
    scanf("%d", &start);
    int tour = tspGreedy(cities, visited, v, start);

    printf("Total Tour Cost: %d", tour);
    return 0;
}