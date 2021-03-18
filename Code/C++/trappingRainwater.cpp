/* Aim: Find total units of rainwater that can be stored for the given array of heights
Approach Used : 1. Find maximum height of bar from the left end upto an index i in the array left_max.
2. Find maximum height of bar from the right end upto an index i in the array right_max.
3. Iterate over the array and update ans: Add min(left_max[i],right_max[i]) - height[i] to ans */
#include <bits/stdc++.h>
using namespace std;
int trappingRainwater(vector<int>& height) {
    int res = 0,left,right;
    int n = height.size();
    for(int i =1; i<n-1; i++){
        left = height[i];
        for(int j =0; j<i; j++){
            left =max(height[j],left);
        }        
        right = height[i];
        for(int j =i+1; j<n; j++){
            right =max(height[j],right);
        }        
        res+= min(left,right) - height[i];      
    }
    return res;
}
int main() {
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) 
        cin>>arr[i];
    cout << trappingRainwater(arr);
    return 0;
}
/* Time complexity: O(n)
Space complexity: O(n)
Test Case 1:
Input - 12
        0 1 0 2 1 0 1 3 2 1 2 1
Output - 6 
Test Case 2:
Input - 6
        420325
Output - 9 */
