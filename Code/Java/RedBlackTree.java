//   Red Black Tree : Insertion and Deletion operations 

/*A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, 
 * and that bit is often interpreted as the colour (red or black).
 * There are certain constraints while creating a Red Black Tree like : 
 * 1. Root node should be of black color.
 * 2. Parent and child node can not be of red color.
 * 3. All the null nodes are black. 
 * 4. Both children of red node are black.
 * These constraints should be followed during inserting and deleting a node in RedBlackTree.*/

package rbt;
import java.util.*;   //importing required packages
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

	private void preOrder(Node node) {   //preorder 
		if (node != TNULL){  //node does not have terminal nodes
		
			String c;
			if(node.color == 0){ //if node color's value is 0
				c = "Black";  //: assign color as black
			}
			else { // if 1
				c = "Red";  // then assign color as red
			}
			System.out.print(node.data + "(" + c + ")" + " ");
			preOrder(node.left);  //recursive traverse left node
			preOrder(node.right);  //recursive traverse right node
		} 
	}

	private void inOrder(Node node) {
		if (node != TNULL){  //node does not have terminal nodes
			String c;
			if(node.color == 0){  //if node color's value is 0  
				c = "Black";     //: assign color as black
			}
			else{   // if 1 
				c = "Red";  // then assign color as red
			}
			inOrder(node.left);  //recursive traverse left node
			System.out.print(node.data + "(" + c + ")" + " ");
			inOrder(node.right);  //recursive traverse right node
		} 
	}

	private void postOrder(Node node) {
		if (node != TNULL){  //node does not have terminal nodes
			String c;
			if(node.color == 0){ //if node color's value is 0
				c = "Black"; //: assign color as black
			}
			else{  // if 1
				c = "Red";  //then assign color as red
			}
			postOrder(node.left);  //recursive traverse left node
			postOrder(node.right);  //recursive traverse right node
			System.out.print(node.data + "(" + c + ")" + " ");
		} 
	}


	// fix the rb tree modified by the delete operation
	private void fixDelete(Node x) {
		Node s;
		while (x != root && x.color == 0) {  //x is not the root and x is black 
			if (x == x.parent.left){   //if x is left child of its parent node
				s = x.parent.right;
				if (s.color == 1) {  //if s is of red color 
					// x ’s sibling S is red
					s.color = 0;   //set s as black color
					x.parent.color = 1;   //set x's parent color to red
					leftRotate(x.parent); //apply left rotation on parent node 
					s = x.parent.right;   //change s to right child of x's parent
				}

				if (s.left.color == 0 && s.right.color == 0) {
					// x ’s sibling S is black, and both of S’s children are black.
					s.color = 1;   //re-color s to red
					x = x.parent;  
				} 
				else{
					if (s.right.color == 0){
						// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
						s.left.color = 0;
						s.color = 1;   //re-color s to red
						rightRotate(s);   //apply right rotation 
						s = x.parent.right;
					} 

					// x ’s sibling S is black, and S’s right child is red.
					s.color = x.parent.color;
					x.parent.color = 0;
					s.right.color = 0;
					leftRotate(x.parent);  // apply left rotation
					x = root;
				}
			} 
			else {
				s = x.parent.left;
				if (s.color == 1){   //if s is red 
					//x ’s sibling S is red
					s.color = 0;
					x.parent.color = 1;   //re-color x's color to red 
					rightRotate(x.parent);  //apply right rotation
					s = x.parent.left;
				}

				if (s.right.color == 0 && s.right.color == 0){   //if right child of s is black
					// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
					s.color = 1;  // re-color 
					x = x.parent;
				} 
				else {
					if (s.left.color == 0) {  //if s-> left color is black
						// x ’s sibling S is black, S’s left child is red, and S’s right child is black.
						s.right.color = 0;
						s.color = 1;   //re-color s to red
						leftRotate(s);  //apply left rotation
						s = x.parent.left;
					} 

					// x ’s sibling S is black, and S’s right child is red.
					s.color = x.parent.color;
					x.parent.color = 0;   //change x'parent color to black
					s.left.color = 0;     //change s'left child color to black
					rightRotate(x.parent);   //apply right rotation
					x = root;  //make x as the root 
				}
			} 
		}
		x.color = 0;   //set x->color as black
	}


	private void rbTransplant(Node u, Node v){
		if (u.parent == null) {   // if u is the root
			root = v;  // set v as root
		} 
		else if (u == u.parent.left) { // if u is at left child of it's parent 
			u.parent.left = v;   //assign v as left child of u.parent
		} 
		else{
			u.parent.right = v;   //assign v as right child of u.parent
		}
		v.parent = u.parent;
	}

	private void deleteNodeHelper(Node node, int key) {   //for deletion of a node 
		// find the node containing key
		Node z = TNULL;
		Node x, y;
		while (node != TNULL) 
		{   //node doesn't have terminal nodes 
			if (node.data == key) { //node to be deleted found
				z = node;  //set node as z
			}

			if (node.data <= key) {  //node to be deleted is greater than/equal to node.data 
				node = node.right;  //traverse to node's right child
			} 
			else {
				node = node.left;   //traverse to node's left child
			}
		}

		if (z == TNULL)  { //if node has terminal nodes
			System.out.println("Couldn't find key in the tree");  //node to be deleted not found
			return;
		} 

		y = z;   //set z as y
		int yOriginalColor = y.color;   
		if (z.left == TNULL) {    //z's left child has terminal nodes 
			x = z.right;   //set z's right child as x
			rbTransplant(z, z.right);    //call transplant function for balancing the tree
		} 
		else if (z.right == TNULL) {   //z's right child has terminal nodes
			x = z.left;  //set z's left child as x
			rbTransplant(z, z.left);    //call transplant function for balancing the tree
		} 
		else {
			y = minimum(z.right);    //find the minimum node and assign it to y
			yOriginalColor = y.color;  
			x = y.right;
			if (y.parent == z) {  //if y->parent is equal to z
				x.parent = y;    //set y as x->parent
			} 
			else {
				rbTransplant(y, y.right);  //use transplant function for balancing 
				y.right = z.right;      
				y.right.parent = y;
			}

			rbTransplant(z, y);  //use transplant function on z and y 
			y.left = z.left;      //assign  y.left to z.left
			y.left.parent = y;
			y.color = z.color;     //set the color of z same as y
		}
		if (yOriginalColor == 0)   {
			fixDelete(x);   //call fixdelete function for balancing the tree 
		}
	}
	
	private void BalanceInsert(Node k) {  // balance the red-black tree
		Node u;  //uncle node
		while (k.parent.color == 1) {  //loop until k's parent is red 
			if (k.parent == k.parent.parent.right) {  //if k.parent is equal to grandparent's right child
				u = k.parent.parent.left; // uncle
				if (u.color == 1){  // if uncle's color is red
					//Parent  is red and Uncle is red too.
					u.color = 0;
					k.parent.color = 0;  
					k.parent.parent.color = 1;  //set grandparent's color to red
					k = k.parent.parent;
				} 
				else {
					if (k == k.parent.left){   //if k is the left child of its parent
						// P  is red and U is black (or NULL).
						k = k.parent;
						rightRotate(k);  //apply right rotation
					}
					// P  is right child of G and K is right child of P.
					k.parent.color = 0;  //set parent's color as black
					k.parent.parent.color = 1;  //set grandparent's color as red
					leftRotate(k.parent.parent);  //apply left rotation
				}
			} 
			else {
				u = k.parent.parent.right; // uncle

				if (u.color == 1) {
					// P  is red and U is red too.
					u.color = 0;
					k.parent.color = 0;  //set parent's color as black
					k.parent.parent.color = 1;   //set grandparent's color as red
					k = k.parent.parent;	  //set k as grandparent 
				} 
				else {
					if (k == k.parent.right) {
						// P  is red and U is black (or NULL)
						k = k.parent;
						leftRotate(k); //apply left rotation 
					}
					//P  is right child of G and K is right child of P.
					k.parent.color = 0;  //set parent's color as black
					k.parent.parent.color = 1;   //set grandparent's color as red
					rightRotate(k.parent.parent);  //apply right rotation
				}
			}
			if (k == root) //if k is the root
			{
				break;
			}
		}
		root.color = 0;   //set root's color to black
	}

	private void printHelper(Node root){   //for printing the nodes of the tree
		// print the tree structure on the screen
		 {
		    if (root == null)  //no nodes in the tree
		    	System.out.println("Tree is empty");
		    else
		    	inOrder(root);  //display nodes in inorder
		    	System.out.println("");
		  }
	}

	public RedBlackTree()  //RedBlackTree class
	{
		TNULL = new Node();   //terminal nodes- objects of Node class
		TNULL.color = 0;     //initialize variables 
		TNULL.left = null;
		TNULL.right = null;
		root = TNULL;
	}

	// Pre-Order traversal
	// Node.Left Subtree.Right Subtree
	public void preorder() 
	{
		preOrder(this.root);   // calling pre order function
	}

	// In-Order traversal
	// Left Subtree . Node . Right Subtree
	public void inorder() 
	{
		inOrder(this.root);  // calling in order function
	}

	// Post-Order traversal
	// Left Subtree . Right Subtree . Node
	public void postorder() 
	{
		postOrder(this.root);   // calling post order function
	}


	// find the node with the minimum key
	public Node minimum(Node node)    //to find minimum node
	{
		while (node.left != TNULL)   //for traversing the entire tree
		{
			node = node.left;  //traverse to the left of the node
		}
		return node;
	}

	// find the node with the maximum key
	public Node maximum(Node node) 
	{
		while (node.right != TNULL) //for traversing the entire tree
		{
			node = node.right; //traverse to the right of the node
		}
		return node;
	}

	// find the successor of a given node
	public Node successor(Node x) 
	{
		// if the right subtree is not null,
		// the successor is the leftmost node in the
		// right subtree
		if (x.right != TNULL){
			return minimum(x.right);  //calling minimum function
		}

		// else it is the lowest ancestor of x whose
		// left child is also an ancestor of x.
		Node y = x.parent;
		while (y != TNULL && x == y.right)  // y has no terminal nodes and x = y-> right 
		{
			x = y;  //assign y to x
			y = y.parent;   
		}
		return y;
	}

	// find the predecessor of a given node
	public Node predecessor(Node x) 
	{
		// if the left subtree is not null,
		// the predecessor is the rightmost node in the 
		// left subtree
		if (x.left != TNULL){ 
			return maximum(x.left);  //find maximum node
		}

		Node y = x.parent;
		while (y != TNULL && x == y.left)  //y has no terminal nodes and x = y->left child
		{
			x = y;  //assign y to x
			y = y.parent;
		}

		return y;
	}

	// rotate left at node x
	public void leftRotate(Node x) 
	{
		Node y = x.right;   //assign x->right child to y
		x.right = y.left;
		if (y.left != TNULL){   //left child of y has no terminal nodes
			y.left.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null){   //there is no parent of x node
			this.root = y;
		} 
		else if (x == x.parent.left){ //x is left child
			x.parent.left = y; //set y as x's left child
		} 
		else {
			x.parent.right = y;  //set y as x's right child
		}
		y.left = x;
		x.parent = y;
	}

	// rotate right at node x
	public void rightRotate(Node x) 
	{
		Node y = x.left;
		x.left = y.right;
		if (y.right != TNULL){   //right child of y has no terminal nodes 
			y.right.parent = x; 
		}
		y.parent = x.parent;
		if (x.parent == null){  //x does not have a parent
			this.root = y;
		} 
		else if (x == x.parent.right){ //x is right child
			x.parent.right = y; //set y as right child of x
		} 
		else {
			x.parent.left = y;  //set y as left child of x
		}
		y.right = x;  //set x as right child of y
		x.parent = y;  //set y as parent of x
	}

	// insert the key to the tree in its appropriate position
	// and fix the tree
	public void insert(int key) 
	{
		// Ordinary Binary Search Insertion
		Node node = new Node();
		node.parent = null;
		node.data = key;
		node.left = TNULL;
		node.right = TNULL;
		node.color = 1; // new node must be red

		Node y = null;
		Node x = this.root;

		while (x != TNULL)  //loop until x have terminal nodes 
		{
			y = x;
			if (node.data < x.data){ //check condition
				x = x.left; //traverse left
			} 
			else {
				x = x.right; //traverse right
			}
		}

		// y is parent of x
		node.parent = y;
		if (y == null) {
			root = node; //set node as root
		} 
		else if (node.data < y.data){  //check equality condition
			y.left = node;  //node will be left child of y
		} 
		else{
			y.right = node; //node will be right child of y
		}

		// if new node is a root node, simply return
		if (node.parent == null){
			node.color = 0;  //set node color to black
			return;
		}

		// if the grandparent is null, simply return
		if (node.parent.parent == null) {
			return;
		}

		// Balance the tree
		BalanceInsert(node);  
	}

	public Node getRoot()  //get the root of the tree
	{
		return this.root;
	}

	// delete the node from the tree
	public void delNode(int data) 
	{
		deleteNodeHelper(this.root, data);
	}

	// print the tree structure on the screen
	public void PrintRedBlackTree() 
	{
		//printHelper(this.root,"", true);
        printHelper(this.root);
	}
	
	public static void main(String [] args)
	{
    	RedBlackTree bst = new RedBlackTree();   // creating object of RedBlackTree class
    	int i = 0;
    	int choice = 0;
    	Scanner sc = new Scanner(System.in);   //Scanner class for input 
    	do //for looping 
    	{
    		do // looping the choice back
    		{
    			System.out.println();
    			System.out.println("--------------- Red Tree Operations -------------");  //printing the menu
        		System.out.println("1. Insert a node from red black tree");
        		System.out.println("2. Delete a node from red black tree");
        		System.out.println("3. Print the red black tree");
        		System.out.println("0. Exit.");
        		System.out.println("Enter your choice: ");
        		choice = sc.nextInt();
        		if(choice < 0 || choice > 3) //choice validation
        		{
        			System.out.println("Invalid choice! Enter your choice again");
        		}
    		}while(choice < 0 || choice > 3);
    		
    		switch(choice)   //switch for choice 
    		{
    		case 1:
    			int n1 = 0;
    			System.out.println("Enter the value of new node: ");
    			n1 = sc.nextInt();
    			bst.insert(n1);  //calling insert function through object
    			System.out.println(n1+" Node Inserted successfully!!");
    			break;
    		case 2:
    			int n2 = 0;
    			System.out.println("Enter the node to be deleted: ");
    			n2 = sc.nextInt();
    			bst.delNode(n2);   //calling delete function through object
    			System.out.println(n2+" Node deleted!");
    			break;
    		case 3:
    			System.out.println("Inorder: ");
    			bst.PrintRedBlackTree();   //calling print function through object
    			System.out.println("Preorder: ");
    			bst.preorder();   //calling preorder function through object
    			System.out.println(" ");
    			System.out.println("Postorder: ");
    			bst.postorder();   //calling postorder function through object
    			System.out.println(" ");
    			break;
    		case 0:
    			System.out.println("Thank You!");  //print exit statement
    			break;
    		}
    	}while(choice != 0);
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

/* Time complexity of Insertion and deletion operation 
   in Red black tree is O( log n ) , where n = Number of Nodes in the tree 
   Time complexity of Printing the red black tree is O(n), 
   where n is the total number of nodes in a red black tree.*/