/*Aim: To print Largest Palindromic Subsequence of input string str in java
Approach: Recursive Solution
In lps function string, starting index, ending index is passed. 
If starting index is equal to ending index as we know single character is a palindrome so it returns 1
If there are only 2 characters and both are same return 2
else it check for whole string and return largest subsequence. */
import java.util.Scanner;
public class largestPalindromeSubsequence {
    public static int lps(char[] str,int i, int j){
        if (i == j) { 
            return 1; 
        }
        if (str[i] == str[j] && i + 1 == j) { 
            return 2; 
        } 
        if (str[i] == str[j]) { 
            return lps(str, i + 1, j - 1) + 2; 
        }
        return Math.max(lps(str, i, j - 1), lps(str, i + 1, j)); 
    }
	public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
		String str = scn.next();
        System.out.print(lps(str.toCharArray(),0,str.length()-1));
	}
}
/* Time Complexity : O(2n)
Space Complexity : O(1)
Test Cases
Test Case 1 :
input = bbbab
output = 4
Test Case 2 :
input = bbccbca
output = 4
Test Case 3 :
input = aaaabbaa
output = 6 */
