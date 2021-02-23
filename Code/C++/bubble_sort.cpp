/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if
 * they are in wrong order.
 * Idea: if arr[i] > arr[i+1] swap them. To place the element in their respective
position, we have to do the following operation N-1 times.*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int counter = 1;
    while (counter < n - 1) {
        for (int i = 0; i < n - counter; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << "\n";
    return 0;
}

/*
Test Case

Input:
4
6 3 9 1
Output:
1 3 6 9
Time Complexity:
Worst and Average time complexity: O(n^2)
Best case time complexity: O(n)
Auxiliary space: O(1)*/
