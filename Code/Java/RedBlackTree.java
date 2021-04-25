//   Red Black Tree : Insertion and Deletion operations 
/*A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the colour (red or black)*/
// Time complexity of Insertion and deletion operation in Red black tree is O(log n ).
package rbt;
import java.util.*;
class Node {
	int data;  // contains the data
	Node parent;  // pointer to the parent
	Node left;  // pointer to left child
	Node right; // pointer to right child
	int color;  // 1-> Red, 0-> Black
}


// class RedBlackTree implements the operations in Red Black Tree
public class RedBlackTree {
	private Node root;
	private Node TNULL;

	private void preOrder(Node node) {
		if (node != TNULL) {
			String c;
			if(node.color == 0)
			{
				c = "Black";
			}
			else
			{
				c ="Red";
			}
			System.out.print(node.data+"("+c+")"+ " ");
			preOrder(node.left);
			preOrder(node.right);
		} 
	}

	private void inOrder(Node node) {
		if (node != TNULL) {
			String c;
			if(node.color == 0)
			{
				c = "Black";
			}
			else
			{
				c ="Red";
			}
			inOrder(node.left);
			System.out.print(node.data+"("+c+")"+" ");
			inOrder(node.right);
		} 
	}

	private void postOrder(Node node) {
		if (node != TNULL) {
			String c;
			if(node.color == 0)
			{
				c = "Black";
			}
			else
			{
				c ="Red";
			}
			postOrder(node.left);
			postOrder(node.right);
			System.out.print(node.data+"("+c+")"+" ");
		} 
	}


	// fix the rb tree modified by the delete operation
	private void fixDelete(Node x) {
		Node s;
		while (x != root && x.color == 0) {
			if (x == x.parent.left) {
				s = x.parent.right;
				if (s.color == 1) {
					// x ’s sibling S is red
					s.color = 0;
					x.parent.color = 1;
					leftRotate(x.parent);
					s = x.parent.right;
				}

				if (s.left.color == 0 && s.right.color == 0) {
					// x ’s sibling S is black, and both of S’s children are black.
					s.color = 1;
					x = x.parent;
				} else {
					if (s.right.color == 0) {
						// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
						s.left.color = 0;
						s.color = 1;
						rightRotate(s);
						s = x.parent.right;
					} 

					// x ’s sibling S is black, and S’s right child is red.
					s.color = x.parent.color;
					x.parent.color = 0;
					s.right.color = 0;
					leftRotate(x.parent);
					x = root;
				}
			} else {
				s = x.parent.left;
				if (s.color == 1) {
					//x ’s sibling S is red
					s.color = 0;
					x.parent.color = 1;
					rightRotate(x.parent);
					s = x.parent.left;
				}

				if (s.right.color == 0 && s.right.color == 0) {
					// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
					s.color = 1;
					x = x.parent;
				} else {
					if (s.left.color == 0) {
						// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
						s.right.color = 0;
						s.color = 1;
						leftRotate(s);
						s = x.parent.left;
					} 

					// x ’s sibling S is black, and S’s right child is red.
					s.color = x.parent.color;
					x.parent.color = 0;
					s.left.color = 0;
					rightRotate(x.parent);
					x = root;
				}
			} 
		}
		x.color = 0;
	}


	private void rbTransplant(Node u, Node v){
		if (u.parent == null) {
			root = v;
		} else if (u == u.parent.left){
			u.parent.left = v;
		} else {
			u.parent.right = v;
		}
		v.parent = u.parent;
	}

	private void deleteNodeHelper(Node node, int key) {
		// find the node containing key
		Node z = TNULL;
		Node x, y;
		while (node != TNULL){
			if (node.data == key) {
				z = node;
			}

			if (node.data <= key) {
				node = node.right;
			} else {
				node = node.left;
			}
		}

		if (z == TNULL) {
			System.out.println("Couldn't find key in the tree");
			return;
		} 

		y = z;
		int yOriginalColor = y.color;
		if (z.left == TNULL) {
			x = z.right;
			rbTransplant(z, z.right);
		} else if (z.right == TNULL) {
			x = z.left;
			rbTransplant(z, z.left);
		} else {
			y = minimum(z.right);
			yOriginalColor = y.color;
			x = y.right;
			if (y.parent == z) {
				x.parent = y;
			} else {
				rbTransplant(y, y.right);
				y.right = z.right;
				y.right.parent = y;
			}

			rbTransplant(z, y);
			y.left = z.left;
			y.left.parent = y;
			y.color = z.color;
		}
		if (yOriginalColor == 0){
			fixDelete(x);
		}
	}
	
