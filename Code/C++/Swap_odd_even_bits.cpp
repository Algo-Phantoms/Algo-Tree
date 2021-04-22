/* Swap all odd and even bits of a given number

    This algoritm would use Bit Manipulation.
    If we take a closer look, we can observe that we basically need to right shift (>>) all even bits by 
    1 so that they become odd bits, and left shift (<<) all odd bits by 1 so that they become even bits.

    For example, x = 23 (00010111) with output 43 (00101011)
*/


#include <bits/stdc++.h>
using namespace std;
  
// Function to swap even and odd bits 
unsigned int swap_oddeven_Bits(unsigned int x) 
{ 
    // Get all even bits of x 
    unsigned int even_bits = x & 0xAAAAAAAA;  
  
    // Get all odd bits of x 
    unsigned int odd_bits  = x & 0x55555555;  
  
    even_bits >>= 1;  // Right shift even bits 
    odd_bits <<= 1;   // Left shift odd bits 
  
    return (even_bits | odd_bits); // Combine even and odd bits 
} 
  
int main() 
{ 
    unsigned int x;
    cin>> x;
 
    printf("%u ", swap_oddeven_Bits(x)); 
  
    return 0; 
} 


/*  Input:- 23
    Output:- 43
    where, 23 is (00010111)
    and    43 is (00101011)
*/