/*
To delete a node from a LinkedList.
There ar 3 cases:
1. Deleting a node from the start:
-> Modify the head pointer to point the 2nd node.
2. Deleting a node from the end:
-> Change the address of the 2nd last node to null.
3. Deleting a node from a specific position:
-> Change the address of the previous node to the address of the next node.
 */
import java.util.*;
public class DeleteNodeFromLinkedList
{
    Scanner scanner = new Scanner(System.in);

    Node start;

    DeleteNodeFromLinkedList()
    {
        start = null;
    }

    public void create(Node node) 
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
    
    void delete(int pos)
    {
        Node ptr = null;
        
        int ctr=1;
        
        if(pos==1)
        { 
            start=start.address;
        }
        
        for(ptr=start;ptr!=null;ptr=ptr.address)
        {
            ctr++;
            if(ctr==pos)
            {
                ptr.address = ptr.address.address;
            }
        }
    }

    public static void main()
    {
        Scanner scanner = new Scanner(System.in);

        DeleteNodeFromLinkedList ob = new DeleteNodeFromLinkedList();
        
        int data, flag=1, pos;
        while(flag!=0)
        {
            System.out.println("Enter data in linked list: ");
            data = scanner.nextInt(); scanner.nextLine();
            ob.create(new Node(data));

            System.out.println("Do you wish to continue? Enter 1 for yes and 0 for no: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }
        ob.display();
        
        flag=1;
        
        while(flag!=0)
        {
            System.out.println("Enter position of node to delete: ");
            pos = scanner.nextInt(); scanner.nextLine();
            
            ob.delete(pos);
            
            ob.display();
            
            System.out.println("Do you wish to continue? Enter 1 for yes and 0 for no: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }

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

Input/Output:
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
Enter position of node to delete: 
3
Linked List: 
1 2 4 5 
Do you wish to continue? Enter 1 for yes and 0 for no: 
0

Input/Output:
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
Enter position of node to delete: 
1
Linked List: 
2 3 4 5 
Do you wish to continue? Enter 1 for yes and 0 for no: 
0
*/

/* Time Complexity: O(1)
 Space Complexity: O(size of linked list) */

 