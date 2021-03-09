/*
    Radix Sort is a non-comparison based sorting algorithm. This sorting algorithm
    is preferable than counting sort, when we have numbers in large range (like 1 to n^2).

    Radix Sort uses counting sort as a sub-routine.The idea of Radix Sort is to do digit 
    by digit sort starting from least significant digit to most significant digit.

    Alogithm:
        1. find largest number in range.
        2. loop till the number of digits in largest number.
           And in each loop , sort the given numbers from least significant digit
           to most significant digit.
*/

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void counting_sort(vector<int> &arr, int size, int exp)
{
    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; i++)
    {
        // for digits in elements of array(from right side)
        count[(arr[i] / exp) % 10]++; 
    }

    // calculating cumulative sum
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // sorting a/c to each digits of elements in array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // storing back in original array the sorted array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int> &arr, int size)
{
    // maximum element of the array
    int max = *max_element(arr.begin(), arr.end()); 

    // looping for number of digits in the max
    for (int exp = 1; (max / exp) > 0; exp *= 10) 
    {
        counting_sort(arr, size, exp);
    }
}

int main()
{
    int size;
    cout << "\nenter size of array(or count of total numbers) : ";
    cin >> size;

    vector<int> arr(size);
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cout << i + 1 << "). ";
        cin >> temp;
        arr[i] = temp;
    }

    int size1 = 0;
    vector<int> neg_arr;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg_arr.push_back(abs(arr[i]));
            size1++;
            arr[i] = 0;
        }
    }

    // sorting positive array
    radix_sort(arr, size); 

    if (size1 != 0)
    {
        // sorting negative array
        radix_sort(neg_arr, size1); 

        // reverse sorted negative array
        reverse(neg_arr.begin(), neg_arr.end()); 

        // merging negative array with positive array
        for (int i = 0; i < size1; i++) 
        {
            arr[i] = -neg_arr[i];
        }
    }

    cout << "\nAfter sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Test Case :

    Input_1 :
        enter size of array(or count of total numbers) : 5

        Start filling your array :
        1). 22
        2). 24
        3). 65
        4). 12
        5). 1

    Output_1 :
        After sorting : 1 12 22 24 65

    Input_2 :
        enter size of array(or count of total numbers) : 6

        Start filling your array :
        1). -3
        2). -4
        3). -5
        4). -3
        5). -1
        6). 0

    Output_2 :
        After sorting : -5 -4 -3 -3 -1 0

    Input_3 :
        enter size of array(or count of total numbers) : 8

        Start filling your array :
        1). -2
        2). -3
        3). 0
        4). -1
        5). 55
        6). 66
        7). 7
        8). 999

    Output_3 : 
        After sorting : -3 -2 -1 0 7 55 66 999
*/

/*
    Time Complexity :
        Radix Sort has time complexity of O(d*(n + k))
            where, d -> number of digits in larget  number
                   n -> number of elements in the array
                   k -> range of numbers, a digit can have

        But in our case, k is fixed 10. So we can right time
        complexity as O(d*n)

    Space Complexity :
        Radix Sort has a space complexity of O(n+k). As it uses
        two auxiliary array, one of size n and another of size of k.

        But in out case, we have fixed k value to be 10. Therefore
        we can write space complexity as O(n).
*/