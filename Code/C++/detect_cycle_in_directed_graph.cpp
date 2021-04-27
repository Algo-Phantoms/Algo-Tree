/*
Detect if a cycle exists in a directed graph.
*/
/*
Terminology: 
If node A makes a dfs call to node B then node A becomes the parent node of node B.
Any edge that connects a node to its ancestor that edge is called as back edge and presence of a back edge in a graph indicates the presence of a cycle in a graph.
An edge is not considered as a back edge if it does not connect a node to an ancestor which is not it's parent.

So we just have to check whether a back edge is present in the graph.

Approaches: 
Approach 1:
1) Create a adjacency list for the given graph.
2) Initialise two boolean arrays to store whether the node is visited.
    a) Visted array to store if the node is visited.
    b) Recursive array to store if the node is visited is current dfs call.
3) If the node is already visited in the dfs traversal for current node i.e. recursive[node]==true then there exists a cycle in the graph 
4) If the node is already visited overall then it indicates that a cycle exists return true.
5) Then continue dfs calls for remaining nodes.

Approach 2:
We will make a dfs call.
And pass an extra argument that is it's parent node  and maintain a visited array.
Already visited node indicates a parent or ancestor to any node
So if the node is already visited in the visited array and is not the parent of the current node then it is an ancestor of the current node showing a back edge exists in the graph.
If the above condition is true then return true else continue with the dfs call.

The first approach is implemented below.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

//Recursive function to check if cylce exists in the directed graph
bool isCyclic(int node, vector<int> &visited, vector<int> &recursive, vector<vector<int>> &adj){

    //If the node is already visited in the current dfs call then cycle exists return true
    if(recursive[node])
        return true;

    //If the node is already visited return true
    if(visited[node])
        return false;

    //Mark true indicating the node is currently visited in the current recursive call
    recursive[node]=true;
    
    //Iterate through the adjacency list of the current node and make a dfs call
    for(auto it:adj[node])
    {
        if(isCyclic(it,visited,recursive,adj))
            return true;
    }

    //Once dfs call for a current node is completely again mark it false 
    recursive[node]=false;

    //Mark visited[node] as true indicationg dfs call for the node is done.
    visited[node]=true;

    //if cycle is not detected return false.
    return false;
}


signed main(){

    //Take input of the number of nodes in the graph.
    int vertices;
    cin>>vertices;

    //Input no of edges in the graph.
    int edges;
    cin>>edges;

    //Adjacency list of edges
    vector<vector<int>>adj(vertices+1);

    
    for(int i=0;i<edges;i++){
        //Input edges 
        int a,b;
        cin>>a>>b;

        //Push the nodes in adjacency list.
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //Initialise all the visited and recursive arrays false.
    vector<int>visited(vertices+1,0);
    vector<int>recursive(vertices+1,0);

    //flag to check if cycle is detected
    int f=0;


    for(int i=1;i<=vertices;i++){
        if(isCyclic(i,visited,recursive,adj)){
            cout<<"Cycle exists"<<endl;
            f=1;
            break;
        }
    }

    if(!f){
        cout<<"Cycle does not exist"<<endl;
    }

    return 0;
}

/*
Input:
 4
 6
 1 2
 1 3
 2 3
 3 1
 3 4
 4 4

Output:
   Cycle exists

Time Complexity : O(E+V) where E is the number of edges and v is the number of vertcies
Space Complexity : O(V) where V is the number of vertices i.e space needed to store the visited and recursive arrays.
*/