	// balance the red-black tree
	private void BalanceInsert(Node k){
		Node u;
		while (k.parent.color == 1) {
			if (k.parent == k.parent.parent.right) {
				u = k.parent.parent.left; // uncle
				if (u.color == 1) {
					//P  is red and U is red too.
					u.color = 0;
					k.parent.color = 0;
					k.parent.parent.color = 1;
					k = k.parent.parent;
				} else {
					if (k == k.parent.left) {
						// P  is red and U is black (or NULL).
						k = k.parent;
						rightRotate(k);
					}
					// P  is right child of G and K is right child of P.
					k.parent.color = 0;
					k.parent.parent.color = 1;
					leftRotate(k.parent.parent);
				}
			} else {
				u = k.parent.parent.right; // uncle

				if (u.color == 1) {
					// P  is red and U is red too.
					u.color = 0;
					k.parent.color = 0;
					k.parent.parent.color = 1;
					k = k.parent.parent;	
				} else {
					if (k == k.parent.right) {
						// P  is red and U is black (or NULL)
						k = k.parent;
						leftRotate(k);
					}
					//P  is right child of G and K is right child of P.
					k.parent.color = 0;
					k.parent.parent.color = 1;
					rightRotate(k.parent.parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root.color = 0;
	}

	private void printHelper(Node root) {
		// print the tree structure on the screen
		 {
		    if (root == null)
		    	System.out.println("Tree is empty");
		    else
		    	inOrder(root);
		    	System.out.println("");
		  }
	}

	public RedBlackTree() {
		TNULL = new Node();
		TNULL.color = 0;
		TNULL.left = null;
		TNULL.right = null;
		root = TNULL;
	}

	// Pre-Order traversal
	// Node.Left Subtree.Right Subtree
	public void preorder() {
		preOrder(this.root);
	}

	// In-Order traversal
	// Left Subtree . Node . Right Subtree
	public void inorder() {
		inOrder(this.root);
	}

	// Post-Order traversal
	// Left Subtree . Right Subtree . Node
	public void postorder() {
		postOrder(this.root);
	}


	// find the node with the minimum key
	public Node minimum(Node node) {
		while (node.left != TNULL) {
			node = node.left;
		}
		return node;
	}

	// find the node with the maximum key
	public Node maximum(Node node) {
		while (node.right != TNULL) {
			node = node.right;
		}
		return node;
	}

	// find the successor of a given node
	public Node successor(Node x) {
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x.right != TNULL) {
			return minimum(x.right);
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		Node y = x.parent;
		while (y != TNULL && x == y.right) {
			x = y;
			y = y.parent;
		}
		return y;
	}

	// find the predecessor of a given node
	public Node predecessor(Node x) {
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the 
		// left subtree
		if (x.left != TNULL) {
			return maximum(x.left);
		}

		Node y = x.parent;
		while (y != TNULL && x == y.left) {
			x = y;
			y = y.parent;
		}

		return y;
	}

	// rotate left at node x
	public void leftRotate(Node x) {
		Node y = x.right;
		x.right = y.left;
		if (y.left != TNULL) {
			y.left.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) {
			this.root = y;
		} else if (x == x.parent.left) {
			x.parent.left = y;
		} else {
			x.parent.right = y;
		}
		y.left = x;
		x.parent = y;
	}

	// rotate right at node x
	public void rightRotate(Node x) {
		Node y = x.left;
		x.left = y.right;
		if (y.right != TNULL) {
			y.right.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) {
			this.root = y;
		} else if (x == x.parent.right) {
			x.parent.right = y;
		} else {
			x.parent.left = y;
		}
		y.right = x;
		x.parent = y;
	}

	// insert the key to the tree in its appropriate position
	// and fix the tree
	public void insert(int key) {
		// Ordinary Binary Search Insertion
		Node node = new Node();
		node.parent = null;
		node.data = key;
		node.left = TNULL;
		node.right = TNULL;
		node.color = 1; // new node must be red

		Node y = null;
		Node x = this.root;

		while (x != TNULL) {
			y = x;
			if (node.data < x.data) {
				x = x.left;
			} else {
				x = x.right;
			}
		}

		// y is parent of x
		node.parent = y;
		if (y == null) {
			root = node;
		} else if (node.data < y.data) {
			y.left = node;
		} else {
			y.right = node;
		}

		// if new node is a root node, simply return
		if (node.parent == null){
			node.color = 0;
			return;
		}

		// if the grandparent is null, simply return
		if (node.parent.parent == null) {
			return;
		}

		// Balance the tree
		BalanceInsert(node);
	}

	public Node getRoot(){
		return this.root;
	}

	// delete the node from the tree
	public void delNode(int data) {
		deleteNodeHelper(this.root, data);
	}

	// print the tree structure on the screen
	public void PrintRedBlackTree() {
		//printHelper(this.root,"", true);
        printHelper(this.root);
	}
	
	public static void main(String [] args){
    	RedBlackTree bst = new RedBlackTree();   // creating object of RedBlackTree class
    	int i=0;
    	int choice=0;
    	Scanner sc = new Scanner(System.in);   //Scanner class for input 
    	do //for looping 
    	{
    		do // looping the choice back
    		{
    			System.out.println();
    			System.out.println("--------------- Red Tree Operations -------------");
        		System.out.println("1. Insert a node from red black tree");
        		System.out.println("2. Delete a node from red black tree");
        		System.out.println("3. Print the red black tree");
        		System.out.println("0. Exit.");
        		System.out.println("Enter your choice: ");
        		choice = sc.nextInt();
        		if(choice<0 || choice>3)
        		{
        			System.out.println("Invalid choice! Enter your choice again");
        		}
    		}while(choice<0 || choice>3);
    		
    		switch(choice)   //switch for choice 
    		{
    		case 1:
    			int n1=0;
    			System.out.println("Enter the value of new node: ");
    			n1 = sc.nextInt();
    			bst.insert(n1);
    			System.out.println(n1+" Node Inserted successfully!!");
    			break;
    		case 2:
    			int n2=0;
    			System.out.println("Enter the node to be deleted: ");
    			n2 = sc.nextInt();
    			bst.delNode(n2);
    			System.out.println(n2+" Node deleted!");
    			break;
    		case 3:
    			System.out.println("Inorder: ");
    			bst.PrintRedBlackTree();
    			System.out.println("Preorder: ");
    			bst.preorder();
    			System.out.println(" ");
    			System.out.println("Postorder: ");
    			bst.postorder();
    			System.out.println(" ");
    			break;
    		case 0:
    			System.out.println("Thank You!");
    			break;
    		}
    	}while(choice!=0);
	}
}

/* 

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
6
6 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
4
4 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
2
2 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
1
1 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
3
3 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
5
5 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
8
8 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
7
7 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
9
9 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
1
Enter the value of new node: 
10
10 Node Inserted successfully!!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
3
Inorder: 
1(Red) 2(Black) 3(Red) 4(Red) 5(Black) 6(Black) 7(Black) 8(Red) 9(Black) 10(Red) 
Preorder: 
6(Black) 4(Red) 2(Black) 1(Red) 3(Red) 5(Black) 8(Red) 7(Black) 9(Black) 10(Red)  
Postorder: 
1(Red) 3(Red) 2(Black) 5(Black) 4(Red) 7(Black) 10(Red) 9(Black) 8(Red) 6(Black)  

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
3
Inorder: 
1(Red) 2(Black) 3(Red) 4(Red) 5(Black) 6(Black) 7(Black) 8(Red) 9(Black) 10(Red) 
Preorder: 
6(Black) 4(Red) 2(Black) 1(Red) 3(Red) 5(Black) 8(Red) 7(Black) 9(Black) 10(Red)  
Postorder: 
1(Red) 3(Red) 2(Black) 5(Black) 4(Red) 7(Black) 10(Red) 9(Black) 8(Red) 6(Black)  

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
2
Enter the node to be deleted: 
10
10 Node deleted!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
2
Enter the node to be deleted: 
7
7 Node deleted!

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
3
Inorder: 
1(Red) 2(Black) 3(Red) 4(Red) 5(Black) 6(Black) 8(Black) 9(Red) 
Preorder: 
6(Black) 4(Red) 2(Black) 1(Red) 3(Red) 5(Black) 8(Black) 9(Red)  
Postorder: 
1(Red) 3(Red) 2(Black) 5(Black) 4(Red) 9(Red) 8(Black) 6(Black)  

--------------- Red Tree Operations -------------
1. Insert a node from red black tree
2. Delete a node from red black tree
3. Print the red black tree
0. Exit.
Enter your choice: 
0
Thank You!
*/