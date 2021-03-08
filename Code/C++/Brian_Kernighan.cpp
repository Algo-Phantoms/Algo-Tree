// Brian Kernighan's Algorithm
#include<bits/stdc++.h>
using namespace std;


/* It is an algorithm developed to count the number of set bits in a number
   in a efficient way.
   
    Time Complexity - 
       1) Naive approach - O(total number of bits in the number)
       2) Efficient approach - O(total number of set bits in the number)

    IDEA/INTUITION behind the efficient algorithm-
        1) Consider any number n. Then if we consider (n-1), it is observed
           that in (n-1), "All the bits from the last set bit to the rightmost
           bit gets changed to it's opposite bit".
          
           Example-
             let n=40, binary representation -> 000....101000 (32 bit)
             now (n-1)=39, binary representation -> 000...100111
             We can clearly verify the above statement from the example.
        
        2) The next step is to take the bitwise And(&) of n and (n-1).
           What this step does, is that it turns off the last set bit.

           Example-
             n=40    ->   000...101000
             n=39    ->   000...100111
             -----------------------
             n&(n-1) ->   000...100000
             
             We clearly see the only change tha happens after the 2 steps,
             is that the left most set bit gets turned off.
        
        3) We repeat this step until n becomes 0.

    
    Below is the code (C++) representing the idea.
    There is a function count_set(), that takes an integer as argument and
    returns the number of set bits.
*/

int count_set(int n){
    int ans=0;      // This keeps the track of the number of set bits 
    while(n>0){
        n=(n&(n-1));
        ans++;
    }
    return ans;
}

//main function
int main(){
    int n;
    cin>>n;   // Taking input from user
    int ans= count_set(n);
    cout<<ans<<"\n";
}

/* TEST CASES

    1) input   : 32
       output  : 1
    2) input   : 39
       output  : 4

    
        TIME COMPLEXITY - O(No. of set bits in input)
        SPACE COMPLEXITY - O(1)

    END...
*/  