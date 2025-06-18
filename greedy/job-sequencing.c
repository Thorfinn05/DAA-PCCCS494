#include<stdio.h>
#define MAX 100

int max(int a, int b){
    return (a > b) ? a : b;
}

int findMax(int arr[], int lb, int ub){
    if(lb != ub){
        int mid = (lb+ub)/2;
        int leftmax = findMax(arr, lb, mid);
        int rightmax = findMax(arr, mid+1, ub);
        return max(leftmax, rightmax);
    }
    return arr[ub];
}

int knapsack(int prof[], int dl[], int n){
    int ratio[MAX];
    int t2, t3; float t1;

    for(int i=0; i<n; i++){
        ratio[i] = ((float)prof[i] / dl[i]);
    }
    
    int total = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(ratio[j+1] > ratio[j]){
                t1 = ratio[j+1];
                ratio[j+1] = ratio[j];
                ratio[j] = t1;

                t2 = prof[j+1];
                prof[j+1] = prof[j];
                prof[j] = t2;

                t3 = dl[j+1];
                dl[j+1] = dl[j];
                dl[j] = t3;
            }
        }
    }
    int max_dl = findMax(dl, 0, n-1);
    int slots[MAX];

    for(int i=0; i<=max_dl; i++){
        slots[i] = -1;
    }

    for(int i=0; i<n; i++){
        for(int j=dl[i]; j>0; j--){
            if(slots[j] == -1){
                slots[j] = i;
                total += prof[i];
                break;
            }
        }
    }
    return total;
}

int main(){
    int n, W;
    int prof[MAX], dl[MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter profits: ");
    for(int i=0; i<n; i++){
        scanf("%d", &prof[i]);
    }

    printf("Enter deadlines: ");
    for(int i=0; i<n; i++){
        scanf("%d", &dl[i]);
    }

    printf("Total Cost: %d", knapsack(prof, dl, n));

    return 0;
}