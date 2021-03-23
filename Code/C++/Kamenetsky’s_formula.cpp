/*Counting number of digits in a factorial using Kamnestsky's Formula:
Reason to use: Result of a factorial can be very large to store where long long integers may also be insufficient.(But python containers are capable of hanadling it.)
    Thus, Kamnestsky's formula allows to handle inputs > 10^6
    with a time complexity of O(1)*/

/*Method :For inputs < 10^6 logarithmic property can be used:
        log( n! ) = log(1*2*3....... * n) 
                  = log(1) + log(2) + ........ +log(n)
        */

//including header files
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
//number of digits in a factorial or a number n
    int facDigits(int N){
        // factorial of -ve number  
        // doesn't exists 
        if (N < 0) 
        return 0; 
        
        // base case 
        if (N <= 1) 
        return 1; 
        
        // Use Kamenetsky formula to calculate 
        // the number of digits 
        double x = ((N * log10(N / M_E) +  
                 log10(2 * M_PI * N) / 
                 2.0)); 
        
        return floor(x) + 1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.facDigits(n)<<"\n";
       
        
    }
    return 0;
}  

/*
Input:
N = 5
Output:
3
Explanation:
5! is 120 so there are 3
digits in 120


*/

/*
Time Complexity:O(1)
Space Complexity:O(1)
*/