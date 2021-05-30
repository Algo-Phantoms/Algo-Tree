// Serialization is the process of converting a data structure or object into 
// a sequence of bits so that it can be stored in a file or memory buffer, or 
// transmitted across a network connection link to be reconstructed later in 
// the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. 

#include <bits/stdc++.h>
using namespace std; 
  
struct node{ 
    int next; 
    struct node* left, *right; 
}; 
  
node* newNode(int next){ 
    node* temp = new node; 
    temp->next = next; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
// This function stores a tree in a file
void serialize(node *root, FILE *f){
    if(root == NULL){ 
        fprintf(f, "%d ", -1); 
        return; 
    } 
  
    // Else, store current node and call function for it's children
    fprintf(f, "%d ", root->next); 
    serialize(root->left, f); 
    serialize(root->right, f); 
} 
  
// This function constructs a tree from a file
void deserialize(node *&root, FILE *f){ 
    // Read next item from file. If theere are no more items
    // item is -1, then return 
    int val; 
    if(!fscanf(f, "%d ", &val) || val == -1)
       return; 
  
    // Else create node with this item and call function for it's children 
    root = newNode(val); 
    deserialize(root->left, f); 
    deserialize(root->right, f); 
} 
  
// A simple inorder traversal used for testing the constructed tree 
void inorder(node *root){ 
    if(root){ 
        inorder(root->left); 
        cout<<root->next<<" "; 
        inorder(root->right); 
    } 
}
int main(){ 
    struct node *root        = newNode(14); 
    root->left               = newNode(7); 
    root->right              = newNode(21); 
  
    //serialize the tree into the file 
    FILE *f = fopen("tree.txt", "w"); 
    if(f == NULL){ 
        cout<<"Could not open file"; 
        return 0; 
    } 
    serialize(root, f); 
    fclose(f); 
  
    // deserialize the storeed tree
    node *root1 = NULL; 
    f = fopen("tree.txt", "r"); 
    deserialize(root1, f); 
    inorder(root1); 
  
    return 0; 
}

// output : 7 14 21

// Test Cases :

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]

// Input: root = []
// Output: []

// Input: root = [1]
// Output: [1]

// Input: root = [1,2]
// Output: [1,2]



// Time complexity : In both serialization and deserialization functions, 
//                   we visit each node exactly once, thus the time complexity is O(N),
//                   where N is the number of nodes, i.e. the size of tree.

// Space complexity : In both serialization and deserialization functions, 
//                    we keep the entire tree, either at the beginning or at the end,
//                    therefore, the space complexity is O(N).

