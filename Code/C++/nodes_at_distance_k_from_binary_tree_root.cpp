#include <iostream>
using namespace std;

//a node consists of data, left pointer and right pointer.
struct node{
    int data;
    struct node *left, *right;
    node (int data){
        this->data = data;
        right = left = NULL;
    }
};

void kDistance(struct node* tree, int k){
    //terminate function when NULL root is encountered.
    if(tree == NULL)
        return;

    // print the nodes at a distance k
    if(k==0){
        cout << tree->data << " ";
        return;
    }

    //recursrively call the function to find nodes at left and right subtrees 
    kDistance(tree->left, k-1);
    kDistance(tree->right, k-1);
}

/* Constructed binary tree is  
             10  
            / \  
           27  56  
          /    / \ 
         41   5   6  
        /
       72
    */
int main(){
    struct node* tree = new node(10);
    tree->left = new node(27);
    tree->right = new node(56);
    tree->left->left = new node(41);
    tree->right->left = new node(5);
    tree->right->right = new node(6);
    tree->left->left->left = new node(72);

    kDistance(tree, 2);
}

