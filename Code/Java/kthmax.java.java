/*
Using Merge Sort, First of all Sort the Given Array with Best Time Complexity
so, Merge Sort is Emplemented. Here sort() Method will sort Array and then
sort Method uses different method as "merge method"
After Sorting then for kth Max Elemets, when sorting is descending
so for kth max element return (k-1)th Element
*/

package kthmaxmin;
import java.util.Scanner;

public class KthMax {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
        // ENter Length of Array
        int n = scan.nextInt();
        // Enter value of k for with kth Max Element is to be found
        int k = scan.nextInt();
        int[] arrr = new int[n];
        for (int i = 0;i<n;i++){
            arrr[i] = scan.nextInt();
        }
        System.out.println(kthmax(arrr,k));
    }
    // Method for getting value of kth Maximum element
    public static int kthmax(int[] arr,int k){
        sort(arr,0,arr.length-1);
        return arr[k-1];
    }
    // Method for Merging
    public static void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int[n1];
        int R[] = new int[n2];
        //Dublicating data to temp arrays
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
        // Merge the temp arrays
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    // Sorting Fuction Using Merge sort to get Best Time Complexity
    // sort Method uses merge function
    public static void sort(int arr[], int l, int r)
    {
        if (l < r) {
            int m =l+ (r-l)/2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
}
/*
    Test Cases:
        Input : 5
                3
                8 9 5 2 4

        Output: 5

        Input : 6
                2
                2 4 6 5 8 3
        Output: 6

        Time Complexity: O(N logN)
        Space Complexity: O(1)

 */
