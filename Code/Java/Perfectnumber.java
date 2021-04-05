/*Problem Statement:Given a number,check whether the given number is perfect number or not .

A number is said to be a perfect number if sum of its proper divisors(excluding the number itself) is equal to the number.*/

//Solution:

import java.util.Scanner;
public class Perfectnumber{ 
    public static void main(String[] args){
        int number;
        int sum=1;//sum is intialized to 1 because  sum will store sum of all proper divisors  and 1 is a proper divisor of all numbers.
         System.out.println("Enter a number:");
        //Use Scanner class for  getting input from the user.
         Scanner sc=new Scanner(System.in);
        number= sc.nextInt();
  //Loop through numbers from 2 to number to check a number is  divisor or not 
        for(int i=2;i*i<number;i++){
            if(number%i==0){
                if(i*i==number){ // If number is a perfect square then we need to add only once because we need proper divisors
                    sum=sum+i;
                }
                else{
                    sum+=i+number/i;
                }
            }
        }
//If sum of divisors is equal to the entered number then the entered number is a perfect number 
        if(sum==number){
            System.out.println( number + " is a perfect number");
        }
        else{
            System.out.println(number+ " is not a perfect number");
        }
    }
    
}


/*

TimeComplexity:O(n^1/2)

Space Complexity:O(1)

Example1: 
  Input:
  Enter a number:15
  Output: 15 is not a perfect square .
Explanation: 1,3,5 are the proper divisors of 15.Sum of properdivisors=1+3+5=9;
             Sum is not equal to 15 .So 15 is not a perfect number.

Example2:
  Input:
  Enter a number: 6
  Output: 6 is a perfect number
Expalnation: 1,2,3 are proper divisors of 6. Sum of proper divisors =1+2+3=6;
             Sum is equal to entered number(6). So 6 is a perfect number.
*/