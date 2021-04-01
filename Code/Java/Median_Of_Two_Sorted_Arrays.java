/* Start partitioning the two arrays into two groups of halves (not two parts, but both partitioned should have same number of elements).
   The first half contains some first elements from the first and the second arrays, and the second half contains the rest (or the last)
   elements form the first and the second arrays. Because the arrays can be of different sizes, it does not mean to take every half from each array. 
   Reach a condition such that, every element in the first half is less than or equal to every element in the second half.
 */
package medianoftwosortedarrays;

import java.util.Scanner;

class Median_Of_Two_Sorted_Arrays{
     
   // Function to find maximum
       public static int maximum(int a, int b) 
       {
              return a > b ? a : b; 
        }     
   
   // Function to find median of given two sorted arrays
      public static int findMedianSortedArrays(int []a,int n,int []b, int m)
      {
          int min_index = 0, 
          max_index = n, i, j;
       
       while (min_index <= max_index)
       {
          i = (min_index + max_index) / 2;
          j = ((n + m + 1) / 2) - i;
       
   // If i = n, it means that Elements from a[] in the second half is an empty set. If j = 0, it means that Elements from b[] in the first half is an empty set. so it is necessary to check that,because we compare elements from these two groups. searching on right.
        if (i < n && j > 0 && b[j - 1] > a[i])     
            min_index = i + 1;     
            
   // If i = 0, it means that Elements from a[] in the first half is an empty set and if j = m, it means that Elements from b[] in the second half is an empty set.so it is necessary to check that, because we compare elements from these two groups. searching on left.
        else if (i > 0 && j < m && 
                 b[j] < a[i - 1])     
            max_index = i - 1;     
           
   // We have found the desired halves.
        else
        {
             
  // This condition happens when we don't have any elements in the first half from a[] so we are returning the last element in b[] from the first half.
            if (i == 0)         
                return b[j - 1];         
               
  // And this condition happens when we don't have any elements in the first half from b[] so we returning the last element in a[] from the first half.
            if (j == 0)         
                return a[i - 1];         
            else       
                return maximum(a[i - 1], b[j - 1]);         
          }
        }
       
         System.out.print("ERROR!!! " + "returning\n"); 
        return 0;
    }     
   
    public static void main(String[] args) 
    {   
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number of elements in first array : ");
        int n = sc.nextInt();
        
        int[] a; 
        a = new int[n];
        for(int i = 0;i<n;i++) {
            a[i] = sc.nextInt();
          }
        
        System.out.println("Enter the Number of elements in Second array : ");
        int m = sc.nextInt();
        
        int[] b; 
        b = new int[m];
        for(int i = 0;i<m;i++) {
            b[i] = sc.nextInt();
          }
   
     // We need to define the smaller array as the first parameter to make sure that the time complexity will be O(log(min(n,m)))
        if (n < m) {
           System.out.print("The median is: " + findMedianSortedArrays(a, n, b, m));
        } else {
           System.out.print("The median is: " + findMedianSortedArrays(b, m, a, n));
        }
    
    }
} 

/*Test Cases
Input : Enter the Number of elements in first array : 
        5
        1
        2
        3
        4
        5
       Enter the Number of elements in Second array : 
        3
        6
        7
        8
Output : The median is: 4
Input : Enter the Number of elements in first array : 
        3
        6
        7
        8
        Enter the Number of elements in Second array : 
        4
        1
        2
        3
        4
Output : The median is: 4

Time and Space Complexity
Time Complexity : O(log(min(n, m))), where n and m are the sizes of given sorted array
Space Complexity : O(1)
*/
 