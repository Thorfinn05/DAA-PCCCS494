#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int minChainMatrix(int arr[], int i, int j) {
    if (i == j) {
        return 0;
    }
    int minimum = 1000000;
    for (int k = i; k < j; k++) {
        int cost = minChainMatrix(arr, i, k) + minChainMatrix(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (cost < minimum) {
            minimum = cost;
        }
    }
    return minimum;
}
int main() {
    int arr[MAX]; 
    int n; 
    printf("Enter n: ");
    scanf("%d", &n);  
    printf("Enter dimensions array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int mcm = minChainMatrix(arr, 1, n - 1);
    printf("Minimum number of scalar multiplications is %d\n", mcm);  
    return 0;
}