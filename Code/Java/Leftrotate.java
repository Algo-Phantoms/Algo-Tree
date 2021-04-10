/*
All the Element of Array will shifted left side
& first element on shifting left will goes to end of array as a vacancy will be created
firstly we will take first value of array in a variable then after shifting entire array
we will place that first valur in last vaccant postion of array
*/

package leftrot;
import java.util.Scanner;

public class Leftrotate {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
//Take size of input array
        System.out.println("Enter Size of Arraay");
        int n = scan.nextInt();
        int[] arrr = new int[n];
//Taking Input values for Array
        System.out.println("Enter "+n+" Elements of array");
        for (int i = 0;i<n;i++){
            arrr[i] = scan.nextInt();
        }
//Taking By How much Position You want to Shift Array Leftwards
        System.out.println("By How much Position You want to Shift Array Leftwards :");
        int t = scan.nextInt();
        for (int i = 0;i<t;i++){
            leftrotation(arrr);
        }
//Results Printout
        System.out.println("After Left Rotation of Final Array by "+t+" Positions :");
        for (int i = 0;i<arrr.length;i++){
            System.out.print(arrr[i]+" ");
        }
    }
    public static void leftrotation(int[] arrr){
        int firstval = arrr[0];
        for (int i =0;i<arrr.length-1;i++){
            arrr[i] = arrr[i+1];
        }
        arrr[arrr.length-1] = firstval;
    }
}
/*
    Test Cases:
A.
        Input: 5 
	       8 9 5 2 4 
	       1
       Output: 9 5 2 4 8



B.
        Input: 6 
	       2 4 6 5 8 3 
	       2
       Output: 6 5 8 3 2 4



        Time Complexity: O(n)
        Space Complexity: O(1)

 */
