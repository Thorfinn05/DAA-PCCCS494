#include<stdio.h>
int MaxMin(int arr[], int low, int high, int *max, int *min){
    int max1, min1;
    if(low == high){
        *max = *min = arr[low];
    }
    else if(low == high-1){
        if(arr[low]<arr[high]){
            *max = arr[high];
            *min = arr[low];
        }
        else{
            *max = arr[low];
            *min = arr[high];
        }
    }
    else{
        int mid = (low+high)/2;
        MaxMin(arr, low, mid, max, min);
        MaxMin(arr, mid+1, high, &max1, &min1);
        if(*max<max1)
            *max = max1;
        if(*min>min1)
            *min = min1;
    }
}
int main(){
    int arr[100];
    int n, max, min;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    MaxMin(arr, 0, n-1, &max, &min);
    printf("Max: %d\nMin: %d", max, min);
    return 0;
}