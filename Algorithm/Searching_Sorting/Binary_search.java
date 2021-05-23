package Algorithm.Searching_Sorting;

// Java program to find number of
// rotations in a sorted and rotated array. 
import java.util.*; 
import java.lang.*; 
import java.io.*; 
  
class Binary_search 
{ 
    // Returns count of rotations for an array 
    // which is first sorted then rotated 
    static int countRotations(int arr[], int low, 
                                       int high) 
    { 
        
        // This condition is needed to handle  
        // the case when array is not rotated  
    
        if (high < low) 
            return 0; 
  
        // If there is only one element left 
        if (high == low) 
            return low; 
  
        // Find mid 
        int mid = low + (high - low)/2;  
  
        // Check if element (mid+1) is minimum element
        if (mid < high && arr[mid+1] < arr[mid]) 
            return (mid + 1); 
  
        // Check if mid itself is minimum element 
        if (mid > low && arr[mid] < arr[mid - 1]) 
            return mid; 
  
        // Decide whether we need to go to left half or right half 
        if (arr[high] > arr[mid]) 
            return countRotations(arr, low, mid - 1); 
  
        return countRotations(arr, mid + 1, high); 
    } 
  
    // Driver program to test above functions 
    public static void main (String[] args)  
    { 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); 
        int arr[ ]= new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(countRotations(arr, 0, n-1)); 
    } 
}

