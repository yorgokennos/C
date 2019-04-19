/******************************************************************************
Author: Yorgo A. Kennos
Date: Friday, April 19 2019
Purpose: Implementation of one of the easiest sorting algorithms. It works by
  repeatedly swapping adjacent elements pushing the largest elements at the
  back of the list (array implementation). 
  
  Best Case: List is in order O(n)
  Worst Case: O(n^2)

*******************************************************************************/

#include <stdio.h>

void bubble_sort(int arr[], int size);
void swap(int* x, int* y);

int main(int argc, char* argv[]){
    int size = 15;
    
    int arr[15] = {5, 1, 4, 2, 8, 12, 1, 6, 0, 43, 13, 24, 8, 12, 30};
    printf("Array Before Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    bubble_sort(arr, size);
    
    printf("Array After Sort\n");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
        
    return 0;
}

void bubble_sort(int arr[], int size){
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
            
        }
    }
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
