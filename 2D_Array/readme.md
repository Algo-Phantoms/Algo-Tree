 # 2D_Array
 
2D array can be defined as an array of arrays. The 2D array is organized as matrices which can be represented as the collection of rows and columns.

However, 2D arrays are created to implement a relational database look alike data structure. It provides ease of holding bulk of data at once which can be passed to any number of functions wherever required.

## How do we access data in a 2D array
Due to the fact that the elements of 2D arrays can be random accessed. Similar to one dimensional arrays, we can access the individual cells in a 2D array by using the indices of the cells. There are two indices attached to a particular cell, one is its row number while the other is its column number.

## Questions :
* Spiral Print ----> [C++](/Code/C++/spiral_print.cpp)
* Wave Print ----> [C++](/Code/C++/wave_print.cpp)
##Question: Overall Median Of Metrix

/*
 * Decscription :
 * 
 * we are finding overall median of metrix (note: each rows are sorted)
 * Time Complexity: O(NlongN)
 * Space Complexity: O(1)
 * 
 * Example Input:
 * 
 * A = [ [1, 3, 5],[2, 6, 9],[3, 6, 9] ]
 * 
 * output: 5
 * 
 * explanation: 
 * Total elements we have
 * 1,2,3,3,5,6,6,9,9 
 * here there are 9 elements and median would be (n+1)/2 = 4th term
 * 
 * 4th term = 5
 * 
 * */


public class MatrixMedian {
  public static double findMedianSortedArrays(int[][] a) {
   int i, n = a.length;
   int m=a[0].length;
   int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE;
   for(i=0;i<n;i++){
	 low=Math.min(low,a[i][0]);
	 high=Math.max(high,a[i][m-1]);
	}	
   int k = ((n * m) / 2);

   int ans=getAns(low, high, a,k,n);
   System.out.println(ans);
   return ans;	
  }
	public static int getAns(int low, int high, int[][] a,int k,int n) {
		int mid = 0,i=0,p=0,q=0;
		while (low <= high) {
			p=0;q=0;
			mid = (high - low) / 2 + low;
			
			for(i=0;i<n;i++)  p+=countLess(a[i],mid);	
		    
			for(i=0;i<n;i++) q+=countEqual(a[i],mid);
			
			if (p > k)
				high = mid - 1;
			else {
				if (p + q <= k)
					low = mid + 1;
				else
			  return mid;
			}
		}
		return mid;
	}
	public static int countLess(int[] a, int x) {
		int low = 0, high = a.length-1;
		int mid = 0;
		int index = -1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a[mid] >= x) {
				high = mid - 1;
			} else {
				index = mid;
				low = mid + 1;
			}
		}
	return index + 1;
	}
	private static int countEqual(int[] a, int x) {
		int low = 0, high = a.length-1;
		int mid = 0;
		int index = -1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a[mid]>= x) {
				index = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		int index2 = -1;
		low = 0;
		high = a.length- 1;
		while (low <= high) {
			mid = (high - low) / 2 + low;
			if (a[mid] <= x) {
				index2 = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		if (index == -1)
			return 0;
		else
			return index2 - index + 1;
	}
	public static void main(String[] args) {
	    int a[][]={
	    		{1, 3, 5},
	    		{2, 6, 9},
	    		{3, 6, 9}
	           };
		findMedianSortedArrays(a);
	}

}

