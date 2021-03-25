/*
         
         Longest Increasing Subsequence

A longest increasing subsequence (LIS) is obtained from a sequence, 
has elements in increasing order, and as long as possible. 
The LIS does not necessarily have to be contiguous or unique, 
one sequence may have multiple increasing subsequences.

*/
import java.util.*;
public class longest_increasing_subsequence {
    static int incre_subseq(int my_arr[], int arr_len) {
        int seq_arr[] = new int[arr_len];
        int i, j, max = 0;
        for (i = 0; i < arr_len; i++)
            seq_arr[i] = 1;
        for (i = 1; i < arr_len; i++)
            for (j = 0; j < i; j++)
                if (my_arr[i] > my_arr[j] && seq_arr[i] < seq_arr[j] + 1)
                    seq_arr[i] = seq_arr[j] + 1;
        for (i = 0; i < arr_len; i++)
            if (max < seq_arr[i])
                max = seq_arr[i];
                
        return max;
    }

    public static void main(String args[]) {
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter number of elements :");
        int n=scan.nextInt();
        int my_arr[]=new int[n];
        for(int i=0;i<n;i++){
            my_arr[i]=scan.nextInt();
        }
        int arr_len = my_arr.length;
        System.out.println("The length of the longest increasing subsequence is " + 
        incre_subseq(my_arr, arr_len));
        scan.close();
    }
}

/*
Test Case 1:

Input :[3, 10, 2, 1, 20]
Output : Length of LIS = 3

Test Case 2:

Input :[50, 3, 10, 7, 40, 80]
Output : Length of LIS = 4

 Time Complexity is O(n^2) , n is the number of elements in the list.
 Space Complexity is O(n) , n is the number of elements in the list.
*/