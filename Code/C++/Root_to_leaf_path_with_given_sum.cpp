/*
We need to find out is their a path from root to leaf such that sum of all the nodes in the path is equal to given sum.
For this we will use inorder traversal of binary tree and keep on subtracting the data of node on which we are presently from the sum.
When we reach the leaf node we will check if the sum is equal to the node's data. If the sum is equal we will return true, else we will return false. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int x){                
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* Insert(Node* root, int data){

    // make new Node
    if(root == nullptr){                
        root = new Node(data);
        return root;
    }

    else if(data < root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }

    return root;
}

bool has_path_sum(Node * root, int sum) {
    if (root == nullptr) return false;
    if (root -> data == sum && root -> left == nullptr && root -> right == nullptr) return true;
    return has_path_sum(root -> left, sum - root -> data) || has_path_sum(root -> right, sum - root -> data);
}

int main() {

    int n;               
    cin >> n;
    
    int data;
    cin >> data;
    Node* root = new Node(data);

    for(int i=1;i<n;i++){ 
        cin >> data;
        root = Insert(root, data);
    }

    int sum;
    cin >> sum;
    cout << has_path_sum(root, sum) << endl;

    return 0;
}

/*
Test Cases:

1.
Input:
4
1 7 9 4  
50

Output:
0

Explanation:
    1         
     \  
      7       
     / \
    4   9  
There is no path from which 50 can be obtained.
    
2.
Input:
5
5 1 7 6 8 
6  

Output:
1

Explanation:
      5         
     / \
    1   7       
       / \
      6   8  
The path consisting of 5 and 1 will give us 6.

Time Complexity: O(Nodes)
Space Complexity: O(Height)
*/
