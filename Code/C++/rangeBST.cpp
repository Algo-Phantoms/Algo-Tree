/*
	Print all data in given range in Binary Search Tree
*/

#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *left,*right;
}Node;

Node* newNode(int data)
{
	Node* node=new Node;
	node->data=data;
	node->left=node->right=nullptr;
	return node;
}

Node* insert(Node* root,int key)
{
	if(root==nullptr)
		return newNode(key);
	else if(key < root->data)
		root->left = insert(root->left,key);
	else if(key > root->data)
		root->right = insert(root->right,key);
	else
		return root;
}

void rangeBST(Node* root,int key1,int key2)
{
    if(root)
    {
        rangeBST(root->left,key1,key2);
        //if the given data lies in the range, print the data
        if(root->data>=key1 && root->data<=key2)
            cout<<root->data<<" ";
        rangeBST(root->right,key1,key2);
    }
}
int main()
{
	int n,val,key1,key2;
	cout<<"Enter the number of elements to be inserted"<<endl;
	cin>>n;
	Node* root = nullptr;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		//insert the values into BST
		root = insert(root,val);
	}
	cout<<"Enter the minimum and maximum range"<<endl;
	cin>>key1>>key2;
	// inorder function to traverse the entire BST
	rangeBST(root,key1,key2);
}

	/*
		Space Complexity : O(1)
		Time Complexity  : O(n)
		
		OUTPUT 1:
		Enter the number of elements to be inserted
		6
		1 3 2 6 5 4
		Enter the minimum and maximum range
		1 4
		1 2 3 4
		
		OUTPUT 2;
		Enter the number of elements to be inserted
		3
		1 2 1
		Enter the minimum and maximum range
		1 1
		1
		
	*/

