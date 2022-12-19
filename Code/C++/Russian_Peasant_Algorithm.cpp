/* 
    Russian Peasant Algorithm: This algorithm deals with the multipliacation of two numbers using bitwise operators.
                              The idea is to double the first number and halve the second number till the second 
                              number does not become 1. Whenever the second number becomes odd first number is 
                              added to the answer which is initialized as 0.
                              
    The following C++ program illustrates Russian Peasant Algorithm.
*/

#include <iostream>
using namespace std;

//Function to multiply two numbers using Russian Peasant Algorithm
unsigned long long int Russian_Peasant_Algorithm(unsigned long long int a,unsigned long long int b)
{
	//Initialising result to 0
	unsigned long long int answer=0;
	
	//Checking that the second number does not become 1
	while(b>0)
	{
		//Checking if second number becomes odd
		//An odd number has LSB as 1 and so its bitwise and with 1 will always be 1.
		if(b&1)
		{
			//Adding the first number to the answer
			answer=answer+a;
		}
		
		//Doubling the first number
		//Left shifting a number by 1 bit means multiplying it with 2
		a=a<<1;
		
		//Halving the second number
		//Right shifting a number by 1 bit means dividing it with 2
		b=b>>1;
	}
	
	//Returning the answer
	return answer;
}

//Driver Program
int main()
{
	unsigned long long int x,y;
	
	//Taking input the two numbers from the user which needs to be multiplied
	cin>>x>>y;
	
	cout<<Russian_Peasant_Algorithm(x,y)<<endl;
	
	return 0;
}

/*
  Sample Input: 4 5  
  Standard Output: 20
  
  Sample Input:1 3
  Standard Output: 3
  
  Sample Input:5 6
  Standard Output: 30
  
  Sample Input: 2345 445
  Standard Output: 1043525
  
  Sample Input: 0 9
  Standard Output: 0
  
  Sample Input: 44 7812
  Standard Output: 343728
  
  
  Time Complexity: O(log b)
  Space Complexity:O(1)
*/


