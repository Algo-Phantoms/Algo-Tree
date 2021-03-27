/*
    Merging of two sorted arrays can be done in constant space by following steps
    (i) iterate first array from last and second array from start
    (ii)if element in first array is greater than the second array then swap those elements
    (iii)decrement iterator of first and increment iterator of second
    (iv)sort both the arrays
    (v)resulting two arrays will be combined sorted
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int n,int m)
{
	for(int i=n-1,j=0;i>=0 && j<m && arr1[i]>arr2[j];i--,j++)
	{
		int temp=arr1[i];
		arr1[i]=arr2[j];
		arr2[j]=temp;
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
}

int main()
{
	int n,m;
	cin>>n>>m;
	int arr1[n],arr2[m];	
	for(int i=0;i<n;i++)
	    cin>>arr1[i];
	for(int i=0;i<m;i++)
	    cin>>arr2[i];    
	merge(arr1,arr2,n,m);
	for(int i=0;i<n;i++)
	    cout<<arr1[i]<<" ";
	for(int i=0;i<m;i++)
	    cout<<arr2[i]<<" ";
	return 0;	   
}

/*Test cases
User input:
5 6
2 6 8 10 12
1 3 6 9 10 15
output: 1 2 3 6 6 8 9 10 10 12 15
*/

/*Time Complexity
The merge() takes total nlogn and mlogm to sort the arrays.
So T(n)=O(nlogn), assuming n>m

Space Complexity=O(1)
*/