/*
Reverse the bits of a given integer in its binary equivalent and 
print the new number obtained in its decimal form in C++.
*/

#include <bits/stdc++.h>
using namespace std;

int reverse_bits(int n)
{

    int reverse = 0, rem;

    // Traversing until there exist bits for the given number
    while (n)
    {
        // Shift the bit of the reversed(answer) number to the right
        reverse = reverse << 1;
        //Storing the temporary lsb of the given number
        rem = n & 1;
        reverse = rem | reverse;
        //Droping the already processed lsb of the given number
        n = n >> 1;
    }
    return reverse;
}

int main()
{
    int n, ans;
    cout << "\nEnter the number : ";
    cin >> n;
    ans = reverse_bits(n); //functuon call
    cout << "The bits-reversed number is: " << ans << endl;
    return 0;
}

/*
Time Complexity: O(n) 
Space Complexity: O(1)
-----------------------------------------------------------------------------------
SAMPLE INPUT :
Enter the number: 23
OUTPUT :
The bits-reversed number is: 29
------------------------------------------------------------------------
SAMPLE INPUT :
Enter the number: 58
OUTPUT:
The bits-reversed number is: 23
*/
