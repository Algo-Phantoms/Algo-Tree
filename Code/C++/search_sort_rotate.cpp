/*
here it is given a sorted and rotated array and it has array arr and N distact elements which is rotated at point  and here it is given an
element target.We have to find index of given element target in the array arr.
 
 explanation:
 original array: [ 1, 3 ,5 ,15, 21, 23]
 sorted and rotated array: [15, 21, 23, 1, 2 ,3]
 Given the array numbers after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Following is The Core Implementation of search and rotate array:-

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //for binary search we need to devide array in two parts 
        //eg for n = [4,5,6,7,0,1,2], target = 1 arr = F F F F F T T
        //we need to return first true;
        //conditions used such that first T will be given number:
        // if given > n[0] T if num < n[0] or num >= given
        // if given < n[0] T if num >= given and num <= n[0]
        int n = nums.size()-1;
        int hi = n, lo = 0;
        int mid;
        if(nums[0] == target) return 0;
        while(lo < hi){
            mid = lo + (hi - lo)/2;   //lower mid 
            if(target > nums[0]){
                if(nums[mid] < nums[0] || nums[mid] >= target){
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            else{
                if(nums[mid] < nums[0] && nums[mid] >= target){
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
        }
        if(nums[lo] == target)return lo;
        else return -1;
    }
};

/*
sample test case 
TEST CASE:
input 1
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [15, 21,23 ,1 ,2, 5], target = 21
Output: 1

runtime=4ms
Time Complexity: O(log n)
* Space Complexity: O(log n)
*/