/*Repeating And Missing Numbers :-
 *     Given an array of size n.
 *      Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array.
 *       we are going to find these two numbers.*/

/*Algorithm
 *    This method involves creating a Hashset with the help of Sets. In this, the elements are assigned to their natural index. In this process,
 *    if an element is assigned twice, then it is the repeating element. And if an element’s assigning is not there, then it is the missing element.*/

/**
 * 
 */
/**
 * @author Pallavi Dhere
 *
 */
package reapeating_and_mising_number;

import java.io.*;
import java.util.*;



public class Repeating_And_Missing_Number {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Number of Intergers:");
        int n=Integer.parseInt(br.readLine());   //Taking the input of n
        
        int[] a; 
        a=new int[n];
        for(int i=0;i<n;i++) {                                        //Array input
            a[i]=Integer.parseInt(br.readLine());
          }                                               
            int[] ans = findTwoElement(a, n);                        //Calling function
            System.out.println("Repeating Number"+"  "+ans[0] + " " +"Missing Number"+"  "+ ans[1]);
        
    }
    
    
    public static int[] findTwoElement(int arr[], int n) {
        // code here
       Set<Integer> numSet=new HashSet<Integer>();    //creating Hashset
        int[] a={0,0};

        
        for(int i=0;i<n;i++)
        {
            
        if(!numSet.contains(arr[i]))     //Checking if numset contains that element
        {
            numSet.add(arr[i]);         //if condition gets false then adding the element to numset
        }
        else
        {
             a[0]=arr[i];              //assigning value to a[0](repeating number)
           
        }
        
        }
        for(int num=1;num<=n;num++)
        {
            if(!numSet.contains(num))                     //checking for missing number 
            {
                a[1]=num;
            }
        }
       return a;
         
    }
}

/*INPUT AND OUTPUT*/
/*
 *Enter the Number of Intergers:
4
1
2
2
4
Repeating Number  2 Missing Number  3

 *Enter the Number of Intergers:
5
1
2
2
4
5
Repeating Number  2 Missing Number  3
*/

/*TIME COMPLEXITY AND SPACE COMPLEXITY*/
/*
 * Time complexity :- O(n)
 * Space Complexity :- O(1)*/


