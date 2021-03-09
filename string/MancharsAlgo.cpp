// Necessary Header files Included
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// Shorthand for long long
using ll = long long;
using namespace std;

// This function returns the Pair in which the first element returns the length
// of the Longest Pallindromic Substring and the Second element returns the
// Longest Pallindromic Substring
pair<ll, string> Manchers(string &str) {
    // Convert the String in the Basic requirements i.e with special symbols
    function<string(string)> convert = [&](string s) -> string {
        string cpy = "@";
        for (int i = 0; i < s.size(); i++) {
            cpy += "#" + s.substr(i, 1);
        }
        cpy += "#$";
        return cpy;
    };
    string cpy = convert(str);
    vector<ll> P(cpy.size(), 0);
    ll C = 0, R = 0;
    // Looping thriugh the loop and checking required conditions
    for (int i = 1; i < cpy.size() - 1; i++) {
        ll iMirror = C - (i - C);
        if (R > i) {
            P[i] = min(R - i, P[iMirror]);
        }
        while (cpy[i + 1 + P[i]] == cpy[i - 1 - P[i]]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    ll maxPalindrome = 0;
    ll centerIndex = 0;
    for (int i = 1; i < cpy.size() - 1; i++) {
        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }
    // Returns the maximum possible length and the String
    return {maxPalindrome,
            str.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome)};
}

void solve() {
    string str;
    cin >> str;
    auto it = Manchers(str);
    cout << "The Length of The String is :: " << it.first
         << "\nAnd the String is :: " << it.second << "\n";
}

int32_t main() {
    // For Fast Input and Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc = 1;
    // cin >> tc;   // If Testcase(s) are there Uncomment it
    while (tc--) {
        solve();
    }
    return 0;
}

/**     Time Complexity O(N)
 *      Space Complexity O(N)     
 * 
 *      Basic Input For Checking
 *      Input  : abcbacbc
 *      Output : The Length of The String is :: 5
 *               And the String is :: abcba
 * 
 *      Input  : abcbabccbab
 *      Output : The Length of The String is :: 8
 *               And the String is :: babccbab   
**/