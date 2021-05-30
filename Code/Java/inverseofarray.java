/*
---------------- INVERSE OF AN ARRAY ----------------------
If the array elements are swapped with their corresponding indices,
then the array finally results is called as inverse of an array.
*/

package peakval;
import java.util.Scanner;

public class peakvalueinarray {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
        int n = scan.nextInt();
        int[] arr = new int[n];
        // Taking Array Elements
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        inversearrray(arr);
    }
    
    public static void inversearrray(int[] arr){
        int[] ans = new int[arr.length];
        for (int i = 0; i<arr.length; i++){
            ans[arr[i]] = i;
        }
        
        for (int i = 0; i<ans.length; i++){
            System.out.print(ans[i]+" ");
        }
    }
}
/*
    Test Cases:
        Input : 5
                4 0 2 3 1
        Output: 1 4 2 3 0

        Input : 3
                2 0 1
        Output: 1 2 0

        Time Complexity: O(n) where n is Length of Array
        Space Complexity: O(1)


 */
