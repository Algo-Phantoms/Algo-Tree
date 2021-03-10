/*
Selection sort is an algorithm that selects the smallest element from an unsorted list in each iteration 
and places that element at the beginning of the unsorted list.

    * Strategy:
        find the smallest number in the array and exchange it with the value in first position of array.
        Now, find the second smallest element in the remainder of array and exchange it with a value in the second position,
        carry on till you have reached the end of array. Now all the elements have been sorted in ascending order.
*/



#include<bits/stdc++.h>
using namespace std;

int main()
{

    
    int n,i,j,k;
	cin>>n;
	int a[n];


    for(i=0;i<n;i++){
    	cin>>a[i];
    }


    // move boundary of unsorted subarray one by one

    for(i=0;i<n-1;i++){

        // Find the minimum element in unsorted array

        for(j=k=i;j<n;j++){

            if(a[j]<a[k])
                k=j;
        }

        // Swap the minimum element with the ith element of array

        swap(a[i],a[k]);
    }


    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;


    return 0;
}



/*
    Test case 1: 
    Input : 7
    3 5 4 1 2 7 6

    Output : 
    1 2 3 4 5 6 7



    Test case 2: 
    Input : 5
    50 20 40 10 30

    Output:
    10 20 30 40 50


    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/


