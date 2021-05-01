/* C++ program to implement Three Way Merge Sort
 Three Way Merge Sort is a variant of merge sort, where an array is recursively split into three subarrays.
 And sort function is called on these three subarrays. The base case of the recursion occurs when size of 
 the array is one, if that occur Return. Finally Merge the subarrays so as to get the resultant sorted array.
*/

#include <bits/stdc++.h>
using namespace std;


// Merge the three sections in ascending order
void merge(int arr[], int start, int midA, int midB, int end, int temp[])  
{  
    int i, j, k, l;
    i = start;
    j = midA; 
    k = midB; 
    l = start;  
  
    // Find the smallest element among the three sections 
    while ((i < midA) && (j < midB) && (k < end))  
    {  
        if(arr[i] < arr[j]) 
        { 
            if(arr[i] < arr[k]) 
            { 
                temp[l++] = arr[i++]; 
            } 
            else
            { 
                temp[l++] = arr[k++]; 
            } 
        } 
        else
        { 
            if(arr[j] < arr[k]) 
            { 
                temp[l++] = arr[j++]; 
            } 
            else
            { 
                temp[l++] = arr[k++]; 
            } 
        } 
    }  
  
    /*
    Now any two arrays would have remaining values that are yet to be merged,
    We have to identify those two arrays and merge the elements.  
    */
 
    while ((i < midA) && (j < midB))  
    {  
        if(arr[i] < arr[j]) 
        { 
            temp[l++] = arr[i++]; 
        } 
        else
        { 
            temp[l++] = arr[j++]; 
        } 
    }  
  
   
    while ((j < midB) && (k < end))  
    {  
        if(arr[j] < arr[k]) 
        { 
            temp[l++] = arr[j++]; 
        } 
        else
        { 
            temp[l++] = arr[k++]; 
        }  
    }  
  
    while ((i < midA) && (k < end))  
    {  
        if(arr[i] < arr[k]) 
        { 
            temp[l++] = arr[i++]; 
        } 
        else
        { 
            temp[l++] = arr[k++]; 
        }  
    }  
  
  /*
    Now a single array would have remaining values that are yet to be merged,
    We have identify that array and copy its remaining elements.  
  */
    
    while (i < midA)  
        temp[l++] = arr[i++];  
  
    while (j < midB)  
        temp[l++] = arr[j++];  
        
    while (k < end)  
        temp[l++] = arr[k++];  
}  



void three_way_merge_sort(int arr[], int start, int end, int temp[])  
{  
    //If the array contains only a single element, then return  
    if (end - start < 2)  
        return;  
  
    // Split the array into three parts
    int midA = start + ((end - start) / 3);  
    int midB = start + 2 * ((end - start) / 3) + 1;  
    
    three_way_merge_sort(temp, start, midA, arr);  
    three_way_merge_sort(temp, midA, midB, arr);  
    three_way_merge_sort(temp, midB, end, arr);  
  
    // Merge the sorted arrays  
    merge(temp, start, midA, midB, end, arr);  
}

int main()
{
    int n;
    cout<<"\nHow many numbers do you want to sort? ";
    cin>>n;
    int arr[n];

    if (n <= 0)
    {
        cout<<"There are no numbers to sort!!!";
        return 0;
    }
    // Input the numbers to sort
    cout<<"Enter the numbers: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    // creating a temporary array 
    int temp[n];  
  
    // Copy the elements of the temporary elements into the new array  
    for (int i = 0; i < n; i++)  
        temp[i] = arr[i];  
  
    //Call the sort function 
    three_way_merge_sort(temp, 0, n, arr);  

    cout<<"The numbers in sorted order is: ";
    // Print the sorted array
    for (int i = 0; i < n; i++)
        cout<<temp[i]<<" ";
    cout<<endl;

    return 0;
}

/*
Test Cases

1.
 Input - 
     How many numbers do you want to sort? 5
     Enter the numbers: 5 4 3 2 1 
 Output - 
     The numbers in sorted order is:  1  2  3  4  5

2.

 Input - 
     How many numbers do you want to sort? 0
 Output - 
     There are no numbers to sort!!!

Time Complexity: O(n*logn), where 'n' is the length of the array.
Space Complexity: O(n)
*/
