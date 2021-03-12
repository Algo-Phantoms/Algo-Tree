/*DFS (Depth-first search) is technique used for traversing tree or graph. Here backtracking is used for traversal. 
 * In this traversal first the deepest node is visited and then backtracks to it’s parent node if no sibling of that node exist.
 * 
 * Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
   
   *Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree)
   
   Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root./
 /**
 */
 
/**
 * @author Pallavi Dhere
 *
 */
package dfs_traversal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;




public class Dfs_Traversal { 
    public Node root; 
  
    // Tree Node 
    static class Node { 
        public int data; 
        public Node left, right;
        
        public Node(int data) 
        { 
            this.data = data; 
            this.left = null; 
            this.right = null; 
        } 
    } 
  
    // Function to insert nodes in level order 
    public Node insertLevelOrder(int[] arr, Node root, 
                                                int i) 
    { 
        // Base case for recursion 
        if (i < arr.length) { 
            Node temp = new Node(arr[i]); 
            root = temp; 
  
            // insert left child 
            root.left = insertLevelOrder(arr, root.left, 
                                             2 * i + 1); 
  
            // insert right child 
            root.right = insertLevelOrder(arr, root.right, 
                                               2 * i + 2); 
        } 
        return root; 
    }
    //Function for Preorder dfs traversal
    public void printPreorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        /* first print data of node */
        System.out.print(node.data + " "); 
  
        /* then recur on left sutree */
        printPreorder(node.left); 
  
        /* now recur on right subtree */
        printPreorder(node.right); 
    } 
  
    // Function to print tree nodes in InOrder fashion 
   public void printInorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        /* first recur on left child */
        printInorder(node.left); 
  
        /* then print the data of node */
        System.out.print(node.data + " "); 
  
        /* now recur on right child */
        printInorder(node.right); 
    }
   
// Function to print tree nodes in InOrder fashion 
    
   public void printPostorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        // first recur on left subtree 
        printPostorder(node.left); 
  
        // then recur on right subtree 
        printPostorder(node.right); 
  
        // now deal with the node 
        System.out.print(node.data + " "); 
    } 
  
    // Driver program to test above function 
    public static void main(String args[])throws IOException 
    {    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Number of notes in a tree");
        int t=Integer.parseInt(br.readLine());
        Dfs_Traversal t2 = new Dfs_Traversal(); 
        
        int[] arr; 
        arr=new int[t];
        for(int i=0;i<t;i++) {
            arr[i]=Integer.parseInt(br.readLine());
          }
        
        t2.root = t2.insertLevelOrder(arr, t2.root, 0); 
        
        System.out.print("Inorder:");
        t2.printInorder(t2.root);
        System.out.println(" ");
        System.out.print("Preorder:");
        t2.printPreorder(t2.root);
        System.out.println(" ");
        System.out.print("Postorder:");
        t2.printPostorder(t2.root);
        System.out.println(" ");
    } 
}
/*OUTPUT AND INPUT*
 * Enter the Number of notes in a tree
5
1
2
3
4
5
Inorder:4 2 5 1 3  
Preorder:1 2 4 5 3  
Postorder:4 5 2 3 1
*  
/
 */