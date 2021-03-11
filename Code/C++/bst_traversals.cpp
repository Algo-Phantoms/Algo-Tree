/* Traversal is a process to visit all the nodes of a tree and may print their values too. Because, all nodes are connected via edges (links) we always start from the root (head) node. That is, we cannot randomly access a node in a tree.
 There are three ways which we use to traverse a tree −

In-order Traversal:

   1. Traverse the left subtree
   2. Visit the root.
   3. Traverse the right subtree
 Pre-order Traversal:
 
   1. Visit the root.
   2. Traverse the left subtree
   3. Traverse the right subtree
 Post-order Traversal:

   1. Traverse the left subtree
   2. Traverse the right subtree
   3. Visit the root.
*/

#include <iostream> 
using namespace std; 

struct Node 
{ 
	int data; // binary tree node has some data
	struct Node* left, *right; //binary tree has left and right child pointer
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

//postorder traversal code:
void Postorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	
	Postorder(node->left); 

	 
	Postorder(node->right); 

	
	cout << node->data << " "; 
} 

/* Inorder Traversal*/
void Inorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	
	Inorder(node->left); 

	
	cout << node->data << " "; 

	
	Inorder(node->right); 
} 

/* Preorder traversal Code*/
void Preorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	
	cout << node->data << " "; 

	
	Preorder(node->left); 

	
    Preorder(node->right); 
} 


int main() 
{ 
	struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	Preorder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	Inorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	Postorder(root); 

	return 0; 
} 
/*
test cases include
testcase 1:
output:
Preorder traversal of binary tree is 
9 8 6 4 7
Inorder traversal of binary tree is
6 8 4 9 7
Postorder traversal of binary tree is
6 4 8 7 9


testcase 2:
output:
Preorder traversal of binary tree is 
1 2 4 5 3
Inorder traversal of binary tree is
4 2 5 1 3
Postorder traversal of binary tree is
4 5 2 3 1

Time Complexity: O(n)
Space Complexity: On not considering the  size of stack for function calls then O(1) otherwise O(n).


*/
