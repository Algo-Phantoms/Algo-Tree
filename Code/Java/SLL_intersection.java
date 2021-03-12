package algotree;
/*
To find the point/node of intersection of two singly linked lists given the head pointers to the two linked lists.
If there is no intersecting node return -1.

Note :
	1. The intersecting node is at the same memory location for both the lists.
	2. None of the lists have a cycle.
	
Constraints :
	1. 1<= Size of linked lists <=3*10^4
	2. 0<= Node values <=10^5
	
Brute Force Approach:
	Using 2 nested loops check for each node of the first list if any node of the second list is the same.
	Time Complexity: O(m*n) where m,n are the sizes of the lists
	Space Complexity: O(1)
	
Optimized Approach : 
	1. Find the difference between the number of nodes in each list.
	2. Traverse the bigger list until this difference value.
	3. Then traverse both the lists in parallel until there is a node with the same address for both the lists.
	Time Complexity : O(m+n) where m,n are the sizes of the lists
	Space Complexity: O(1)
*/

public class SLL_intersection {
	
	//Class which defines the structure of each node in the linked list
	static class Node{
		public int data;
		public Node next;
	}
	
	
	
	//Function to count the number of nodes in a linked list
	static int count_nodes(Node head) {
		int c=0;
		Node temp = head;
		while(temp!=null) {
			c++;
			temp = temp.next;
		}
		return c;
	}
	
	//Function to find the intersecting point of the two linked lists
	static int findMergeNode(Node head1,Node head2) {
		int count1 = count_nodes(head1);
		int count2 = count_nodes(head2);
		int diff;
		int result=-1;
		Node curr1 = head1;
		Node curr2 = head2;
		//Find the difference and traverse the bigger list to that point
		if(count1>count2) {
			diff = count1-count2;
			for(int i=0;i<diff;i++)
				curr1 = curr1.next;
		}else {
			diff = count2-count1;
			for(int i=0;i<diff;i++)
				curr2 = curr2.next;
		}
		//Now equal number of nodes left in both the lists
		//Traverse the lists simultaneously and check for common node
		while((curr1!=null)&&(curr2!=null)) {
			if(curr1==curr2) {
				result = curr1.data;
				break;
			}
			curr1 = curr1.next;
			curr2 = curr2.next;
		}
		return result;
	}
	
	public static void main(String[] args) {
		Node head1 = new Node();
		Node head2 = new Node();
		System.out.println("Test Case 1:");
		/*
		    1st Linked List : 2 -> 4 -> 6 -> 8 -> 10
		    2nd Linked List : 3 -> 5 -> 8 -> 10
		 */
		//Head Node of 1st linked list
		head1.data = 2;
		//Head Node of 2nd Linked List
		head2.data = 3;
		Node newNode;
		//Creation of second linked list
		newNode = new Node();
		newNode.data = 5;
		head2.next = newNode;
		//Creation of first linked list
		newNode = new Node();
		newNode.data = 4;
		head1.next = newNode;
		
		newNode = new Node();
		newNode.data = 6;
		head1.next.next = newNode;
		
		newNode = new Node();
		newNode.data = 8;
		head1.next.next.next = newNode;
		head2.next.next = newNode;
		
		newNode = new Node();
		newNode.data = 10;
		head1.next.next.next.next = newNode;
		
		head1.next.next.next.next.next = null;
		
		int result;
		result = findMergeNode(head1,head2);
		if(result!=-1)
			System.out.println("The two linked lists intersect at node value "+result);
		else
			System.out.println("The two linked lists do not intersect");
		
		
		System.out.println("Test Case 2:");
		/*
		    1st Linked List : 4 -> 8 -> 12
		    2nd Linked List : 3 -> 5 -> 7 -> 10
		 */
		//Head Node of 1st linked list
		head1.data = 4;
		//Head Node of 2nd Linked List
		head2.data = 3;
	
		//Creation of first linked list
		newNode = new Node();
		newNode.data = 8;
		head1.next = newNode;
		
		newNode = new Node();
		newNode.data = 12;
		head1.next.next = newNode;
		
		head1.next.next.next = null;
		
		//Creation of second linked list
		newNode = new Node();
		newNode.data = 5;
		head2.next = newNode;
		
		newNode = new Node();
		newNode.data = 8;
		head2.next.next = newNode;
		
		newNode = new Node();
		newNode.data = 10;
		head2.next.next.next = newNode;
		
		head2.next.next.next.next = null;
		
		result = findMergeNode(head1,head2);
		if(result!=-1)
			System.out.println("The two linked lists intersect at node value "+result);
		else
			System.out.println("The two linked lists do not intersect");
		
	}
	
}
/* 
Test Case 1:
1st Linked List : 2 -> 4 -> 6 -> 8 -> 10
2nd Linked List : 3 -> 5 -> 8 -> 10

Test Case 2:
1st Linked List : 4 -> 8 -> 12
2nd Linked List : 3 -> 5 -> 7 -> 10

Output:
Test Case 1:
The two linked lists intersect at node value 8
Test Case 2:
The two linked lists do not intersect

Time Complexity : O(n)
Space Complexity : O(1)
*/
