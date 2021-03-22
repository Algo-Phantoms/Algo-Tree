/* Quick sort is the algorithm which is used to sort the elements in increasing or decreasing order 
by picking pivot element and partitions the given array
we can choose the pivot element from the array which we want to

The main purpose of the quick sort i.e. partition is to put the pivot element at its correct position
*/

#include<stdio.h>
#include<conio.h>

void quickSort(int array[] , int low, int high) ; 
int partition(int array[] , int low, int high) ;
void swap(int *a, int *b) ;
void printArray(int array[] , int size) ;

int main(){
    int data[] = {8,7,2,1,0,9,6} ; // Sorting The elements in the increasing order by Qsort 
    int n = sizeof(data) / sizeof(data[0]) ;
    quickSort(data, 0, n - 1) ;
    printf("Sorted array in ascending order : \n ") ;
    printArray(data, n) ;
}
// We have to make partition each time in the array
int partition(int array[] , int low, int high){
    int pivot = array[0] ;
    int start = low ;
    int end = high ;
    while(start < end){
        while(array[start] <= pivot){
            start++ ;
        }
        while(array[end] > pivot){
            end-- ;
        }
        if(start < end){
            swap(&array[start] , &array[end]) ;
        }
    }
    swap(&array[low], &array[end]) ;
    return end ;
}
void quickSort(int array[] , int low, int high){
    if(low < high){
        int location = partition(array, low, high) ;
        quickSort(array, low, location-1) ;
        quickSort(array, location+1, high) ;
    }
}
void swap(int *a, int *b){
    int t = *a ;
    *a = *b ;
    *b = t ;
}
void printArray(int array[] , int size){
    for(int i = 0; i < size; i++){
        printf("%d " , array[i]) ;
    }
    printf("\n") ;
}

/*
Test Case :
array = {8,7,2,1,0,9,6} ;

o/p : {0,1,2,6,7,8,9}

Time Taken by Quick Sort to complete :
BestCase : Theta(nlogn)
Worst Case :  theta(n^2)

*/
