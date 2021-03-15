/*
    Find the Top view of Binary Tree

        Explaination:- Top view of binary tree is a set of vertices that appears when the tree is viewed from top.
            for solving this problem we have to traverse the tree vertically. It means that we put nodes of same horizontal 
            distance together.


                eg:-         1                
                            / \
                           2   3     -> Top view of tree =  [4,2,1,3,7]                   
                          / \  /\
                         4  5  6 7


            We do the level order traversal so that the topmost node at a horizontal node is visited before any 
            other node of same horizontal distance below it.For achieving horizontal distance we maintain a HashMap and check 
            if a node at particular horizontal distance is seen or not. 


                    Horizontal distance for given example:-

                             -2 -1 0 1 2
                              |  | | | |
                                   1
                                  / \
                                 2   3
                                / \  / \
                               4  5  6  7


*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


vector<int>TopView(struct Node *root)
{
    vector<int>ans;
    queue<pair<Node *,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty())
    {
        int x = q.size();
        for(int i = 0;i<x;i++)
        {
            auto node = q.front();
            q.pop();
            
            auto cur = node.first;
            int d = node.second;

            // If current node seen before at particular horizontal distance so that 
            // current node is not the part of the Top view of binary tree.
            if(mp.count(d)==false)
            {
                
                mp[d] = cur->data;
            }
            
            if(cur->left)
            {
                q.push({cur->left,d-1});
            }
            if(cur->right)
            {
                q.push({cur->right,d+1});
            }
        }
    }
    for(auto x:mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    Node *root = NULL;
    queue<Node*>q;

    int i = n;
    while(i>0)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;

        if(!root)
        {
            root = new Node(a);
            q.push(root);
        }
        Node *pick = q.front();
        q.pop();
        if(c=='L')
        {   
            pick->left = new Node(b);
            q.push(pick->left);
        }
        cin>>a>>b>>c;

        if(c=='R')
        {
            pick->right = new Node(b);
            q.push(pick->right);
        }
        i-=2;
    }



    vector<int> ans = TopView(root);

    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}





// Time complexity for solving this problem is O(NlogN)
// where N is the number of nodes in the given binary tree with each insertion operation 
// in Map requiring O(log2n) complexity.

