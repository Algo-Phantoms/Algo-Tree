/*
Time Complexity : O(N);
Here we have given following binary tree as input:
	5
   / \
  6   7
 / \ / \
3  4 2  9 

When this will get converted to double linked list, we will get following output -
3 6 4 5 2 7 9
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
