#include<iostream>
using namespace std;
#include <map>

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



//Creating a void function that will print the top view of Binary Tree


// Consider example:
//          1
//        2   3
//      4  5 6  7

//      output: 4 2 1 3 7 

//      let's assign the position to the root pos=0;
//      and the left node will have left_pos=pos-1;
//      and the right node will have right_pos=pos+1;

//      therefore: 1=0
//                 2=-1
//                 3=1
//                 4=-2
//                 5=0
//                 6=0
//                 7=2
//      If we carefully observe this ,the numbers lies  in the same vertical line will have the same postion 
//      for pos=0 no: 1,5,6

//      so if we safe the node's value corresponding to every unique position in map will provide the top most view in the particular
//      order from leftmost to rightmost .
//      But the point is what to do with the repeating pos like in the case for pos=0 .So we will make sure that if key corresponding
//      to the particular pos is not being created then we have to place a key-value pair into it otherwise don't.
//      By storing the node for the first occurance of the particular position will just store the outerost elements and thus in return 
//      giving us the top-most view.

//      Approach:

//      We will create 2 maps map1 and map2,first will store the pos corresponding to an node and the other will store the node correspondingto a 
//      particular position 
//      And we will use level order traversal that if it's left/right root exist then it will push in the queue and stores it's pos in the 
//      map1.
//      Doing this work till queue does not become empty;
//      While poping the element ,find the pos corresponding to it .If the key as the pos is already present in map2 don't do anything otherwise
//      place it in map2;
//      After this whole thing we will have map2 with the unique postion and the node's value corresponding to it and in the ascending order 
//      as well 
//      So just iterate through the map2 and print the second value .



void TopViewofBT(BinaryTreeNode<int>*root)
{
	//Base Case
	if(root==NULL)
	{
		return ;
	}
	map<Node*,int>m; //stores the pos corresponding to a node .Here Key:Node and value is position 
    map<int,int>mp;  //stores the node's value corresponding to a pos .Here Key:position and value is Node's value 
    queue<Node*>q;
    m[root]=0;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        int t=m[temp];   //getting the pos of the particular node 
        if(mp.find(t)==mp.end())
        {
            mp[t]=temp->data;      //storing the node' value corresponding to the unique pos
        }
        if(temp->left)           //checking if node's left exist 
        {
            m[temp->left]=t-1;    //pos_left=pos-1
            q.push(temp->left);
        }
        if(temp->right) //checking if node's right exist 
        {
            q.push(temp->right); //pos_right=pos+1;
            m[temp->right]=t+1;
        }
    }
    for(map<int,int>::iterator i=mp.begin();i!=mp.end();i++)   //iterating through the map 
    {
        cout<<i->second<<" ";  //printing the node's value 
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    TopViewofBT(root);
}