/*       Palindrome Number : 
                    Given an integer x, return true if x is palindrome integer.
                    An integer is a palindrome when it reads the same backward as forward.
                    This code is implemented without using extra space.  
                    In this we will be taking two point , leading and trailing which will be pointing
                    in start and end of the number and then we will be comparing start and end , if 
                    found equal then we will move the pointers and we will compare till every digit is
                    checked . So if condition satisfied then we will  return true else return false.                     
*/

#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int num)
{
    // divi =  divisor
    int divi = 1;

    //finding the apt. divisor for the number
    while (num / divi >= 10)
    {
        divi *= 10;
    }

    while (num != 0)
    {
        int leading = num / divi;
        int trailing = num % 10;
        if (leading != trailing)
        {
            return false;
        }
        //reducing number to compare
        num = (num % divi) / 10;
        divi = divi / 100;
    }
    return true;
}
int main()
{
    int num;
    cout << "Enter the number to check : " << endl;
    cin >> num;
    checkPalindrome(n) ? cout << "True" : cout << "False";
    return 0;
}

/*
Time complexity : O(log n)
(here n is number of elements in array)
Space complexity : O(1)
*/

/*
Test Cases : 
    Test case 1 :
        Input : 1001
        Output : True
    Test case 2 : 
        Input : 1234
        Output : False
*/

