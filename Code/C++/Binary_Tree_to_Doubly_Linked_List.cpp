/*
Here we are converting a given binary tree to a doubly linked list. 
Here the left and right pointers of the given binary tree will get converted into the previous and next pointer of the Doubly Linked List.
Basically, the order of the nodes in the doubly linked list will be same as the inorder traversal of the Binary Tree.
And hence, here the head of the doubly linked list will be the leftmost node of given binary tree. 
*/

#include <iostream>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* InsertNode(int n)
{
	TreeNode* t = new TreeNode;
	t->value = n;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void Convert_to_Double_Linked_List(TreeNode* A, TreeNode** h)
{
	if(A==NULL){
		return;
	}
	
	//Here we initialise the previous visited node as NULL
	//We use 'static' keyword here so that we can use this value only, in all the recursive calls
	static TreeNode* p = NULL;			
	
	//converting left subtree to double linked list recursively
	Convert_to_Double_Linked_List(A->left, h);		
	
	//converting the node to double linked list
	if(p==NULL)					
	{
		*h = A;
	}
	else						
	{
		A->left = p;
		p->right = A;
	}
	p = A;
	
	//now converting right subtree to double linked list recursively
	Convert_to_Double_Linked_List(A->right, h);		
}

void write_values(TreeNode* A)
{
	while(A){
		cout<<A->value<<" ";
		A = A->right;
	}
}

int main()
{
	TreeNode* root = InsertNode(5);
	root->left = InsertNode(6);
	root->right = InsertNode(7);
	root->left->left = InsertNode(3);
	root->left->right = InsertNode(4);
	root->right->left = InsertNode(2);
	root->right->right = InsertNode(9);
	
	TreeNode* top = NULL;
	
	//converting binary tree to double linked list
	Convert_to_Double_Linked_List(root,&top);		
	
	cout<<"Elements of Doubly Linked List are: "<<endl;
	
	write_values(top);
	
	return 0;
}

/*
Time Complexity : O(N);
Space Complexity : O(1);

Test Case 1- 

Here if we give following binary tree as input:
	5
   / \
  6   7
 / \ / \
3  4 2  9 

Then we will get following output - 
3 6 4 5 2 7 9

Test Case 2-

If we give following binary tree as input:
	2
   / \
  8   5
 /   / 
3   4 

Then we will get following output - 
3 8 2 4 5
*/
