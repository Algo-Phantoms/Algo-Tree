# String

A char array is just that - an array of characters:

- If allocated on the stack (like in your example), it will always occupy eg. 256 bytes no matter how long the text it contains is
- If allocated on the heap (using malloc() or new char[]) you're responsible for releasing the memory afterwards and you will always have the overhead of a heap allocation.
- If you copy a text of more than 256 chars into the array, it might crash, produce ugly assertion messages or cause unexplainable (mis-)behavior somewhere else in your program.
- To determine the text's length, the array has to be scanned, character by character, for a \0 character.

A string is a class that contains a char array, but automatically manages it for you. Most string implementations have a built-in array of 16 characters (so short strings don't fragment the heap) and use the heap for longer strings.

<hr>

## Questions : Given a String A, arrange it in such a way so that the period of the string is minimum
Solution:
import java.util.*;
public class PeriodOfString {
    public static void main(String[] args) {
         String A = "abacbc";
        
        // OR USE SCANNER FOR INPUT
        // Scanner sc = new Scanner(System.in);
        // String A = sc.next();
        
         System.out.println(solve(A));
    }
    public static int solve(String A) {
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0;i<A.length();i++){
            if(map.containsKey(A.charAt(i))) {
                map.put(A.charAt(i),map.get(A.charAt(i))+1);
            }
            else {
                map.put(A.charAt(i),1);
            }
        }
        ArrayList<Integer> list = new ArrayList<>(map.values());
        int gcd = list.get(0);
        for(int i=0;i<list.size();i++) {
            gcd = gcd(gcd,list.get(i));
        }
        return A.length()/gcd;
    }
    public static int gcd(int A,int B) {
        if(A==0) return B;
        return gcd(B%A,A);
    }
}


<!-- N is length of String  -->
TimeComplexity: O(N)  
Space Complexity: O(N)

Example : Given a String , arranged its letters in such a way that the period of the string is minimum and return the length of the string.
        Input:
        A = "abacbc"
        Output:
        3
        Explanation:
        The given string can be arranged as "abcabc" in which abc is the minimum string which repeats afterwards.

