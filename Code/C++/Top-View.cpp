/*
 
 QUES :  Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be    printed in any order.

        A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.
 
 */


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


/*
Creating a void function that will print the top view of Binary Tree


 Consider example:
          1
        2   3
      4  5 6  7

      output: 4 2 1 3 7

      let's assign the position to the root pos=0;
      and the left node will have left_pos=pos-1;
      and the right node will have right_pos=pos+1;

      therefore: 1=0
                 2=-1
                 3=1
                 4=-2
                 5=0
                 6=0
                 7=2
      If we carefully observe this ,the numbers lies  in the same vertical line will have the same postion
      for pos=0 no: 1,5,6

      so if we safe the node's value corresponding to every unique position in map will provide the top most view in the particular
      order from leftmost to rightmost .
      But the point is what to do with the repeating pos like in the case for pos=0 .So we will make sure that if key corresponding
      to the particular pos is not being created then we have to place a key-value pair into it otherwise don't.
      By storing the node for the first occurance of the particular position will just store the outerost elements and thus in return
      giving us the top-most view.

      Approach:

      We will create 2 maps map1 and map2,first will store the pos corresponding to an node and the other will store the node correspondingto a
      particular position
      And we will use level order traversal that if it's left/right root exist then it will push in the queue and stores it's pos in the
      map1.
      Doing this work till queue does not become empty;
      While poping the element ,find the pos corresponding to it .If the key as the pos is already present in map2 don't do anything otherwise
      place it in map2;
      After this whole thing we will have map2 with the unique postion and the node's value corresponding to it and in the ascending order
      as well
      So just iterate through the map2 and print the second value .
*/



void TopViewofBT( BinaryTreeNode< int >* root )
{
	//Base Case
	if(root == NULL)
	{
		return ;
	}
    //stores the pos corresponding to a node .Here Key:Node and value is position
    
	map < Node*, int > m;
    
    //stores the node's value corresponding to a pos .Here Key:position and value is Node's value
    
    map < int , int > mp;
    
    queue< Node* >q;
    
    m[root] = 0;
    
    q.push( root );
    
    while( !q.empty() )
    {
        Node* temp = q.front();
        q.pop();
        
        //getting the pos of the particular node
        
        int t = m[temp];
        
        if(mp.find(t) == mp.end())
        {
            //storing the node's value corresponding to the unique pos
            mp[t] = temp->data;
        }
        
        //checking if node's left exist
        
        if( temp->left )
        {
            //pos_left=pos-1
            m[temp->left] = t - 1;
            q.push(temp->left);
        }
        
        //checking if node's right exist
        
        if(temp->right)
        {
            //pos_right=pos+1;
            q.push( temp->right );
            m[temp->right] = t + 1;
        }
    }
     //iterating through the map
    
    for( map<int,int>::iterator i = mp.begin() ; i != mp.end() ; i++)
    {
        //printing the node's value
        cout<< i->second <<" ";
    }
    
    cout<< endl;
}

int main()
{
    
    BinaryTreeNode<int>* root = takeInput();
    
    TopViewofBT(root);
    
}

/*
 
 TIME COMPLEXITY : O(nlogn) , n is the number of nodes in a Binary Tree
 
 SPACE COMPLEXITY : O(n) , n is the number of nodes in a Binary Tree
 
 
 EXAMPLES:
 
 1.
 
          1
        2   3
      4  5 6  7

 
    INPUT  : 1 2 3 4 5 6 7 -1
 
    OUTPUT : 4 2 1 3 7
 
 
 2.
 
 
     1
   /   \
 2       3
   \
     4
       \
         5
          \
            6
 
 
   INPUT  : 1 2 3 -1 4 -1 -1 -1 5 -1 6
   
   OUTPUT : 2 1 3 6
 
 
 */
