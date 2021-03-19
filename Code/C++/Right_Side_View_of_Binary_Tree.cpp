/*
PROBLEM STATEMENT:

Given a binary tree, print the right side view of the tree. The right side view of the binary tree
includes the nodes which are visible when the tree is viewed from the right side.
For example:
		    20
		   /  \
		  4    7
		 / \  / 
		1  8 34  
	       /      \
	      64      32

Right side view: 20 7 34 32 
The input will be in the form of preorder and -1 denotes a null node.
*/


#include<bits/stdc++.h>
using namespace std;

// Class for the structure of tree
class node{
	public:
		//value stored at each node
		int data;
		//pointer to refer to the left child	
		node* left;
		//pointer to refer the right child
		node* right;

		//constructor for initializing values
		node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};

//Function to build the tree and it returns the root of the tree
node* BuildTree(){

	//user inputs the values in preorder and enters -1 to denote a null node
	int d;
	cin>>d;
	if(d == -1)
		return NULL;

	//A new node created with value d
	node* root = new node(d);

	//Recursive call to the left and right child of the root
	root->left = BuildTree();
	root->right = BuildTree();

	return root;
}

//Function to print the right side view of the binary tree
void RightView(node* root, int level, int &maxlevel){

	//base case
	if(root == NULL)
		return;

	//checking the current level is greater than maxlevel so far
	if(level > maxlevel){

		//Displays the values which appear from the right side view of a tree
		cout<<root->data<<" ";

		//Updating maxlevel
		maxlevel = level;
	}

	//recursive cases for right and left childs
	RightView(root->right, level + 1, maxlevel);
	RightView(root->left, level + 1, maxlevel);
}

//Driver function
int main(){

	cout<<"enter elemnets: ";

	//Function call to build the tree
	node* root = BuildTree();

	//maxlevel ensures that no two nodes on the same level of the tree are printed
	int maxlevel = -1;

	//Function call to display the right side view of the tree. The parameters passed are: the root node, the 0th level of the tree, and maxlevel 
	RightView(root, 0, maxlevel);

	return 0;
}


/*
TEST CASES:

1.
Input: 20 4 1 64 -1 -1 -1 8 -1 -1 7 34 -1 32 -1 -1 -1
Output: 20 7 34 32
Explanation: The tree will look like this

		    20		<----
		   /  \
		  4    7	<----
		 / \  / 
		1  8 34  	<----
	       /      \
	      64       32	<----

2.
Input: 10 7 8 -1 -1 9 -1 -1 15 18 -1 -1 19 -1 -1
Output: 10 15 19
Explanation: The tree will look like this

		    10			<----
		   /  \
		  7    15		<----
		 / \  /  \
		8   9 18  19		<----


TIME COMPLEXITY: O(N), where N is the number of nodes in the tree.
SPACE COMPLEXITY: O(N), due to the stack space used during recursive calls.

*/
