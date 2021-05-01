/*
Binary tree is a data structure that has at most 2 child node i.e. left and right child.
For DFS traversal, we start with a node, traverse its adjacent child node and then to the 
adjacent child node of current and so on. We can inorder / preorder / postorder way to do so.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node                        //structure of the binary tree
{
    int info;                      //data part
    struct Node *left, *right;     //left and right node which will contain address of left and right subtree
};

//function to create tree
struct Node* create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout << "\nEnter data to be inserted or type -1 : ";
    cin>>data;

    //condition for termination
    if(data == -1)
        return 0;

    tree->info = data;

    cout << "Enter left child of " << data;
    tree->left = create();

    cout << "Enter right child of " << data;
    tree->right=create();

    return tree;
};

/*
In the DFS traversal, we start with a node and traverse its adjacent
child node and continue this process until we are done with all the nodes.
As trees do not contain cycles,we will surely traverse all the nodes.
We have tree ways of doing it:
1.Pre-order way: First print the data, goto left child and then goto right child.
1.In-order way: First goto left child, print the data and then goto right child.
1.Post-order way: First goto left child, then goto right child and then print the data.
*/

void DFS_PreOrder(Node* root)
{
    if(root == NULL)
        return;
    cout << root->info << " ";
    DFS_PreOrder(root->left);
    DFS_PreOrder(root->right);

}

void DFS_PostOrder(Node* root)
{
    if(root == NULL)
        return;
    DFS_PostOrder(root->left);
    DFS_PostOrder(root->right);
    cout << root->info << " ";
}

void DFS_InOrder(Node* root)
{
    if(root == NULL)
        return;
    DFS_InOrder(root->left);
    cout << root->info << " ";
    DFS_InOrder(root->right);
}

//Driver Program
int main()
{
    Node *root = NULL;
    root = create();

    cout << "\nDFS Traversal(Pre-Order): ";
    DFS_PreOrder(root);
    cout << "\nDFS Traversal(Post-Order): ";
    DFS_PostOrder(root);
    cout << "\nDFS Traversal(In-Order): ";
    DFS_InOrder(root);

    return 0;
}

/*
Time Complexity : O(n), because we are traversing n-nodes on the tree
Space Complexity: O(1)

Sample Input/Output(1):
Enter data to be inserted or type -1 : 10
Enter left child of 10
Enter data to be inserted or type -1 : 20
Enter left child of 20
Enter data to be inserted or type -1 : 30
Enter left child of 30
Enter data to be inserted or type -1 : -1
Enter right child of 30
Enter data to be inserted or type -1 : -1
Enter right child of 20
Enter data to be inserted or type -1 : -1
Enter right child of 10
Enter data to be inserted or type -1 : 40
Enter left child of 40
Enter data to be inserted or type -1 : -1
Enter right child of 40
Enter data to be inserted or type -1 : 50
Enter left child of 50
Enter data to be inserted or type -1 : -1
Enter right child of 50
Enter data to be inserted or type -1 : -1

DFS Traversal(Pre-Order): 10 20 30 40 50
DFS Traversal(Post-Order): 30 20 50 40 10
DFS Traversal(In-Order): 30 20 10 40 50

Tree Formed :
    10
    /\
  20  40
 /     \
30     50


Sample Input/Output(2):
Enter data to be inserted or type -1 : 1
Enter left child of 1
Enter data to be inserted or type -1 : 2
Enter left child of 2
Enter data to be inserted or type -1 : -1
Enter right child of 2
Enter data to be inserted or type -1 : 3
Enter left child of 3
Enter data to be inserted or type -1 : -1
Enter right child of 3
Enter data to be inserted or type -1 : -1
Enter right child of 1
Enter data to be inserted or type -1 : 4
Enter left child of 4
Enter data to be inserted or type -1 : 5
Enter left child of 5
Enter data to be inserted or type -1 : -1
Enter right child of 5
Enter data to be inserted or type -1 : -1
Enter right child of 4
Enter data to be inserted or type -1 : -1

DFS Traversal(Pre-Order): 1 2 3 4 5
DFS Traversal(Post-Order): 3 2 5 4 1
DFS Traversal(In-Order): 2 3 1 5 4


Tree Formed :
     1
    / \
   2   4
   \   /
   3  5
*/
