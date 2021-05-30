// Given an array nums which consists of non-negative integers and an integer m,
// you can split the array into m non-empty continuous subarrays.
// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        // f[i][j] to be the minimum largest subarray sum for splitting nums[0..i] into j parts
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return dp[n][m];
}

int main(){
    // Number of element in the array
    int n;
    cin >> n;
    vector<int> nums(n);
    // Input element of an array
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int number_of_split;
    cin >> number_of_split;
    // calling splitArray function to find number of ways to split nums into number_of_split subarray
    // with minimum largest sum.
    cout << splitArray(nums, number_of_split) << endl;
    
    return 0;
}

// Input 1: nums = [7,2,5,10,8], number_of_split = 2
// Output 1: 18

// Input 2: nums = [1,2,3,4,5], number_of_split = 2
// Output 2: 9

// Input: nums = [1,4,4],  number_of_split = 3
// Output: 4

// Time Complexity : O(n * n + number_of_split)
// Space Complexity : O(n * number_of_split)
// where n is the size of array nums.
