/*
Find all unique prime factors of any number n where (n>1) for example if n is 20 then output will be (2,5).
Firstly we will check from i = 2 to  n whether that i is a factor of n or not ?
if i is a factor of n then we check it is prime or not using isPrime Method in Java which return boolean type output
*/

package bhagwat;
import java.util.Scanner;

public class Uniquefactor {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Number : ");
        int n = scan.nextInt();
        System.out.println();
        System.out.println("Unique Prime Factors of "+n+" are :");
        for (int i = 2;i<=n;i++){
            if (n%i == 0 && isPrime(i)){
                System.out.print(i+" ");
            }
        }
    }
    public static boolean isPrime(int n){
        if (n == 2){
            return true;
        }
        if (n>2) {
            for (int i = 2; i < n; i++) {
                if (n % i == 0) {
                    return false;
                }
            }
        }else {
            return false;
        }
        return true;
    }
}
/*
    Test Cases:
        Input: 10
        Output: 2 5

        Input: 48
        Output: 2 3

        Time Complexity: O(n)
        Space Complexity: O(1)
 */