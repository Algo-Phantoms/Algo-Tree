/*

Longest common prefix in an array of strings.
 
Input: [ "github", "githubeducation" ,"git" ];
Output : "git"

If there is no common prefix, return an empty string " ".


*/



import java.util.Scanner;
class LongestCommonPrefix {
	
	public static void main(String arggs[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length of String array:");
		int N = sc.nextInt();
		String[] strs = new String[N];
		for(int i = 0 ; i < N ; i++)
		{
			strs[i] = sc.next();
		}
		System.out.println(longestCommonPrefix(strs));
	
	}
	
    public static String longestCommonPrefix(String[] strs) {
       
        if(strs.length == 0)  //returning empty string if input array is empty
		{
            return "";
        }
       
        if(strs.length == 1)  //returning 1st element if input is only 1 string element
		{
            return strs[0];
        }
       
        String commonPrefix = strs[0];
      
        for(int i=1; i<strs.length; i++) 
        {
            if(commonPrefix.equals("")) 
            {
                return "";  //base condition for exiting the method
            }
            commonPrefix = findCommonPrefix(commonPrefix, strs[i]);
        }
        return commonPrefix;
    }
    
	//divide and conquer method for finding longest common prefix
	
    static String findCommonPrefix(String s1, String s2) {
        
        if(s2.length() == 0) {
            return "";
        }
        
        int i = 0;
        for(i=0; i<Math.min(s1.length(), s2.length()); i++) {
            if(s1.charAt(i)!=s2.charAt(i)) {
                return s1.substring(0, i);
            }
        }
        return s1.substring(0, i);
    }
}


/*

--Test Case 1--

Input: Enter the length of String array:
	   0
Output: (empyty string)

--Test Case 2--
Input:Enter the length of String array:
4
github
githubpro
githubmaster
githubeducation
github
Output: github



( n = length of String
  m = number of Strings in array )

Time complexity: O(s)		
Space Complexity: O(s)
where s = n * m

*/