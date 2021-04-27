// CPP program to find the Union of two unsorted arrays.

/* Procedure 
==================
First of all here we'll initialize an empty set 's'.
then we'll iterate through the first array and put every element of the first array in the set s.
Repeat the process for the second array.
Finally we'll print the set s.
*/

#include <bits/stdc++.h>
using namespace std;
void Union(int a1[], int a2[], int n1, int n2)
{
    set<int> s;
    for (int i = 0; i < n1; i++)
        s.insert(a1[i]);
    for (int i = 0; i < n2; i++)
        s.insert(a2[i]);
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
}
int main()
{
    int a1[100005], a2[1000005], n1, n2, i;
    cout << "Enter the size of both the arrays: ";
    cin >> n1 >> n2;
    cout << "\nEnter the elements of 1st array:";
    for (i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }
    cout << "\nEnter the elements of 2nd array:";
    for (i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }
    cout << "\nUnion of both the arrays:\n";
    Union(a1, a2, n1, n2);
    return 0;
}

/*
Time Complexity: O((n+m) log(n+m))
 where m,n are the sizes of both arrays.
Sample Input output set
==========================
Sample Input 1
----------------
5
6
2 6 9 7 1
1 2 3 4 5 6
Sample Output 
--------------
Enter the size of both the arrays: 
Enter the elements of 1st array:
Enter the elements of 2nd array:
Union of both the arrays:
1 2 3 4 5 6 7 9 

Sample Input 2
---------------
6
6
1 2 3 4 5 6
1 2 3 4 5 6
Sample Output
Enter the size of both the arrays: 
Enter the elements of 1st array:
Enter the elements of 2nd array:
Union of both the arrays:
1 2 3 4 5 6 

Sample Input
1
4
7 
1 2 3 4 
Sample Output
Enter the size of both the arrays: 
Enter the elements of 1st array:
Enter the elements of 2nd array:
Union of both the arrays:
1 2 3 4 7 
*/
