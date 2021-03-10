#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    int info;
    int ltag;
    int rtag;
    struct treenode *left;
    struct treenode *right;
};

struct treenode* insertion(struct treenode *root, int data)
{
    treenode *ptr = root;
    treenode *par = NULL;
    while (ptr != NULL)
    {
        par = ptr;

        if (data < ptr->info)
        {
            if (ptr -> ltag == 0)
                ptr = ptr -> left;
            else
                break;
        }
        else
        {
            if (ptr->rtag == 0)
                ptr = ptr -> right;
            else
                break;
        }
    }

    //creating a new node
    struct treenode *newnode = new treenode;
    newnode->info = data;
    newnode->ltag = 1;
    newnode->rtag = 1;

    if(par == NULL)
    {
        root = newnode;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    else if(data < par->info)
    {
        newnode->left = par->left;
        newnode->right = par;
        par->ltag = 0;
        par->left = newnode;
    }
    else
    {
        newnode->left = par;
        newnode->right = par->right;
        par->rtag = 0;
        par->right = newnode;
    }

    return root;
}

struct treenode *inorderSuccessor(struct treenode *root)
{
    if(root->rtag == 1)
        return root->right;

    root = root->right;

    while(root->ltag == 0)
        root = root->left;
    return root;
}

void inorder(struct treenode *root)
{
    struct treenode *temp = root;

    if (root == NULL)
        cout<<"Tree is empty";

    while(temp->ltag == NULL)
        temp = temp->left;

    while(temp != NULL)
    {
        cout<<temp->info<<"  ";
        temp = inorderSuccessor(temp);
    }
}


int main()
{
    int data,choice;
    struct treenode *root = NULL;

    while(1)
    {
        cout<<"\n1. Create tree"<<endl;
        cout<<"2. In-order traversal"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                while(1)
                {
                    cout<<"Enter element or press -1 : ";
                    cin>>data;
                    if(data == -1)
                        break;
                    else
                        root = insertion(root , data);
                }
                break;
            }


        case 2:
            cout<<"\nIn-order traversal is : ";
            inorder(root);
            break;

        case 3:
            exit(0);
            break;

        default :
            cout<<"\nINVALID CHOICE"<<endl;
        }
    }
    return 0;
}

/*Sample Input/Output of the Program :

1. Create tree
2. In-order traversal
3. EXIT
Enter your choice : 1
Enter element or press -1 : 10
Enter element or press -1 : 20
Enter element or press -1 : 30
Enter element or press -1 : 40
Enter element or press -1 : 50
Enter element or press -1 : -1

1. Create tree
2. In-order traversal
3. EXIT
Enter your choice : 2

In-order traversal is : 10  20  30  40  50
1. Create tree
2. In-order traversal
3. EXIT
Enter your choice : 3

Process returned 0 (0x0)   execution time : 15.427 s
Press any key to continue.

*/


