import java.util.HashSet;
import java.util.Scanner;

/* We're given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? and we need to find all unique triplets in the array which gives the sum of zero.
This involves traversing through the array. For every element arr[i], find a pair with sum “-arr[i]”. This problem reduces to pair sum and can be solved in O(n) time using hashing. */

public class Three_Sum {
	
	//function to take the array input.
			public static int[] takeInput() {
				Scanner s= new Scanner(System.in);
				int n= s.nextInt();
				int arr[]= new int[n];
				for( int i=0; i< arr.length; i++) {
					arr[i]= s.nextInt();
				}
				return arr;
			}
			
			 // function to print triplets with 0 sum
		    static void findTriplets(int arr[], int n) 
		    {
		    	// Initially set found to false
		        boolean found = false;
		 
		        for (int i = 0; i < n - 1; i++) 
		        {
		            // Find all pairs with sum equals to "-arr[i]"
		            HashSet<Integer> s = new HashSet<Integer>();
		            for (int j = i + 1; j < n; j++) 
		            {
		                int x = -(arr[i] + arr[j]);
		                //check if my HashSet contains x
		                if (s.contains(x)) 
		                {
		                    System.out.println(x+" "+arr[i]+" "+arr[j]);
		                    found = true;
		                } 
		                else
		                { 
		                //if my HashSet doesn't contain x then add arr[j] into the HashSet
		                    s.add(arr[j]);
		                }
		            }
		        }
		         
		        //if our found remains false, it means we didn't find a triplet
		        if (found == false)
		        {
		            System.out.println(" No Triplet Found");
		        }
		    }
		 
		    public static void main(String[] args) 
		    {
		        int arr[] = takeInput();
		        int n = arr.length;
		        findTriplets(arr, n);
		    }
		}

/* Test Case:
	
	Input 1:
		arr[]= {0, -1, 2, -3, 1}
    Output 1:
    	-1 0 1
    	-3 2 1
    	
    Input 2:
        arr[]= {1, -2, 1, 0, 5}
    Output 2:
    	1 -2  1
    	
Time Complexity: O(n2).
Space Complexity: O(n). */
		 
