/*
 *  Description: Find all subset lexicographically
 *  
 *  Subset: Subset is same as subsequences except it has empty set.
 *          total subset of size n= 2^n
 *  Lexicographic order: Lexicographical ordering means dictionary order. 
 *                 For ex: In dictionary 'apq' comes after 'abbb' because 'p' comes after 'a'
 *                 in English alphabetic.
 *                 
 *                 In case of number always smaller subset come first.
 *                 for ex: [1,2,3]  subset {1,2,3} come before {3}.
 *   
 *   example: ar[1,2,3]
 *   lexicographic subsets: 
 *             [],[1],[1,2],[1,2,3],[2],[2,3],[3]
 *             
 *             
 *  Time Complexity: 2^n
 *  Space Complexity: O(N) 
 * */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
public class SubsetRecursionLexicographic {
	public static ArrayList<ArrayList<Integer>> ans= new ArrayList<ArrayList<Integer>>();
	
	public static ArrayList<ArrayList<Integer>> subsets(int[] A) {
       Arrays.sort(A);
	   ans.clear();
	   ans.add(new ArrayList<Integer>());
	   subsetFunction(A,0,new ArrayList<Integer>());
	 return ans;
	}
	
	//recursive function
	private static void subsetFunction(int[] ar, int index, ArrayList<Integer> list) {
	for(int i=index;i<ar.length;i++){
	  list.add(ar[i]);
	  ans.add(new ArrayList<Integer>(list));		
	  subsetFunction(ar,i+1,list);	
	  list.remove(list.size()-1);  
	 }
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
	   //input size of array
		int n=sc.nextInt();
		
		//Insert Array Element
		int i;
		int[] arr=new int[n];
		for(i=0;i<n;i++){
		  arr[i]=sc.nextInt();	
		}
		
		ArrayList<ArrayList<Integer>> ans=subsets(arr);
		for(ArrayList<Integer> l: ans){
		  System.out.println(l);	
		} 
	}
}
