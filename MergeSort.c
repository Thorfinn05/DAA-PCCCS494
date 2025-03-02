#include<stdio.h>

//Merging two sorted subarrays into single array
void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1= mid - left+1;  //Size of left subarray
    int n2 = right - mid;  //Size of right subarray

    int L[n1], R[n2];  //Temporary arrays

    //Copy data into left and right subarrays
    for (i=0; i<n1; i++)
        L[i] = arr[left + i];
    for (j=0; j<n2; j++)
        R[j] = arr[mid + 1 + j];

    //Merging the two sorted subarrays into single main array
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else    
            arr[k++] = R[j++];
    }

    //Copying remaining elements of left and right subarrays
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}


//Recursive Merge Sort funtion
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;  //Finding the middle

        //Recursively sorting left and right halves
        mergeSort(arr, left, mid);  
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);  //Merging the sorted halves
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
    int n;
    printf("Enter population: ");  //Denoting the size
    scanf("%d",&n);

    int arr[n];  //Declaring an array of size n
    printf("Enter elements in array: ");  //Taking user inputs for array element
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Given Array: ");  //Printing the given array
    printArray(arr, n);

    mergeSort(arr, 0, n-1);  //Perforimg merge sort
    
    printf("Sorted Array: ");  //Printing the sorted array
    printArray(arr, n);

    return 0;
}