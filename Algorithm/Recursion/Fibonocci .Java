/*The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..  */

//In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 


import java.util.*;
  
  public class Main{
  
  public static void main(String[] args) {
      // write your code here
      Scanner scn = new Scanner(System.in);
      int n=scn.nextInt();
      int a=0;
      int b=1;
      for(int i=0;i<n;++i)
      {
          System.out.print(a+" ");
          int c=a+b;
          a=b;
          b=c;
          
      }
      
   }
  }
  
  
  /* Test Case 1 : n = 10 
  
  Output : 0 1 1 2 3 5 8 13 21 34 */
  
  /*Test Case 2: n = 1
  
  Output : 0  */
  
 /* Test Case 3: n = 20
 
 Output : 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 */
  
/* The Code will give wrong output if number in the series exceeds Integer.MAX_VALUE*/

// Example Test case that would fail :

/* Test Case 4: n = 50
   Output : 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 
            5702887 9227465 14930352 24157817 39088169 63245986 102334155 165580141 267914296 433494437 701408733 1134903170 1836311903 -1323752223 512559680 -811192543 

Negative values are wrong basically these values are greater than Integer.MAX_VALUE

*/






  
  
