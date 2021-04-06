/*
Insertion sort is a sorting algorithm.
The array is virtually divided into two sections i.e., a sorted and an unsorted section. 
Values from the unsorted section are picked and placed at the correct 
position in the sorted section.

*/

import java.util.*;
public class Insertion_sort
{
    public static void main(String args[])
    {
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
        for (int a = 1; a < n; a++) 
        {  
            int c = A[a];  
            int b = a-1;  
            while ( (b > -1) && ( A[b] > c ) ) 
            {  
                A[b+1] = A[b];  
                b--;  
            }  
            A[b+1] = c;  
        }
        System.out.println("Sorted array: ");
        for(k=0; k<n; k++)
        {
            System.out.println(A[k]);
        }
    }
}

/*

TEST CASE 1:
INPUT

Enter the array size 
5
Enter the array elements 
25
46
38
96
1

OUTPUT:

Sorted array: 
1
25
38
46
96

TEST CASE 2:
INPUT:

Enter the array size 
8
Enter the array elements 
2
56
1
36
99
1000
85
1 

OUTPUT:

Sorted array: 
1
1
2
36
56
85
99
1000

Time complexity: 

Worst-case: О(n^2) comparisons and swaps
Best-case: O(n) comparisons and O(1) swaps
Average-case: O(n2) comparisons and swaps

Worst-case space complexity: О(n) total, O(1) auxiliary

*/