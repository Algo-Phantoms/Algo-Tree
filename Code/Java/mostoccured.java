/*
Firstly Array will be Sorted
As a result of which all Same Elements will be in Neighbourhood of each other
Then Occurance will be compared, if more than Previous Max Occurance then
That will be taken as Number with Max Occurance
*/

package mostoccu;
import java.util.Scanner;

public class MostOccured {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
        int n = scan.nextInt();
        int[] arrr = new int[n];
        for (int i = 0;i<n;i++){
            arrr[i] = scan.nextInt();
        }
        System.out.println(most(arrr));
    }
    public static int most(int[] arr){
        int ans = -1;
	// Sorrting Array
        sortArray(arr);
	// A Varible to keep Previous Number
        int prevno = arr[0];
	// A Variable which Keeps Count of Occurance
        int count = 1;
        int maxoccc = Integer.MIN_VALUE;
        for (int i = 1; i<arr.length; i++){
            if (arr[i] == prevno){
                count++;
            }else {
                prevno = arr[i];
        	// If count is more than maxocc then that element will be Most Occured Element        
		if (count > maxoccc){
                    maxoccc = count;
                    ans = arr[i-1];
                }
                count = 1;
            }
        }
	// For checking Last Count
	if (count > maxoccc){
            ans = arr[arr.length-1];
        }
        return ans;
    }

// Sorting Array Algorithm
    public static void sortArray(int[] nums) {
        for (int i = 0; i<nums.length; i++){
            for (int j = i+1 ;j<nums.length; j++){
                int minindex = Integer.MAX_VALUE;
                if (minindex > nums[j]){
                    minindex = j;
                }
                if (nums[minindex] < nums[i]){
                    int temp = nums[i];
                    nums[i] = nums[minindex];
                    nums[minindex] = temp;
                }
            }
        }
    }

}
/*
    Test Cases:
        Input : 5
                8 9 8 2 4 1
        Output: 8

        Input : 6
                2 4 6 5 4 3 4
        Output: 4

        Time Complexity: O(n) Where n is Length of Arrray
        Space Complexity: O(n)

 */
