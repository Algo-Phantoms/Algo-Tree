/*LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
 * A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
 * For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.*/

import java.util.Scanner;
public class Longest_Common_Subsequence {
	public static int LengthOfLCS(String s, String t) {
		     int m = s.length();
		     int n = t.length();
		     int storage[][] = new int[m + 1][n + 1];
		     // Base case for first row
		     for (int i = 0; i <= m; i++) {
			         storage[i][0] = 0;
		     }
         // Base case for first column
		     for (int i = 0; i <= n; i++) {
			          storage[0][i] = 0;
		     }
         for (int i = 1; i <= m; i++) {
			        for (int j = 1; j <= n; j++) {
				           if (s.charAt(m - i) == t.charAt(n - j)) {
                         storage[i][j] = 1 + storage[i - 1][j - 1];
                   } else {
                          storage[i][j] = Math.max(storage[i][j - 1], storage[i - 1][j]);
				            }
			          }
	      	}
		      return storage[m][n];
	}
	public static String printTheLCS(String s, String t) {
		     int[][]Storage = new int[s.length() + 1][t.length() + 1];
         int m = s.length();
         int n = t.length();
		     // Following steps build storage[m+1][n+1] in bottom up fashion
		           // storage[i][j] contains the maximum length of LCS of s[0..i-1] and t[0..j-1]
		            for (int i = 0; i <= s.length(); i++) {
			               for (int j = 0; j <= t.length(); j++) {
			                   	   // Base case 
				                     if (i == 0 || j == 0) {
				                        	Storage[i][j] = 0;
				                     } else if (s.charAt(i - 1) == t.charAt(j - 1)) {
					                        Storage[i][j] = Storage[i - 1][j - 1] + 1;
				                     } else {
					                        Storage[i][j] = Math.max(Storage[i - 1][j], Storage[i][j - 1]);
				                     }	
			                }
	            	}
           // Following code is used to print LCS
		       int index = Storage[s.length()][t.length()];
		       int temp = index;
        
           // Create a character array to store the lcs string
		           char[] lcs = new char[index + 1];
		           lcs[index] = '\u0000'; // Set the terminating character
        
           // Start from the right-most-bottom-most corner and
		       // one by one store characters in lcs[]
		           int i = m;
		           int j = n;
		           while (i > 0 && j > 0) {
			               // If current character in s and t are same, then current character is part of LCS
			                  if (s.charAt(i - 1) == t.charAt(j - 1)) {
			                         // Put current character in result
				                         lcs[index - 1] = s.charAt(i - 1);

				                       // reduce values of i, j and index
			                           	i--;
				                          j--;
				                          index--;
			                    }     // If not same, then find the larger of two and go in the direction of larger value
			                    else if (Storage[i - 1][j] > Storage[i][j - 1]) {
				                           i--;
		                      } else {
			                             j--;
			                    }	
		           }
		           String ans = "";
		           for (int k = 0; k <= temp; k++) {
		               	ans += lcs[k];
		            }
		    return ans;
    } 
  
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str1 = sc.next();
		String str2 = sc.next();
		System.out.print("Longest Common Subsequence of " + str1 + " and " + str2 + " is " + printTheLCS(str1,str2) + 
				         "of length "+ LengthOfLCS(str1,str2));
		sc.close();
	}
}
/*
Sample Input  1: Str1 : "ABCDGH"  Str2 : "AEDFHR"
Sample Output 1: Longest Common Subsequence of “ABCDGH” and “AEDFHR” is “ADH” of length 3.
Sample Input  2: Str1 : "AGGTAB"  Str2 : "GXTXAYB"
Sample Output 2: Longest Common Subsequence of “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

Time Complexity : O(M*N)
Auxiliary Space : O(N)
*/
