
/*A binary tree is a tree-type non-linear data structure with a maximum of two children for each parent.
 *  Every node in a binary tree has a left and right reference along with the data element. 
 * The node at the top of the hierarchy of a tree is called the root node. The nodes that hold other sub-nodes are the parent nodes.*/


/* Doubly linked list is a type of linked list in which each node apart from storing its data has two links. 
 * The first link points to the previous node in the list and the second link points to the next node in the list.
 *  The first node of the list has its previous link pointing to NULL similarly the last node of the list has its next node pointing to NULL.*/
 

/*Algorithm*/ 
/* Binary Tree In-Place convert it into a doubly linked list.
 * The left and right pointers of binary tree nodes should act as previous and next pointers in a doubly-linked list,
 * and the doubly linked list nodes should follow the same order of nodes as inorder traversal on tree.
 * We can convert Binary tree into Doubly Linkedlist in a single traversal by doing inorder traversal.
 * The idea is to keep track of the previously processed node in inorder traversal,and for every encountered
 *  node,set its left child to prev and prev's right child current node.  */
/**
 * 
 */
/**
 * @author Pallavi Dhere
 *
 */
package binarytreetodoublylinkedlist;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;




public class Binarytree_To_Doublylinkedlist
{  
    private static Node root;
  //A class to store a binary tree node
    public class Node
    {
      public int data;
      public Node left = null;
      public Node right = null;

     public Node(int data) {
         this.data = data;
     }
    }

 // Wrapper over `Node` class
    public static class NodeWrapper
    {
     public Node node;

     NodeWrapper(Node node) {
         this.node = node;
     }
   }



public Node insertLevelOrder(int[] arr,final Node root, int i) 
{  
    Node d=root;
//Base case for recursion 
    if (i < arr.length) { 
        Node temp = new Node(arr[i]); 
        d = temp; 

     // insert left child 
     d.left = insertLevelOrder(arr, d.left, 2 * i + 1); 

     // insert right child 
     d.right = insertLevelOrder(arr, d.right, 2 * i + 2); 
} 
return d; 
}

//private static Node root;

 // Helper function to print a given doubly linked list
   public static void printDLL(Node head)
   {
     Node curr = head;
     while (curr != null)
     {
         System.out.print(curr.data + " ");
         curr = curr.right;
     }
   }

 // Function to in-place convert a given binary tree into a doubly linked list

 // `root` —> current node
 // `head` —> head of the doubly linked list (Passed by reference)
 // `prev` —> previously processed node (Passed by reference)
   public static Node convert(Node curr, final Node head, NodeWrapper prev)
   {
       Node x=head;
     // base case: tree is empty
     if (curr == null) {
         return x;
     }

     // recursively convert the left subtree first
     x = convert(curr.left, x, prev);

     // adjust pointers
     if (prev.node != null)
     {
         // set the current node's left child to `prev`
         curr.left = prev.node;

         // make the previous node's right child as `curr`
         prev.node.right = curr;
     }

     // if `prev` is null, then update the head of doubly linked list
     // as this is the first node in inorder
     else {
         x = curr;
     }

     // after the current node is visited, update the previous pointer
     // to the current node
     prev.node = curr;

     // recursively convert the right subtree
     return convert(curr.right, x, prev);
 }

 // In-place convert a given binary tree into a doubly linked list
 public static Node convert( Node root)
 {   
     // `prev` keeps track of the previously processed node in the
     // inorder traversal
     Node prev = null;

     // Wrap the `prev` node, so its reference can be changed inside
     // the `convert()` method
     NodeWrapper _prev = new NodeWrapper(prev);

     // convert the above binary tree into doubly linked list
     // (using inorder traversal)
     return convert(root, root, _prev);
 }

 public static void main(String[] args)throws IOException
 {
    

     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     System.out.println("Enter the Number of notes in a tree");
     int t=Integer.parseInt(br.readLine());
     Binarytree_To_Doublylinkedlist ob = new Binarytree_To_Doublylinkedlist(); 
     
     int[] arr; 
     arr=new int[t];
     for(int i=0;i<t;i++) {
         arr[i]=Integer.parseInt(br.readLine());
       }
     
     //creates a binary tree using levelordertraversal
     Binarytree_To_Doublylinkedlist.root = ob.insertLevelOrder(arr, Binarytree_To_Doublylinkedlist.root, 0); 

     Binarytree_To_Doublylinkedlist.root = convert(Binarytree_To_Doublylinkedlist.root);

     // root is now head of the doubly linked list

     // print the list
     printDLL(Binarytree_To_Doublylinkedlist.root);
 }
}

/*INPUT AND OUTPUT*/
/*
 * Enter the Number of notes in a tree
4
7
3
8
2
2 3 7 8 

*Enter the Number of notes in a tree
5
8
2
4
7
5
7 2 5 8 4
 */

/*TIME COMPLEXITY AND SPACE COMPLEXITY*/
/*
 * Time complexity:- O(n) where n is number of nodes 
 * space complexity:- O(h) where h is height of tree*/


