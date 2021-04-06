/*    Check if the Linked List is palindrome or not.
      Approach: We will traverse the linkedlist to first find the middle element and then reverse the 
      second half of the linked list in O(n/2) time. 
      Then we will check from both the directions of the linked list to see if it is a palindrome or not.
      We print "Yes" if its a palindrome otherwise "No".
*/
import java.util.*;

public class Check_LinkedList_palindrome {

	public static class ListNode {
		      int val;
		      ListNode next;
		      ListNode() {}
		      ListNode(int val) { this.val = val; }
		      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
		 }
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		
		int n= sc.nextInt();
		ListNode head= new ListNode(sc.nextInt());
		ListNode tempp= head;
		for(int i=0; i<n-1; i++) {
			tempp.next= new ListNode(sc.nextInt());
		}
		
		ListNode temp= head;
        int count=0;
        while(temp!=null){
            temp=temp.next; count++;
        }
        count= count/2;
        // the middle number i.e. count/2 is calculated above.
    
        ListNode midnode= head;
        ListNode fast= head;
        while(fast.next!=null && fast.next.next!=null){
            midnode= midnode.next;
            fast= fast.next.next;
        }
        
        ListNode prev= midnode;
        midnode= midnode.next;
        
        //we will start reversing other half here
        ListNode curr= midnode;
        ListNode next= null;
        while(curr!=null){
            next= curr.next;
            curr.next= prev;
            prev= curr;
            curr= next;
        }
        ListNode lastNode= prev;
        
        while(count-->0){
            if(head.val!=lastNode.val) {
            	System.out.println("No");
            	System.exit(1);
            }
            head= head.next;
            lastNode= lastNode.next;
        }
        System.out.println("Yes");
        
	}

}

/*
INPUT:
5
1 2 3 4 5
OUTPUT:
No

INPUT:
6
1 2 3 3 2 1
OUTPUT:
Yes


Complexity Analysis:  
    * Time complexity: O(N)
      Only traversal of the loop till N is needed.
    * Auxiliary Space: O(1) 
      There is no space required.
*/
