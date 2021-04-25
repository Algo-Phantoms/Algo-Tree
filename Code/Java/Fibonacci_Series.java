/*The Fibonacci sequence is a series where the next term is the sum of pervious two terms. The first two terms of the Fibonacci sequence is 0 followed by 1.
The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21....
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
                  int t1 = 0;
                  int t2 = 1;
                  int t3;
                  int i;    
                  System.out.print(t1 +" "+ t2);        //printing 0 and 1    
    
                  for(i = 2 ; i < count ; i++) {               //loop starts from 2 because 0 and 1 are already printed        
                        t3 = t1 + t2;    
                        System.out.print(" "+t3);    
                        t1 = t2;    
                        t2 = t3;    
                    }    
  
          }
}


/*Method 2: Using Recursion*/
class FibonacciExample2{  
    public static int t1 = 0;
    public static int t2 = 1;
    public static int t3 = 0;    
    public static void printFibonacci(int count){    
       if(count>0){    
            t3 = t1 + t2;    
            t1 = t2;    
            t2 = t3;    
            System.out.print(" " + t3);   
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
          int arr[] = new int[n+2];   // 1 extra to handle case, n = 0
          int i;
      
    /* 0th and 1st number of the series are 0 and 1*/
          arr[0] = 0;
          arr[1] = 1;
     
         for (i = 2; i <= n; i++) {
       /* Add the previous 2 numbers in the series and store it */
              arr[i] = arr[i-1] + arr[i-2];
           }
      
     return arr[n];
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
 
  Test case 1
  Input : Enter the number of elements: 6
  Output : 0 1 1 2 3 5
  Test case 2
  Input : Enter the number of elements: 9
  Output : 0 1 1 2 3 5 8 13 21
   
  Time Complexity and Space Complexity
  (Method 1 - Via for Loop)
  Time Complexity : O(n)
  Space Complexity :O(1)
   
  (Method 2 - Via Recursion)
  Time Complexity : T(n) = T(n-1) + T(n-2) which is exponential.
  Space complexity : O(n) , if we consider stack space in recursive calls
 
  (Method 3 : Via Dyanamic Programing)
  Time Complexity : O(n)
  Space Complexity : O(1)
 */ 
