//Cpp program for Sliding Window Maximum.
/*
         Approach
         ========
               The basic Approach is to use a deque (b) to save all currently "maximum" elements.
               
               1. So for each i,we first pop up the elements that are no larger than (vector) v[i].
               2. From b until we find one that is larger than v[i] or the b is empty since those elements
                  will be covered by v[i] and can not be a maximum of any k-element window. 
               3. Then we put v[i] in the b.
               4. If i>=k-1, we need to ouput the maximum for window [i-k+1, i], 
                  which is the front element of b.
               5. We will check if the front element is v[i-k+1],
               6. If so, we have to pop it up since it will be out of the
                  window [i-k+2, i+1] in the next iteration.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    deque<int> b;
    vector<int> r;
    int n, m, i, k;
    cout << "\nEnter the size of the array(N) and value of K(size of window):";
    cin >> n >> k;
    cout << "\nEnter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }
    for (auto i = 0; i < v.size(); ++i)
    {
        while (!b.empty() && v[i] >= v[b.back()])
            b.pop_back();
        b.push_back(i);
        if (i >= k - 1)
            r.push_back(v[b.front()]);
        if (b.front() <= i - k + 1)
            b.pop_front();
    }
    cout << "\nThe resultant array : ";
    for (auto i = 0; i < r.size(); ++i)
    {
        cout << r[i] << " ";
    }
    return 0;
}
/*
           Time complexity is O(N).
           Space Complexity is O(N).
           
           Sample Input/Output
           
           Sample Input 1:
               8 3
               1 3 -1 -3 5 3 6 7 
           Sample Output 1:
               Enter the size of the array(N) and value of K(size of window):
               Enter the elements of the array:
               The resultant array : 3 3 5 5 6 7 
               
           Sample Input 2:
               8 4
               1 3 -1 -3 5 3 6 7 
           Sample Output 2:
               Enter the size of the array(N) and value of K(size of window):
               Enter the elements of the array:
               The resultant array : 3 5 5 6 7 
               
           Sample Input 3:
               8 3
               3 4 2 4 5 6 7 8 
           Sample Output 3:
               Enter the size of the array(N) and value of K(size of window):
               Enter the elements of the array:
               The resultant array : 4 4 5 6 7 8
               
*/
