/* Here is the code for finding the Longest Conmmon Prefix
from the input provided by user.

_______________________________________________________________
*/ 

import java.util.Scanner; 

public class Main {
    private static String longestCommonPrefix(String[] strs) {
        String lcp = "";
        
        if(strs.length == 0 || strs == null) {
            return lcp;
        }
        
        int index = 0;
        
        for(char c : strs[0].toCharArray()) {
            for(int i = 1; i < strs.length; i++) {
                if(index >= strs[i].length() || c != strs[i].charAt(index)) {
                    return lcp;
                }
            }
            lcp += c;
            index++;
        }
	    
        return lcp;
    }
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] words = str.split("\\s+");
	System.out.println(longestCommonPrefix(words));
    }
}

/*
Time complexity:
	O(N) as depends on the characters given in the string

Space complexity:
	O(1) Takes constant space.
*/

/*
Test cases:
	Input:  small smile smell
        Output: sm
	
	Input:  flight flock fly
	Output: fl
*/

