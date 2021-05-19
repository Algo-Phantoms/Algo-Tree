/*
AVL tree is basically a self-balancing binary search tree in which the balancing factor
i.e difference between the height of left-subtree and right-subtrees is either 0 or 1 or -1
(not more than one). If the balance factor is disturbed then we need to rotate the nodes 
to maintain the balance factor.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left , *right;
    int height;
};

//print in-order traversal of the tree
void inorder(node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->info<<" ";
    inorder(root->right);
}

//print pre-order traversal of the tree
void preorder(node* root)
{
   if(root == NULL)
    return;

   cout << root->info<<" ";
   preorder(root->left);
   preorder(root->right);
}

//print post-order traversal of the tree
void postorder(node* root)
{
   if(root == NULL)
    return;

   preorder(root->left);
   preorder(root->right);
   cout << root->info<<" ";
}

//height() will calculate the height of the tree
int height(node *root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

//left-left rotation function
node* LLrotation(node *root)
{
    node *p1;                                //for adjustments
    node *p2;

    p1 = root;                               //A
    p2 = root->left;                         //B

    p1->left = p2->right;                    //A->left = B->right;
    p2->right = p1;                          //B->right = A;

    return p2;                               //new pointer i.e. B
}

//right-right rotation function
node* RRrotation(node *root)
{
    node *p1;                                //for adjustments
    node *p2;

    p1 = root;                               //A
    p2 = root->right;                        //B

    p1->right = p2->left;                    //A->right = B->left;
    p2->left = p1;                           //B->left = A;

    return p2;                               //new pointer i.e. B
}

//left-right rotation function
node* LRrotation(node *root)
{
    node *p1;
    node *p2;
    node *p3;

    p1 = root;                              //A
    p2 = root->left;                        //B
    p3 = root->left->right;                 //C

    p2->right = p3->left;                   //B->right = C->left
    p1->left = p3->right;                   //A->left = C->right
    p3->right = p1;                         //C->right = A
    p3->left = p2;                          //C->left = B

    return p3;                              //C is the new root
}

//right-left rotation function
node* RLrotation(node *root)
{
    node *p1;
    node *p2;
    node *p3;

    p1 = root;                              //A
    p2 = root->right;                       //B
    p3 = root->right->left;                 //C

    p1->right = p3->left;                   //A->right = C->left
    p2->left = p3->right;                   //B->left = C->right
    p3->right = p2;                         //C->right = B
    p3->left = p1;                          //C->left =

    return p3;                              //C is the new root
}

//return the height of a particular node
int nodeheight(node* root)
{
    if(root && root->left)
    {
        if(root->left->height > root->right->height)
            return (root->left->height + 1);
    }
    else if(root && root->right)
    {
        if(root->right->height > root->left->height)
            return (root->right->height + 1);
    }
}

//returns the balance factor of a node
int BalanceFactor(node* root)
{
    if(root == NULL)
        return 0;
    else
        return(height(root->left) - height(root->right));
}

//creates a new node of the given data
node* create(int data)
{
    node *newnode = new node;
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

//inserts a node in the AVL tree
node* AVLinsertion(node* root , int data)
{
    if(root == NULL)
    {
        root = create(data);
        return root;
    }

    else if(data < root->info)
        root->left = AVLinsertion(root->left , data);

    else
        root->right = AVLinsertion(root->right , data);

    //node's height will be max of (l-height,r-height) + 1
    root->height = (max(height(root->left) , height(root->right))+1);

    //Insertion is done now conditions for rotation if needed.
    if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
        return LLrotation(root);

    if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
        return LRrotation(root);

    if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
        return RRrotation(root);

    if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
        return RLrotation(root);

    return root;
}

//return the minimum node of the tree
node* minimum_node(node *root)
{
    if(root == NULL)
        return NULL;

    if(root->left == NULL)
        return root;

    else
        minimum_node(root->left);
}

//return the maximum node of the tree
node* maximum_node(node *root)
{
    if(root == NULL)
        return NULL;

    if(root->right == NULL)
        return root;

    else
        maximum_node(root->right);
}

//deletes an element from tree
node* delete_element(node *root , int data)
{
    if(root == NULL)
        return root;

    if(data < root->info)
        root->left = delete_element(root->left , data);

    else if(data > root->info)
        root->right = delete_element(root->right , data);

    else
    {
        if(root->left != NULL && root->right != NULL)
        {
            node* temp = minimum_node(root->right);
            root->info = temp->info;
            root->right = delete_element(root->right , temp->info);
        }

        else if(root->left != NULL)
            return (root->left);

        else if(root->right != NULL)
            return(root->right);

        else                                                                     //both left and left is null
            return NULL;
    }

    if(root == NULL)
        return root;

    root->height = 1 + (max(height(root->left) , height(root->right)));

    if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == 1)
        return LLrotation(root);

    else if(BalanceFactor(root) == 2 && BalanceFactor(root->left) == -1)
        return LRrotation(root);

    else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == -1)
        return RRrotation(root);

    else if(BalanceFactor(root) == -2 && BalanceFactor(root->right) == 1)
        return RLrotation(root);

    return root;
}

//checks if the tree formed is AVL or not
int checkAVL(node* root)
{
    if(root == NULL)
        return 1;

    int left = checkAVL(root->left);
    int right = checkAVL(root->right);

    if(BalanceFactor(root) >= -1 && BalanceFactor(root) <= 1)
        return 1;

    return 0;
}

int main()
{
    node *root = NULL;
    int data,choice;
    while(1)
    {
        cout << "\n1. Insertion";
        cout << "\n2. Deletion";
        cout << "\n3. Traversal";
        cout << "\n4. Check for AVL";
        cout << "\n5. EXIT";
        cout << "\nENTER CHOICE : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                while(1)
                {
                    cout << "\nEnter element or press -1 : ";
                    cin >> data;
                    if(data == -1)
                        break;
                    else
                        root = AVLinsertion(root , data);
                }
                break;
            }
        case 2:
            {
                cout << "\nEnter element to be deleted : ";
                cin >> data;
                delete_element(root , data);
                break;
            }
        case 3:
            {
                cout << "\nPre-order traversal of the tree formed = ";
                preorder(root);

                cout << "\nIn-order traversal of the tree formed = ";
                inorder(root);

                cout << "\nPost-order traversal of the tree formed = ";
                postorder(root);
                break;
            }
        case 4:
            {
                if(checkAVL(root) == 1)
                    cout << "\nTree is AVL";
                else
                    cout << "\nTree is not AVL";
                break;
            }
        case 5:
            {
                exit(0);
                break;
            }
        default:
            cout << "\nINVALID CHOICE\n";
        }
    }
    return 0;
}

/*
    Complexity -

    Insertion : O (log n), because it takes account of Balance Factor
    Deletion : O (log n), because it takes account of Balance Factor
    Traversal : O (n)

    Output:

    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 1

    Enter element or press -1 : 12

    Enter element or press -1 : 8

    Enter element or press -1 : 20

    Enter element or press -1 : -1

    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 3

    Pre-order traversal of the tree formed = 12 8 20
    In-order traversal of the tree formed = 8 12 20
    Post-order traversal of the tree formed = 8 20 12
    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 4

    Tree is AVL
    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 2

    Enter element to be deleted : 20

    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 3

    Pre-order traversal of the tree formed = 12 8
    In-order traversal of the tree formed = 8 12
    Post-order traversal of the tree formed = 8 12
    1. Insertion
    2. Deletion
    3. Traversal
    4. Check for AVL
    5. EXIT
    ENTER CHOICE : 5

    Process returned 0 (0x0)   execution time : 30.580 s
    Press any key to continue.
*/

