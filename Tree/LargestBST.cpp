/*Find the BST with the maximum heigth i.e. largest BST of the binary tree, which the user will input.*/
#include <iostream>
#include <queue>
#include<limits.h>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


int height(BinaryTreeNode<int> *root) {

    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isbst(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL) return true;
    if(root->data<min||root->data>max) return false;
    return isbst(root->left,min,root->data-1)&&isbst(root->right,root->data,max);
}
bool isBST(BinaryTreeNode<int> *root){

    return isbst(root,INT_MIN,INT_MAX);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    
    if(isBST(root)) return height(root);
    return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));

}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout<<"enter the root data:";
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
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
-------------------------------------------------------------------------
SAMPLE CASE 1:
INPUT
enter the root data:9 3 5 10  2 3 -1 -1 -1 -1 -1 9 -1 -1
OUTPUT
2
--------------------------------------------------------------------------
SAMPLE CASE 2:
INPUT
enter the root data:8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
OUTPUT
4

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/
