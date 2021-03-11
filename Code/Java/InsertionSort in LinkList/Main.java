class Linkedlist  {
    node head;
    node sorted;
    class node    {
        int val;
        node next;
        public node(int val)
        {
            this.val = val;
        }
    }
    void add(int val)  {
        node newNode = new node(val);
        newNode.next = head;
        head = newNode;
    }
    void insertion_Sort(node headref)   {
        sorted = null;
        node current = headref;
        while (current != null)  {
            node next = current.next;
            Insert_sorted(current);
            current = next;
        }
        head = sorted;
    }
    void Insert_sorted(node newNode)   {
        if (sorted == null || sorted.val >= newNode.val) {
            newNode.next = sorted;
            sorted = newNode;
        } else {
            node current = sorted;
            //find the node and then insert
            if (current.next == null || current.next.val >= newNode.val) {
            } else {
                current = current.next;
                while (true) {
                    if (current.next == null || current.next.val >= newNode.val) break;
                    current = current.next;
                }
            }
            newNode.next = current.next;
            current.next = newNode;
        }
    }

    void print_list(node head)   {
        while (true) {
            if (head == null) break;
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}
public class Main
{
    public static void main(String[] args) {
        Linkedlist l1=new Linkedlist();
        l1.add(5);
        l1.add(4);
        l1.add(6);
        l1.add(10);
        l1.add(17);
        l1.add(1);
        System.out.println("Original Linked List:");
        l1.print_list(l1.head);
        l1.insertion_Sort(l1.head);
        System.out.println("\nSorted Linked List:");
        l1.print_list(l1.head);
    }
}

