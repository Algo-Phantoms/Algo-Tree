/* In Binary Search Tree Or Binary Tree a Node can have at most 2 children
 * Traversal means visiting every node of a tree single time
 * Postorder Traversal
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root. */

import java.util.*;

class Node {
	Node left;
    	Node right;
    	int data;
 
        Node(int data) {
    		this.data = data;
    		left = null;
    		right = null;
    	}
}

public class add_bst_postorder_traversal {
	
	/* Given a binary search tree, print its nodes in postorder*/
	public static void postorder(Node root) {
	    if(root == null)
	    	return;

	    //first recursion on left subtree
	    postorder(root.left);
	    
	    //then recursion on right subtree
	    postorder(root.right);
	    
	    //now deal with the node
	    System.out.print(root.data+" ");
	}
	
	public static Node insert(Node root, int data) {
        	if(root == null) {
            		return new Node(data);
        	} else {
            		Node cur;
            		if(data <= root.data) {
                		cur = insert(root.left, data);
                		root.left = cur;
            		} else {
                		cur = insert(root.right, data);
               			 root.right = cur;
            		}
            		return root;
        	}
    	}

	public static void main(String[] args) {
        	Scanner scan = new Scanner(System.in);
        	int t = scan.nextInt();
        	Node root = null;
        	while(t > 0) {
            		int data = scan.nextInt();
            		root = insert(root, data);
            		t--;
        	}
  
        	postorder(root);
    	}	
        /* Sample Input1:
         * 6
         * 1 2 5 3 6 4
         * Expected Output:
         * 4 3 6 5 2 1 
 
         * Sample Input2:
	 * 15
         * 1 14 3 7 4 5 15 6 13 10 11 2 12 8 9
	 * Expected Output:
         * 2 6 5 4 9 8 12 11 10 13 7 3 15 14 1  */
         
         /* Time Complexity => O(n) 
	 * Space Complexity => O(height of recursion tree)*/
}

