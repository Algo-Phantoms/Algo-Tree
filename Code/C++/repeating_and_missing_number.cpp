/*    Repeating and Missing number

An unsorted array of size n is given where the elements in the array range from 1 to n.
One number from 1 to n is missing and one number occurs twice in the array.
We have to find these two numbers.

Algorithm -

1. We will try to place all the elements on their positions such that a[i] = i+1.
2. Take a pointer at the starting of the array.
3. If the current element is at its position, move the pointer to next position.
4. Else place it at its position by swapping
5. Repeat the above steps till whole array is traversed.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // n is the size of array
    int n;
    cin >> n;

    // taking array as input
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
        cin >> a[i];

    int i = 0;
    while ( i < n )
    {
        // if element is at its position
        if ( a[i] == i + 1 || a[i] == a[ a[i] - 1 ] )
            i++ ;
        else
            // if not swap
            swap ( a[i], a[ a[i] - 1 ] );
    }

    int r = 0, m = 0;
    for ( int i = 0 ; i < n ; i++ )
    {
        // find the element which is not at its position
        if ( a[i] != i + 1 )
        {
            r = a[i];
            m = i + 1;
            break;
        }
    }

    cout << "Repeating number is " << r << endl;
    cout << "Missing number is " << m;
}

/*
Testcases
Input :
5
4 1 3 2 1
Output : Repeating number is 1
Missing number is 5

Input :
6
1 4 5 2 3 4
Output : Repeating number is 4
Missing number is 6

Time complexity : O(n)		
Space complexity : O(1)

where n is the size of the array
*/
