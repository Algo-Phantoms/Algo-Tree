/*
This is a menu driven (Java)program which has the following choices:
1. Insert at the beginning.
2. Insert at the end.
3. Insert at a specific position.
4. Delete an element.
5. Display all the elements in the list.
(Insert at beginning - To insert an element at the beginning of the doubly linked list.
Insert at end - To insert an element at the end of the doubly linked list.
Insert at specific position - To insert an element at the specified position in the doubly linked list.
Delete - To delete an element from the doubly linked list.)
*/ 
import java.util.*;
import java.io.*;
class Node
{
    int data;
    Node prevnode,next;
    Node(int data)
    {
        this.data=data;
        prevnode=null;
        next=null;
    }
}
class LinkedList
{
    int i=1,count=1;
    Node head;
    LinkedList()
    {
        head=null;
    }
    void insertAtBeginning(int val)
    {
        Node newnode=new Node(val);
        if(head==null)
        head=newnode;
        else
        {
            head.prevnode=newnode;
            newnode.next=head;
            head=newnode;
        }
    }
    void insertAtEnd(int val)
    {
        Node newnode=new Node(val);
        if(newnode==null)
        System.out.println("No space");
        Node temp=head;
        while(temp.next!=null)
            temp=temp.next;
        temp.next=newnode;
        newnode.prevnode=temp;
    }
    void insertAtPosition(int pos)
    {
        Node temp=head;
        while(temp!=null)
        {
            count++;
            temp=temp.next;
        }
        if(pos>count)
        System.out.println("Invalid position");
        else
        {
            temp=head;
            while(i<pos-1)
               temp=temp.next;
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter the element you want to insert");
            Node newnode=new Node(sc.nextInt());
            newnode.next=temp.next;
            temp.next.prevnode=newnode;
            temp.next=newnode;
            newnode.prevnode=temp;
        }
    }
    void delete(int val)
    { 
        Node temp=head;
        while(temp.data!=val&&temp.next!=null)
        temp=temp.next;
        if(temp==head&&val==temp.data)
        {
            head=head.next;
            head.prevnode=null;
        }
        else if(temp.next==null&&val==temp.data)
            temp.prevnode.next=null;
        else if(temp.data==val)
        {
            temp.next.prevnode=temp.prevnode;
            temp.prevnode.next=temp.next;
        }
        else
        System.out.println("Element not found");
    }
    void display()
    {
        if(head==null)
        System.out.println("List is empty");
        else
        {
            Node temp=head;
            while(temp!=null)
            {
                System.out.print(temp.data+" ");
                temp=temp.next;
            }
            System.out.println();
        }
    }
}
public class DoubleLinkedList1
{
    public static void main(String args[])
    {
        int ch;
        LinkedList l=new LinkedList();
        Scanner sc=new Scanner(System.in);
        do
        {
            System.out.println("1.Insert at beginning");
            System.out.println("2.Insert at end");
            System.out.println("3.Insert at specific position");
            System.out.println("4.Delete");
            System.out.println("5.Exit");
            System.out.println("Enter your choice");
            ch=sc.nextInt();
        switch(ch)
        {
            case 1: 
            System.out.println("Enter the data");
            l.insertAtBeginning(sc.nextInt());
            l.display();
            break;
            case 2:
            System.out.println("Enter the data");
            l.insertAtEnd(sc.nextInt());
            l.display();
            break;
            case 3:
            System.out.println("Enter the position");
            l.insertAtPosition(sc.nextInt());
            l.display();
            break;
            case 4:
            System.out.println("Enter the element");
            l.delete(sc.nextInt());
            l.display();
            break;
            case 5:
            System.out.println("Exiting...");
            break;
            default:
            System.out.println("Invalid choice");
        }
        }while(ch!=5);

    }
}

/*
Input format in test case:
1st line contains the choice the make.
2nd line contains the element they want to insert, delete, act according to the choice they make 
(except in the case of third choice, where the 2nd line is to enter the position and the 3rd line is to enter the element).

Test case 1:
1.Insert at beginning
2.Insert at end
3.Insert at specific position
4.Delete
5.Exit
Enter your choice
1
Enter the data
23
Output: 23  

Test case 2:
1.Insert at beginning
2.Insert at end
3.Insert at specific position
4.Delete
5.Exit
Enter your choice
2
Enter the data
56
Output: 23 56

Test case 3:
1.Insert at beginning
2.Insert at end
3.Insert at specific position
4.Delete
5.Exit
Enter your choice
3
Enter the position
2
Enter the element you want to insert
88
Output: 23 88 56

Time complexity : O(n)
Space complexity : O(n)
*/
