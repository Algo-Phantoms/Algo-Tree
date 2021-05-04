/* Balanced Bracket Problem
Explanation :- To check if the expression is balanced i.e. closing brackets and opening brackets match up well.
It will be an iterative solution in which loop will iterate over each character of expression, if opening brackets encountered then simply push in stack, if closing brackets 
encountered then if stack is empty return false or if top element of stack is not brackets significant other return false. After Iterating whole expression if stack not empty 
means some opening brackets doesn't have closing hence not balanced. At end if stack is empty means expression is balanced.
*/
import java.io.*;
import java.util.*;

public class Main {
public static void main(String[] args) throws Exception {

        Scanner scn = new Scanner(System.in);

        String str = scn.nextLine();

        Stack<Character> st = new Stack<>();

        for(int idx=0;idx<str.length();++idx)
        {
            char ch = str.charAt(idx);

            if(ch=='[' || ch=='{' || ch=='(' ) // If opening brackets encountered just push in stack
            {
                st.push(ch);
            }

            else if(ch==']')  // for closing bracket check if its significant one is present on top of stack ans also stack must not be empty
            {
                if(  st.size()==0 || st.peek()!='[' )
                {
                    System.out.println(false);
                    return;
                }
                st.pop();
            }

            else if (ch=='}')   // for closing bracket check if its significant one is present on top of stack ans also stack must not be empty
            {
                if(st.size()==0   || st.peek()!='{' )
                {
                    System.out.println(false);
                    return;
                }
                st.pop();
            }

            else if(ch==')')    // for closing bracket check if its significant one is present on top of stack ans also stack must not be empty
            {
               if( st.size()==0 || st.peek()!='(')
                {
                    System.out.println(false);
                    return;
                }
                st.pop();
            }
        }
        if(st.size()!=0)    // at the end if stack is not empty this means some opening brackets doesn't have closing pair so not balanced
        {
             System.out.println(false);
             return;
        }
        System.out.println(true);  // if all cases satisfies means brackets are balanced
       }
 }

/* for e.g  test case 1 = "[]" 
first '[' is encountered pushed in stack,  then ']' is encountered so check stack is not empty and has '[' at top so pop '[' .
At the end size of stack is zero hance, Balanced.
*/

/* test case 2 ="("
first '(' is encountered pushed in stack,  At the end size of stack is not zero hance,not Balanced.
*/

/* test case 3 = "}"
first '}' is encountered and stack is empty hence ']' doesn't have significant other so not Balanced.
*/
/*
Time Complexity: O(n) 
Auxiliary Space: O(n) for stack
*/
