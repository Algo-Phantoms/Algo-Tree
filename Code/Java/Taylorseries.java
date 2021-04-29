/*
Here for Finding sum of Taylor Series of e^x, we Create 2 functions, one for
calculating factorial [factorial(x)] with help of recursion to make good time & Space Complexity
and other [ex(x,n)] for calculating value of Taylor Series.
 */

package taylor;
import java.util.Scanner;

public class Taylorseries {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Value of x :");
        int x = scan.nextInt();
        System.out.println("Enter Value of n :");
        int n = scan.nextInt();
        int ans = ex(x,n);
        System.out.println("Value of Taylor Series of e^x is : "+ans);
    }
    public static int ex(int x, int n){
        int ans = 1;
        for (int i = 1;i<=(n-1);i++){
            ans += (x/factorial(i));
        }
        return ans;
    }
    public static int factorial(int x){
        if (x == 0){
            return 1;
        }else {
            return (x*factorial(x-1));
        }
    }
}
/*
    Test Cases:
        Input: 7 8
        Output: 12

        Input: 3 25
        Output: 5

        Time Complexity: O(n)
        Space Complexity: O(1)
 */
