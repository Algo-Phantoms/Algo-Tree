//  Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

//  '.' Matches any single character.​​​​
//  '*' Matches zero or more of the preceding element.

#include <bits/stdc++.h>
using namespace std;


bool isMatch(string s, string p) {
    // finding the length of string and pattern
    int m = s.size(), n = p.size();
    // Use dp vector is used to store the intermediate result
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    // When a star(*) is present, we may need to check many different suffixes of the text
    // and see if they match the rest of the pattern.
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else {
                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[m][n];
}


int main() {

    // Input :
    string s1 = "aa", p1 = "a";
    cout << isMatch(s1, p1) << endl;

    string s2 = "aa", p2 = "a*";
    cout << isMatch(s2, p2) << endl;

    return 0;
}


// Test Cases :

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// ---------------------------------------------------------------

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'.
// Therefore, by repeating 'a' once, it becomes "aa".
// ------------------------------------------------------------------

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// ------------------------------------------------------------------

// Input: s = "aab", p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time.
// Therefore, it matches "aab".
// -------------------------------------------------------------------



// Time Complexity: O(TP), Let T and P be the lengths of the text and the pattern respectively.

// Space Complexity: The only memory we use is the O(TP) boolean entries in our cache.
//                   Hence, the space complexity is O(TP
