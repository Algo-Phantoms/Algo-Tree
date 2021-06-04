/*
 * To insert a node in a LinkedList.
 * There are 2 cases:
 * 1. To insert a node at the start of the linked list.
 * 2. To insert a node in between the linked list.
 */

import java.util.*;

class InsertionInLinkedList
{
    Node start;

    InsertionInLinkedList()
    {
        start = null;
    }

    void create(Node node) 
    {
        //This function is to create the LinkedList
        if (start == null)
        {
            start = node;
        }
        else 
        {
            Node temp = start;
            while (temp.address != null)
                temp = temp.address;
            temp.address = node;
        }
    }

    void display()
    {
        //This function is to display the linkedlist
        Node temp = start;
        System.out.println("Linked List: ");
        while (temp!= null)
        {
            System.out.print(temp.data + " ");
            temp = temp.address;
        } 
        System.out.println();
    }
    
    void insert(int pos, int value)
    {
        //This function is to insert a node in the linkedlist
        Node ptr = null;
        
        int ctr = 1;
        
        if(pos == 1)
        {
            Node temp = new Node(value);
            temp.data = value;
            temp.address = start;
            start = temp;
        }
        
        for(ptr = start; ptr != null; ptr = ptr.address)
        {
            ctr++;
            
            if(ctr == pos)
            {
                Node temp = new Node(value);
                temp.data = value;
                temp.address = ptr.address;
                ptr.address = temp;
            }
        }
    }
   
    public static void main()
    {
        Scanner scanner = new Scanner(System.in);

        InsertionInLinkedList ob = new InsertionInLinkedList();
        
        int data, flag=1, value, pos;
        while(flag!=0)
        {
            System.out.println("Enter data in linked list: ");
            data = scanner.nextInt(); scanner.nextLine();
            ob.create(new Node(data));

            System.out.println("Do you wish to continue? Enter 1 for yes and 0 for no: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }
        ob.display();
        
        System.out.println("Enter value to be inserted in the linked list: ");
        value = scanner.nextInt(); scanner.nextLine();
        System.out.println("Enter position of insertion in the linked list: ");
        pos = scanner.nextInt(); scanner.nextLine();
        
        ob.insert(pos, value);
        ob.display();
    }
}
class Node
{
    public int data;
    public Node address;
    Node(int d) 
    {
        data = d;
        address = null;
    }
}   

/*
  Test Cases-
  
  1.
  Enter data in linked list: 
  1
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  2
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  3
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  4
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  5
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  0
  Linked List: 
  1 2 3 4 5 
  Enter value to be inserted in the linked list: 
  6
  Enter position of insertion in the linked list: 
  3
  Linked List: 
  1 2 6 3 4 5 
  
  2.
  Enter data in linked list: 
  1
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  2
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  3
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  4
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  1
  Enter data in linked list: 
  5
  Do you wish to continue? Enter 1 for yes and 0 for no: 
  0
  Linked List: 
  1 2 3 4 5 
  Enter value to be inserted in the linked list: 
  7
  Enter position of insertion in the linked list: 
  1
  Linked List: 
  7 1 2 3 4 5 
  
  Time Complexity: O(n)
  Space Complexity: O(n)
  where n is the number of elements in the linked list
 */