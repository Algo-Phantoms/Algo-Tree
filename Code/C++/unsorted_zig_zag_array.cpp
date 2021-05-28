/*
Approach : Swap pairs of elements except the first element.
As - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
So, we will take array and its size as parameters, run a loop from i to size of the array 
and swap every pair of element using swap function. At the end of loop, we will print the array.
*/

#include <bits/stdc++.h>
using namespace std;

//helper function that converts given array in zig-zag form
void zigzag(int a[], int n)
{
    for(int i = 1 ; i < n ; i += 2)
    {
        if(i < n-1)
            swap(a[i], a[i+1]);
    }

    cout << "\nZig - Zag array : ";
    for(int i=0 ; i < n ; i++)
        cout << a[i] << "  ";
}

int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Original array  : ";
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << "  ";

    zigzag(a, n);

    return 0;
}

/*
    Test Case -

    Sample Input/Output (1):
    Original array  : 4  3  7  8  6  2  1
    Zig - Zag array : 4  7  3  6  8  1  2
    
    Sample Input/Output (2):
    Original array  : 14  13  17  18  16  12  11
    Zig - Zag array : 14  17  13  16  18  11  12

    Time Complexity : O(n) , where n is the number of elements.
    Space Complexity : O(1)

    If we want a sorted data we can first sort the array
    using sort() and then call the zigzag() function.
*/
