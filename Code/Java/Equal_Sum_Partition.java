/* Equal Sum Partition Problem
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets should be same. 
Steps to solve this problem: 
1) Calculate sum of the array entire array. If sum of the array is odd, then there can not be two subsets with equal sum, so return false. 
2) If sum of array the elements is even, calculate sum = sum/2 and find a subset of array with sum equal to sum/2. 
Dynamic Programming Solution (Space Complexity Optimized):
We can solve this problem using a 1D array of size (sum/2 + 1 ) only.*/

import java.util.Scanner;
public class Equal_Sum_Partition {
	    public static boolean canPartition(int arr[], int n) {
		        int sum = 0;
		        // Calculate the sum of array
		        for(int num: arr){
		            sum+=num;
		        }
		        // If sum%2 is odd then return false
		        if(sum%2==1) {
		        	return false;
		        }
		        // If sum is even then find the subsets of sum equal to sum/2
		        sum /= 2;
		        boolean []partition = new boolean[sum+1];
		        partition[0] = true;
		        // Fill the partition table using 
		        // Bottom Up Approach
		        for(int i=1; i<=arr.length; ++i){
		        	
		            for(int j=sum; j>=0; --j){
		            	
		                if(j-arr[i-1] >= 0){
		                	// Check if sum - arr[i-1] could be formed from a subset using elements before index i
		                	partition[j] = partition[j-arr[i-1]] || partition[j];
		                }
		            }
		        }
		        return partition[sum];
		}
		public static void main(String[] args) {
			     Scanner sc = new Scanner(System.in);
			     int n = sc.nextInt();
			     int a[] = new int[n];
			     for (int i = 0; i < n; i++) {
				       a[i] = sc.nextInt();
			     }
			     System.out.println(canPartition(a, n));
			     sc.close();
		}
}
/*
 Sample Test   1:
 Sample Input  1: n = 4,  arr[] = {1, 5, 11, 5}
 Sample Output 1: true 
 The array can be partitioned as {1, 5, 5} and {11}
 
 Sample Test   2:
 Sample Input  2: n = 3,  arr[] = {1, 5, 3}
 Sample Output 2:  false 
 The array cannot be partitioned into equal sum sets.

 Time  Complexity: O( sum*n )
 Space Complexity: O( Sum )
 */


