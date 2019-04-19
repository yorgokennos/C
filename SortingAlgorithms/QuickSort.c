/******************************************************************************
  Author: Yorgo A. Kennos
  Date: Friday April 19, 2019
  Purpose: Implementation of QuickSort, a divide and conquer algorithm. It picks
    an element as the pivot and partitions the array around the pivot. This  
    implementation picks the last element as the pivot, although we could pick
    the first, median or even a random element.
    
    Best Case: O(n^2) // when largest element is picked 
    Worse Case: O(n log n)

*******************************************************************************/

#include <stdio.h>

void swap(int* x, int* y);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main(int argc, char* argv[]){
    int size = 15;
    
    int arr[15] = {5, 1, 4, 2, 8, 12, 1, 6, 0, 43, 13, 24, 8, 12, 30};
    printf("Array Before Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    quickSort(arr, 0, size - 1);
    
    printf("Array After Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
        
    return 0;
}
/*
    Essentially this function takes the last element of the 
    list as the pivot (could also be implemented using first,
    median, or random pivot). Then places the pivot element
    at its correct position in the sorted list, and places 
    the smaller element to the left of the pivot and all the
    greater elements to the right of the pivot
*/
int partition(int arr[], int low, int high){
    int pivot = arr[high]; //pivot
    int j = (low - 1); //index of smaller element
    
    for(int i = low; i <= high - 1; i++){
        //if current element is <= pivot
        if(arr[i] <= pivot){
            j++; //increment index of smaller element
            swap(&arr[j], &arr[i]);
        }
    }
    
    swap(&arr[j + 1], &arr[high]);
    return (j + 1);
}

/*
  low is the starting index.
  high is the ending index.
*/

void quickSort(int arr[], int low, int high){
    if(low < high){
        //p is partitioning index
        int p = partition(arr, low, high);
        
        //Separately sort element before and after 
        //partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
    
    
    
}


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
