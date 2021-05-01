// C++ program to merge k sorted arrays of size n each.

#include<bits/stdc++.h>
using namespace std;
#define n 4

// Merge arr1[0..n1-1] and arr2[0..n2-1] into
// arr3[0..n1+n2-1]
void mergeArrays(int arr1[], int arr2[], int n1,
							int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i<n1 && j <n2)
	{
		// Check if current element of first
		// array is smaller than current element
		// of second array. If yes, store first
		// array element and increment first array
		// index. Otherwise do same with second array
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	// Store remaining elements of first array
	while (i < n1)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < n2)
		arr3[k++] = arr2[j++];
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n],int i,int j, int output[])
{
	//if one array is in range
	if(i==j)
	{
		for(int p=0; p < n; p++)
		output[p]=arr[i][p];
		return;
	}
	
	//if only two arrays are left them merge them
	if(j-i==1)
	{
		mergeArrays(arr[i],arr[j],n,n,output);
		return;
	}
	
	//output arrays
	int out1[n*(((i+j)/2)-i+1)],out2[n*(j-((i+j)/2))];
	
	//divide the array into halves
	mergeKArrays(arr,i,(i+j)/2,out1);
	mergeKArrays(arr,(i+j)/2+1,j,out2);
	
	//merge the output array
	mergeArrays(out1,out2,n*(((i+j)/2)-i+1),n*(j-((i+j)/2)),output);
	
}


// MAIN CODE STARTS HERE...

int main()
{
	// Change n at the top to change number of elements
	// in an array
	int arr[][n] = {{66, 99, 110, 800},
					{1, 6, 70, 100},
					{2, 4, 9, 200}};
	int k = sizeof(arr)/sizeof(arr[0]);
	int output[n*k];
	mergeKArrays(arr,0,2, output);

	cout << "Merged array -->" << endl;
	printArray(output, n*k);

	return 0;
}
/*	
	1-->
    INPUT--{{6, 9, 11, 800},
			{1, 5, 10, 1000},
			{2, 4, 99, 200}}

    OUTPUT--- 
    Merged array -->
    1 2 4 5 6 9 10 11 99 200 800 1000 
   
	2-->
	INPUT-- {{3, 7, 11, 80},
			{12, 90, 100, 1000},
			{23, 34, 99, 209}}


	OUTPUT---
	Merged array -->
	3 7 11 12 23 34 80 90 99 100 209 1000 
    
	3-->
	INPUT-- {{66, 99, 110, 800},
			{1, 6, 70, 100},
     		{2, 4, 9, 200}}


	OUTPUT---
	Merged array -->
	1 2 4 6 9 66 70 99 100 110 200 800

	*/


// Time Complexity: O( n * k * log k). 
// There are log k levels as in each level the k arrays are divided in half and at each level the k arrays are traversed. 
// So time Complexity is O( n * k ).
// Space Complexity: O( n * k * log k). 
// In each level O( n*k ) space is required So Space Complexity is O( n * k * log k).