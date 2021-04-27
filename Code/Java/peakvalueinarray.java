/*
An array element is a peak if it is NOT smaller than
its neighbours. For corner elements, we need to
consider only one neighbour.
Here we will Assume Peak element in Array is -11 i.e if peak elemwnt dosent exists then will retuen -1,
then by Liner Search, we will compare (i) with (i+1) & (i-1), if found greater than both the Neighbouring Elemnts
then it will retuen that Element.
*/

package peakval;
import java.util.Scanner;

public class peakvalueinarray {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Array");
        int n = scan.nextInt();
        if (n>0) {
            System.out.println("Enter " + n + " Elements of array");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
            }
            int ans = peakval(arr);
            System.out.println();
            System.out.println("Peak Value in Array is : " + ans);
        }else {
            System.out.println("Enter Valid Length of Array");
        }
    }
    public static int peakval(int[] arr){
        if (arr.length >=2){
            if(arr[0]>arr[1]){
                return arr[0];
            }
        }
        int peak = -1;
        for (int i = 1;i<arr.length-1;i++){
            if (arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                peak = arr[i];
                return peak;
            }
        }
        if (arr.length >=2){
            if(arr[arr.length-1]>arr[arr.length-2]){
                return arr[arr.length-1];
            }
        }
        return peak;
    }
}
/*
    Test Cases:
        Input : 5
	        8 9 5 2 4
        Output: 9

        Input : 3
		0 1 0
        Output: 1

        Time Complexity: O(n)
        Space Complexity: O(1)
 */
