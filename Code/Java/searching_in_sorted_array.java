/*
If a sorted array is rotated around a random pivot and you don't know the pivot.
      index - [0,1,2,3,4,5]
i.e - array - [1,3,5,7,8,9] is a sorted array let pivot = 3(this is the index and here zero-based indexing is used)
                                                                index - [0,1,2,3,4,5]
around which the array is rotated then resultant array would be array - [8,9,1,3,5,7]

Now this algorithm is used to find the index of key element(which we need to find) in rotated array in O(logn).

key Observation of Algorithm =>
 -> if we choose any index and split the array into two then one of the two sub array is sorted.
*/


public class searching_in_sorted_array {

	static int searchRotatedArray(int a[], int key, int left, int right) {
		if (left > right) // it means the required element in not present in array
			return -1;

		int mid = left + (right - left) / 2; // choosing mid value to split array into two sub array

		if (a[mid] == key) // found required element
			return mid;

		/*
		  a[left..........,mid,..........,right]
		  left part - a[left,..........,mid-1]
		  right part -  a[mid+1,..............right]
		*/

		if (a[left] <= a[mid]) { // left part is sorted
			if (a[left] <= key && a[mid] > key) //key in present in left part
				return searchRotatedArray(a, key, left, mid - 1);

			return searchRotatedArray(a, key, mid + 1, right);
		}

		if (a[mid] > key && a[right] <= key) //key is present in right part
			return searchRotatedArray(a, key, mid + 1, right);

		return searchRotatedArray(a, key, left, mid - 1);
	}

	public static void main(String []args) {
		int a[] = {12, 34, 37, 38, 2, 5, 9, 11};
		int size = a.length;
		int key = 38;
		int index = searchRotatedArray(a, key, 0, size - 1);
		if (index == -1) {
			System.out.println("This element is not present in Array");
		} else {
			System.out.println(index);
		}

	}
}

/*
Test case 1 :
  input -
  size -> 7
  a-> [3 4 5 6 7 1 2]
  key -> 2

  output -> 6

  explanation ->
  index - [0 1 2 3 4 5 6]
    a   - [3 4 5 6 7 1 2]
  2 is present on index 6 so output is 6.

Test case 2 :
 input -
 size -> 8
 a-> [12 34 37 38 2 5 9 11]
 key -> 38

 output -> 3

 explanation ->
 index - [0  1  2  3  4 5 6 7]
   a   - [12 34 37 38 2 5 9 11]
 38 in present as index 3 so output is 3.
 
Time complexity  -
best case - O(1) - when key element is at mid position
average case- O(logn)

Space complexity - O(1)
*/
