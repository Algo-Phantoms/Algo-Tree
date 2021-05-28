/*
Here Linklist is Used for Storing all Digits of 2 Array
Here union Linkedlist contain all elements which are there in both arrays
and Intersection LinkedList contains elements only which are in both array
*/

package twoarray;
import java.util.Scanner;

public class ArrayUnionAndIntersection {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // Length of 1st Array
        int n = scan.nextInt();
        int[] arr = new int[n];
        // All Values of 1nd Array
        for (int i =0;i<arr.length;i++){
            arr[i] = scan.nextInt();
        }
        // Length of 2st Array
        int m = scan.nextInt();
        int[] brr = new int[m];
        // All Values of 2nd Array
        for (int i =0;i<m;i++){
            brr[i] = scan.nextInt();
        }
        unionANDintersection(arr,brr);
    }
    public static void unionANDintersection(int[] A, int[] B){
        LinkedList<Integer> ls1 = new LinkedList<Integer>();
        for (int i = 0;i<A.length;i++){
            ls1.add(A[i]);
        }
        LinkedList<Integer> ls2 = new LinkedList<Integer>();
        for (int i = 0;i<B.length;i++){
            ls2.add(B[i]);
        }
        LinkedList<Integer> union = new LinkedList<Integer>();
        LinkedList<Integer> intersection = new LinkedList<Integer>();
        for (int i = 0;i<ls1.size();i++){
            int num = ls1.get(i);
            if (ls2.contains(num)){
                intersection.add(num);
            }
            if (!union.contains(num)){
                union.add(num);
            }
        }

        for (int i = 0;i<ls2.size();i++){
            int num = ls2.get(i);
            if (!union.contains(num)){
                union.add(num);
            }
        }
        System.out.println("Intersection Array");
        System.out.println(intersection);
        System.out.println("Union Array");
        System.out.println(union);
    }
}
/*
    Test Cases:
        Input : 3
                2 3 4
                5
                4 2 6 1 3
        Output:
                Intersection Array
                [2, 3, 4]
                Union Array
                [2, 3, 4, 6, 1]


        Input : 2
                8 1
                4
                8 6 3 0
        Output :
                Intersection Array
                [8]
                Union Array
                [8, 1, 6, 3, 0]

        Time Complexity: O(N)
        Space Complexity: O(1)
 */
