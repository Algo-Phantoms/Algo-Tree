 #include<iostream>
 using namespace std;
#include<vector>
 //creating a Binary Tree Node class 
 template <typename T>  //makes sure that we can make a node of any data type we want 
 class BinaryTreeNode {
     public : 
     T data;                      //data corresponding to the paticular node 
     BinaryTreeNode<T> *left;     //stores the address of the left side of the BT
     BinaryTreeNode<T> *right;    //stores the address of the right side of the BT

     BinaryTreeNode(T data) {
         this -> data = data;
         left = NULL;
         right = NULL;
     }
 };

 //Take the Input Of the Binary Tree in the level Order Traversal 
 // Make sure if there is left or right node of any node then give it's data as -1;

 BinaryTreeNode<int>* takeInput() {

     int rootData;
     cin >> rootData;
     if(rootData == -1) {
         return NULL;
     }
     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); //the root node 
     queue<BinaryTreeNode<int>*> q;
     q.push(root);
     while(!q.empty()) {
         BinaryTreeNode<int> *currentNode = q.front();
 	    q.pop();
         int leftChild, rightChild;
         cin >> leftChild;           //giving the data for the leftChild .If the data provided is -1  don't make any node of it .
         if(leftChild != -1) {
             BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
             currentNode -> left =leftNode;
             q.push(leftNode);
         }
         cin >> rightChild;
         if(rightChild != -1) {
             BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
             currentNode -> right =rightNode;
             q.push(rightNode);
         }
     }
     return root;   //returning the root of the Binary Tree 
 }


 //left view of a Binary Tree  Example:  1:2,3 ; 2:4,5; 3:6,7; 4:-1,8
//      1
//    2   3
//  4  5 6  7
//   8
//the left view will be : 1 2 4 8


 // Understanding: When we carefully observe this ,all the elements that are occuring at the starting of every level is added up in 
 // the left view  of a BT

 // So we try to taverse the tree in a level Order Traversal and storing the starting element of each level in the vector .
 // At the end returning the vector ,that will contain the elements (left view elements).

vector<int>leftview(BinaryTreeNode<int>*root)
{
    vector<int>ans;
    if(root==NULL)      //checking for the base case if root==NULL return the empty vector
    {
        return ans;
    }

    queue<BinaryTreeNode<int>*>q;

    q.push(root);
    while(!q.empty())
    {
        int n=q.size();          //gives the no of elements at a particular level stored in the queue at a particular time
        BinaryTreeNode<int>*help=q.front();
        q.pop();
        ans.push_back(help->data);   //storing the first encountered elemts in the particular level 
        if(help->left!=NULL)
        {
            q.push(help->left);      //storing the left and the right nodes in the queue if exists
        }
        if(help->right!=NULL)
        {
            q.push(help->right);
        }
        n--;
        while(n--)        //working for the left over elements at the same level just excluding the first element 
        {
            BinaryTreeNode<int>*help=q.front();
            q.pop();
            ans.push_back(help->data);   
             //storing the left and the right nodes in the queue if exists
            if(help->left!=NULL)
            {
               q.push(help->left);
            }
           if(help->right!=NULL)
           {
              q.push(help->right);
           }
        }
    }
    return ans;

}
