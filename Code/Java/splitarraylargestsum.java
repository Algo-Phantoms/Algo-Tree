/*
-- Split Array Largest Sum --
Given an array nums which consists of non-negative integers and an integer m,
you can split the array into m non-empty continuous subarrays.
Here is an algorithm to minimize the largest sum among these m subarrays in which
Set left to be the largest number in the array. Set right to be the sum of the array.
Then the result should be in the range of [left, right].
Finding the target by using binary search.
*/

package arrayls;
import java.util.Scanner;

public class splitarr {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[] arrr = new int[n];
        System.out.println("Enter "+n+" Elements of array");
        for (int i = 0;i<n;i++){
            arrr[i] = scan.nextInt();
        }
        System.out.println(splitArray(arrr, m));
    }
    public static int splitArray(int[] nums, int m) {
        int n = nums.length;
        int left = 0;
        int right = 0;
        // Here Lest will be incresed Forwards
        //Set left to be the largest number in the array
        //Set right to be the sum of the array.
        for (int i = 0; i < n; ++i) {
            left = Math.max(left, nums[i]);
            right += nums[i];
        }
        // Then the result should be in the range of [left, right].
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (canSplit(nums, mid, m)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    private static boolean canSplit(int[] nums, int target, int m) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            if (sum > target) {
                ++cnt;
                sum = nums[i];
                if (cnt > m) return false;
            }
        }
        return true;
    }
}
/*
    Test Cases:
        Input : 5   // Length of Array
                2   // value of m
                7 2 5 10 8
        Output: 18

        Input : 3   // Length of Array
                3   // value of m
                1 4 4
        Output: 9

        Time Complexity: O(n) where n is length of array
        Space Complexity: O(1)

 */
