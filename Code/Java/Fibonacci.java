import java.util.*;
class Fibonacci{  
 static int n1=0,n2=1,n3=0;    
 static void printFibonacci(int number){    
    if(number>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         System.out.print(" "+n3);   
         printFibonacci(number-1);    
     }    
 }    
 public static void main(String args[]){    
  Scanner sc=new Scanner(System.in);
  int number=sc.nextInt();
  System.out.print(n1+" "+n2);//printing 0 and 1    
  printFibonacci(number-2);//n-2 because 2 numbers are already printed   
 }  
}
