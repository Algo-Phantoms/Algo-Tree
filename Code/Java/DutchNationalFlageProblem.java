/* Dutch National Flag Algorithm is used for sort the elements in an array when there are only three type of elemnts are present in the array, this is a very efficient algorithm using this algorithm we can sort our array in O(N) with only one pass.*/

/*Problem Statement :
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Apply Dutch National Flag algorithm
	  use only one pass
	        T.C O(N)
	        S.C O(1)
*/
import java.util.Scanner;

public class DutchFlageAlgo {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of array \n");
		// no. of elements in an array
		int n = sc.nextInt(); 
		int[] arr = new int[n];
		// put the elements in an array
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
        //call the method
		sortColors(arr);
	}
	    public static void sortColors(int[] nums) {
	     
	
	     int lo = 0, mid = 0, hi = nums.length - 1;
	        
	        while(mid <= hi){
	            switch(nums[mid]){
	                case 0:{
	                    int temp = nums[mid];
	                    nums[mid] = nums[lo];
	                    nums[lo]  = temp;
	                    mid++;
	                    lo++;
	                    break;
	                }
	                    
	                case 1:{
	                    mid++;
	                    break;
	                }
	                
	                case 2:{
	                    int temp = nums[mid];
	                    nums[mid] = nums[hi];
	                    nums[hi]  = temp;
	                    hi--;
	                    break;
	                }     
	            }
	        }
	           for(int arr : nums)
	           System.out.print(arr +" ");  
	      
	    }
	}


/*
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.

Sample Test Cases:

Test case 1:
Input- [2,0,1,0,1]
Output - [0,0,1,1,2]

Test case 2:
Input - [1,1,0]
Output - [0,1,1]

Test Case 3:
Input - [0]
Output - [0]
*/


	

