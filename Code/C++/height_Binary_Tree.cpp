/*
The following code finds the height of a binary tree. 
Initially, we define a node of the binary tree using the class 'Node',
which consists of a data (an integer here) and pointers to its left and right children.
To create the binary tree we use the function 'createBinaryTree' which returns the pointer 
to the root. Now, this 'createBinaryTree' function utilizes 'insertNode' function to insert 
a new node in the tree. The insertion of a new node can be done in any way (level order fashion, 
inorder fashion etc). The implemented code inserts a node following the 'Binary  Search Tree' fashion.
Although the insert function is not our concern, as our main motto is to find the height of the 
binary tree.

The height of the binary tree is defined by :
"Number of edges in longest path from the root to a leaf node"

The 'heightBinaryTree' function finds the height of the tree in a recursive manner. For any leaf node
the height is 0. The function finds the height of left subtree and right subtree of a node
and takes the greater of them and adds '1' to it to find the height of the node.
'1' is added to count the edge between the node and its subtree which is along the longest path
to the root.
*/

#include <iostream>

using namespace std;

class Node
{
public:
    // The fields of the binary tree i.e., data, pointer to left child, pointer to the right child
    int data;
    Node *left;
    Node *right;
};

Node *insertNode(Node *root, int data)
{
    // This function inserts a new node to the binary tree

    // If the tree is empty, the created new node is made as the root of the tree 
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        Node *cur;

        // Checks whether the inserted data is less than or equal to the data in root, if so then insert 
        // the new node as the left child of the current node
        if (data <= root->data)
        {
            cur = insertNode(root->left, data);
            root->left = cur;
        }

        // Else insert it as right child of the current node
        else
        {
            cur = insertNode(root->right, data);
            root->right = cur;
        }
    }

    return root;
}

Node *createBinaryTree(Node *root)
{
    int data;
    cin >> data;

    // The user has to insert data to create the binary tree, when -1 is entered, the formation stops
    while (data != -1)
    {
        root = insertNode(root, data);
        cin >> data;
    }
    return root;
}

int heightBinaryTree(Node *root)
{
    // If root is null i.e., tree is empty return -1
    if (!root)
        return -1;

    // finds the height of the left subtree
    int lheight = heightBinaryTree(root->left);

    // finds the height of the right subtree
    int rheight = heightBinaryTree(root->right);

    // returns the height
    return 1 + max(lheight, rheight);
}

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);
    
    cout << "Height of the binary tree is: " << heightBinaryTree(root) << endl;
}

/*
Sample Inputs and Outputs:
    Test Case 1:
        Input: 15 -1
        Tree:           15
        Output: Height of the binary tree is: 0
        

    Test Case 2:
        Input: 10 9 11 7 12 8 15 -1
        Tree:
                        10
                       /  \
                      9    11
                     /       \
                    7         12
                    \           \
                     8           15
        Output: Height of the binary tree is: 3

    Test Case 3:
        Input: 1 2 3 4 5 6 7 8 9 -1
        Tree:           1
                         \
                          2
                           \
                            3
                             \
                              4
                               \
                                5
                                 \
                                  6
                                   \
                                    7
                                     \
                                      8
                                       \ 
                                        9
        Output: Height of the binary tree is: 8



Time Complexity:
    As we are visiting every node exactly once, hence the time complexity of the
    algorithm is O(N), where, 'N' is the number of nodes

*/
