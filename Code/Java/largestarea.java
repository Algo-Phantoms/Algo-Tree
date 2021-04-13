/*
Here for Largest Rectange Area (Histogram)
Stack are Used Example :
consider this one example histogram with
7 bars of heights {6, 2, 5, 4, 5, 1, 6}.
The largest possible rectangle possible is 12
*/

package stackall;
import java.util.Scanner;

public class longestArea {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Size of Arraay");
        int n = scan.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        System.out.println(getMaxArea(arr));
    }
    public static int getMaxArea(int hist[]){
        int n  = hist.length;
        // stack holds indexes of hist[] array
        Stack<Integer> s = new Stack<>();
        int max_area = 0;
        //stores top of stack
        int tp;
        int area_with_top; // To store area with top bar as the smallest bar
        // Run through all bars of given histogram
        int i = 0;
        while (i < n)
        {
            // Here we will push bar to stack, If this bar is higher than the bar on top stack,
            if (s.empty() || hist[s.peek()] <= hist[i])
                s.push(i++);
                // If this bar is lower than top of stack, then calculate area of rectangle
                // with stack top as the smallest (or minimum height) bar. 'i' is
                // 'right index' for the top and element before top in stack is 'left index'
            else
            {
                tp = s.peek();
                s.pop();
                // Calculating the area with hist[tp] stack as smallest bar
                area_with_top = hist[tp] * (s.empty() ? i : i - s.peek() - 1);
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
        // Here we will pop the remaining bars from stack
        //  then calculate area with every popped bar as the smallest bar
        while (s.empty() == false)
        {
            tp = s.peek();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.peek() - 1);
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
        return max_area;
    }
}
/*
    Test Cases:
        Input : 5
                2 8 6 4 5
        Output: 16

        Input : 4
                25 36 14 25
        Output: 56

        Time Complexity: O(n)
        Space Complexity: O(1)
 */
