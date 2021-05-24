/*Find the BST with the maximum heigth i.e. largest BST of the binary tree, which the user will input.*/

#include <iostream>
#include <queue>
#include<limits.h>

template <typename T>    // template to take any data type string or integer as input
class BinaryTreeNode {   
   public:               //following is the binary tree node class structure
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {  //constructor
        this->data = data; 
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {     //destructor
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


int height(BinaryTreeNode<int> *root)  //returning heigth of the tree

    if(root == NULL) return 0;                                   // height of the tree will be the height of left or right child node with maximum height
    return 1 + max( height(root->left), height(root->right) );  //  and + 1 for the root to child height
}

bool isbst(BinaryTreeNode<int> *root, int min, int max){       //checking if the tree is bst or not
    if(root == NULL) return true;
    if(root->data < min || root->data > max) return false;
    return isbst(root->left, min, root->data-1) && isbst(root->right, root->data, max);    //checking BST for right child of root root and left child of root by
                                                                                          // giving a recursive call if both are true only then the root is BST   
}
bool isBST(BinaryTreeNode<int> *root){

    return isbst(root, INT_MIN, INT_MAX);  //creating helper function to check BST
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    if(isBST(root)) return height(root);
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));    //determining which is a larger BST Subtree by finding the the height of left and right subtree of root
   
}

BinaryTreeNode<int>* takeInput() { //INPUT FUNCTION
    int rootData;
    cout << "enter the root data:";
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    } 
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    while ( !q.empty() ) {           // Taking input data and pushing it in queue "q". 
        BinaryTreeNode<int>* currentNode = q.front();   
        q.pop();                  // Pushing data in "q" in the form [(ROOT) A, (LEFT CHILD OF ROOT) B, (RIGHT CHILD OF ROOT) C, LEFT CHILD Of B, RIGHT CHILD OF B, LEFT CHILD of C,..]
        int leftChild, rightChild;
       
        cin >> leftChild;     
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
/*
----------------------------------------------------------------------------------

TIME COMPLEXITY: O(N) [WHERE N IS NUMBER OF NODES IN INPUT BST]
SPACE COMPLEXITY: O(H) [WHERE H IS HEIGHT OF THE INPUT BST]

-------------------------------------------------------------------------------
SAMPLE CASE 1:
INPUT
enter the root data:9 3 5 10  2 3 -1 -1 -1 -1 -1 9 -1 -1
OUTPUT
2
--------------------------------------------------------------------------------
SAMPLE CASE 2:
INPUT
enter the root data:8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
OUTPUT
4

*/
