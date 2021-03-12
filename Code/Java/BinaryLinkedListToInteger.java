/* This is the code for the conversion of binary number in a linked list to Integer in Java

Algorithm : Traverse the linked list from head (head part contains the most significant bit 
            of the binary number represented using linked list) to the tail (contains the least significant bit)
            Let initially our ans = 0; So as we start traversing , 
            multiply ans with 2 (2 is base of decimal  number) as
            ans = ans * 2;
            And then add the bit(either 1 or 0) in the ans as 
            ans = ans + 1;
            and then move on to other block and perfrom similar operation , 
            When we ended the traversing of the linked list , the value of the ans is the desired result

*/

import java.io.*;
import java.util.*;
public class BinaryLinkedListToInteger {
    
    // class Node is used as the block of the linked list
    static class Node {

        /* the next variable is of Node type and is to store the reference of the next 
        block present in the linked list otherwise it's value is null
        While the data variable is to store the value of the block either 1 or 0 */
        
        private Node next;
        private int data;

        Node(int data) {
            
            /* Constructor */

            this.data = data;
            this.next = null; 
        
        }
        Node getNext(){
            /* Function return the refrence of the next Node */ 
            
            return next;
        }
        void addNext(Node next){
            /* Function is to update the value of the next variable */
        
            this.next = next;
        }
        int getData(){
            /* Function returns the value of data variable */
            
            return data;
        }
    }

    public static Node convertStringToLinkedList(String st) {
        
        /* this Function is convert the string into the singly linked list and 
        then return the head of the linked list  */

        int len = st.length();
        Node head = null;
        Node tail = null;
        for(int i=0; i<len; i+=1) {

            int x = (int)st.charAt(i) - 48 ; // char to int
            Node temp = new Node(x);

            if(head == null){
                head = temp;
                tail = temp;
                continue;
            }
            tail.addNext(temp);
            tail = temp;
        }

        return head;
    }

    public static int convertLinkedListToInteger(Node head, int val){
        /* Function is to convert the Linked list to Integer as mentioned in the algorithm above */
        
        if(head == null) return val; // base condition i.e. the end of the list , returns the Answer
        val *= 2;
        val += head.getData();
        return (convertLinkedListToInteger(head.getNext(), val));
    }
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String args[]) {

        /* Taking binary number input as a String  */
        
        String input = sc.next();

        Node head = convertStringToLinkedList(input);  //Creating a Linked list with the String input
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


Complexity Analysis :

        *Time complexity : O(N) - The linked list is traversed only once to get the result , hence it is linear
        
        *Auxillary Space : O(1) - Considering we have Linked List beforehand , to store the ans only
                                  we required a constant space

*/