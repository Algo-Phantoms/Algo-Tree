
class LongestCommonPrefix {
	
	public static void main(String arggs[])
	{
		String[] strs = {"alarm" , "alacrity" , "algorithm"};
		System.out.println(longestCommonPrefix(strs));
	
	}
	
    public static String longestCommonPrefix(String[] strs) {
       
        if(strs.length == 0) {
            return "";
        }
       
        if(strs.length == 1) {
            return strs[0];
        }
       
        String commonPrefix = strs[0];
      
        for(int i=1; i<strs.length; i++) 
        {
            if(commonPrefix.equals("")) 
            {
                return "";
            }
            commonPrefix = findCommonPrefix(commonPrefix, strs[i]);
        }
        return commonPrefix;
    }
    
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
