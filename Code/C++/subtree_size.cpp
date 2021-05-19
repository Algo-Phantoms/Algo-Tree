/* PROBLEM DESCRIPTION

    Given a tree of size v nodes 
    we have to find subtree size of each node of the given tree
        ,i.e,number of nodes present in the subtree of each nodes of the tree

    NOTE : the root node is given 
        (its compulsory to define the root node because for different root nodes ,we will have different subtrees)


     ALGORITHM

    1.We use DFS (depth first search ) approach to solve this problem
    2.using DFS ,we traverse each nodes and return the number of subnodes of each node.
    3.for each node v, initialize the num variable to 1 and mark it as visited
    4.Now, loop through all the connected nodes .
    5.Inside the loop, update num each time with the value returned by calling the dfs function
    of each connected nodes of that node .
    6.after coming out of the loop,update the vth index of the subtree_totalNodes with num.
       This will give the value of subtree size.
    7.finally return the num value.

*/


//SOURCE CODE

#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5;           //assume the maximum size of the tree does not exceeds 1e5

vector<int> adj[N];         // adjacency list to store all the nodes of the tree
int visited[N];             //to keep track of visited nodes
int subtree_totalNodes[N];  //stores subtree size of each nodes of the tree

//depth first search function to find the subtree size of each node of the  tree
int dfs(int v) {
    visited[v] = 1;
    int num = 1;  //for each node initialize the number of nodes with 1
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            num += dfs(*i);     //dfs call for all connected nodes
        }
    }
    subtree_totalNodes[v] = num;  //update subtree size of node v with num
    return num;
}

int main() {
    int v;
    cin >> v;  //read number of nodes in the tree
    int x, y;

    //take user input for the node of the tree
    for (int i = 0; i < v - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //read the root of the tree
    int root;
    cin >> root;  // subtrees size will be calculated on the basis of the root given by the user

    //call dfs for root node
    dfs(root);

    //print the total number of subtree nodes of each node of the tree with the given root
    for (int i = 0; i < v; i++) {
        cout << "node :" << i << "  subtree_nodes : " << subtree_totalNodes[i] << "\n";
    }
    return 0;
}



/*USER'S INPUT AND OUTPUT

SAMPLE INPUT OUTPUT 1

                0
            /   |   \
          1     2    3
       /  |  \
      4   5   6
     / \      /
    7   8    9

    10
    0 1
    0 2
    0 3
    1 4
    1 5
    4 7
    4 8
    2 6
    6 9
    0
    node : 0 subtree_nodes : 10
    node : 1 subtree_nodes : 5
    node : 2 subtree_nodes : 3
    node : 3 subtree_nodes : 1
    node : 4 subtree_nodes : 3
    node : 5 subtree_nodes : 1
    node : 6 subtree_nodes : 2
    node : 7 subtree_nodes : 1
    node : 8 subtree_nodes : 1
    node : 9 subtree_nodes : 1


    SAMPLE INPUT OUTPUT 2

                0
            /    |   \   \
            1     2     3  4
        / | \   / |
    5   6  7  8  9


    10 
    0 1 
    0 2 
    0 3 
    0 4 
    1 5 
    1 6 
    1 7 
    2 8 
    3 9 
    0 
    node : 0 subtree_nodes : 10 
    node : 1 subtree_nodes : 4 
    node : 2 subtree_nodes : 2 
    node : 3 subtree_nodes : 2 
    node : 4 subtree_nodes : 1 
    node : 5 subtree_nodes : 1 
    node : 6 subtree_nodes : 1 
    node : 7 subtree_nodes : 1 
    node : 8 subtree_nodes : 1 
    node : 9 subtree_nodes : 1

   
    TIME COMPLEXITY :  O(n)  (in order to calculate n-1 edges) 
    SPACE COMPLEXITY : O(n) (to keep track of visited nodes and array to store subtree size)
   
*/