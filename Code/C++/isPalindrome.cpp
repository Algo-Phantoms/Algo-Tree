/* Aim: To check whether a input string is palindrome or 
Approach Used : {Two Pointer Approach}
Checked the string length and put one pointer at starting index and another pointer at last index.
Both the strings str1 and str2 are compared in while loop
If str1 is equal to str2 till si < ei then it is palindrome else not. */
#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(string str){
    int si = 0;
    int ei = str.length() - 1;
    while(si < ei){
        if(str[si++] != str[ei--]){
            return false;
        }
    }return true;
}
int main(){
    string str;
    cin >> str;
    if(isPalindrome(str))  cout<<"Yes, It is Palindrome";
    else  cout<<"No, It is Not Palindrome";
    return 0;
}
/*Test Case 1:
Input - ababcbaba
Output - Yes, It is Palindrome 
Test Case 2:
Input - abccab
Output - No, It is Not Palindrome*/
