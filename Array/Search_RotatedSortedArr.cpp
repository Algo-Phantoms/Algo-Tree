/* Problem Statement:
Given an integer array, and an element x, find the index of the element in O(log n) time.
Integer array is sorted in ascending order, but it is rotated at some pivot. */

#include <bits/stdc++.h>
using namespace std;

int search_SortedRotatedArr(vector<int> arr, int x){ //O(logn) time (since it uses binary search) , O(1) auxiliary space
    int n = arr.size();
    if(n == 2){
        if(arr[0] == x){
            return 0;
        }
        else if(arr[1] == x){
            return 1;
        }
        else{
            return -1;
        }
    }
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            return mid;
        }
        //if the array's left half is sorted
        if(arr[low] <= arr[mid]){
            if(x < arr[mid] && x >= arr[low]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        //if right half of the array is sorted
        else{
            if(x > arr[mid] && x <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1; //if element not found in arr
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x; //Number we have to search for
    cin >> x; 
    cout << search_SortedRotatedArr(arr, x);
    return 0;
}

/* Example:
Input: arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, x = 3
Output: 8 */
