/*    Floyd’s Cycle-Finding Algorithm 
      Approach: This is the fastest method and optimized approach to traverse a LinkedList:  
        * Traverse linked list using two pointers.
        * Move one pointer(slow_p) by one and another pointer(fast_p) by two.
        * If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.   
*/
import java.io.*;
import java.util.*;
public class Cycle_Detection_In_Linked_List {
    // Creation of SinglyLinkedListNode 
    static class SinglyLinkedListNode {
        public int data;
        public SinglyLinkedListNode next;
        
        public SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }
    // Creation of Singly Linked List with insertNode function  
    static class SinglyLinkedList {
        public SinglyLinkedListNode head;
        public SinglyLinkedListNode tail;

        public SinglyLinkedList() {
            this.head = null;
            this.tail = null;
        }
         
        public void insertNode(int nodeData) {
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
            }
            this.tail = node;
        }
    }
    static boolean hasCycle(SinglyLinkedListNode head) {
            if(head == null ){
                 return false;
              }
              SinglyLinkedListNode slow = head;
              SinglyLinkedListNode fast = head.next;
              while(slow != fast) {
                    if(fast == null || fast.next == null || slow == null ) {
                       return false;
                    }
                    slow = slow.next;
                    fast = fast.next.next;
              }
              return true;
    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        System.out.println("Enter the test cases: ");
        int tests = scanner.nextInt();

        for (int testsItr = 0; testsItr < tests; testsItr++) {
        	System.out.println("Enter the pos ( is used to denote the index of the node that tail's next pointer is connected to ): ");
            int index = scanner.nextInt();
           
            SinglyLinkedList llist = new SinglyLinkedList();
            System.out.println("Enter the llist count: ");
            int llistCount = scanner.nextInt();

            for (int i = 0; i < llistCount; i++) {
            	System.out.println("Enter next node: ");
                int llistItem = scanner.nextInt();
                llist.insertNode(llistItem);
            }
          
          	SinglyLinkedListNode extra = new SinglyLinkedListNode(-1);
            SinglyLinkedListNode temp = llist.head;

            for (int i = 0; i < llistCount; i++) {
                if (i == index) {
                    extra = temp;
                }
                if (i != llistCount-1) {
                    temp = temp.next;
                }
            }
            temp.next = extra;

            boolean result = hasCycle(llist.head);
            if( result == true ) {
                System.out.println("The given LList has cycle. "); 
            }else {
            	System.out.println("The LList has no cycle "); 
            }
        }
        scanner.close();
    }
}
/*
Sample Input 1:
Enter the test cases: 
1
Enter the pos ( is used to denote the index of the node that tail's next pointer is connected to ): 
1
Enter the llist count: 
3
Enter next node: 
1
Enter next node: 
2
Enter next node: 
3
The given LList has cycle.

Sample Input 2:
Enter the test cases: 
1
Enter the pos ( is used to denote the index of the node that tail's next pointer is connected to ): 
-1
Enter the llist count: 
1
Enter next node: 
1
The LList has no cycle 

Complexity Analysis:  
    * Time complexity: O(N)
      Only one traversal of the loop is needed.
    * Auxiliary Space: O(1) 
      There is no space required.
*/
