/*
Here we need to find minimum and maximum element in Binary Search Tree.
Recusive method is used to find the minimum and maximum element in BST.
*/

#include <iostream>
using namespace std;

struct BSTNode{
int data;
BSTNode* left;
BSTNode* right;
};

/*
GetNewNode function helps to create a new node by allocating it a memory dynamically.
It has just one parameter which is "data" which assigns value to the node thereby
creating a fresh node having left and right child as “NULL”.
*/

BSTNode* GetNewNode(int data){
BSTNode* newNode=new BSTNode();
newNode->data=data;
newNode->left=newNode->right=NULL;
return newNode;
}

BSTNode* Insert(BSTNode* root,int data){
if(root==NULL){
  root=GetNewNode(data);                  // Insert the first node data if root is NULL
  return root;
  }
else if(data<=root->data){
root->left=Insert(root->left,data);       // Insert the left node data if the data is lesser than or equal to the root node data
 }
 else{
 root->right=Insert(root->right,data);    // Insert the right node data if the data is greater than the root node data
 }

 return root;
}

/*
The minimum element in a Binary Search Tree will be the leftmost node in leftsubtree,
so we keep on traversing the leftsubtree tree till we reach the leftmost node (current = current->left),
and when we encounter the leftmost node we print it’s value and terminate the loop as current->left will become NULL.
*/

int findmin(BSTNode* root){
BSTNode* current=root;
if(root==NULL){
 cout<<"Error:List is empty"<<endl;
 }
 while(current->left!=NULL){
 current=current->left;
 }
 return current->data;
}

/*
The maximum element in a BST will be the last node in the right subtree.
That is what we are doing in findmax() function, we are making the current = current->right so that we can reach the extreme right node or the last node in a right subtree.
The last node in a right subtree will not have any child, therefore the while condition is going to terminate as current->right will become NULL.
*/

int findmax(BSTNode* root){
BSTNode* current=root;
if(root==NULL){
 cout<<"Error:List is empty"<<endl;
 return -1;
 }
 while(current->right!=NULL){
 current=current->right;
 }
 return current->data;
}

int main(){
BSTNode* root=NULL;   //creating an empty tree
int n,num;
cout<<"Enter number of elements you have to add: ";
cin>>n;
cout<<"Enter the elements to be added in Binary Tree: ";

for(int i=0;i<n;i++){
cin>>num;
root=Insert(root,num);
}

cout<<"Minimum value in BST: "<<findmin(root)<<endl;
cout<<"Maximum value in BST: "<<findmax(root);

return 0;
}

/*

Test Case 1:
Input:
Enter number of elements you have to add: 6
Enter the elements to be added in Binary Tree: 10
20
15
28
12
17

Output:
Minimum value in BST: 10
Maximum value in BST: 28


Test Case 2:
Input:
Enter number of elements you have to add: 5
Enter the elements to be added in Binary Tree: 13
48
20
68
19

Output:
Minimum value in BST: 13
Maximum value in BST: 68

*/


