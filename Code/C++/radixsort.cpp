
// C++ implementation of Radix Sort
#include<iostream>
using namespace std;


int getMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void CountingSort(int arr[], int size, int div)
{
	int output[size];
	int count[10] = {0};

	for (int i = 0; i < size; i++)
		count[ (arr[i] / div) % 10 ]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[ (arr[i] / div) % 10 ] - 1] = arr[i];
		count[ (arr[i] / div) % 10 ]--;
	}

	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}


void RadixSort(int arr[], int size)
{
	int m = getMax(arr, size);
	for (int div = 1; m / div > 0; div *= 10)
		CountingSort(arr, size, div);
}


int main()
{

	int size;
	cin >> size;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	RadixSort(arr, size);


	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

/*Radix sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix
Time complexity: O(d(n+k))
Space complexity: O(n+k)



Eg: size = 8 ;
    arr[8] = 11 9 7 5 4 3 2 1

    O/P : 1 2 3 4 5 7 9 11


  	size =  5
	arr[5] =5 4 3 2 1

	O/P : 1 2 3 4 5

    size =  10
    arr[10] =3 3 4 2 4 4 4 2 4 4

    O/P : 2 2 3 3 4 4 4 4 4 4

*/