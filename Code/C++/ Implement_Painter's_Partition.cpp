#include <climits>
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
	int arr[] = { 10, 10, 10, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << partition(arr, n, k) << endl;

	return 0;
}

// Input:  k=2 , A={10, 10, 10, 10}
// Output: 20