/*
*           Insertion in Linked List
Insertion in Linked List can be achieved in 3 ways i.e:
   1.At the front of Linked List
   2.after a given node.
   3.At the end of Linked List.
    
*
*   Output: 
*
*   Initial list is: 1 2 3 
*   After Inserting at the Beginning, list is: 4 1 2 3 
*   After Inserting at the End, list is: 4 1 2 3 5 
*   After Inserting after given node, list is: 4 1 2 3 5 6  
*
*
*
*/

class Node {
    int data;
    Node next;

    public Node(int key) {
        data = key;
        next = null;
    }
}

class LinkedListInsertion {
    Node head;

    LinkedListInsertion() {
        head = null;
    }

    void printList() {
        Node h = head;
        while (h != null) {
            System.out.print(h.data + " ");
            h = h.next;
        }

    }

    /* Inserting at the beginning of a Linked List. */
    void insertAtBeginning(int key) {

        Node temp = new Node(key);
        temp.next = head;
        head = temp;

    }

    /* Inserting at the end of a Linked List. */
    void insertAtEnd(int key) {
        Node h = head;
        if (h == null) {
            Node temp = new Node(key);
            temp.next = null;
            head = temp;
        } else {
            while (h.next != null) {
                h = h.next;
            }
            Node temp = new Node(key);
            temp.next = null;
            h.next = temp;
        }
    }

    /* Inserting after a specific node. */
    void insertAfterNode(int key, int nodeAfter) {
        Node h = head;
        if (h == null) {
            System.out.println("The node can't be inserted in this case as node " + nodeAfter + " doesn't exist.");
        } else {
            while (h.data != nodeAfter) {
                h = h.next;
                if (h == null) {
                    System.out.println("Node doesn't exist.");
                    return;
                }
            }

            Node temp = new Node(key);
            temp.next = h.next;
            h.next = temp;
        }

    }

    /* Main method. */
    public static void main(String args[]) {
        LinkedListInsertion list = new LinkedListInsertion();

        list.head = new Node(1);
        list.head.next = new Node(2);
        list.head.next.next = new Node(3);
        System.out.print("Initial list is: ");
        list.printList();
        System.out.println();
        list.insertAtBeginning(4);
        System.out.print("After Inserting at the Beginning, list is: ");
        list.printList();
        System.out.println();
        list.insertAtEnd(5);
        System.out.print("After Inserting at the End, list is: ");
        list.printList();
        System.out.println();
        list.insertAfterNode(6,5);
        System.out.print("After Inserting after given node, list is: ");
        list.printList();
        System.out.println();

    }
}

// Time and Space Complexity of Insertion at front is O(1)
// Time and Space Complexity of Insertion after a given node is O(n) , n is number of nodes.
// Time and Space Complexity of Insertion at end is O(n), n is number of nodes.
