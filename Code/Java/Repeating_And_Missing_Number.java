/*Repeating And Missing Numbers :-
     Given an array of size n.
     Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array.
     we are going to find these two numbers.

  Algorithm
    This method involves creating a Hashset with the help of Sets. In this, the elements are assigned to their natural index. In this process,
    if an element is assigned twice, then it is the repeating element. And if an element’s assigning is not there, then it is the missing element.
*/

package reapeating_and_mising_number;

import java.io.*;
import java.util.*;

public class Repeating_And_Missing_Number {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Number of Intergers : ");
        //Taking the input of n
        int n = Integer.parseInt(br.readLine());   
        
        int[] a; 
        a = new int[n];
        for(int i = 0; i < n; i++) {   
            a[i] = Integer.parseInt(br.readLine());
        } 
        
        int[] ans = findTwoElement(a, n);                       
        System.out.println("Repeating Number"+"  "+ans[0] + " " +"Missing Number"+"  "+ ans[1]);
        
    }
    
    
    public static int[] findTwoElement(int arr[], int n) {
      
       Set<Integer> numSet = new HashSet<Integer>();    
       int[] a = {0,0};

       for(int i = 0; i < n; i++) {
        //Checking if numset contains that element
           if(!numSet.contains(arr[i]))     
           {   
            //if condition gets false then adding the element to numset
            numSet.add(arr[i]);         
           } else {    
            //assigning value to a[0](repeating number)
             a[0] = arr[i];              
           }
       }
       for(int num = 1; num <= n; num++) {  
            //checking for missing number 
           if(!numSet.contains(num))                     
            {
                a[1] = num;
            }
        }
       return a;
         
    }
}

/*
Test Cases

Input : Enter the Number of Intergers:
4
1
2
2
4
Output : Repeating Number  2 Missing Number  3

Input : Enter the Number of Intergers:
5
1
2
2
4
5
Output : Repeating Number  2 Missing Number  3

TIME COMPLEXITY AND SPACE COMPLEXITY
Time Complexity :- O(n), Where n is the size of array.
Space Complexity :- O(1)
*/
