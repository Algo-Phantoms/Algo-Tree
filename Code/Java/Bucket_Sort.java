/*
Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called buckets.
The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.
Several buckets are created. Each bucket is filled with a specific range of elements. 
The elements inside the bucket are sorted using any other algorithm. Finally, the elements of the bucket are gathered to get the sorted array.

*/


import java.util.*;

class BucketSort {

    private static void bucketSort(float[] arr, int k) {
        if (arr.length < 2)
            return;
        
        // getting upper limit for dividing numbers in buckets
        int length = arr.length;
        float max_val = arr[0];
        for (int i = 1; i < length; i++) {
            max_val = Math.max(max_val, arr[i]);
        }
        max_val += 1;

        //making bucket list and adding buckets in it
        ArrayList<ArrayList<Float>> bucketList = new ArrayList<ArrayList<Float>>();
        for (int i=0; i < k; i++) {
            bucketList.add(new ArrayList<Float>());
        }

        //dividing numbers in different buckets
        for (int i = 0; i < length; i++) {
            int bucketIndex = (int) ((arr[i] * k) / max_val);
            bucketList.get(bucketIndex).add(arr[i]);
        }

        // sorting each bucket one by one
        for (int i = 0; i < length; i++) {
            Collections.sort(bucketList.get(i));
        }

        //joining buckets
        int pos = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j<bucketList.get(i).size(); j++) {
                arr[pos] = bucketList.get(i).get(j);
                pos += 1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        float arr[] = new float[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextFloat();
        }
        System.out.println("Enter number of buckets:");
        int bucketNum = sc.nextInt();

        // before sorting
        System.out.println("Array before bucket sort:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        bucketSort(arr, bucketNum);

        // after sorting
        System.out.println("Array after Bucket sort:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}

/*
Test Cases:
Example 1:
Enter size of array:
10
Enter array elements:
88
26
77
49
91
62
33
85
99
11
Enter number of buckets:
5

Output:
Array before bucket sort:
88.0 26.0 77.0 49.0 91.0 62.0 33.0 85.0 99.0 11.0 
Array after Bucket sort:
11.0 26.0 33.0 49.0 62.0 77.0 85.0 88.0 91.0 99.0

Example 2:
Enter size of array:
7
Enter array elements:
0.49
5.9
3.41.11
4.5
6.6
2.0
Enter number of buckets:
3

Output:
Array before bucket sort:
0.49 , 5.9 , 3.4 , 1.11 , 4.5 , 6.6 , 2.0
Array after Bucket Sort:
0.49 , 1.11 , 2.0 , 3.4 , 4.5 , 5.9 , 6.6

Time Complexity:  O(n^2)
Space Complexity - O(nk)
where n = number of elements in the input array
where k = number of buckets
*/
