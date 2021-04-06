/*
Kandane's algorithm is used to find the maximum subarray sum.

Given an array of n numbers. We have to calculate the maximum subarray sum i.e., 
the largest possible sum of a sequence of consecutive values in the given array.

The array can consist of positive as well as negative elements.
*/

import java.util.*;
public class Kandane_algorithm
{
    int maximum_number(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    public static void main(String args[])
    {
        int sum = 0;
        int largest_sum = 0;
        int k = 0;
        int n=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the array size ");
        n = sc.nextInt();
        int A[] = new int [n];
        System.out.println("Enter the array elements ");
        for(k=0;k<n;k++)
        {
            A[k]=sc.nextInt();
        }
        Kandane_algorithm obj = new Kandane_algorithm();
        for(k=0;k<n;k++)
        {
            sum = obj.maximum_number(A[k], sum+A[k]);
            largest_sum = obj.maximum_number(largest_sum, sum);
        }
        System.out.println("Largest sum = "+largest_sum);
    }
}

/*
Test case 1:
INPUT: 

Enter the array size 
8
Enter the array elements 
-6
8
9
-1
5
6
-6
2

OUTPUT:
Largest sum = 27

Test case 2:
INPUT:

Enter the array size 
5
Enter the array elements 
2
-3
0
5
9

OUTPUT:
Largest sum = 14
*/

/*

Time complexity: O(n)
Space complexity: O(1)

*/