

/*Description: In this question we have to rotate the array by d elements to the left direction.
for example: [1 2 3 4 5 6 7 8] is the array and we have to rotate 2 consecutive element inleft direction.
                so output will be [3 4 5 6 7 8 1 2]
In this approach we will basically use the recursive approach of BLOCK SWAP ALGORITHM to
rotate  D elements in an array to left direction*/

import java.util.*;
class rotateArrayWithD_Element
{
 // THIS IS THE RECURSIVE APPROACH
    public static void leftRotate(int a[], int i, int d, int n){
        /* THIS IS THE BASE CASE */
        /* Return If number of elements to be rotated
        is zero or equal to array size */
        if(d == 0 || d == n)
            return;
        /*If number of elements to be rotated
        is exactly half of array size */
        if(n - d == d)
        {
            swap(a, i, n - d + i, d);
            return;
        }
        /* If A is shorter*/   
        if(d < n - d)
        {
            swap(a, i, n - d + i, d);
            leftRotate(a, i, d, n - d);    
        }
        else /* If B is shorter*/   
        {
            swap(a, i, d, n - d);
            leftRotate(a, n - d + i, 2 * d - n, d); 
        }
    }
 
/*This function swaps d elements starting from index f with d elements
starting at index s */
public static void swap(int a[], int f, int s, int d)
{
    int temp;
    for(int i = 0; i < d; i++)
    {
        temp = a[f + i];
        a[f + i] = a[s + i];
        a[s + i] = temp;
    }
}

/* function to print an array */
public static void printArray(int a[], int n) // here n is the size of the array
{
    int i;
    for(i = 0; i < n; i++)
        System.out.print(a[i] + " ");
    System.out.println();
}

// This is the main function
public static void main (String[] args)
{
    Scanner sc = new Scanner(System.in);  // taking user input
    System.out.println("Enter the size of the array");
    int n = sc.nextInt();
    int[] arr  = new int[n];
    for (int i = 0; i < n; i++) {
        System.out.println("Enter the " + (i+1) +" element ");
        arr[i]  = sc.nextInt();
    }
    System.out.println("Enter the number of the element that you want to rotate in the array");
    int d= sc.nextInt();
    
    leftRotate(arr,0 , d, n);
    printArray(arr, n);    
}
}

/* here the input format is 
         n               --> this is the size of the array
         array elements  -->  this the input for the array elements using for loop 
         d               --> this is the no of element to rotate together in an array

Test case 1:

    input:

        Enter the size of the array:                                            
        8 

        Enter the elements of the array:  --> this is space seperated array
        1 2 3 4 5 6 7 8 

        Enter the number of the element that you want to rotate in the array:
        4

    output:

        5 6 7 8 1 2 3 4            

 Test case 2:

    input:
        Enter the size of the array:                                                  
        12  

        Enter the elements of the array:  --> this is space seperated array                                                         
        11 23 35 24 57 63 74 89   

        Enter the number of the element that you want to rotate in the array:                                           
        3
    output:
        24 57 63 74 89 11 23 35  
 */

 /* TIME COMPLEXITY : O(n) --> where n is the size of the array
    SPACE COMPLEXITY : O(1) --> No extra space required (the recursive stack that is filled 
                                                        during the process has been later 
                                                        collected by garbage collecter present 
                                                        in java).
*/

