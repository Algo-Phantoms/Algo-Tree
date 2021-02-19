/* 
Kadane's Algorithm is used to solve the maximum subarray sum problem.

The maximum subarray problem is the task of finding the largest 
possible sum of a contiguous subarray.
	
We make three cases in this algorithms.

1 - all the array elements are postive - then complete array 
sum is the largest subarray sum.

2 - all the array elemets are negative - then smallest elements 
is the largest subarray sum.

3 - elements are mix of positive and negative numbers - then we keep adding 
elements in the variable until the variable is positive. We keep track of the
variable value after each addition, so that we know the maximum value it rose to,
that maximum value is our answer. 
*/

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] items = new int[size];

        for (int i = 0;i < size; i++) 
            items[i] = sc.nextInt();

        System.out.print(maximumSubArray(items));
    }

    public static int maximumSubArray(int[] items) {
        int sum = 0;
        int maximumSubArray = items[0];
    
        for (int i : items) {
            sum += i;
            maximumSubArray = Math.max(sum,maximumSubArray);
    
            if (sum < 0) sum = 0;
        }
    
        return maximumSubArray;
    }
}

/*
	Testcase

	Input :

	5
	4 1 -3 7 12

	Output : 21

	Input :

	6
	-1 -4 -5 8 7 9

	Output : 24

	Time complexity : O(n) 
	Space complexity : O(1)

*/
