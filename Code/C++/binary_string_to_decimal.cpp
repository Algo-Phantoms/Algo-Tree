/*
A string containing only 0's and 1's is called a binary string.
The equivalent decimal of a binary number is the sum of 2 raised to the power of the positional values where 1 is present. 
The least significant bit is assigned positional value 0.
The following program illustrates how to convert a binary string to its equivalent decimal
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	string s;
	
	// Taking input the binary string from the user
	cin >> s;
	
	// Assigning a variable to store the size of the string
	int n = s.size();
	
	// Initializing a variable named decimal to 0 which stores the decimal equivalent of the inputted binary string
	int decimal = 0;
	
	// Running a loop to convert the binary to its equivalent decimal
	for(int i = n-1;i >= 0;i--)
	{
		// Updating the variable decimal if the ith position of the string has value '1'
		if(s[i] == '1')
		decimal += (int)pow(2,abs(i-(n-1)));
	}
	
	// Printing the equivalent decimal of the inputted binary string
	cout << decimal;	
	
	return 0;
	
}

/*
TEST CASES:

Sample input : 1100
Standard output: 12

Sample input : 1000
Standard output: 8

Sample input : 100010
Standard output: 34

Time Complexity : O(n) where n is the size of string
Space Complexity: O(n)
*/
