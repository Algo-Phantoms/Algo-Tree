
/**
 * Author - Khushee Kapoor
 * 
 * To merge two sorted linked lists.
 * Algorithm: (class MergeSortedLinkedList)
 * 1. Node temp points to the start of the linked list, and Node tail points to the end.
 * 2. Node temp selects the smaller element from the two linked lists and links it to the
 *    tail of the final linked list, moving the tail one step forward.
 * 3. The process repeats until the data from the linked lists are over.
 * 4. In case one linked list is longer, the temp node links it to the tail node.
 *  
 */
import java.util.*;

class Driver
{
    /**
     * This is a driver class. It is used to:
     * -> instantiate two objects for two linked lists (void main)
     * -> create two linked lists (void create)
     * -> display the linked lists (void display)
     * -> call the MergedSort function form MergeSortedLinkedList class (void main)
     */

    Node start; 

    public static void main(String args[])
    {
        /**
         * This function acts as driver code to create the linked lists,
         * and call the functions to merge the sorted linked lists and
         * display them.
         */
        Scanner scanner = new Scanner(System.in);

        Driver ob1 = new Driver();
        Driver ob2 = new Driver();

        int data, flag=1;
        while(flag!=0)
        {
            System.out.println("Enter data in linked list 1 in sorted manner: ");
            data = scanner.nextInt(); scanner.nextLine();
            ob1.create(new Node(data));

            System.out.println("Do you wish to continue? Enter 1 for yes and 0 for no: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }
        
        flag=1;
        
        while(flag!=0)
        {
            System.out.println("Enter data in linked list 2 in sorted manner: ");
            data = scanner.nextInt(); scanner.nextLine();
            ob2.create(new Node(data));

            System.out.println("Do you wish to continue? Enter 1 for yes and 0 for no: ");
            flag = scanner.nextInt(); scanner.nextLine();
        }

        ob1.start = new MergeSortedLinkedList().MergeSorted(ob1.start, ob2.start);
        ob1.display();     

    }

    public void create(Node node) 
    {
        //This function is to create the linkedlist
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
        System.out.println("Final Linked List: ");
        while (temp!= null)
        {
            System.out.print(temp.data + " ");
            temp = temp.address;
        } 
        System.out.println();
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

class MergeSortedLinkedList
{
    Node MergeSorted (Node A, Node B)
    {
        Node temp = new Node(0);
        Node tail = temp;
        
        while(true) 
        {
            if(A == null)
            {
                tail.address = B;
                break;
            }
            if(B == null)
            {
                tail.address = A;
                break;
            }
            if(A.data >= B.data)
            {
                tail.address = B;
                B = B.address;
             } 
            else
            {
                tail.address = A;
                A = A.address;
            }

            tail = tail.address;
        }
        return temp.address;
    }
}

/**
 * Test-
 * Enter data in linked list 1 in sorted manner: 
 * 1
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 1
 * Enter data in linked list 1 in sorted manner: 
 * 4
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 1
 * Enter data in linked list 1 in sorted manner: 
 * 10
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 0
 * Enter data in linked list 2 in sorted manner: 
 * 2
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 1
 * Enter data in linked list 2 in sorted manner: 
 * 6
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 1
 * Enter data in linked list 2 in sorted manner: 
 * 17
 * Do you wish to continue? Enter 1 for yes and 0 for no: 
 * 0
 * Final Linked List: 
 * 1 2 4 6 10 17 
 */

/**
 * Time Complexity: O(m+n)
 * where m and n are the lengths of the linked lists
 * 
 * Space Complexity: O(1)
 */

