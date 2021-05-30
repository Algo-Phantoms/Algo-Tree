/*

* A subsequence of arr[] is called Bitonic if it is first increasing, then decreasing 
  where arr[] is an  array arr[0 ... n-1] containing n positive integers.
* If a sequence is sorted in increasing order it is  considered Bitonic with the decreasing part as empty. 
  Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

* Approach used : 
  Here we will follow the modification of Longest Increasing Subsequence for better time complexity O(nlogn) 
  otherwise it can be solved using Dynamic programming in O(n^2) time complexity.
  
  *-- First we will define 4 Arrays of input size n:
        -- increasing[n] to calculate LIS of the array
        -- decreasing[n] to calculate LIS of the array
        -- end_point_1[n] to store the values for LIS for increasing[n]
        -- end_point_2[n] to store the values for LIS for decreasing[n]
  *-- Then we will find the  LIS for increasing[n]
  *-- Then we will reverse the array and store it in decreasing[n]
  *-- Then we will find LIS for decreasing[n]
  *-- Now, the Longest Bitonicc Subsequence length  will be max of end_point_1[i] + end_point_2[i] + 1
  *-- Now we just have to see where this given expression : end_point_1[i] + end_point_2[i] + 1 ; will be maximised  and then we will get the answer

*/

#include <bits/stdc++.h>
using namespace std;

//Function to Find out the longest bitonic subsequence
int  find_longest_bitonic_subsequence(int arr[], int n) {

    // Base Case: if there is no element present or no element remaining for computation.
    if (n == 0)
        return 0;

    // Array storing the input array
    // in same order to calculate LIS:
    int increasing[n];

    // To store lengths of Increasing subsequence.
    int end_point_1[n];

    // Array storing the input array
    // in reverse order to calculate LIS:
    int decreasing[n];
 
    // To store lengths of Decreasing subsequence
    int end_point_2[n];
 
    // initializing first index same as
    // original array:
    increasing[0] = arr[0];
 
    // index is initialized as 1 from where
    // the remaining computations will be done
    int index = 1;
 
    // end_point_1 stores Longest Increasing subsequence
    // length values till index
    end_point_1[0] = 0;
 
    // remaining computations to get the
    // LIS length for increasing
    for (int i = 1; i < n; i++) {

        if (arr[i] > increasing[index - 1]) {
            increasing[index++] = arr[i];
            end_point_1[i] = index - 1;
        }
        else if (arr[i] < increasing[0]) {
            increasing[0] = arr[i];
            end_point_1[i] = 0;
        }
        else {
            int point = lower_bound(increasing ,increasing + (index - 1), arr[i]) - increasing;
            increasing[point] = arr[i];
            end_point_1[i] = point;
        }

    }
 
    // reinitializing the index to 1 for decreasing array
    index = 1;
 
    // reversing the array to get the Longest
    // Decreasing Subsequence Length
    int i = 0;
    int j = n - 1;
    while (i < j)
       swap(arr[i++], arr[j--]);

    
    decreasing[0] = arr[0];
    end_point_2[0] = 0;
 
    for (int i = 1; i < n; i++) {

        if (arr[i] > decreasing[index - 1]) {
            decreasing[index++] = arr[i];
            end_point_2[i] = index - 1;
        }
        else if (arr[i] < decreasing[0]) {
            decreasing[0] = arr[i];
            end_point_2[i] = 0;
        }
        else {
            int point = lower_bound(decreasing ,decreasing + (index - 1), arr[i]) - decreasing;
            decreasing[point] = arr[i];
            end_point_2[i] = point;
        }

    }

    // Reversing the end_point_2 array
    i = 0;
    j = n - 1;

    while(i < j) 
        swap(end_point_2[i++] , end_point_2[j--]);
 
    // Longest Bitonic Subsequence length is
    // maximum of tail1[i] + tail2[i] + 1:
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ans < (end_point_1[i] + end_point_2[i] + 1))
            ans = (end_point_1[i] + end_point_2[i] + 1);
 
 
    return ans;
}

int main() {

    //Fast input output operation by matching the synchronization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Taking the number of test cases
    int t;
    cin >> t;

    while (t--) {

        // Taking the size of array as input for which longest bitonic subsequence is to find out.
        int n;
        cin >> n;

        // Taking the array elements as input.
        int arr[n];
        for(int i=0 ;i<n ;i++) {
            cin >> arr[i];
        }
        
        // Longest bitonic subsequence length which is the answer.
        int longest_bitonic_subsequence;

        // Call the function for finding out the Longest bitonic subsequence length
        longest_bitonic_subsequence = find_longest_bitonic_subsequence(arr,n);

        // Print the answer
        cout << longest_bitonic_subsequence << "\n";

    }

    return 0;
}

/*

* Sample Test Cases :
    Input 1:
    1
    7
    4 5 9 7 6 3 1

    Output 1:
    7

    Input 2:
    1
    6
    1 5 4 7 9 15

    Output 2:
    5

* Explanation of first test case :
-- Given_Array[]   Increasing[]   end_point_1[]   Reversed_Given_Array[]   Decreasing[]   end_point_2[]   Reversed_end_point_2[]   (end_point_1 + Reversed_end_point_2[] + 1)
        4               1               0               1                      1                0                    2                      3
        5               5               1               3                      3                1                    2                      4
        9               6               2               6                      4                2                    4                      7  // This is the answer
        7               0               2               7                      7                3                    3                      6
        6               0               2               9                      9                4                    2                      5  
        3               0               0               5                      0                2                    1                      2
        1               0               0               4                      0                2                    0                      1

* Explanation of second test case :
-- Given_Array[]   Increasing[]   end_point_1[]   Reversed_Given_Array[]   Decreasing[]   end_point_2[]   Reversed_end_point_2[]   (end_point_1 + Reversed_end_point_2[] + 1)
        1               1               0               15                     1                0                   0                       1
        5               4               1               9                      5                0                   1                       3
        4               7               1               7                      0                0                   0                       2
        7               9               2               4                      0                0                   0                       3
        9               15              3               5                      0                1                   0                       4  
        15              0               4               1                      0                0                   0                       5  // This is the answer


* Time Complexity: O(nlogn)
* Auxilary Space: O(n) 

*/ 
