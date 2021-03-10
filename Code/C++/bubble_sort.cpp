/*
    Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. 
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //  Size of array
    int n;
    cin>>n;

    //  Input of array element
    int array[n];
    for(int i=0;i<n;i++) cin>>array[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(array[j]>array[j+1])
            {
                //  If number is bigger than next comming number then we swap those numbers. 
                swap(array[j],array[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
}
/*
        Test case :

        Input :
         5
         25 16 47 3 91
        Output :
         3 16 25 47 91
        
        Worst Case Time Complexity: O(n2)
        Best Case Time Complexity: O(n) 
        Average Time Complexity: O(n2)
        Space Complexity: O(1)

*/
