/*
	QuickSort is a Non-Comparative sorting algorithm.The comparisons are made among the digits of the number from LSB to MSB. 
    The number of passes depend upon the length of the number with the most number of digits.
	 
*/


#include <iostream>
#include <cmath>

using namespace std;
// code base 
int getMax(int arr[], int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
 // radix sort called 
void CountingSort(int arr[], int size, int div) 
{ 
    int output[size]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < size; i++) 
        count[ (arr[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = size - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/div)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/div)%10 ]--; 
    } 
  
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 
  
 
void RadixSort(int arr[], int size) 
{ 
    int m = getMax(arr, size); 
    // get max from array
    for (int div = 1; m/div > 0; div *= 10) 
    //do counting sort of every digit
        CountingSort(arr, size, div); 
} 
  
 
int main() 
{ 
 int size;
 cout<<"Enter the size of the array: "<<endl;
 cin>>size;
 int arr[size];
 cout<<"Enter "<<size<<" integers in any order"<<endl;
 for(int i=0;i<size;i++)
 {
 cin>>arr[i];
 }
   cout<<endl<<"Before Sorting: "<<endl;
   for(int i=0;i<size;i++)
 {
 cout<<arr[i]<<" ";
 }
 
 RadixSort(arr, size); 
   
 cout<<endl<<"After Sorting: "<<endl;
   for(int i=0;i<size;i++)
 {
 cout<<arr[i]<<" ";
 } 
    
    return 0; 
}

/* 
    Test Case : 

    Input :	10
    		237, 146, 259, 348, 152, 163, 235, 48, 36, 62

    Output : 	36, 48, 62, 146, 152, 163, 235, 237, 259, 348

    Time Complexity: The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases:
    Best Case	: O(nk)
    Average Case: θ(nk)	
    Worst Case	: Ω(n+k)	

    Space Complexity: O(n+k)
*/