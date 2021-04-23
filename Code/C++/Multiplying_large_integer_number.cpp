/*
PROBLEM STATEMENT:
Given two positive integers, find its product. The numbers may be very large, they may or may not fit in long long int.
Approach:
The idea is to store the numbers in array, every digit will be stored as an element of array.
*/

#include<bits/stdc++.h>
using namespace std;

// A function to print the product of two large integers
void LargeMultiplication(vector<int> num1, vector<int> num2, int len1, int len2){

	// Multiplying the ith digit of second number to all the jth digits of first number and storing it at (i+j)th index of the product array
	//maximum length of the product will be sum of the lengths of both the numbers
	int product[len1 + len2] = {0};	
	for(int i = 0; i < len2; i++){
		for(int j = 0; j < len1; j++){
			product[i+j] += num2[i]*num1[j];
		}
	}

	for(int i = 0; i < len1 + len2 - 1; i++){
		int temp = product[i] / 10;
		product[i+1] += temp;
		product[i] %= 10;
	}
	int idx;
	//if the product contains less digits than len1 + len2, then discarding all those digits which are 0 at the end 
	for(int i = len1 + len2 - 1; i >= 0; i-- ){
	    if(product[i] > 0){
	        idx = i;
	        break;
	    }
	}
	//Printing the product of two numbers in the reversed order as the answer is calculated after reversing the two numbers
	for(int i = idx; i >= 0; i--){
	    cout<<product[i];
	}
}


int main(){
	vector<int>num1;
	vector<int>num2;
	string str1, str2;
	
	cout<<"Enter first number: ";
	cin>>str1;
	cout<<"Enter second number: ";
	cin>>str2;
	
	for(int i = str1.size()-1; i >= 0; i--){
		num1.push_back(str1[i] - '0');
	}
	for(int i = str2.size()-1; i >= 0; i--){
		num2.push_back(str2[i] - '0');
	}
	int len1 = num1.size();
	int len2 = num2.size();
	//Function call to print the product
	cout<<"The multiplication of entered numbers is: ";
	LargeMultiplication(num1, num2, len1, len2);
	return 0;
}

/*
TEST CASES:
1.
Input: 
1234
56789
Output:
70077626

2.
Input:
150353265326
22055653351
Output:
3316139500221184007426

TIME COMPLEXITY: O(m*n), due to two nested loops used for multiplying each digit of number 1 with each digit of number 2
SPACE COMPLEXITY: O(m+n), due to the product array created
where 'n' and 'm' denotes the length of the first and second number respectively.
*/
