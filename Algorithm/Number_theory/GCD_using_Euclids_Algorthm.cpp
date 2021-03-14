/*GCD(Greatest Common Divisor) - The GCD of 2 or more integers is the largest integer that divides each of the integers such that their
remainder is zero. In the below code we are going to find out the GCD of 2 numbers using Euclid's Algorithm*/
/*Euclid's algorithm for GCD-
We are going to follow the below mentioned formula to find GCD of 2 numbers, 
GCD(A,B)=GCD(B, A%B); here A and B are two integer values 
We are going to call our GCD function recursively untill we get 0 in the remainder.
But our algorithm will stop once we get 0 in the remainder then we can say that A(integer value) is our desired GCD ie.
GCD(A, 0) = A */

//C++ Program to find GCD of 2 numbers using Euclid's Algorithm
#include<bits/stdc++.h>
using namespace std;

//Recursive function to return gcd of n1 and n2
int GCD(int n1,int n2)
{
   //Base Case
   if(n2==0)
    {
        return n1;
    }

   //Calling Recursively
   return GCD(n2,n1%n2) ; 
}

//Main function Code
int main()
{
    //Declaring two integer variables
    int a,b;
    cout<<"Enter 2 integers whose GCD you want to find out : ";

    //Taking input from user
    cin>>a>>b;

    //Printing output value
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<GCD(a,b)<<endl;
    
    return 0;
}

/*
Two Test case you can try out with this code-

# Input : a=20
          b=12
  Output : 4 
# Input : a=98
          b=56
  Output : 14*/

/*
Time Complexity - O(log(max(a,b)))
Space Complexity - O(log(a) + log(b))
*/
