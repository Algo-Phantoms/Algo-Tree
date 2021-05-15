/*
K Largest Elements of an array.
A simple and concise approach which is implemented using Priority Queue. In which first we insert first K elements of array in the min priority queue then for the rest of 
elements of array we compare one by one with min element present in priority queue if current element is greater then min element then we replace min element with current 
element, at last we are left with K largest element of the array in the priority Queue.
*/
import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws Exception {
      Scanner scn = new Scanner(System.in);
      int n = scn.nextInt();
      int[] arr = new int[n];

      for (int i = 0; i < n; i++) {
         arr[i] = scn.nextInt();
      }

      int k = scn.nextInt();
      PriorityQueue<Integer> pq = new PriorityQueue<>(); // A min Priority Queue
      
      for(int i=0;i<k;++i)                               // add k elements in the Priority Queue 
      {
          pq.add(arr[i]);
      }
      
      for(int i= k ;i<n;++i)                            // traverse on rest of the array
      {
          int ele=pq.remove();                          // remove the minimum element from the Priority Queue
          if(arr[i]>ele)
          {
              ele=arr[i];                              // if current element is greater than minimum element replace
          }
          pq.add(ele);                                 // add in Priority Queue
      }
      
      while(pq.size()>0)
      {
          System.out.print(pq.remove()+" ");          // Print the Elements in Priority Queue
      }
      
    }

}
/*
Test Case 1 :
Input : 13
        12 62 22 15 37 99 11 37 98 67 31 84 99
        4
output :84 98 99 99        
       
*/
/*
Test Case 2 :
Input : 15
        1 45 2 15 37 99 11 37 98 67 31 84 9 100 3
        3
output :98 99 100        
*/
/*
Time complexity : O(nlogk) // where n is size of input array and k is number of largest element needed
Auxiliary Space : O(k)
*/
