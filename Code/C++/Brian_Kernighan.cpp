/* Brian Kernighan's Algorithm

It is an algorithm developed to count the number of set bits in a number
   in a efficient way.

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

    Above function at line 36, that takes an integer as argument and
    returns the number of set bits.
*/
#include<bits/stdc++.h>
using namespace std;

int count_set(int n){
    // 'ans' variable keeps the track of the number of set bits
    int ans = 0;      
    while(n > 0){
        n = (n & (n-1));
        ans++;
    }
    return ans;
}

//main function
int main(){
    int n;
    // Taking input from the user
    cin >> n;   
    int ans = count_set(n);
    cout << ans << "\n";
}

/* Test case : 
    1) input   : 32
       output  : 1
    2) input   : 39
       output  : 4

        Time Complexity -> O(n) where n is number of set bits in input.
        
        Space Complexity -> O(1)

*/

