/* 
Way of reversing circular linked list
1. Traverse each node
2. Reverse the link of each node
3. Move to the next node and apply similar procedure
4. Change start pointer to new node now
5. Circular linked list has been reversed
*/
import java.io.*;
class Node                 // class for creating Node
{
    public int data;
    public Node link;
    public Node()           // default constructor
    {
        link = null;
        data = 0;
    }
    public Node(int d, Node n)         // parameterized constructor
    {
        data = d;
        link = n;
    }
}
class Reverse_Circular_Linked_List 
{
    protected Node start = null;               // start pointer to point at beginning of circular linked list
    public Node insert(int val)             // method to insert a node at the end of list
    {
        Node nptr, save;
        nptr = new Node(val, null);
        if (start==null)
            start = nptr;
        else
        {
            save = start;
            while(save.link!=start)
                save = save.link;
            save.link = nptr;
        }
        nptr.link = start;
        return start;
    }
    public Node reverse()                 // method for reversing the links in the entire list
    {
        if (start==null)
        {
            System.out.println("Empty list") ;
            return null;
        }
        Node prev = null;
        Node curr = start;
        Node temp;
        while(curr.link!=start)
        {
            temp = curr.link;
            curr.link = prev;
            prev = curr;
            curr = temp;
        } 
        curr.link = prev;
        start.link = curr;
        start = curr;
        return start;
    }
    public void printit()                  // method to print elements of the linked list
    { 
        if (start == null) 
            return; 
        Node temp = start;
        while (temp.link != start)
        { 
            System.out.print( temp.data + " "); 
            temp = temp.link; 
        } 
        System.out.print( temp.data + " ");
    } 
}
public class ReverseCircLinkList
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        int data, n;
        System.out.println("Enter the number of nodes in linked list : ");
        n = Integer.parseInt(b.readLine());
        Reverse_Circular_Linked_List ll =new Reverse_Circular_Linked_List();
        for(int i=1;i<=n;i++)
        {
            System.out.println("Enter data : ");
            data = Integer.parseInt(b.readLine());
            ll.insert(data);
        }
         System.out.println("Linked List before reversal : ");
         ll.printit();
         System.out.println();
         ll.start = ll.reverse();
         System.out.println("Linked List after reversal : ");
         ll.printit();
    }
}

/* 
Test cases : 

Input 1 : Enter the number of nodes : 4
          5 7 11 45
Output 1 : Linked List before reversal :
           5 7 11 45
           Linked List after reversal :
           45 11 7 5
           
Input 2 : Enter the number of nodes : 7
          11 34 56 78 89 2 44
Output 2 : Linked List before reversal :
           11 34 56 78 89 2 44
           Linked List after reversal :
           44 2 89 78 56 34 11
           
Time complexity : O(n)
Space complexity : O(1)
*/
