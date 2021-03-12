/* The question goes like given an array of integers
and a sum say 's' find the smallest subarray with sum greater than the given value(s). 

*/

class SmallestSubArraySum {
    // Returns length of smallest subarray with sum greater than x.
    // If there is no subarray with given sum, then returns n+1
    static int smallestSubWithSum(int arr[], int n, int s) {
        // Initilize length of smallest subarray as n+1
        int min_len = n + 1;

        // Pick every element as starting point
        for (int start = 0; start < n; start++) {
            // Initialize sum starting with current start
            int curr_sum = arr[start];

            // If first element itself is greater
            if (curr_sum > s)
                return 1;

            // Try different ending points for curremt start
            for (int end = start + 1; end < n; end++) {
                // add last element to current sum
                curr_sum += arr[end];

                // If sum becomes more than x and length of
                // this subarray is smaller than current smallest
                // length, update the smallest length (or result)
                if (curr_sum > s && (end - start + 1) < min_len)
                    min_len = (end - start + 1);
            }
        }
        return min_len;
    }

    // Driver program
    public static void main(String[] args) {
        int arr1[] = { 7, 10, 5, 1, 2 };
        int s = 9;
        int n1 = arr1.length;
        int res1 = smallestSubWithSum(arr1, n1, s);
        if (res1 == n1 + 1)
            System.out.println("Not Possible");
        else
            System.out.println("Smallest subarray will contain = " + res1 + "element/element's");

    }
}

/*
 * Sample Test Cases
 * 
 * 1) arr[] = {1, 4, 45, 6, 0, 19} s = 51 Output: Smallest subarray will contain
 * = 3 element/element's
 * 
 * 2) arr[] = {12, 2, 10} s = 28 Output : Not Possible
 * 
 * 3) arr[] = {2, 11, 99, 1, 0, 200, 3, 2, 1, 250} s = 280 Output: 4
 */