//Lowest Common Ancestor problem
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

};

TreeNode * newNode(int val)
{
    TreeNode *temp = new TreeNode;
    temp-> data = val;
    temp->left = temp->right = NULL;
    return temp;
}



map<TreeNode*, int> Level;
map<TreeNode* , TreeNode*> parent;

void check_parent_and_level(TreeNode* root, int level){
    /* This function is for finding the parent of each node and also in which level the node is present */

    if(root -> left != NULL){ /* when the left child is not NULL , 
                              store it's parent in parent Hashmap and also store it's level in Level Hashmap */
        parent[root -> left] = root;
        Level[root -> left] = level ;
        check_parent_and_level(root -> left, level + 1); /* And recursively call the function again on the root-> left 
                                                            and now the root is the root->left for that function*/
    }
    if(root -> right != NULL){/* when the right child is not NULL , 
                                store it's parent in parent Hashmap and also store it's level in Level Hashmap */
        parent[root -> right] = root;
        Level[root -> right] = level ;
        check_parent_and_level(root -> right, level + 1); /* And recursively call the function again on the root-> right 
                                                            and now the root is the root->right for that function*/
    }
}

 /*Approach 1 -> using the concept of parent and visit*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    if(root == n1 || root == n2){ /* If any of the node is the root node then answer will be the root -> data*/
        return root;
    }
    parent[root] = newNode(-1);
    Level[root] = 0;

    check_parent_and_level(root, 1); /* Calling this function to find parent and level for each node*/
        
    if(n1 == parent[n2]){ /* n1 node is parent of n2 node then answer is n1 -> data*/
        return n1;
    }

    if(n2 == parent[n1]){ /* n2 node is parent of n1 node then answer is n2 -> data*/
       
        return n2;
    }

    if(parent[n1] == parent[n2]){ /* if parent of both of the node is same , then answer is the parent -> data*/
        
        return parent[n1];
    }
        
    unordered_map<TreeNode* , int> visited; /* this is the hashmap which will tell that the node has been visited or not*/
        
    while(n1 != root){ /* move from n1 node to the root and mark all the nodes as visited in the way*/
        visited[n1] = 1;
        n1 = parent[n1];
    }
        
    while(n2 != root){ /* move from n1 node to the root and check all the nodes those are visited in the way*/
        if(visited.find(n2) != visited.end()){ /* is any of the node is visited previously, it means this node is on the way of both of the node n1 and n2 ,
                                                    so the node is the lowest common ancestor and return n2 node*/
            return n2;
        }
        visited[n2] = 1; /* else mark the node as visited*/
        n2 = parent[n2];
    }
        
        
    return root;
}

/*Approach 2 -> using the concept of parent and level*/
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if(n1 == root || n1 == root){ /* If any of the node is the root node then answer will be the root -> data*/
            return root;
        }
        parent[root] = newNode(-1);
        Level[root] = 0;
        check_parent_and_level(root, 1); /* Calling this function to find parent and level for each node*/
        
        if(Level[n1] != Level[n2]){ /* level of both of the node is not same then take them in the same level by using the parent */
           
            while(Level[n1] < Level[n2]){ /* here node2 is below node1*/
                n2 = parent[n2];
                
            }
            while(Level[n1] > Level[n2]){ /* here node1 is below node2*/
                n1 = parent[n1];
            }
        }

       if(Level[n1] == Level[n2]){ /* if level of both of the node are same*/
           if(n1 == n2){ /* if both the node is same return any of the node*/
               return n1;
           }
            if(parent[n1] == parent[n2]){ /* if parent of both the node is same return parent of any of the node*/
                return parent[n1];
            }
            while(parent[n1] != parent[n2]){ /* if parent of both the node is not same change the level and to do that change the nodes by their parent nodes*/
                n1 = parent[n1];
                n2 = parent[n2];
                if(parent[n1] == parent[n2]){ /* if parent of both the node is same return parent of any of the node*/
                    return parent[n1];
                }
            }
        }
        return root;
    }

int main() {
    TreeNode* root = newNode(3);
    root -> left = newNode(5);
    root -> right = newNode(1);
    root -> left -> left = newNode(6);
    root -> left -> right = newNode(2);
    root -> right -> left = newNode(0);
    root -> right -> right = newNode(8);
    root -> left -> right -> left = newNode(7);
    root -> left -> right -> right = newNode(4);
    /*
                        3
                     /    \
                   5        1
                  / \      / \  
                 6   2    0   8
                    / \    
                   7   4
    */

    TreeNode* node1 = newNode(1);
    TreeNode* node2 =  newNode(5);
    
    TreeNode* ans = lowestCommonAncestor(root, node1, node2);
    cout << ans -> data << endl;

    /* Answer -> 3
    */

    
    node1 = newNode(6);
    node2 = newNode(4);
    
    ans = lowestCommonAncestor(root, node1, node2);
    cout << ans -> data << endl;

    /* Answer -> 5
    */

    
    node1 = newNode(6);
    node2 = newNode(8);
    
    ans = lowestCommonAncestor(root, node1, node2);
    cout << ans -> data << endl;

    /* Answer -> 3
    */

    
    node1 = newNode(7);
    node2 = newNode(4);
    
    ans = lowestCommonAncestor(root, node1, node2);
    cout << ans -> data << endl;

    /* Answer -> 2*/
    

    return 0;
}

