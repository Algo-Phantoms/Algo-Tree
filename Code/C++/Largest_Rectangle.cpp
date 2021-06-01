/*Here, we consider each bar has a unit width. We will use a notion of a Rectangle for each bar and two indices j and k. For each bar, we can find the rectangle with the height of it and also containing it.
To do this for a bar, let's say i bar, we go to left from i and stop at the first bar which is smaller than the i bar. Say we have stopped at j position. 

Time Complexity: For each bar we are considering a linear search. Thus it is O(n^2) in total.

Here, we use Divide and Conquer Approach.*/

#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

#define pb push_back


vector < lli > height;
vector < int > s;
lli Histogram(vector<lli> &height)
{
    s.clear();
    height.push_back(0);

    lli sum = 0;
    int i = 0;
    while(i < height.size())
    {
        if(s.empty() || height[i] > height[s.back()])
        {
            s.push_back(i);
            i++;
        }
        else
        {
            int t = s.back();
            s.pop_back();

            sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
        }
    }

    return sum;
}

int main(void)
{
    int i,j,k,kase=0;

    int n;
    while( scanf("%d",&n)==1 )
    {
        height.assign(n, 0);
        for(i=0; i<n; i++) scanf("%lld",&height[i]);
        printf("%lld\n",Histogram(height));
    }
    return 0;
}


/* _Test Case 1:_                                      
    Input:  5                                            
            1 2 3 4 5                                          
    
    Output: 9                                           
    
    _Test Case 2:_
    Input: 10
           6320 6020 6098 1332 7263 672 9472 2838 3401 9494
           
    Output: 18060
Time Complexcity:  O(n)
Space Complexcity:  O(n) 
*/
