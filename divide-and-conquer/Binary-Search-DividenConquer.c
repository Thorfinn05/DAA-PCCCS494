#include<stdio.h>

//Recursive function of Binary Search
int binarySearch(int arr[], int low, int high, int target){
    if (low <= high){
        int mid = low + (high - low) / 2;  //Finding the middle index of array

        if (arr[mid] == target)
            return mid;  //Target found at middle index
        else if (arr[mid] < target)
            return binarySearch(arr, mid+1, high, target);  //Searching in the right half of array as target is greater than element at middle index
        else
            return binarySearch(arr, low, mid-1, target);  //Searching in the left half of array as target is smaller than element at middle index
    }
    return -1;
}

//Bubble Sort Function
void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){  //Swapping elements if they are not in correct order
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, target;

    printf("Enter population: ");  //Denoting the size 
    scanf("%d", &n);

    int arr[n];  //Declaring an array of size n
    printf("Enter elements in array: ");  //Taking user inputs for array elements
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array: ");  //Printing the given array
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);  //Sorting the array before Binary Search

    printf("Sorted Array: ");  //Printing the sorted array
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter element to search: ");  //Taking user input to search
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n-1, target); //Performing Binary Search

    //Displaying the result
    if (result != -1)  
        printf("Element %d found at index %d.\n", target, result);  
    else
        printf("Element %d not found in the array.\n", target);

    return 0;

}