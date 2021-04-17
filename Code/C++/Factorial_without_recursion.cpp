/*
Factorial of a non-negative integer, is multiplication of all integers smaller than or equal to n.
*/
#include<iostream>
using namespace std;
int main()
{
    int num, fact=1;
    cout<<"\nEnter the number whose factorial you want to find:-";
    cin>>num;
    for(int i=num; i>1; i--) 
    {
        fact=fact*i;
    }
    cout<<"Factorial of "<<num<<" is "<<fact;
    return 0;
}
/*
Test case 1:
	Input : 5
	Output : 120
Test case 1:
	Input : 3
	Output : 6
Time complexity: O(n)
Space Complexity: 1
*/
