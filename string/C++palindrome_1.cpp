
#include <iostream>
using namespace std;

//palindrome check for a number!!!
/*This program reverses an integer (entered by the user) using while loop. Then, if statement is 
used to check whether the reversed number is equal to the original number or not.*/

//driver code
int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number of your choice: "; //taking input from the user
     cin >> num;

     n = num;

     do   //do while loop to reverse the digits of the number
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n== rev) //checking if the reversed number is same as the original input number
         cout << " The number is a palindrome!!!";
     else
         cout << " The number is not a palindrome!!!";

    return 0;
}
/*test cases-
 1.input-121
 output-The number is a palindrome!!!
 2.input-34567
 output-The number is not a palindrome!!!
 3.input-123454321
 output-The number is a palindrome!!! */
