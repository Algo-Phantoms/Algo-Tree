/*Algorithm to find the maximum element for each and every contiguous subarray of size k for a given array

The idea is to maintain a sorted list of elements with the help of a dequeue,
such that the front of the dequeue contains the maximum element of the current window at all times
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maximumSlidingWindow(vector<int> &arr, int k, int n)
{
    deque<int> dq;
    vector<int> ans;

    /* Every time the window shifts, we need to do 3 things,
       1) Remove the element which is out of the current window
          If present, it is guaranteed that it will be at the front of the dequeue
       2) If the new element being added is larger than the rearmost element of the dequeue,
          then keep popping elements from the back, until we encounter a greater element or the dequeue become empty
       3) Now push the new element to the back of the dequeue
       4) Update the answer vector
    */

    for(int i=0;i<n;i++)
    {
        if(i>=k && dq.front()== arr[i-k])
        {
            dq.pop_front();
        }

        while(!dq.empty() && arr[i]>dq.back())
        {
            dq.pop_back();
        }
        dq.push_back(arr[i]);

        if(i>=k-1)
        {
            ans.push_back(dq.front());
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> ans= maximumSlidingWindow(arr, k, n);
    for(int i=0;i<=n-k;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

/* Test Case 1:
   n= 4, k= 3
   arr= [2, 8, 0, 1]
   ans= [8, 8]

   Test Case 2:
   n= 8, k= 3
   arr = [1,3,-1,-3,5,3,6,7]
   ans=  [3,3,5,5,6,7]

   Time Complexity:  O(n)
   Space Complexity: O(k) {Since we maintain a dequeue of size at most k at all times}
*/
