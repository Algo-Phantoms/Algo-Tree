//LEVEL ORDER TRAVERSAL OF BINARY TREE
// Level order traversal is breadth first traversal of the tree;
//         (8)
//       /     \
//     (3)    (12)
//     /      /  \
//   (1)    (10) (16)

// Level order traversal of the tree above: 8 3 12 1 10 16
// We will use a queue. A queue uses First In First Out (FIFO) order. We will visit each node and push it's children into the queue.
// In this way, the order in which nodes of a level are visited becomes the order in which the children of the nodes of this level
// will be visited.
// We will start by pushing the root in the queue. Then while the queue is not empty, we will pop the node at the top of the queue,
// print it's value and push it's non-NULL children into the end of the queue.
// The process stops when the queue becomes empty and there are no more nodes to traverse.

// The level order traversal of each level individually for the above tree will be:
// 8
// 3 12
// 1 10 16

// To print each level individually, we can modify our approach, such that in a single iteration we traverse all the nodes of a particular
// level and then print a newline at the end of this iteration, before moving on to the next level. To do this, store the number of Nodes 
// present in the queue, this will be the count of the nodes in the particular level. Then do the same operations as mentioned above to the
// Nodes of this level. After we have visited every node of this level, we print a newline and start the next iteration for the next level.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int value;
    struct Node *left, *right;
};

// Function to create a new node with value val
Node* createNode(int val){
    Node *newNode = new Node;
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for level order traversal of the binary tree
void PrintLevelOrder(Node* root){
    //if root is NUll return
    if(root == NULL)
        return;
    queue<Node*>q;
    
    //push the root in the queue
    q.push(root);
    
    while(q.empty() == false){
        //remove and store the node present in the front of the queue
        Node* temp=q.front();
        q.pop();
        
        // Print it's value
        cout<<temp->value<<" ";
        
        // Push it's non-NULL children to the back of the queue;
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return;
}

// Function for level order traversal of each level individually in a binary tree
void PrintLevelOrderIndividually(Node* root){
    // if root is NUll return
    if(root == NULL)
        return;
    queue<Node*>q;
    
    // push the root in the queue
    q.push(root);
    
    while(q.empty() == false){
        // store the number of elements in the queue. This is the count of the Nodes in this particular level,
        // and we will perform operations for only these nodes in this iteration
        int count=q.size();
        
        // Apply the approach discussed for all nodes of this particular level
        for(int i=1; i<=count; i++){
            
            //remove and store the node present in the front of the queue
            Node* temp=q.front();
            q.pop();
            
            // Print it's value
            cout<<temp->value<<" ";
            
            // Push it's non-NULL children to the back of the queue;
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        
        // This level has been printed completely so we will print a new line before the next level
        cout<<endl;
    }
    return;
}

int main()
{
    //Creating a binary tree
    Node *root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(12);
    root->left->left = createNode(1);
    root->right->left = createNode(10);
    root->right->right = createNode(16);
    
    cout << "Level Order traversal of binary tree is: \n";
    PrintLevelOrder(root);
    cout<<endl;
    
    cout<<"Level Order Traversal with of each level individually is: \n";
    PrintLevelOrderIndividually(root);
    
    return 0;
}
