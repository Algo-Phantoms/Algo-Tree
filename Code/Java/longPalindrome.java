/*
Here Manacher’s Algorithm is Implemented
for Longest Palindromic Substring in which
Linear Time Complexity for Longest Palindromic Substring due Manacher's Algorithm
Here we will take LPS length value at currentLeftPosition (L[iMirror]) and value
of (centerRightPosition – currentRightPosition), i.e. (R – i)
Here how we Proceed for algorithm
*/

package algo;
import java.util.Scanner;

public class manacherAlgo{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String inp = scan.nextLine();
        LongestPalindromicString(inp);
    }
    public static void LongestPalindromicString(String text)
    {
        int N = text.length();
        if (N == 0)
            return;
        N = 2 * N + 1;
        
        // L for LPS Length Array and N for Position count
        int[] L = new int[N + 1];
        L[0] = 0;
        L[1] = 1;
        
        
        // centerPosition then centerRightPosition then currentRightPosition then acurrentLeftPosition
        int C = 1;
        int R = 2;
        int i = 0;
        int iMirror;
        int maximumLenOFLPS = 0;
        int maximumLPSCenPos = 0;
        int start = -1;
        int end = -1;
        int diff = -1;

        
        // Uncomment it to print LPS Length array
        // printf("%d %d ", L[0], L[1]);
        for (i = 2; i < N; i++)
        {
            // get currentLeftPosition iMirror for currentRightPosition i
            iMirror = 2 * C - i;
            L[i] = 0;
            diff = R - i;
            
            
            // If currentRightPosition i is within centerRightPosition R
            if (diff > 0)
                L[i] = Math.min(L[iMirror], diff);
            
        
            // Attempt to expand palindrome centered at currentRightPosition i. Here for odd positions,
            // here we compare characters and if match then increment LPS Length by ONE.
            // If even position, we just increment LPS by ONE without any character comparison
            while (((i + L[i]) + 1 < N && (i - L[i]) > 0) &&
                    (((i + L[i] + 1) % 2 == 0) ||
                            (text.charAt((i + L[i] + 1) / 2) ==
                                    text.charAt((i - L[i] - 1) / 2))))
            {
                L[i]++;
            }

            
            
            if (L[i] > maximumLenOFLPS) // Track maximumLenOFLPS
            {
                maximumLenOFLPS = L[i];
                maximumLPSCenPos = i;
            }
            
            
            
            // If palindrome centered at currentRightPosition i
            // expand beyond centerRightPosition R,
            // adjust centerPosition C based on expanded palindrome.
            if (i + L[i] > R)
            {
                C = i;
                R = i + L[i];
            }
        }
        
        start = (maximumLPSCenPos - maximumLenOFLPS) / 2;
        end = start + maximumLenOFLPS - 1;
        
        
        
        for (i = start; i <= end; i++)
            System.out.print(text.charAt(i));
        System.out.println();
    }
}
/*
    Test Cases:
        Input: abacdedcaba
        Output: abacdedcaba

        Input: abacdfgdcabba
        Output: abba

        Time Complexity: O(n)  where, n is number of characters in input String
        Space Complexity: O(1)
 */
