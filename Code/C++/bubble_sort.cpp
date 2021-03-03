/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if
 * they are in wrong order.
 * Idea: if arr[i] > arr[i+1] swap them. To place the element in their respective
position, we have to do the following operation N-1 times.*/

#include<iostream>
using namespace std;

void bubbleSort(int array[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int swap=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0) break;
    }
}

void Print(int array[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    Print(arr,n);
}

/*
Test Case

Input:
4
6 3 9 1
Output:
1 3 6 9
Time Complexity:
Worst and Average time complexity: O(n^2)
Best case time complexity: O(n)
Auxiliary space: O(1)*/
