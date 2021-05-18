/*
-LONGEST PREFIX SUFFIX
-Given a string, find the length of longest substring that is both prefix and suffix
-overlapping of prefix and suffix not allowed

-idea is to divide the given string from between and check if both string are equal
-if so return the length of that substring
-otherwise check for the shorter length
 */

#include <iostream>
using namespace std;

int main()
{

    string s;
    // input from the user
    cin>>s;
    /*if length of given string is less
    than two, no such substring exist
    hence prints 0*/
    if (s.length()<2)
        cout<<0;
    else 
    {
        /*divide string into two equal parts
        and store starting indices of both*/
        int l=0, i=s.length()/2;
        /*loop calculating the length of
        such substring*/
        while (i<s.length()) 
        {
        /*check if left string character is equal
          to right one if so increament indices of both
          by 1*/
            if (s[i]==s[l])
            {
                ++l;
                ++i;
            }
        /*otherwise check for shoter substring*/
            else 
            {
                i=i-l+1;
                l=0;
            }
        }
        /*as overlapping is not allowed*/
        if (l>s.length()/2)
            cout<<s.length()/2;
        else
            cout<<l;
    }
    return 0;
}


/*

Test Cases

Test Case-1
 Input = "rrrrr"
 Output = 2

Test Case-2
 Input = "abcdabc"
 Output = 3

Time complexity = O(n), where n is length of string,i.e n=s.length()
Space complexity = O(1)

*/
