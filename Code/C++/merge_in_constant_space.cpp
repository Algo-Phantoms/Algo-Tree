/*
    Merging of two sorted arrays can be done in constant space by following steps:
    (i) iterate first array from last and second array from start
    (ii)if element in first array is greater than the second array then swap those elements
    (iii)decrement iterator of first and increment iterator of second
    (iv)sort both the arrays
    (v)resulting two arrays will be combined for the sorted output																								
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int n,int m)
{
	//iterating the first array from last and second array from first element 
	for(int i=n-1,j=0;i>=0 && j<m && arr1[i]>arr2[j];i--,j++)         //--------O(n+m)
	{
		//swap those elements of second array from first array which are less than the element of first array 
		int temp=arr1[i];
		arr1[i]=arr2[j];
		arr2[j]=temp;
	}
	// sort the respective arrays and combined array will be our result
	sort(arr1,arr1+n);                                                //---------O(nlogn)
	sort(arr2,arr2+m);                                                //---------O(mlogm)
}

int main()
{
	int n,m;
	cin>>n>>m;
	int arr1[n],arr2[m];
	//taking input for first array	
	for(int i=0;i<n;i++)       
	    cin>>arr1[i];
	//taking input for first array	
	for(int i=0;i<m;i++)
	    cin>>arr2[i];  
	//call merge operation   
	merge(arr1,arr2,n,m);

	//printing sorted array
	for(int i=0;i<n;i++)
	    cout<<arr1[i]<<" ";
	for(int i=0;i<m;i++)
	    cout<<arr2[i]<<" ";
	return 0;	   
}

/*Test cases
User input 1:
5 6
2 6 8 10 12
1 3 6 9 10 15
output: 1 2 3 6 6 8 9 10 10 12 15
User input 2:
9 6
17 19 20 22 28 30 31 33 34
1 3 6 9 10 15
output: 1 3 6 9 10 15 17 19 20 22 28 30 31 33 34
*/

/*Time Complexity
Time Complexity of merge(): 
T(n+m)=O(n+m)+O(nlogn)+O(mlogm)=O(nlogn)
So ,Time Complexity of algorithm will be
T(n+m)=O((n+m)log(n+m))

Space Complexity=O(1)
*/
