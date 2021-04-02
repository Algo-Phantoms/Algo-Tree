#include <bits/stdc++.h>
using namespace std;

/*
Approach :
Exclude the first element, swap the remaining elements in pairs.
As - keep a[0], swap a[1] and a[2], swap a[3] and a[4], and so on.
*/

void zigzag(int a[], int n)
{
    for(int i=1 ; i<n ; i+=2)
    {
        if(i < n-1)
            swap(a[i], a[i+1]);
    }

    cout<<"\nZig - Zag array : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}

int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<"Original array  : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    zigzag(a, n);

    return 0;
}

/*
    Test Case -

    Output :

    Original array  : 4  3  7  8  6  2  1
    Zig - Zag array : 4  7  3  6  8  1  2

    Time Complexity : O(n)
    Space Complexity : O(1)

    If we want a sorted data we can first sort the array
    using sort() and then call the zigzag() function.
*/
