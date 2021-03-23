/*
    Find Binary Trees Reverse Level Order Traversal
    Aim : To print the last level first then second last level and so on.
    Input: A Binary Tree
    Output: Last level of nodes to First Level of nodes
    Solution: We have used a deque(double-ended queue) to get the reverse level order. 
              A deque allows insertion and deletion at both the ends. 
              We first push the right subtree to the deque, then process the left subtree.
*/
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int input;
    struct Node *left;
    struct Node *right;
};
//Function to create a new Tree
Node* newNode(int value)
{
    Node* temporary = new Node;
    temporary->input = value;
    temporary->left = NULL;
    temporary->right = NULL;

    return temporary;
}
//Function to Build Tree
Node* buildTree(string st)
{
    //Corner Cases
    if(st.size() == 0 || st[0] == 'M')
    return NULL;

    vector<string> ipp;

    istringstream iss(st);
    for(string st; iss >> st; )
    ipp.push_back(st);

    //Create  root of the tree
    Node* root = newNode(stoi(ipp[0]));

    
    queue<Node*> queue;
    queue.push(root);
    
    //Start from  second element
    int i = 1;
    while(!queue.empty() && i < ipp.size())
    {

        //Get & remove front of the queue
        Node* currentNode = queue.front();
        queue.pop();

        
        string  currentValue = ipp[i];

        //If  left child is not null
        if(currentValue != "M")
        {
            //Create  left child for the current node
            currentNode->left = newNode(stoi(currentValue));

            //Push it to the queue
            queue.push(currentNode->left);

        }

        //For the right child
        i++;
        if(i >=ipp.size())
           break;
        currentValue = ipp[i];

        //If right child is not null
        if(currentValue != "N")
        {
            //Create  right child for the current node
            currentNode->right = newNode(stoi(currentValue));

            //Push it to the queue
            queue.push(currentNode->right);
        }
        i++;

    }
    return root;
}

vector<int> reverse_Level_Order(Node* root);

int main()
{
        printf("Input: \n");   
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverse_Level_Order(root);
        printf("Output: \n");
        for(int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    
    return 1;
}

//Function for reverse_Level_Order

vector<int> reverse_Level_Order(Node *root)
{
    vector<int>result;
    if(!root)
    return result;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        vector<int>temporary;
        while(n--)
        {
            Node* p = q.front();
            q.pop();
            temporary.push_back(p->input);
            if(p->left)
            q.push(p->left);
            if(p->right)
            q.push(p->right);
        }
        result.insert(result.begin(),temporary.begin(),temporary.end());
    }
    return result;
}
/* INPUT: 1 3 2
    1
   / \
  3   2
  
  OUTPUT:
    3 2 1

  INPUT:40 60 50 80 100
      40
     / \
    60 50
   / \
 80  100
 
  OUTPUT: 80 100 60 50 40

    Time Complexity: O(n)
    
    Space Complexity:O(n)
*/