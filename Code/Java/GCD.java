import java.util.Scanner; //importing scanner class for reading input from user

public class GCD {

    public static void main(String[] args) {

        int num1, num2, gcd = 0;

        // Lets read the two inputs from the user
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the First Number: ");
        num1 = sc.nextInt();
        System.out.print("Enter the Second Number: ");
        num2 = sc.nextInt();
        sc.close();  //Close the Scanner Object after reading input

        /*
         * If the user inputs a negative number We have to convert it to positive number
         * As GCD exists for positive numbers only
         */
        num1 = (num1 > 0) ? num1 : -num1;
        num2 = (num2 > 0) ? num2 : -num2;

        /*
         * We have to find the smaller number from the given inputs Here the loop will
         * run from 1 to samller number
         */
        if (num2 > num1) {

            /*
             * loop is running from 1 to the smallest of both numbers In this example the
             * loop will run from 1 to num1 because num1 is the smaller number. All the
             * numbers from 1 to num1 will be checked. A number that perfectly divides both
             * numbers would be stored in variable "gcd". By doing this, at the end, the
             * variable gcd will have the largest number that divides both numbers without
             * remainder.
             */

            for (int i = 1; i <= num1; i++) {
                if (num1 % i == 0 && num2 % i == 0)
                    gcd = i;
            }

        }

        else {

            /*
             * loop is running from 1 to the smallest of both numbers In this example the
             * loop will run from 1 to num2 because num2 is the smaller number. All the
             * numbers from 1 to num2 will be checked. A number that perfectly divides both
             * numbers would be stored in variable "gcd". By doing this, at the end, the
             * variable gcd will have the largest number that divides both numbers without
             * remainder.
             */

            for (int i = 1; i <= num2; i++) {
                if (num1 % i == 0 && num2 % i == 0)
                    gcd = i;
            }
        }

        System.out.printf("GCD of %d and %d is: %d", num1, num2, gcd);
    }

}


/*   TEST CASES

Enter the First Number: -5                                                                                                                    
Enter the Second Number: 50                                                                                                                   
GCD of 5 and 50 is: 5  


Enter the First Number: 100                                                                                                                   
Enter the Second Number: 10000                                                                                                                
GCD of 100 and 10000 is: 100                                                                                                                  
  
Enter the First Number: 100                                                                                                                   
Enter the Second Number: 10000                                                                                                                
GCD of 100 and 10000 is: 100                                                                                                                  
                             

*/
