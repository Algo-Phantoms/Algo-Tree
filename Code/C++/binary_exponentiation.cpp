/*Finding exponents of a number using the inbuilt function of the C++
language can be slow. Faster way to calculate exponents is using binary
exponentiation. 
Binary Exponentiation works on a simple principle that 
3^8 can also be written as (3^4)^2 and 3^4 can be written as (3^2)^2.
This way we lessen the amount of calculations we need to make when 
the power is huge. */
#include<iostream>
using namespace::std;

long long power(int n,int a) //We will calculate n to the power of a => n^a
{
    long long result=1;
    while(a>0)
    {
        if(a%2==0)
        {
            result=result*n;
        }
        n=n*n;
        a/=2;
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    int a;
    cin>>a;
    cout<<power(n,a)<<"\n";

}