/*
Prime Numbers are those who dont's have any divisors other than 1 and itself,
so, the number (n) which has any divisors in between 2 and (n-1) is not Prime Number
so, firstly consider special case of 2 (2 is the only even prime)
then, all other even No. except 2  as Not Prime
Thus, we will check from 3 to (n-1) (all odd No. )for reminder to be 0, if reminder comes 0 at any one position
so that will not be prime No. if not at any single position then it will reach upto end of isPrime Method & will be prime.
 */
package primeno;
import java.util.Scanner;

public class CheckPrime {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter No : ");
        int n = scan.nextInt();
        System.out.println(isPrime(n));
    }
    public static boolean isPrime(int n) {
        if (n == 2){
            return true;
        } else if (n%2==0){
            return false;
        }else if (n<=1){
            return false;
        }
        for (int i =3 ;i<Math.sqrt(n) ; i+=2){
            if (n%i==0){
                return false;
            }
        }
        return true;
    }
}
/*
    Test Cases:
        Input: 5
        Output: true

        Input: 6
        Output: false

        One Exception : 2 is the only even prime (Taken Special case)
        Input: 2
        Output: true

        Time Complexity: O(n)
        Space Complexity: O(1)
 */