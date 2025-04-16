#include <stdio.h>
#define MAX 100

int max(int a, int b){
    return a > b ? a : b;
}

int findMax(int arr[], int lb, int ub) {
    if(lb != ub) {
        int mid = (lb + ub) / 2;
        int leftMax = findMax(arr, lb, mid);
        int rightMax = findMax(arr, mid + 1, ub);
        return max(leftMax, rightMax);
    }
    return arr[ub];
}

int knapsack(int profit[], int deadlines[], int n) {
    float ratio[MAX];
    float t1;
    int t2, t3;

    for(int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / deadlines[i];
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(ratio[j + 1] > ratio[j]) {
                
                t1 = ratio[j + 1];
                ratio[j + 1] = ratio[j];
                ratio[j] = t1;

               
                t2 = profit[j + 1];
                profit[j + 1] = profit[j];
                profit[j] = t2;

                
                t3 = deadlines[j + 1];
                deadlines[j + 1] = deadlines[j];
                deadlines[j] = t3;
            }
        }
    }

    int max_dl = findMax(deadlines, 0, n - 1);
    int slot[MAX] = {0};  
    int total = 0;

    for(int i = 0; i < n; i++) {
        for(int j = deadlines[i] - 1; j >= 0; j--) {
            if(slot[j] == 0) {  
                slot[j] = 1;   
                total += profit[i];
                break;
            }
        }
    }

    return total;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int deadlines[MAX], profit[MAX];
    printf("Enter deadlines: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &deadlines[i]);
    }

    printf("Enter profit: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("\nTotal profit: %d", knapsack(profit, deadlines, n));
    return 0;
}