/*                                          QUESTION
    Given a value V, if we want to make change for x amount of money, and we have infinite supply of each of 
    C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?

    A general approach would be to use recursion, by subracting the money from the given amount and
    running the code for the remaining value. Another method would be to manually check from the 
    beginning of the array and storing the possible values in another array/vector.

    However, if we use a greedy algorithm and start in a reverse or
    descending order, we can get to the result faster than the manual method
    and have less complexity than the recursion method.
*/

#include <bits/stdc++.h>
using namespace std;

void denom(int mny){
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int len = sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr + len);  //here, the given denominations are sorted else we'd have to sort first
    vector<int> sum;
    for(int i = len - 1; i >= 0; i--){
        while(mny >= arr[i]){
            mny -= arr[i];
            sum.push_back(arr[i]);
        }
    }
    for(auto &x: sum){
        cout << x << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n; cin.ignore();
    denom(n);
    return 0;
}
