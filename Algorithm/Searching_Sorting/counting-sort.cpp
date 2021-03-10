#include <iostream>
using namespace std;
//Counting sort is linear time algorithm for the cases whenever input element are in a small range
//Time Complexity: Theta(n+k) & Auxiliary Space: Theta(n+k), to sort n element in range from 0 to k-1 range

//Naive Implementation
void countingSort(int arr[], int n, int k)
{
    int count[k];
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[index] = i;
            index++;
        }
    }
}

//General Purpose Implementation
void countSort(int arr[], int n, int k)
{
    int count[k];
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < k; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main(void)
{
    int arr[] = {1, 4, 4, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 5; //range of the number

    // countingSort(arr, n, k);
    countSort(arr, n, k);

    //Printing Array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
// Code By: Avinash Kumar.
