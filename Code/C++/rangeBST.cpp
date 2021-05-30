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
        if(root->data>=key1 && root->data<=key2){
        	cout<<root->data<<" ";
		}
        rangeBST(root->right,key1,key2);
    }
}
int main()
{
	int n,val,key1,key2,minimum=INT_MAX,maximum=INT_MIN;
	cout<<"Enter the number of elements to be inserted"<<endl;
	cin>>n;
	Node* root = nullptr;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		//insert the values into BST
		root = insert(root,val);
		minimum=min(minimum,val);
		maximum=max(maximum,val);
	}
	cout<<"Enter the minimum and maximum range"<<endl;
	cin>>key1>>key2;
	
	if(minimum>key2 || maximum<key1)
	//If both the given keys are less than the minimum or maximum value of a tree then there will be no elements in that range
		cout<<"No elements in the given range";
	else
	// inorder function to traverse the entire BST
		rangeBST(root,key1,key2);
	return 0;
}

	/*
		Space Complexity : O(height) as recursion call
		Time Complexity  : O(n) n elements are inserted
		
		TESTCASE 1:
		Enter the number of elements to be inserted
		6
		1 3 2 6 5 4
		Enter the minimum and maximum range
		1 4
		
		OUTPUT:
		1 2 3 4
		
		TESTCASE 2:
		Enter the number of elements to be inserted
		3
		1 2 1
		Enter the minimum and maximum range
		1 1
		
		OUTPUT:
		1
		
		TESTCASE 3:
		Enter the number of elements to be inserted
		5
		1 2 3 4 5
		Enter the minimum and maximum range
		6 7
		
		OUTPUT:	
		No elements in the given range
		
		TESTCASE 4:
		Enter the number of elements to be inserted
		5
		6 7 8 9 10
		Enter the minimum and maximum range
		2 5
		
		OUTPUT:
		No elements in the given range		
		
	*/
