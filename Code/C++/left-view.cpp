/*
 QUESTION : Print the left view of a given Binary Tree
 
 APPROACH :
 We will use Level Order Traversal of a Binary Tree with some extensions,that will  print the first node of every level in a Binart Tree
 Note :
 
 1. For the first level there is only root so root's data will always get printed.
 2. For every  level that we are on it, we will maintain a check variable that will be initialized with false and as soon as the first node  of a next  level encounters we will print it's data and make it true ,that means for the next level we have found the first node .
     Therefore before getting to the next level we will print the data of it's first node .
 3. We will maintain a curr and a count variable that will store the number of nodes in a curr level and next level respectively. count  will always get incremented as soon as we push the node in the queue for the level on which we are working . curr will always get decremented as soon as the node  get popped out from queue.
 4. As soon as our curr becomes 0 ,curr will get the value of count and count will be back to 0 so that it can count the nodes for the next level.
 5. This is how we will get to every level and will prints the first node's data that we will encounters.
 */

#include<iostream>
using namespace std;
#include <queue>

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

BinaryTreeNode< int >* takeInput() {
    
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    //the root node
    
    BinaryTreeNode< int > *root = new BinaryTreeNode< int >( rootData );
    queue<BinaryTreeNode< int >*> q;
    q.push( root );
    
    while(!q.empty())
    {
        
        BinaryTreeNode< int > *currentNode = q.front();
        q.pop();
        int leftChild, rightChild ;
        
        //giving the data for the leftChild .If the data provided is -1  don't make any node of it .
        
        cin >> leftChild;
        
        if( leftChild != -1 ) {
            BinaryTreeNode< int >* leftNode = new BinaryTreeNode< int >( leftChild );
            currentNode -> left = leftNode;
            q.push( leftNode );
        }
        
        //giving the data for the leftChild .If the data provided is -1  don't make any node of it .
        
        cin >> rightChild;
        
        if( rightChild != -1 ) {
            BinaryTreeNode< int >* rightNode = new BinaryTreeNode< int >( rightChild ) ;
            currentNode -> right = rightNode;
            q.push( rightNode );
        }
    }
    
    //returning the root of the Binary Tree
    
    return root;
}

//Printint the left view of a Binary Tree;

void leftview ( BinaryTreeNode< int >* root )
{
    if(root == NULL)
     {
         return ;
     }
    //root's data is the first and the only node at it's level so it will get printed
    cout << root->data << " " ;
    //maintaining a queue to stored the nodes
    queue< BinaryTreeNode< int >* > q ;
    q.push( root );
    //no of elements at the current level
    int curr = 1;
    //to count the no of elements for the next level
    int count = 0;
    while( !q.empty())
    {
        //make a check if we have got the first node of next  level or not.
        bool check = false;
        //a loop that will run till we get completed with the number of nodes on the particular level
        while( curr-- )
        {
            BinaryTreeNode< int >* help = q.front();
            q.pop();
            //checking if root's left exsits or not
            if( help->left != NULL )
            {
                q.push( help->left );
                //if we have not found the first node for the next level
                if(!check)
                {
                    //this node will be the first node for the next level
                    cout << help->left->data << " ";
                    check=true;
                }
                //incremente the count for the number of nodes at next level
                count++;
                
            }
            if( help->right != NULL )
            {
                q.push( help->right );
                 //if we have not found the first node for the next level
                if( !check )
                {
                     //this node will be the first node for the next level
                    cout << help->left->data << " ";
                    check = true;
                }
                 //incremente the count for the number of nodes at next level
                count++;
            }
        }
        //completition of the current level and next level started .
        
        //initializing the curr as count,means it will now store the number of nodes at the  level that we will work upon mow.
        curr = count;
        // Count will become 0 so that it can  store the number of nodes for the next level .
        count = 0;
    }
    return ;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    leftview(root);
}
/*
 EXAMPLE :
 
1.   10
    /  \
   5    9
  /    /  \
 8    2    7
 
 OUTPUT :  10 5 8

 
 2.  11
    /  \
   6    9
       /  \
       2    7
 
 
OUTPUT :  11 6 2
 
TIME COMPLEXITY  : O(n)
 
 SPACE COMPLEXITY : O(n)
 
 where n is the number of nodes in a Binary Tree
 
 */
