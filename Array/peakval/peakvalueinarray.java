package peakval;
import java.util.Scanner;
/*
Here we will Assume Peak element in Array is array[0] i.e 1st value,
then we will compare it with next one, if found grater than peak then
we will change peak to that value
*/
public class peakvalueinarray {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
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
        int peak = arr[0];
        for (int i = 0;i<arr.length;i++){
            if (peak<arr[i]){
                peak = arr[i];
            }
        }
        return peak;
    }
}
/*
    Test Cases:
        Input: 5 8 9 5 2 4
        Output: 9

        Input: 3 0 1 0
        Output: 1

        Time Complexity: O(n)
        Space Complexity: O(1)

 */
