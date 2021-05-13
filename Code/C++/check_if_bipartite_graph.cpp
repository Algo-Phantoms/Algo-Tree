/*
Check if a graph is bipartite graph.

A Bipartite graph is a graph whose vertcies can be divided into independent sets such that for every edge(u,v) u and v belong to different set i.e all edges should be from one set to another.Itis possible if the graph coloring is possible using two colors such that vertices in a set are colored with same color.
*/

/*
We are trying to split the graph into two groups of edges.
So we color the edges, 1 = red, -1 = blue, 0 = not colored yet.

We will do BFS traversal on graph .
*/

#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<int>adjacent[], int n){
    // vector to store the color of every node
    vector<int>colors(n,0);

    //queue to perform bfs traversal
    queue<int>q;


    for( int i = 0 ; i < n ; i++ ){
        //if the node is already colored continue
        if(colors[i])
        continue;

        //color the node 
        colors[i]=1;
        //push the node in queue for bfs traversal
        q.push(i);

        while(!q.empty()){
            int temp = q.front();
            for( int j = 0 ; j < adjacent[temp].size() ; j++ ){

                //color neighbour with opposite color
                if(colors[adjacent[temp][j]] == 0){
                    colors[adjacent[temp][j]] = -colors[temp];
                    q.push(adjacent[temp][j]);
                }
                //If the neighbour has the same color return false i.e graph can't be bipartite graph
                else if(colors[adjacent[temp][j]] == colors[temp]){
                    return false;
                }
            }
            q.pop();
        }
    }
    return true;
}

int main(){
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;

    vector<int>adjacent[vertices+1];

    for(int i = 0 ; i < edges ; i++ ){
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    if(checkBipartite(adjacent, vertices))
    cout<<"The graph is Bipartite"<<endl;
    else
    cout<<"The graph is not Bipartite"<<endl; 

    return 0;
}

/*

TestCase:
    Input : 
        4
        4
        0 1
        1 2
        2 3
        0 3
    Output: 
        The graph is Bipartite

    Input
        5
        5
        0 1
        1 2
        2 3
        3 4
        4 0
    Output:
        The graph is not Bipartite

Time Complexity : O(V + E)  
Space Complexity : O(V)     where V is the number of vertices and E is the no of edges

*/