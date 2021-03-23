/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.*/

#include <bits/stdc++.h> 
using namespace std; 
  
int HK[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 }; 
int v = sizeof(HK) / sizeof(HK[0]); 
  
void findMin(int V) 
{ 
    vector<int> ans; 
  
    for (int i = v - 1; i >= 0; i--) { 
        while (V >= HK[i]) { 
            V -= HK[i]; 
            ans.push_back(HK[i]); 
        } 
    } 
  
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << "  "; 
} 
  
int main() 
{ 
    int v;
    cin>>v;
    findMin(v); 
    return 0; 
}

/*Two Test case you can try out with this code-
# Input  93
  Output 50 20 20 2 1 
# Input  49
  Output 20 20 5 2 2*/
          
/*Time Complexity = O(v)
Space Complexity = O(1)*/