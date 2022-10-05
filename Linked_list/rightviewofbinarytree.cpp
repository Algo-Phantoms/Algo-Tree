#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                          sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void rightViewUtil(struct Node *root,
                   int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
   
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
 
  
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 

void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
 

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    rightView(root);
 
    return 0;
}
