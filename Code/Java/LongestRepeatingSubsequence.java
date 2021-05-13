/*
The longest repeating subsequence problem is a classic variation of the Longest Common Subsequence (LCS) problem. 
The idea is to find the LCS of the given string with itself, i.e., call LCS(X, X) and 
exclude the cases when indexes are the same (i = j) since repeated characters hold a different index in the input string.

            | 0                                    (if i = 0 or j = 0)
LRS[i][j] = | LRS[i-1][j-1] + 1                    (if X[i-1] = X[j-1] & i!=j)
            | max (LRS[i-1][j], LRS[i][j-1])       (if X[i-1] != X[j-1])
*/
import java.util.Scanner;

class LongestRepeatingSubsequence {
    
    // Function to find LRS of substrings X[0…m-1], X[0…n-1]
    public static String LRS(String X, int m, int n, int[][] T) {

        // if the end of either sequence is reached,
        // return an empty string
        if (m == 0 || n == 0) {

            return new String("");

        }

        // if characters at index m and n matches and the index are different
        if (X.charAt(m - 1) == X.charAt(n - 1) && m != n) {

            return LRS(X, m - 1, n - 1, T) + X.charAt(m - 1);

        }
        // otherwise, if characters at index m and n don't match
        else {

            if (T[m - 1][n] > T[m][n - 1]) {

                return LRS(X, m - 1, n, T);

            } else {

                return LRS(X, m, n - 1, T);

            }
        }
    }

    // Function to fill the lookup table by finding the length of LRS
    // of substring X[0…n-1]
    public static void LRSLength(String X, int[][] T) {

        // Fill the lookup table in a bottom-up manner.
        // The first row and first column of the lookup table are already 0.
        for (int i = 1; i <= X.length(); i++) {

            for (int j = 1; j <= X.length(); j++) {

                // if characters at index i and j matches
                // and the index are different

                if (X.charAt(i - 1) == X.charAt(j - 1) && i != j) {

                    T[i][j] = T[i - 1][j - 1] + 1;

                }

                // otherwise, if characters at index i and j are different
                else {

                    T[i][j] = Integer.max(T[i - 1][j], T[i][j - 1]);

                }
            }
        }

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String X = sc.nextLine();

        // T[i][j] stores the length of LRS of substring X[0…i-1] and X[0…j-1]
        int[][] T = new int[X.length() + 1][X.length() + 1];

        // fill lookup table
        LRSLength(X, T);

        // storing the result
        String result = LRS(X, X.length(), X.length(), T);

        // find the longest repeating subsequence
        System.out.println("The length of the longest repeating subsequence is " + +result.length());

        // uncomment this if you want to print the longest Repeating Subsequence
        // System.out.println("The longest repeating subsequence is " + result);
    }
}

// Time Complexity - O(n^2)
// Space Complexity - O(n^2)

// TestCase-1
// Input
// aabb

// Output
// The length of the longest repeating subsequence is 2

// TestCase-2
// Input
// ATACTCGGA

// Output
// The length of the longest repeating subsequence is 4
