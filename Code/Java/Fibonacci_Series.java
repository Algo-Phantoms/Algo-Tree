/*The Fibonacci sequence is a series where the next term is the sum of pervious two terms. The first two terms of the Fibonacci sequence is 0 followed by 1.
The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21....
*/
/**
 * 
 */
/**
 * @author Pallavi Dhere
 *
 */
package fibonaccinumbers;

import java.util.Scanner;

/*Method 1 : Using For Loop*/
class FibonacciExample1{  
          public static void main(String args[])  
             {   
                  Scanner sc = new Scanner(System.in);
                  System.out.println("Enter count : ");
                  int count = sc.nextInt();
                  System.out.println(count);
                  int t1=0;
                  int t2=1;
                  int t3;
                  int i;    
                  System.out.print(t1+" "+t2);        //printing 0 and 1    
    
                  for(i=2;i<count;++i)               //loop starts from 2 because 0 and 1 are already printed    
                   {    
                        t3=t1+t2;    
                        System.out.print(" "+t3);    
                        t1=t2;    
                        t2=t3;    
                    }    
  
          }
}


/*Method 2: Using Recursion*/
class FibonacciExample2{  
    public static int t1=0;
    public static int t2=1;
    public static int t3=0;    
    public static void printFibonacci(int count){    
       if(count>0){    
            t3 = t1 + t2;    
            t1 = t2;    
            t2 = t3;    
            System.out.print(" "+t3);   
            printFibonacci(count-1);    
        }    
    }    
    public static void main(String args[]){    
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter count : ");
        int count = sc.nextInt();   
        System.out.print(t1+" "+t2);                    //printing 0 and 1    
        printFibonacci(count-2);                        //n-2 because 2 numbers are already printed   
    }  
 }  




/*Method 3: Using Dynamic Programming*/
class FibonacciExample3
{
  public static int fibonacci(int n)
    {
    /* Declare an array to store Fibonacci numbers. */
          int a[] = new int[n+2]; // 1 extra to handle case, n = 0
          int i;
      
    /* 0th and 1st number of the series are 0 and 1*/
          a[0] = 0;
          a[1] = 1;
     
         for (i = 2; i <= n; i++)
           {
       /* Add the previous 2 numbers in the series
         and store it */
              a[i] = a[i-1] + a[i-2];
           }
      
     return a[n];
 }
      
    public static void main (String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter count : ");
        int count = sc.nextInt();
        System.out.println(fibonacci(count));
    }
}
/*
 * (for method 1)
 * Time Complexity : O(n)
 * Space Complexity :O(1)
 * 
 *  
(For method 2)
* Time Complexity : T(n) = T(n-1) + T(n-2) which is exponential.
* Space complexity : O(n) , if we consider stack space in recursive calls
*/

/*
(For method 3)
// Time Complexity : O(n)
// Space Complexity : O(1)
*/
/*
Sample test cases
Enter the number of elements: 6
 0
 1
 1 
 2
 3 
 5 
Enter the number of elements: 9
 0 
 1 
 1 
 2 
 3 
 5 
 8 
 13 
 21 
*/ 