/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ?if present find all unique triplets in the array which gives the sum of zero.

Following is the C++ implementation of the code

*/

#include<bits/stdc++.h>
using namespace std;

void threeSum(vector<int>& nums) {

//if size of array is less than 3 then we can return null
if(nums.size() < 3) {cout<<"No elements found"<<endl; return;}
//lets take a 2D vector to return the unique pairs
vector<vector<int>> ret;
//sort the array of numbers so that we can use 2 pointers to find pairs
sort(nums.begin(),nums.end());

for(int i=0;i<nums.size()-1;++i){
//to avoid duplicates
if(i>0 && nums[i] == nums[i-1]) continue;
//so our target sum to find  will be -nums[i].Lets find a pair that sums to -nums[i] from i+1 to nums.size()-1 since the array is sorted
int tar = 0 - nums[i],hi=nums.size()-1,lo=i+1;

while(hi>lo){
    int summ = nums[hi]+nums[lo];
    //if summ is greater than target we need to decrease the sum by shifting right pointer hi towards left
    if(summ > tar)
        hi--;
        //if summ is smaller than target we need to increase the sum i.e shifting left pointer lo towards right
    else if(summ < tar)
        lo++;
        //if summ is equal to target push the pair into result vector.
    else{
        ret.push_back({nums[i],nums[lo],nums[hi]});
        lo++,hi--;
        while(hi>lo && nums[hi]==nums[hi+1]) hi--;
        while(hi>lo && nums[lo]==nums[lo-1]) lo++;
    }
  }
}
  //if size of ret vector is 0 then their is no such pair
  if(ret.size()==0) {cout<<"No such pairs exist"<<endl; return;}
  //print the result
  cout<<"Unique triplets are:"<<endl;
    for(int i=0;i<ret.size();i++)
    {
      for(auto s:ret[i])
      cout<<s<<" ";
      cout<<endl;
    }

 }

int main()
{
  int n;
  cout<<"Enter number of elements in array"<<endl;
  cin>>n;
  vector<int>nums(n);
  cout<<"enter the elements of the array"<<endl;
  for(int i=0;i<n;i++)
  {
  cin>>nums[i];
  }
  threeSum(nums);

}



/*
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
as Unique triplets : -1+-1+2=0 and -1+0+1=0

Example 2:
Input : nums=[1,-1,3] 
output: No such triplets exist 

Example 3:
Input: nums=[1,-1] 
Output: No such elements found


Complexity Analysis:
Time complexity: O(N^2).
There are only two nested loops traversing the array, so time complexity is O(n^2). Two pointers algorithm takes O(n) time and the first element can be fixed using another nested traversal.
Space Complexity: O(1).
As no extra space is required.

*/
