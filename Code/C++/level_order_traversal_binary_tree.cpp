/*
LEVEL ORDER TRAVERSAL OF BINARY TREE
Level order traversal is breadth first traversal of the tree;
        (8)
      /     \
    (3)    (12)
    /      /  \
  (1)    (10) (16)

Level order traversal of the tree above: 8 3 12 1 10 16
We will use a queue. A queue uses First In First Out (FIFO) order. We will visit each node and push it's children into the queue.
In this way, the order in which nodes of a level are visited becomes the order in which the children of the nodes of this level
will be visited.
We will start by pushing the root in the queue. Then while the queue is not empty, we will pop the node at the top of the queue,
print it's value and push it's non-NULL children into the end of the queue.
The process stops when the queue becomes empty and there are no more nodes to traverse.

The level order traversal of each level individually for the above tree will be:
8
3 12
1 10 16

To print each level individually, we can modify our approach, such that in a single iteration we traverse all the nodes of a particular
level and then print a newline at the end of this iteration, before moving on to the next level. To do this, store the number of Nodes 
present in the queue, this will be the count of the nodes in the particular level. Then do the same operations as mentioned above to the
Nodes of this level. After we have visited every node of this level, we print a newline and start the next iteration for the next level.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* left,*right;
    Node(int val){
        value=val;
        left=nullptr;
        right=nullptr;
    }
};

// Function for level order traversal of the binary tree
void PrintLevelOrder(Node* root){
    //if root is NUll return
    if(root == nullptr)
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
        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
    }
    return;
}

// Function for level order traversal of each level individually in a binary tree
void PrintLevelOrderIndividually(Node* root){
    // if root is NUll return
    if(root == nullptr)
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
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
        
        // This level has been printed completely so we will print a new line before the next level
        cout<<endl;
    }
    return;
}

int main()
{
    /*
    Creating a binary tree for test case 1
            (8)
          /     \
        (3)    (12)
        /      /  \
      (1)    (10) (16)
    */
    Node *root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(12);
    root1->left->left = new Node(1);
    root1->right->left = new Node(10);
    root1->right->right =new Node(16);
    
    cout << "Level Order traversal of binary tree with root1 is: \n";
    PrintLevelOrder(root1);
    cout<<endl;
    
    cout<<"Level Order Traversal with of each level individually for root1 is: \n";
    PrintLevelOrderIndividually(root1);
    cout<<endl;
    
    /*
    Creating a binary tree for test case 2
            (1)
          /    \
        (3)   (4)
              /  \
            (5) (6)
            /
          (7)
    */
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(4);
    root2->right->left = new Node(5);
    root2->right->right = new Node(6);
    root2->right->left->left =new Node(7);
    
    cout << "Level Order traversal of binary tree with root2 is: \n";
    PrintLevelOrder(root2);
    cout<<endl;
    
    cout<<"Level Order Traversal with of each level individually for root2 is: \n";
    PrintLevelOrderIndividually(root2);
    cout<<endl;
    return 0;
}

/*
Test Case 1:

Input:
        (8)
      /     \
    (3)    (12)
    /      /  \
  (1)    (10) (16)

Output:
     Level Order traversal of binary tree with root1 is:                                                                                           
     8 3 12 1 10 16                                                                                                                                
     Level Order Traversal with of each level individually for root1 is:                                                                           
     8                                                                                                                                             
     3 12                                                                                                                                          
     1 10 16  

Test Case 2:

Input:
        (1)
      /    \
    (3)   (4)
          /  \
        (5) (6)
        /
      (7)

Output:
     Level Order traversal of binary tree with root2 is:                                                                                             
     1 3 4 5 6 7                                                                                                                                     
     Level Order Traversal with of each level individually for root2 is:                                                                             
     1                                                                                                                                               
     3 4                                                                                                                                             
     5 6                                                                                                                                             
     7  

Time complexity:O(n), where n is the number of nodes

Space complexity: O(n) for creating a queue, where n is the number of nodes
*/