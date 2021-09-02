import java.util.Scanner;
class LinkedList 
{
        static Node head;

	// A linked list node
        static class Node
       {
	int data;
	Node next;
        };

       static Node push( Node head, int data) // Function to insert a node at the beginning 
       {
	
	Node new_node = new Node();// allocate node
	
	new_node.data = data; // enter the data 

	new_node.next = (head); //link the old list to the new node

	(head) = new_node; // move the head to point to the new node 

	return head;
        }


	
	int detectAndRemoveLoop(Node node) // Function that detects loop in the list
	{
		Node first= node, last = node;
		
		while (first!= null && last != null
			&& last.next != null) 
			{
			  first= first.next;
			  last = last.next.next;
 
 			  if (first== last) 
			{
				removeLoop(first, node);
				return 1;
			}
		}
		return 0;
	}

	void removeLoop(Node loop, Node curr) // Function to remove loop
	{
		Node point_1 = null, point_2 = null;
		point_1 = curr;
		
		while (1 == 1) 
		{
			point_2 = loop;
			while (point_2.next != loop && point_2.next != point_1) 
			{
				point_2 = point_2.next;
			}
			
			if (point_2.next == point_1) 
			{
				break;
			}
			point_1 = point_1.next;
		}

		point_2.next = null;
	}

	
	void printList(Node node) // Function to print the linked list
	{
		while (node != null) 
		{
			System.out.print(node.data + " ");
			node = node.next;
		}
	}
	public static void main(String[] args)
	{
		LinkedList list = new LinkedList();
		Scanner sc = new Scanner(System.in);
		System.out.print("Please enter the number of nodes : ");
		int n = sc.nextInt();
		
		for (int i = 1; i<n;i++)
		{  System.out.print("Please enter the "+i+" node : ");
		   int temp = sc.nextInt();
		   head=push(head,temp);
		 }
		System.out.println("Do you want to connect the end to a specific node? Enter 1 for YES");
		int ans = sc.nextInt();
		if( ans == 1)
		 {
		    System.out.println("Enter the node number.");
		    int ans_2 = sc.nextInt();
		    Node val= head;
		    for(int i=1; i<ans_2;i++)
		    {
		        val= val.next;
		      }
		    head = val;       
		    System.out.print("Linked List entered:");
		    list.printList(head);
		    list.detectAndRemoveLoop(head);
		    System.out.println("Linked List after removing loop :");
		    list.printList(head);
		  }  
		else
		   System.out.println("There is no loop here.");
	       }
}

