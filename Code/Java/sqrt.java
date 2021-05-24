/*
By using Binary Search,
When x is equal to square of mid then square root is mid Hence, Retuen Mid,
But If x Becomes Just Greater than swaure of mid then Square rool become mid -1
i.e just less by one from mid
Here answer is updated when mid*mid is smaller than x,
and move closer to sqrt(x)
*/
package squareroot;
import java.util.Scanner;

public class sqrt {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        System.out.println(floorSqrt(x));
    }

    public static int floorSqrt(int x)
    {
        if (x == 0 || x == 1) {
            return x;
        }
        // Using Binary Search
        int start = 1, end = x, ans=0;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (mid*mid == x) {
                return mid;
            }
            if (mid*mid < x) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
}
/*
    Test Cases:
        Input: 9
        Output: 3

        Input: 8
        Output: 2

        Time Complexity: O(log n) where n is the given number
        Space Complexity: O(1)
 */
