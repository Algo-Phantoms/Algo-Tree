/*
Function to find and print the maximum element in every window of size k.

A simple and concise approach which is implemented using Stack, it is somewhat as finding max on the right. First we find next maximum element on right for every element if no 
such element is present then we assume that it is present at inx array.length. Number of windows present in array of length 10 with size of window 3 is 8 i.e.(array.length-k+1).
Slide the window over the array and for each window print maximum element present in it with the help of maximum on right array.
*/
import java.io.*;
import java.util.*;

public class Main{
  
  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = scn.nextInt();
    }
    int k = scn.nextInt();
    int [] r = right(a);                   // calling maximum element on right function it will return the index of maximum elements on right
    int j = 0;                              // let first element be maximum element
    for(int i = 0; i < a.length - k + 1; ++i)       // sliding the window
    {
        if(j < i)                           // if element is out of window
        {
            j = i;                          // set first element in window the maximum element
        }
        while(r[j] < i + k)                   // here j is the index of current maximum element and r[j] will give the index of next maximum element, while r[j] is in the window 
        {
            j = r[j];                       // update maximum to r[j]
        }
        System.out.print(a[j] + " ");        // at last j will have the index of maximum element print jth element of array
    }
  }
 
 
public static int[] right(int[] arr)     // function to get next maximum element on right
{
    Stack<Integer> st = new Stack<>();   // create a stack of type integer
    int [] ans = new int[arr.length];    // create an ans array of same length
    int right = arr.length - 1;            // traverse from the last element of array
    
    while(right >= 0)                      // while index in range
    {
        if(st.size() == 0)                 // if size of stack is zero this means element has no maximum element on right
        {
            ans[right] = arr.length;     // put arr.length on the right index of ans array
            st.push(right);              // push the current index in the stack
            right--;                     // decrease index
        }
        
        else if(arr[right] < arr[st.peek()]) // if top of stack contains index of element that is greater than current element 
        {
            ans[right] = st.peek();        // put top element on the right index of ans array 
            st.push(right);                // push the current index in the stack
            right--;                       // decrease index
        } 
        else
        {
            st.pop();                      // else pop the top element
        }
        
    }
    return ans;
}
 
}
/*
Test Case 1:
input: 17
       2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6 
       4
output: 9 9 8 12 12 14 14 32 32 32 32 19 19 19             
*/
/*
Test Case 2: 
input: 18
       7 9 3 8 19 7 17 6 14 4 32 0 6 18 8 12 3 0 
       5
output: 19 19 19 19 19 17 32 32 32 32 32 18 18 18              
*/
/*
Time Complexity: O(n)  // where n is the size of input array
Space Complexity: O(n)
*/

