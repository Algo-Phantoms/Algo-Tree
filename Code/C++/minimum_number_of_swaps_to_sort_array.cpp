/*

Here we have to sort the array with minimum swaps but here we are going to do the reverse thing i.e
Here we will be storing the elements along with their index in a vector of pairs.
Then we will sort the vector.
And now we will be converting this Sorted vector to our previous array using minimum swaps.
For Video Explaination you can follow my video https://youtu.be/1BxbBgNSwHo , here I have explained in detail.
You can refer the below Code for better understanding

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // size of array
    int n;
    cin>>n;
    // input array
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // vector of pairs for storing array elements with their indexes
    vector<pair<int,int> > swap_array;
    for(int i=0;i<n;i++) swap_array.push_back({arr[i],i});

    sort(swap_array.begin(),swap_array.end());
    int counter_of_swaps = 0;

    for(int i=0;i<n;i++){
        if(swap_array[i].second == i)
            continue;
        else{
            counter_of_swaps++;
            swap(swap_array[i],swap_array[swap_array[i].second]);
            i--;
        }
    }

    cout<<counter_of_swaps;


    return 0;
}
/*
Testcase 1:

Input:
5
1 5 4 3 2

Output:
2

Testcase 2:

Input:
5
5 4 3 2 1

Output:
2

Time Complexity--> O(NLogN) where N = size of the array
Space Complexity--> O(N) where N = size of the array
*/