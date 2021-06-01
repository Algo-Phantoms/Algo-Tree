/* 

CHECK WHETHER A BINARY TREE IS A BINARY SEARCH TREE
The BST property which is "Every node on the right subtree has to be 
larger than the current node and every node on the left subtree has to 
be smaller than the current node" is the key to figure out whether a 
Binary tree is Binary Search Tree(BST) or not.

Algorithm:
       To see if a binary tree is a binary search tree, check:
       1. If a node is a left child, then its key and the keys of the
         nodes in its right subtree are less than its parent’s key.
       2. If a node is a right child, then its key and the keys of the
         nodes in its left subtree are greater than its parent’s key.

*/
#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Function to determine whether a given binary tree is a BST by keeping a
// valid range (starting from [-INFINITY, INFINITY]) and keep shrinking
// it down for each node as we go down recursively
bool isBST(Node* node, int minKey, int maxKey)
{
    // base case
    if (node == NULL) {
        return true;
    }
 
    // if the node's value falls outside the valid range
    if (node->data < minKey || node->data > maxKey) {
        return false;
    }
 
    // recursively check left and right subtrees with an updated range
    return isBST(node->left, minKey, node->data) &&
            isBST(node->right, node->data, maxKey);
}
 
// Function to determine whether a given binary tree is a BST
void isBST(Node* root)
{
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("The tree is a BST.");
    }
    else {
        printf("The tree is not a BST!");
    }
}
// Driver Program 
int main()
{   
    cin >> n;
    int keys[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> keys[i];
    }
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // swap nodes
    swap(root->left, root->right);
    isBST(root);
 
    return 0;
}

/*

Testcases:

1.

Input:-
15 10 20 8 12 16 25
Output:-
The tree is not a BST!

2.

Input:-
3 2 5 1 4
Output:-
The tree is not a BST!


Complexities:

Time Complexity:- O(n) where n is size of BST
Space Complexity:- O(n) where n is tree's height

*/
