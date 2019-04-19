/******************************************************************************
    Author: Yorgo A. Kennos
    Date: Friday April 19, 2019
    Purpose: Selection sort algorith repeatedly find the min element and places it
      at the start of the list. Using two for loops the "start" of the list is 
      incremented after every min element is found. 
      
      Worst Case: O(n^2)
      Avg Case:   O(n^2)

*******************************************************************************/

#include <stdio.h>

void swap(int* x, int* y);
void selectionSort(int arr[], int n);


int main(int argc, char* argv[]){
    int size = 15;
    
    int arr[15] = {5, 1, 4, 2, 8, 12, 1, 6, 0, 43, 13, 24, 8, 12, 30};
    printf("Array Before Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    selectionSort(arr, size);
    
    printf("\n\nArray After Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
        
    return 0;
}

void selectionSort(int arr[], int n){
    int minIndex;
    
    for(int i = 0; i < n - 1; i++){
        minIndex = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        //swap the found min w/ first element
        //then increment "start of array"
        swap(&arr[minIndex], &arr[i]);
    }
}



void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
