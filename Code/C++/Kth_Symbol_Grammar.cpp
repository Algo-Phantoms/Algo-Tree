/*
Problem Statement:- First row has 0. Every 0 is changed to 01 and every 1 is changed to 10.
Given n rows and index K (column), return the K-th indexed symbol in row n.

n=1 0
n=2 0 1
n=3 0 1 1 0
n=4 0 1 1 0 1 0 0 1

INPUT:-  n= 4 K=3
OUTPUT:- 1
INPUT:-  n= 3 K=4
OUTPUT:- 0


Approach used:
figured out a pattern that with each n rows it has 2^(n-1) symbols in nth row.
then from 2^(n-1) symbols half are exactly same as previous row. Therefore, calling Kth_Symbol_Grammar function recursively 1st on first half of the symbols then
on second half. And when satisfying the base case we get the answer.
*/

#include <bits/stdc++.h>
#define input(n); int n; cin>> n
using namespace std;

int Kth_Symbol_Grammar(int n,int k)
{
    /*
    Base case is when both n and k are equal to 1.
    Now calculating mid and observing that (n-1)th row is exactly same to the nth row till mid.
    Hence, calling function twice when k is less than equal to mid or grater than mid, for n-1 and k else n-1 and k-mid.
    */
    if(n==1 && k==1)
        return 0;
    int mid = pow(2,n-1) / 2;

    if(k<=mid)
        return Kth_Symbol_Grammar(n-1,k);
    else
        return !Kth_Symbol_Grammar(n-1,k-mid);
}


int main()
{
    cout<<"Test cases: ";
    input(t);
    // enter number of test cases
    while(t--)
    {
        cout<<"INPUT: ";
        input(n);
        // enter n (which acts as number of rows)
        input(k);
        // enter k (which acts as number of columns)
        int Symbol = Kth_Symbol_Grammar(n,k);
        // Function calling and returning the Kth-indexed grammar
        cout<<"OUTPUT: "<<Symbol<<"\n";
        // Printing returned value from the function (either 0 or 1)

    }
	return 0;
}


/*

Test cases: 4
INPUT: 4 3
OUTPUT: 1
INPUT: 3 4
OUTPUT: 0
INPUT: 2 2
OUTPUT: 1
INPUT: 2 1
OUTPUT: 0



Time Complexity: O(n+k)  where n is rows and K is column as per inputs
Space Complexity: O(n)
*/
