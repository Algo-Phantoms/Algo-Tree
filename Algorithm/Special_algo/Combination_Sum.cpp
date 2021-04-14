/* Combination Sum Problem.
Problem Statement:
Given an array of integers and a target value, the unique combination of values in array should sum up to the target value. 
The same number can be chosen multiple times.
*/
#include<bits/stdc++.h>
using namespace std;

// Function that finds the number combinations.
void combinationSum(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &combn, int beg)
{
    // if target sum is 0, combination is created
    if(!target) {
        ans.push_back(combn);
        return;
    } 
    // recursively adding array elements from the beginning of the array, into the combn vector.
    // done until the element doesn't exceed the target.
    for(int i=beg; i!=arr.size() && target >= arr[i]; ++i) {
        // insert an element into the combination
        combn.push_back(arr[i]);
        
        // select further elements based on (target - inserted elements sum)
        combinationSum(arr, target - arr[i], ans, combn, i);
        
        // if the sum of elements exceed target, pop out element from the combination
        combn.pop_back();
    }
}
int main() {
    // array size
    int n; 
    cout << "\nEnter Array Size: "; cin >> n;
    
    // array elements
    vector<int> arr (n);
    cout << "\nEnter Array Elements: ";
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    // target sum
    int target;
    cout << "\nEnter Target Sum: "; cin >> target;
    
    //Sorting the array
    sort(arr.begin(), arr.end());
    
    // a 2D vector to store all possible combinations
    vector<vector<int> > ans;
    
    // a vector to make a combination out of arr
    vector<int> combination;
    
    // calling the utility function
    combinationSum(arr, target, ans, combination, 0);
    
    // print the combinations
    for(int i=0; i<ans.size(); ++i) {
        if(ans[i].size() > 0) {
            cout << "\n[";
            for(int j=0; j<ans[i].size(); ++j) 
                if(j == ans[i].size() - 1) cout << ans[i][j]; 
                else cout << ans[i][j] << ", ";
            cout << "]";
        }
    }
    return 0;
}
/* Sample Input 1:
Enter Array Size: 4
Enter Array Elements: 1 2 3 4
Enter Target Sum: 10
Output:
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[1, 1, 1, 1, 1, 1, 1, 1, 2]
[1, 1, 1, 1, 1, 1, 1, 3]
[1, 1, 1, 1, 1, 1, 2, 2]
[1, 1, 1, 1, 1, 1, 4]
[1, 1, 1, 1, 1, 2, 3]
[1, 1, 1, 1, 2, 2, 2]
[1, 1, 1, 1, 2, 4]
[1, 1, 1, 1, 3, 3]
[1, 1, 1, 2, 2, 3]
[1, 1, 1, 3, 4]
[1, 1, 2, 2, 2, 2]
[1, 1, 2, 2, 4]
[1, 1, 2, 3, 3]
[1, 2, 2, 2, 3]
[1, 2, 3, 4]
[1, 3, 3, 3]
[2, 2, 2, 2, 2]
[2, 2, 2, 4]
[2, 2, 3, 3]
[2, 4, 4]
[3, 3, 4]

Sample Input 2:
Enter Array Size: 4
Enter Array Elements: 4 2 8 6
Enter Target Sum: 8
Output: 
[2, 2, 2, 2] 
[2, 2, 4]
[2, 6]
[4, 4]
[8]
*/
