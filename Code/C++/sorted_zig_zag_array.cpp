#include <bits/stdc++.h>
using namespace std;

/*
Approach :
Sort the array first then,
Exclude the first element, swap the remaining elements in pairs.
As - keep a[0], swap a[1] and a[2], swap a[3] and a[4], and so on.
*/

void zigzag(int a[] , int n)
{
    for(int i=1 ; i<n ; i+=2)
    {
        if(i+1 < n)
            swap(a[i] , a[i+1]);
    }

    cout<<"\nZig - Zag array : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}

int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a , a+n);

    cout<<"Original array  : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    zigzag(a , n);

    return 0;
}

/*
    Test Case -

    Output :

    Original array  : 1  2  3  4  6  7  8
    Zig - Zag array : 1  3  2  6  4  8  7

    Time Complexity : O(n log n)
    Space Complexity : O(1)

    If we want a sorted data we can first sort the array
    using sort() and then call the zigzag() function.
*/

