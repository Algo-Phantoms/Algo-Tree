/*

This is a theoretical computer science problem.
There are n people in a circle waiting to be executed.
Starting from any position, a person starts executing the k'th person ahead of him, 
then the person after the one who is executed repeats the same task, 
as there will be only one person surviving, we have to find the person who will remain alive.

*/

#include <iostream>
#include <vector>
using namespace std;

void josephus(vector<int> &v, int k, int idx, int &ans)
{
    if (v.size() == 1)
    { // only one person will be left, which is the answer
        ans = v[0];
        return;
    }

    idx = (idx + k - 1) % v.size();
    v.erase(v.begin() + idx);
    josephus(v, k, idx, ans);
}

int main()
{
    // use vector, if persons are not listed from 1 to n
    vector<int> lst;
    int n, k, ans = 0;
    cin >> n >> k;
    lst.reserve(n);
    for (int i = 0; i < n; i++)
    {
        lst.push_back(i + 1);
    }
    // lst = {1,2,3,4,..,n}
    josephus(lst, k, 0, ans);
    cout << ans << endl;
    return 0;
}

/*

Test Case:

Input: 3 2
Output: 3

Input: 4 6
Output: 3

Input: 32 32
Output: 27

Time Complexity: O(n)
Space Complexity: O(n)

*/
