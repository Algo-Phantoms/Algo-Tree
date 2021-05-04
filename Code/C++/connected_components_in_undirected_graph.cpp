/*
Find the connected components in a undirected graph.
*/

/*
Algorithm:
1) First initialize all the vertices as not visited with a boolean array.
2) For every vertex if it is not visited perform a DFS call.
    a) If vertex v is not visited call DFS function

*** DFS fucntion *** 
1) Mark the node as visited.
2) Push the node in componenet vector which stores the nodes in current DFS node
3) Iterate through the adjacency list of the node and make a dfs call for every node if its not visited.
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005

//globally declare avariables so there will no need to pass them in every dfs call exclusively

//stores the no of vertcies in the graph
int n;

//Adjacency list of graph.
vector<int> adjacent[MAXN];

//boolean array to check if the node is visited.
bool visited[MAXN];

//vector to store nodes in the current dfs call i.e node in a component.
vector<int> component;

/*
DFS Utility funciton
*/
void dfs(int node){

    //mark the node as visited
    visited[node] = true;

    //push the node in component vector
    component.push_back(node);

    //iterate through the adjacency list of node
    for(auto it : adjacent[node]){

        //if the node is not visited then recursively call the dfs function
        if(visited[it] == false){
            dfs(it);
        }
    }

}

int main(){

    //Input of the number of nodes in the graph.
    int vertices;
    cin>>vertices;

    //Input no of edges in the graph.
    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++){
        //Input edges 
        int a,b;
        cin>>a>>b;

        //Push the nodes in adjacency list.
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    //variable to count the no of cycles
    int count = 0;

    cout<<"Components : "<<endl;

    for(int i=1;i<=vertices;i++){

        //If the node is not visited make a dfs call
        if(visited[i] == false){

            //Empty the component vector to store the nodes of current component
            component.clear();

            //increment the count of connected components
            count++;

            dfs(i);

            //Print the nodes in the current connected component
            for(int j=0;j<component.size();j++)
                cout<<component[j]<<" ";

            cout<<endl;
        }
    }

    cout<<"No. of components in the graph : "<< count << endl;
}

/*
Test Case : 
Input : 
    8
    5
    1 2
    2 3
    3 4
    5 6
    7 8

Output : 
    Components : 
    1 2 3 4 
    5 6 
    7 8 
    No. of components in the graph : 3


Time Complexity : O(N + E) where N is the number of nodes and E is the number of edges
*/