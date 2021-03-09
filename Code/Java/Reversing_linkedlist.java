/*Here Pointer to the head node of a linked list is given, 
 * the task is to reverse the linked list. We are going to reverse the list by changing the links between nodes.We are using Iterative method.*/
/*Initialize three pointers prev as NULL, curr as head and next as NULL.
          Iterate through the linked list. In loop, do following. 
          ->Before changing next of current, 
            -> store next node 
                  next = curr->next
            -> Now change next of current 
           *This is where actual reversing happens 
                  curr->next = prev 
                ->Move prev and curr one step forward. 
                  prev = curr 
                  curr = next*/


import java.util.*;   //used for Scanner function
import java.io.*;     //used for IOException

class Node{                    //creating Node class 
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
    
}
public class Reversing_linkedlist {


                 static void printList(Node node)   //Function to Print LinkedList
                 { 
	                   while (node != null) 
	                   { 
		                   System.out.print(node.data + " "); 
		                   node = node.next;                         //referring to next node
	                   } 
	                System.out.println(); 
                  } 
         public static void main(String args[]) throws IOException {          //Main starts
    
                        Scanner sc =new Scanner(System.in);                  //Class used for input taking
                        System.out.println("Enter The Numbers Of Nodes in LinkedList:");
    	                int n = sc.nextInt();                                //Number of nodes
    
                        Node head = new Node(sc.nextInt());
                        Node tail = head;
    
                        for(int i=0; i<n-1; i++)                              //For Loop for taking Input
                        {
                             tail.next = new Node(sc.nextInt());
                             tail = tail.next;
                        }
                          
                          System.out.println("Entered LinkedList is:");
                          printList(head);  
                          Solution ob = new Solution();                       // object creation for solution class
                          head = ob.reverseList(head);                         //using ob object reverseList is called
                          System.out.println("Reversed LinkedList is:");
                          printList(head); 
                         
            } 
 }
class Solution{
  
    Node reverseList(Node head)                 //Function for reversing
    {  
    	Node current = head;
        Node prev = null;
        while(current!=null){                       //Checking if the linked list is not null
        head = current.next;                        //assigning next of current to head
        current.next = prev;                        //next of current node = prev;
        prev = current;                             //prev is equal to current node
        current = head;                             //current node is equal to head
       }
    
  return prev;                                      
      
   }
}

/*INPUT AND OUTPUT*/
/*
 * 
 *Enter The Numbers Of Nodes in LinkedList:
  5
  1
  2
  3
  4
  5
  Entered LinkedList is:
  1 2 3 4 5 
  Reversed LinkedList is:
  5 4 3 2 1 
 */
/*
 *Enter The Numbers Of Nodes in LinkedList:
  4
  9
  8
  7
  6
  Entered LinkedList is:
  9 8 7 6 
  Reversed LinkedList is:
  6 7 8 9 
 */
/*TIME COMPLEXITY & SPACE COMPLEXITY*/
/*TIME COMPLEXITY:-O(n)
 * SPACE COMPLEXITY:-O(1)*/

