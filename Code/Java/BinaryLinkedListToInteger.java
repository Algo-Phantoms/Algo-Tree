/* This is the code for the conversion of binary number in a linked list to Integer in Java*/


import java.util.*;
public class BinaryLinkedListToInteger {
    
    // class node is used as the block of the linked list
    static class node {

        /* the next variable is of node type and is to store the reference of the next 
        block present in the linked list otherwise it's value is null
        While the data variable is to store the value of the block either 1 or 0 */
        
        node next;
        int data;

        node(int data) {
            this.data = data;
            this.next = null; 
        }
    }

    public static node convertStringToLinkedList(String st) {
        /* this Function is convert the string into the singly linked list and 
        then return the head of the linked list  */

        int len = st.length();
        node head = null, tail = null;
        for(int i=0; i<len; i+=1) {

            int x = (int)st.charAt(i) - 48 ; // char to int
            node temp = new node(x);

            if(head == null){
                head = temp;
                tail = temp;
                continue;
            }
            tail.next = temp;
            tail = temp;
        }

        return head;
    }

    public static int convertLinkedListToInteger(node head, int result){
        
        if(head == null) return result; // base condition ie. the end of the list
        result *= 2;
        result += head.data;
        return (convertLinkedListToInteger(head.next, result));
    }
    
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        /* Taking binary number input as a String  */
        String input = sc.next();

        node head = convertStringToLinkedList(input);  //Creating a Linked list with the String input
        int number = convertLinkedListToInteger(head, 0); //Converting linked list data to an Integer
        System.out.println("Integer is : "+number);
    }
}

/*
Sample Input1: 1010
Sample Output 1: Integer is : 10

Sample Input 2: 1111
Sample Output 2: Integer is : 15

Sample Input 3 100000
Sample Output 3: Integer is : 32
*/