//Java program to merge K-sorted linked list.
//User will provide k sorted linked list and program will merge them and return the listed list in sorted order.
//Methods is based on divide and conquer method

import java.util.*;

//Main class which contains main method
//It internally calls Solution class which has a method for merge
public class MergedKSortedLinkedList{

    //main method
    public static void main(String args[]){
        
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of Linked List");
        int k = scanner.nextInt();
        Node ll[] = new Node[k];
	    for(int i=0;i<2;i++){
	        ll[i] = new Node();
            System.out.println("Enter number of elements for "+(i+1)+" Linked List");
            int n = scanner.nextInt();
            for(int j=0;j<n;j++){
                System.out.println("Enter "+(j+1)+" element for "+ (i+1)+" Linked List");
                ll[i].insert(scanner.nextInt());
            }
	    }
	    Solution s = new Solution();
	    Node head = s.mergeKLists(ll);
	    head.show();
        scanner.close();
    }
}

//Class contains methods for merge k sorted linked list
class Solution {
    //this method will be called from main method
    public Node mergeKLists(Node[] lists) {
        if(lists.length==0) return null;
        if(lists.length==1) return lists[0];
        int k = lists.length;
        Node h2 = null;
        Node h1 = merge(lists,0,k/2);
        if(k/2+1<=k-1)
            h2 = merge(lists,k/2+1,k-1);
        return mergehelper(h1,h2);
    }
    
    //method will divide the Node[] into smaller part
    public Node merge(Node[] lists, int left, int right){
        Node h2 = null, h1 = null;
        if(left==right)
            return lists[left];
        int k = right-left+1;
        h1 = merge(lists, left, left+k/2-1);
        h2 = merge(lists, left+k/2, right);
        return mergehelper(h1,h2);
    }
    
    //Helper class which will help to merge the linked list in sorted form
    public Node mergehelper(Node h1, Node h2)
    {
        Node temp = new Node(0);
        Node dummy = temp;
        if(h1==null && h2 == null) return null;
        if(h1 == null) return h2;
        if(h2 == null) return h1;
        while(h1!=null && h2!=null){
            if(h1.data>h2.data){
                dummy.next = h2;
                h2 = h2.next;
            }
            else{
                dummy.next = h1;
                h1 = h1.next;
            }
            dummy = dummy.next;
        }
        if(h1!=null)
            dummy.next = h1;
        if(h2!=null)
            dummy.next = h2;
        return temp.next;
    }
}

/*
Input:
Enter number of Linked List
3
Enter number of elements for 1 Linked List
3
Enter 1 element for 1 Linked List
1
4
5
Enter number of elements for 2 Linked List
3
Enter 1 element for 1 Linked List
1
3
4
Enter number of elements for 1 Linked List
2
Enter 1 element for 1 Linked List
2
6

Output:
1 1 2 3 4 4 5 6
*/