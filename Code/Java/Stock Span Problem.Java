/* Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.
e.g.
for the array [2 5 9 3 1 12 6 8 7]
span for 2 is 1                
span for 5 is 2
span for 9 is 3
span for 3 is 1
span for 1 is 1
span for 12 is 6
span for 6 is 1
span for 8 is 2
span for 7 is 1
In our solution we assume that -1th day has maximum value, so that if the value of cuurent day has no preceeding highest value then -1th day by default will be its highest
value.
The solution is an iterative solution implemented using stack which is similar as finding max on the left.
Stack is of type integer and index is pushed in the stack.
In ans array if for current element there exist a maximum element on left then :
ans[index] = index - stack.peek()
If no such day exist then stack will be empty, then ans array will have :
ans[index] = index - (-1) 
 
i.e  ans[index] = index +1 
*/
import java.io.*;
import java.util.*;

public class Main{
  public static void display(int[] a){                // display function
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val +"\n");
    }
    System.out.println(sb);
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){                     // Taking input in Array
       a[i] = Integer.parseInt(br.readLine());
    }

    int[] span = solve(a);                         // calling span function
    display(span);                                  // display answer
 }

 public static int[] solve(int[] arr){

   int[] a = new int[arr.length];                 // creating ans array

   Stack<Integer> st = new Stack<>();             // Stack of type Integer

   int left=0;                                   // variable to manage indexing

   while(left<arr.length)                        // traversing in array
   {
       if(st.size()==0)                          // If stack is empty this means -1th day is the last day which have higher value than current day
       {
           a[left]=left+1;                       //in our ans array put the different between current day and last day at which stock was higher than today i.e left - (-1)
           st.push(left);                        // push the index
           left++;                               //increase index

        }

       else if(arr[st.peek()]>arr[left])         // if stack's top index of array has value greater than current element
       {
           a[left]=left-st.peek();              // in our ans array put the different between current day and last day at which stock was higher than today
           st.push(left);                       // push the index
           left++;                              // increase index
       }

       else 
       {
           st.pop();                            // pop the day which have smaller value than current value
       }

     }
   return a;                                     // return ans array                          

 }

}

/*
Test Case 1:
Input : 10
        2
        3
        5
        6
        2
        8
        9
        7
        6
        10
output: 1
        2
        3
        4
        1
        6
        7
        1
        1
        10
Time Compexlity  : O(n)
Auxiliary Space  : O(n)
        
*/

/*
Test Case 1:
Input : 12
        8
        3
        5
        6
        2
        8
        9
        7
        6
        1
        5
        7
output: 1
        1
        2
        3
        1
        6
        7
        1
        1
        1
        2
        5
Time Compexlity  : O(n)
Auxiliary Space  : O(n)
*/
