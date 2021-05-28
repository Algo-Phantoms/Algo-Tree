/*
Approach : First sort the array then, swap pairs of elements
except the first element. Example - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
So, we will take array and its size as parameters, run a loop from i to size of the array 
and swap every pair of element using swap function. At the end of loop, we will print the array.
*/

#include <bits/stdc++.h>
using namespace std;

//helper function that converts given array in zig-zag form
void zigzag(int a[] , int n)
{
    for(int i = 1 ; i < n ; i += 2)
    {
        if(i+1 < n)
            swap(a[i] , a[i+1]);
    }

    cout << "\nZig - Zag array : ";
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << "  ";
}

int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a , a+n);

    cout << "Original array  : ";
    for(int i=0 ; i<n ; i++)
        cout << a[i]<<"  ";

    zigzag(a , n);

    return 0;
}

/*
    Test Case -

    Sample Input/Output (1):
    Original array  : 1  2  3  4  6  7  8
    Zig - Zag array : 1  3  2  6  4  8  7
    
    Sample Input/Output (2):
    Original array  : 11  12  13  14  16  17  18
    Zig - Zag array : 11  13  12  16  14  18  17

    Time Complexity : O(n log n), where n is the number of elements.
    Space Complexity : O(1)
*/

