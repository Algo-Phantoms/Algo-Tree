public class linkedList {
    node head = null;
    static class node {
        int val;
        node next;

        public node(int val)
        {
            this.val = val;
        }
    }

    node sortedMerge(node a, node b)
    {
        node result=null;
        if (a != null) {
            if (b == null)
                return a;
            if (a.val <= b.val) {
                result = a;
                result.next = sortedMerge(a.next, b);
            } else {
                result = b;
                result.next = sortedMerge(a, b.next);
            }
            return result;
        } else {
            return b;
        }
    }

    node mergeSort(node h)
    {
        if (h == null || h.next == null) {
            return h;
        }
        node middle = getMiddle(h);
        node nextofmiddle = middle.next;
        middle.next = null;
        node left = mergeSort(h);
        node right = mergeSort(nextofmiddle);
        node sortedlist = sortedMerge(left, right);
        return sortedlist;
    }
    node getMiddle(node h)
    {
        if (h == null)
            return h;
        node fastptr = h.next;
        node slowptr = h;
        while (fastptr != null) {
            fastptr = fastptr.next;
            if (fastptr != null) {
                slowptr = slowptr.next;
                fastptr = fastptr.next;
            }
        }
        return slowptr;
    }

    void push(int new_data)
    {
        node new_node = new node(new_data);
        new_node.next = head;
        head = new_node;
    }
    void printList(node headref)
    {
        while (true) {
            if (headref == null) break;
            System.out.print(headref.val + " ");
            headref = headref.next;
        }
    }

    public static void main(String[] args)
    {

        linkedList li = new linkedList();
        li.push(15);
        li.push(10);
        li.push(5);
        li.push(20);
        li.push(3);
        li.push(2);
        System.out.println("Linked List without sorting is :");
        li.printList(li.head);
        li.head = li.mergeSort(li.head);
        System.out.print("\n Sorted Linked List is: \n");
        li.printList(li.head);
    }
}