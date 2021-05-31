/*
Find the diameter of binary tree.
*/

//The diameter of a tree is the number of nodes on the largest path between two end nodes i,e the leaf nodes.
//Height is the number of nodes along the longest path from the root node down to the farthest node.

/*
Algorithm:
** Diameter of a tree is sum of the height of the left subtree and the right subtree.

1) We will calculate the height of left and right subtree by recursively calling the height function for every node.
2) Diameter of a tree is maximum diameter of -
    A) Left subtree
    B) Right subtree and 
    C) Height of left subtree + height of right subtree + 1

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int val){
        data = val;
        
        //left and right child of node is initialised to NULL
        left = NULL;
        right = NULL;

    }
};

//Recusive function to calculate the height of the tree
int height(struct Node* root){
    //If the tree is empty height is 0
    if(root==NULL)
        return 0;

    /*
    Recusively calling height function to calculate the heigth of the tree 
    which is equal to 1 + max(height(root->left),height(root->right))
    */
    return 1 + max(height(root->left), height(root->right));
}

//Recursive functin to calculate the diameter of the tree
int diameter(struct Node* root){
    
    //base case if tree is NULL diameter is 0
    if(root==NULL)
        return 0;

    //calculate the height of the left subtree
    int leftHeight = height(root->left);

    //calculate the height of the right subtree
    int rightHeight = height(root->right);

    //calcualte the diameter of the left subtree
    int leftDiameter = diameter(root->left);

    //calculate the diameter of the right subtree
    int rightDiameter = diameter(root->right);

    //Diameter of the tree
    return max(leftHeight + rightHeight + 1 , max(leftDiameter, rightDiameter));
}

int main(){
    /* Constructed binary tree is
             1
            / \
           2  3
            / \    
            4  5
    */

   struct Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->right->left = new Node(4);
   root->right->right = new Node(5);

   cout<<"Diameter of the binary tree is : "<<diameter(root)<<endl;;

   return 0;
}

/*
TestCase:
        Constructed binary tree is
             1
            / \
           2  3
            / \    
            4  5

Output:
   Diameter of the binary tree is : 4
 

Time Complexity :  O(n^2) where n is the number of nodes in the binary tree
Space Complexity : O(1) 

*/