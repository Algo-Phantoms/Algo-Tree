/*
Find the Dublicate in the array.
Here we will transverse all element of array in first start upto end.
For every element,take its absolute value and if the abs(array[i])‘th element
is positive, the element has not encountered before, else if negative the
element has been encountered before print the absolute value of the
current element.
*/
package array_dublicate;
import java.util.Scanner;

public class Dublicate_array {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Length of Array");
        int n = scan.nextInt();
        int[] arr = new int[n];
        for (int i = 0 ; i < n ; i++){
            arr[i] = scan.nextInt();
        }
        System.out.println("The Dublicate Elemnts are :");
        dublicate(arr);
    }
    public static void dublicate(int[] arr){
        int len = arr.length;
        for (int i = 0; i < len; i++) {
            int j = Math.abs(arr[i]);
            if (arr[j] >= 0) {
                arr[j] = -arr[j];
            }else {
                System.out.print(j + " ");
            }
        }
    }
}
/*
    Test Cases :
        Input: 5
               1 2 2 3 1
        Output:2 1

        Input: 6
               2 2 1 4 4 6
        Output:4 2

        Time Complexity: O(n) where n is the size of Array
        Space Complexity: O(1)
 */