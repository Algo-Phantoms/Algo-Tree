// C++ implementation to top k frequent elements in an array
/*
The main idea is to use unordered map as hash table to store frequencies of elements and then use frequencies as indexes and put elements with given frequency in an array

*/
#include <bits/stdc++.h>
using namespace std;

// function to print top k frequent elements in case of tie we will be printing the element which appeared first
void Top_K_Frequent_Elements(int arr[], int n, int k)
{
	// unordered_map 'um' implemented as frequency
	// hash table
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++)
		um[arr[i]]++;

	// Use frequencies as indexes and put
	// elements with given frequency in a
	// vector (related to a frequency) by traversing the input array

	vector<int> freq[n + 1];
	for (int i = 0; i < n; i++) {
		int f = um[arr[i]];
		if (f != -1) {
			freq[f].push_back(arr[i]);
			um[arr[i]] = -1;
		}
	}

	// Initialize count of items printed
	int c = 0;

	// Traverse the frequency array from
	// right side as we need the most
	// frequent items.
	for (int i = n; i >= 0; i--) {

		// Print items of current frequency
		for (int x : freq[i]) {
			cout << x << " ";
			c++;
			if (c == k)
				return;
		}
	}
}

// Driver program to test above
int main()
{
  int n;
  cout<<"enter number of elements in array"<<endl;
  cin>>n;
	int arr[n];
  cout<<"enter the array"<<endl;
for(int i=0;i<n;i++)cin>>arr[i];
cout<<"Enter the value of k"<<endl;
	int k ;
  cin>>k;
	Top_K_Frequent_Elements(arr, n, k);
	return 0;
}
/*
Example:
Input:arr=[ 3, 1, 4, 4, 5, 2, 6, 1]
k=3
Decreasing order of elements based on frequencies of elements will be
[1,4,3,5,2,6]
as 1 freq-2
   4 freq-2
   3 freq-1
   5 freq-1
   2 freq-1
   6 freq-1
Output: 1 4 3

Time Complexity: O(n) as we traversed the entire array
Auxiliary Space: O(n) as we used vector and unordered map
*/
