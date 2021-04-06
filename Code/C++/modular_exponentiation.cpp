/* 
Normal power algorithm would take O(power) time to calculate the answer.
But here we use the fact that every number can be represented in power of 2!
Consider 4^7

Normal calculation = (4*4*... 7 Times)
Modular exponentiation = (4^4)*(4^2)*(4^1)

We use this power of 2s to our advantage.
(4^2)=(4^1)^2
(4^4)=(4^2)^2 
So, this reduces the number of multiplication, as we only need to sqaure the number (squaring is just single multiplication operation).
*/

#include<bits/stdc++.h>
using namespace std;

long long modular_exponentiation(long long base,long long power,long long mod)
{
    base=base%mod;
    long long answer=1;
    while(power>0)
    {
        if(power%2==1)
        { 
            answer=(answer*base)%mod;
        }
        base=(base*base)%mod;
        power=power/2;
    }
    return answer;
}

int main()
{
    long long base,power,mod;
    cout<<"Enter base: ";
    cin>>base;
    cout<<"Enter power: ";
    cin>>power;
    cout<<"Enter mod: ";
    cin>>mod;
    cout<<"("<<base<<"^"<<power<<")%"<<mod<<" = "<<modular_exponentiation(base,power,mod)<<"\n";
}

/*
Sample I/0

1. 
    INPUT
    Enter base: 2
    Enter power: 10 
    Enter mod: 8000 
    OUTPUT
    (2^10)%8000 = 1024

2.
    INPUT
    Enter base: 3
    Enter power: 6
    Enter mod: 1 
    OUTPUT
    (3^6)%1 = 0
*/

/*
Time Complexity: O(log(power))
Space Complexity: O(1)
*/

