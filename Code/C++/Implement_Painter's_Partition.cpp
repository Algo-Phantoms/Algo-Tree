#include <climits>   // This header difines constants with the limits of fundamenntal integral type for the specific system and compiler implementation used. 
#include <iostream>
using namespace std;

int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}


int partition(int arr[], int n, int k)
{

	if (k == 1)
		return su
		return arr[0];

	int best = INT_MAX;
	for (int i = 1; i <= n; i++)
		best = min(best, max(partition(arr, i, k - 1),
								sum(arr, i, n - 1)));

	return best;
}

int main()
{
	int size;
        cin>>size;
         int arr[size];
        for(int i=0;i<size;i++)
          cin>>arr[i];
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << partition(arr, n, k) << endl;

	return 0;
}

// Input: size=4, k=2 , A={10, 10, 10, 10}
// Output: 20

// Input: size= 4, k = 2, A = {10, 20, 30, 40}
// Output: 60

// Time Complexity: O(N*log(sum(arr[])))
