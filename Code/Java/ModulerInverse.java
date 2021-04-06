/*Moduler multiplicative inverse ia a number by which multiply our number and mod with modulus the result will be 1

i.e 

if our number is A and modulus is M and the Multiplicative inverse is B then (A*B)%M=1
*/


import java.util.*;
public class ModulerInverse{

     public static void main(String []args){
        int c=0;
        Scanner sc=new Scanner(System.in);
        int firstNumber=sc.nextInt();
        int Modulus=sc.nextInt();
        for(int i=1;i<Modulus;i++)
        {
            if((firstNumber*i)%Modulus==1)
            {
                System.out.println(i);
                c=1;
                break;
            }
        }
        if(c==0)
        {
            System.out.println("Inverse not found");
        }
     }
}

/*
Teat Case-
  Input-10 17
  Output-12
  
  Input-10 10 
  Output-Inverse not found 
Time Complexity-O(M) //M=Modulus
Space complexity-1*/
