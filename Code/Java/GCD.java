/*GCD of two number is the largest number by which the given number is divisable

i.e.

if the given two numbers are A(>0) and B(>0) and their GCD is G
then A%G==0 and B%G==0 and G is the Biggest number*/

import java.util.Scanner;

public class EuclideanGCD {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int firstNumber=sc.nextInt();
        int secondNumber=sc.nextInt();
        System.out.println(GCD(firstNumber,secondNumber));
    }
    public static int GCD(int A,int B){
        if(B==0){
            return(A);
        }
        return(GCD(B,(B%A)));
    }
}
/*
    Test Cases:
    Input: 12 16
    Output:4

    Input: 4 1
    Output: 1

    Time Complexity: O(log(max(a,b)))
    Space Complexity: 1
*/
        