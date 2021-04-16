
/*
 *                Find all Permutation of a String
 * 
 * A permutation is an arrangement of all or part of a set of objects, 
 * with regard to the order of the arrangement. 
 * For instance, the words ‘abc’ and ‘cba’ represents two distinct 
 * permutation (or arrangements) of a similar three letter word.
 */
import java.util.*;
public class Permutation_String {  
    public static String swapString(String a, int i, int j) {  
        char[] b =a.toCharArray();  
        char ch;  
        ch = b[i];  
        b[i] = b[j];  
        b[j] = ch;  
        return String.valueOf(b);  
    }  

    public static void generatePermutation(String str, int start, int end)  
    {  
        if (start == end-1)  
            System.out.println(str);  
        else  
        {  
            for (int i = start; i < end; i++)  
            {  
                str = swapString(str,start,i);  
                generatePermutation(str,start+1,end);  
                str = swapString(str,start,i);  
            }  
        }  
    }  

    public static void main(String[] args)  
    {  
        Scanner in=new Scanner(System.in);
        String str = in.next();  
        int len = str.length();  
        System.out.println("All the permutations of the string are: ");  
        generatePermutation(str, 0, len);  
        in.close();
    }  

}  

/*
 * Test Case 1 :
 * Input : abc
 * Output: All the permutations of the string are: abc acb bac bca cba cab
 * 
 * Test Case 2 :
 * Input : ab
 * Output : All the permutations of the string are: ab ba

Time Complexity is O(n) , n is the length of the string.
Space Complexity is O(n) , n is the length of the string.   
 */