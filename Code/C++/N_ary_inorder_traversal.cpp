/*
N-ary tree inorder traversal.
The inorder traversal of a n-ary tree is traversing all the children of the tree
except the last one, the root and finally the rightmost child.
*/
#include<iostream>
#include<vector>
using namespace std;

int n=0;                                          //specifies the number of children the tree has
class TreeNode
{
public:
  int data;
  vector<TreeNode*>children;
  TreeNode(int val)
  {
    data=val;
  }
};

TreeNode *root=NULL;                                    //initialising root to NULL

//creating tree through recursion
TreeNode* creating_tree(int depth)
{
  cout<<"Enter node's data(at depth)"<<depth<<": ";
  int val,child;
  cin>>val;
  TreeNode* instance=new TreeNode(val);
  cout<<"Number of children this node contains: ";
  cin>>child;
  int i=0;
  for(;i<child;i++)
  {
    TreeNode *temp=creating_tree(depth+1);
    instance->children.push_back(temp);
  }

  //initialising the left children with NULL
  while(i<n)
  {
    instance->children.push_back(NULL);
    i++;
  }
  return instance;
}

//inorder traversal of the n-ary tree
void inorder_traversal(TreeNode *root)
{
    if(root==NULL)return;
    int i=0;

    //traversal of all children just before the last
    for(;i<n-1;i++)
    {
      inorder_traversal(root->children[i]);
    }
    cout<<root->data<<" ";

    //traversal of the last node
    inorder_traversal(root->children[i]);
}

int main()
{
  cout<<"Enter the no. of children the tree has: ";
  cin>>n;
  root=creating_tree(1);
  inorder_traversal(root);
  return 0;
}
/*
  Test Case 1:
                Input array: 1,2,5,6,7,3,8,9,4,10

                Tree formed:         1
                                /    |   \
                              2      3    4
                            / | \   /|   /
                           5  6  7 8 9  10

                Inorder Traversal of the following tree: 5,6,2,7,8,9,3,1,10,4

  Test Case 2:
                Input array: 4,5,7,11,12,8,13,6,9,10

                Tree formed:          4
                                    /   \
                                  5      6
                                /   \   / \
                               7     8 9  10
                              / \   /
                            11  12 13

                Inorder Traversal of the following tree: 11,7,12,5,13,8,4,9,6,10
*/

/*
    Time Complexity for the above code: O(m) --where m is the number of nodes
    Space Complexity: O(m)
*/
