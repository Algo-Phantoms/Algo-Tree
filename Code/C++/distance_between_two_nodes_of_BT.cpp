/*distance between two nodes of a binary tree
 the distance between two nodes is the minimum number of edges to be traversed to reach one node from another
ALGORITHM
1.find the LCA(lowest common ancestor)
2.find the distance of n1(d1) & n2(d2) from LCA
3.return (d1 + d2)
*/

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

};
 
//finding the lowest common ancestor.
Node* LCA(Node* root, int n1,int n2){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);

    if(left!= nullptr && right != nullptr){
        return root;
    }

    if(left == nullptr && right == nullptr){
        return nullptr;
    }

    if(left != nullptr){
        return LCA(root->left,n1,n2);
    }

    return LCA(root->right,n1,n2);
}

//finding the distance between two nodes
int finddistance(Node* root, int k, int dist){
    if(root == nullptr){
        return -1;
    }

    if(root->data == k){
        return dist;
    }

    int left=finddistance(root->left,k,dist+1);
    if(left != -1){
        return left;
    }

    return finddistance(root->right,k,dist+1);
}

//calculating final distance between two nodes
int distance(Node* root, int n1, int n2){
    Node* lca = LCA(root,n1,n2);

    int d1 = finddistance(lca,n1,0);
    int d2 = finddistance(lca,n2,0);

    return d1+d2;
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

   int i,j;
    cin>>i>>j;
   cout<<distance(root,i,j)<<endl;  
   
     return 0;
}
  
/*
    TEST CASE1:
    INPUT: i=4 ,j=5 
    OUTPUT: 4.
 
    TEST CASE 2: 
    INPUT: i=3 ,j=5 
    OUTPUT:1.
  


    TIME COMPLEXITY:O(h) where h is the height of tree 
    SPACE COMPLEXITY:O(1)
*/
