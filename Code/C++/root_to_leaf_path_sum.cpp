/*
We need to find out is their a path from root to leaf such that sum of all the nodes in the path is equal to given sum.
For this we will use inorder traversal of binary tree and keep on subtracting the data of node on which we are presently from the sum.
When we reach the leaf node we will check if the sum is equal to the node's data. If the sum is equal we will return true, else we will return false. 
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

bool has_path_sum(Node * root, int sum) {
    if (root == NULL) return false;
    if (root -> data == sum && root -> left == NULL && root -> right == NULL) return true;
    return has_path_sum(root -> left, sum - root -> data) || has_path_sum(root -> right, sum - root -> data);
}

int main() {
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    int sum;
    cin >> sum;
    cout << has_path_sum(root, sum) << endl;

    return 0;
}

/*
Input:
    1         
     \  
      7       
     / \
    9   4   
sum=8

Output:
0

Input:
      1         
     / \
    5   7       
       / \
      6   4     
         / \
        2   3   
sum=14

Output:
1

Time Complexity: O(Nodes)
Space Complexity: O(Height)
*/