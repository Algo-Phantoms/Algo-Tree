/* In Binary Search Tree Or Binary Tree a Node can have at most 2 children
 * Traversal means visiting every node of a tree single time
 * inorder Traversal
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree) */

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

public class add_bst_inorder_traversal {
	
	//Given a binary tree, print its nodes in inorder
	public static void inorder(Node root) {
        	if(root==null)
            		return;

        	//first recursion on left child
        	inorder(root.left);
        
       	        //then print the data of node 
        	System.out.print(root.data+" ");
        
        	//now recursion on right child
        	inorder(root.right);
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
       
        	inorder(root);
    	}	
        /* Sample Input1:
         * 6
         * 1 2 5 3 6 4
         * Expected Output:
         * 1 2 3 4 5 6 
 
         * Sample Input2:
	 * 15
         * 1 14 3 7 4 5 15 6 13 10 11 2 12 8 9
	 * Expected Output:
         * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 */

	/* Time Complexity => O(n) 
	 * Space Complexity => O(height of recursion tree)*/
}
