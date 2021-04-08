/*
Question:

Implement the next permutation, which rearranges the list of numbers into Lexicographically 
next greater permutation of list of numbers. 
If such arrangement is not possible, 
it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 

Approach:

1. Find the largest index k from the right such that a[k] > a[k - 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k - 1] < a[l].
3. Swap the value of a[k - 1] with that of a[l].
4. Reverse the sequence from a[k] up to and including the final element a[n].
5. Finally print the resultant array.

*/
// Code in C++


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;              //size of an array
    cin>>n;
    vector<int> a(n);   //given array
    for(int i=0;i<n;i++) cin>>a[i];     //input an array
    int idx = -1;                       // initialising index as -1
        for(int i=n-1;i>0;i--){
            if(a[i]>a[i-1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){                    //check if array is sorted in descending order
            reverse(a.begin(),a.end()); //if true then reverse the array
        }
        else{
            int prev = idx;
            for(int i=idx+1;i<n;i++){
                if(a[i]>a[idx-1] and a[i]<=a[prev]){
                    prev = i;
                }
            }
            swap(a[idx-1],a[prev]);
            reverse(a.begin()+idx,a.end());
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";       //printing the resultant array

    return 0;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)

Test Case:

Input 1:
6
1 2 3 6 5 4

Output 1:
1 2 4 3 5 6


Input 2:
3
3 2 1

Output 2:
1 2 3

*/