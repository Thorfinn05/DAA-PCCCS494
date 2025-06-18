#include<stdio.h>

//Partion the array and place pivot at correct position
int partition(int arr[], int left, int right){
    int pivot = arr[right];  //Denoting the last element as pivot
    int i = left - 1;  //Pointer for smaller element

    for (int j = left; j < right; j++){
        if (arr[j] < pivot){
            i++;
            //Swapping arr[i] and arr[j] if arr[j] is smaller than pivot
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
        }
    }

    //Placing the pivot at its correct position
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i+1;  //Returning index of pivot
}

//Recursive Quick Sort Function
void quickSort(int arr[], int left, int right){
    if(left < right){
        int piv = partition(arr, left, right);  //Finding pivot position

        //Recursively sorting elements before and after the pivot
        quickSort(arr, left, piv -1);
        quickSort(arr, piv + 1, right);
    }
}

//Function to print array
void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n, arr[100];
    printf("Enter population: ");  //Denoting the size
    scanf("%d",&n);

    // int arr[n];  //Declaring an array of size n
    printf("Enter elements in array: ");  //Taking user inputs for array element
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Given Array: ");  //Printing the given array
    printArray(arr, n);

    quickSort(arr, 0, n-1);  //Perforimg quick sort
    
    printf("Sorted Array: ");  //Printing the sorted array
    printArray(arr, n);

    return 0;
}