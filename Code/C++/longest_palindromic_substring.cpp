// Given a string s, return the longest palindromic substring in s.

#include<bits/stdc++.h>
using namespace std;

int palindromeLength(string s, int left, int right){
        // finding the length of substring which satisfy 
        // the palindromic condition.
        int l = left, r = right;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l - 1;
}

string longestPalindrome(string s) {
        // if the string is null then longest palindromic substring is "".
        if(s.size() < 1){
            return "";
        }
        // a palindrome mirrors around its center. Therefore, a palindrome can 
        // be expanded from its center.
        // minimum length of palindrome is 0, so start and end both are zero initially.
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            // index i pointing to 'C', if palindrome is "ABCBA"
            int len1 = palindromeLength(s, i, i);
            // index i and i + 1, pointing to 'C' if palindrome is "ABCCBA"
            int len2 = palindromeLength(s, i, i+1);
            // maximum length from both possible case
            int len = max(len1, len2);
            // if length is greater than previous palindrome length then 
            // reassign start and end value according to the present maximum length.
            if(len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        // retrun the palindromic substring of maximum length
        return s.substr(start, end - start + 1);     
    }
    

int main(){
    // Input string 
    string str;
    cin >> str;
    // Calling longestPalindromic() function to find the longest palindromic substring in str.
    string long_palindromic_substr = longestPalindrome(str);
    cout << long_palindromic_substr << endl;
    return 0;
}

// Input 1: s = "babad"
// Output 1: "bab"

// Input 2: s = "cbbd"
// Output 2: "bb"

// Input 3: s = "ac"
// Output 3: "a"

// Time Complexity : O(n * n)
// Space Complexity : O(1)
