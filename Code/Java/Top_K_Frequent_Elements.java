/*
The K most frequent elements can be found if we add all the array elements into the HashMap, and then count the frequency for each element.
Now we'll get the max frequency now initialize an array of ArrayList. here index is frequency, value is list of numbers and then add most frequent elements to the result
 */

import java.util.*;

public class Top_K_Frequent_Elements {
	
	public static int[] takeInput() {
		Scanner s= new Scanner(System.in);
		int n= s.nextInt();
		int arr[]= new int[n];
		
		for( int i=0; i< arr.length; i++) {
			arr[i]= s.nextInt();
		}
	
		return arr;
	}

	public static List<Integer> topKFrequent(int[] nums) {
		Scanner s= new Scanner(System.in);
		 int k= s.nextInt();
		 
	    //count the frequency for each element
	    HashMap<Integer, Integer> map = new HashMap<>();
	    for(int num: nums){
	        map.put(num, map.getOrDefault(num, 0) + 1);
	    }
	 
	    //get the max frequency
	    int max = 0;
	    for(Map.Entry<Integer, Integer> entry: map.entrySet()){
	        max = Math.max(max, entry.getValue());
	    }
	 
	    //initialize an array of ArrayList. index is frequency, value is list of numbers
	    ArrayList<Integer>[] arr = (ArrayList<Integer>[]) new ArrayList[max+1];
	    for(int i=1; i<=max; i++){
	        arr[i]=new ArrayList<Integer>();
	    }
	 
	    for(Map.Entry<Integer, Integer> entry: map.entrySet()){
	        int count = entry.getValue();
	        int number = entry.getKey();
	        arr[count].add(number);
	    }
	 
	    List<Integer> result = new ArrayList<Integer>();
	 
	    //add most frequent numbers to result
	    for(int j=max; j>=1; j--){
	        if(arr[j].size()>0){
	            for(int a: arr[j]){
	                result.add(a);
	                //if size==k, stop
	                if(result.size()==k){
	                    return result;
	                }
	            }
	        }
	    }
	    return result;
	}

	public static void main(String[] args) {
 
		int arr[]= takeInput();
		 List<Integer> result= topKFrequent(arr);
		System.out.println(result);
	}
}

/*
Sample Input 1:-
 arr[]= {1}
 k= 1
Sample Output 1:-
 [1]
 
Sample Input 2:-
 arr[]= {4,5,5,2,1,1,1,5,2,3,3,5,2}
 k= 3
Sample Output 2:
 [1,5,2]
 
Time Complexity:  O(n)
Space Complexity: O(n)
 */


