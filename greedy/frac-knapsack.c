#include<stdio.h>
#define MAX 10

float knapsack(int prof[], int wt[], int W, int n){
    float ratio[MAX];
    int t2, t3;
    float t1;

    for(int i=0; i<n; i++){
        ratio[i] = (prof[i] / wt[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(ratio[j+1] > ratio[j]){
                t1 = ratio[j+1];
                ratio[j+1] = ratio[j];
                ratio[j] = t1;

                t2 = prof[j+1];
                prof[j+1] = prof[j];
                prof[j] = t2;

                t3 = wt[j+1];
                wt[j+1] = wt[j];
                wt[j] = t3;
            }
        }
    }

    int w = 0;
    float total = 0.0;

    for(int i=0; i<n; i++){
        if(w<W){
            if(w + wt[i] < W){
                w += wt[i];
                total += prof[i];
            }
            else{
                total += ((prof[i] / (float)wt[i]) * (W - w));
                w = W;
                break;
            }
        }
    }
    return total;
}

int main(){
    int n, W;
    int prof[MAX], wt[MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter profits: ");
    for(int i=0; i<n; i++){
        scanf("%d", &prof[i]);
    }

    printf("Enter weights: ");
    for(int i=0; i<n; i++){
        scanf("%d", &wt[i]);
    }

    printf("Enter total weight: ");
    scanf("%d", &W);

    printf("Total Cost: %.2f", knapsack(prof, wt, W, n));

    return 0;
}