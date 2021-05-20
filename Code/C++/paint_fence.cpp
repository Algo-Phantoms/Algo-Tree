/*
Problem statement:
Given a fence with n posts and k colors , find out the number of ways of painting the fence
such that atmost 2 adjacent posts have the same color.
Suppose we have a single post, The number of ways of painting the fence with k colors is k
Now we consider 2 posts, Then the number of ways of painting the second fence with the same
color as the first post is k, and the number of ways of painting the second post with a different
color is k*(k-1) as we have k-1 colors that are different from the first post's color.
So the total number of ways of painting 2 fences is k*(k-1) + k. Now we consider 3 posts,
Then the number of ways of painting the third fence same as the second fence is the number of
ways of painting the second fence with a different color that is k*(k-1). The number of ways of
painting the third fence using a different color is equal to the total number of ways of
painting the second fence * (k-1). Hence the total number of ways of painting 3 fences is k*(k-1) + (k+k*(k-1))*(k-1).
This way we can find the total number of ways of painting n fences
*/

#include <bits/stdc++.h>

using namespace std;
unsigned long long MOD = 1000000007;
//paintfence function uses permutations to find the number of ways of painting fences
unsigned long long paintfence(int n, int k)
{
    unsigned long long total, diff, same;
    same = k;
    diff = k * (k - 1);
    total = k * k;
    for (int i = 1; i < n - 1; i++)
    {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total%MOD;
}

int main()
{
    int n, k;
    cout << "Enter the number of posts" << endl;
    cin >> n;
    cout << "Enter the number of colors" << endl;
    cin >> k;
    cout << "The number of ways of painting the fence is : " << paintfence(n, k) << endl;
    return 0;
}

/*
Sample I/O:
Enter the number of posts
2
Enter the number of colors
4
The number of ways of painting the fence is : 16

Enter the number of posts
3
Enter the number of colors
2
The number of ways of painting the fence is : 6

Complexity Analysis
Time complexity - O(n)
Space complexity - O(1), where n is the number of posts
*/
