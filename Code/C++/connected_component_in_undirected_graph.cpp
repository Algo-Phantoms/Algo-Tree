/*
Find the connected component in a undirected graph and the all the component with there respective vertices

Approach:

*   First take take vertices and edges in input.

*   I have taken vector list for graph repsentation. You can also take structure or 2d array for storing the values.

*   Populate the List the the edges, it is undirected graph so we have to insert edge(v,u) and edge(u,v).

*   Create 2 vectors, first for indicating the vertices is visited or not and second for find the component 
    where the vertex belong in my case( first vector which is visited, second vector a ).

*   Iterate over the vertices and check if the node is visited if not visited then call dfs and 
    iterate over the nodes connected to this vertex and update the visited and component vectors in dfs funtion.

*   After iterating over the vertices iterate over the component vector and update the vertices to there respective component in a map which is (mp->unordered_map).

*   Now simply print the component with there respective nodes.

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>graph_list[],vector<bool>&visited,int cnt,int node,vector<int>&components)
{
    visited[node]=true;
    components[node]=cnt;
    for(int curnode:graph_list[node])
    {
        if(!visited[curnode])
        {
            dfs(graph_list,visited,cnt,curnode,components);
        }
    }
    return ;
}


int main()
{
    int vertices,edges;
    //take the input vertices and edges
    cin>>vertices>>edges;

    vector<int>graph_list[vertices];

    //populate the graph in grap_list
    while (edges--)
    {
        int v,u;
        cin>>v>>u;
        graph_list[v].push_back(u);
        graph_list[u].push_back(v);    
    }

    //vector  for check the node is visited or not and for finding the component
    vector<bool>visited(vertices,false);
    vector<int>a(vertices,0);
    int cnt=0;

    //iterate over the vertices and find all the connected nodes and update them
    for(int start=0;start<vertices;start++)
    {
        if(!visited[start])
        {
            //call to dfs function
            dfs( graph_list ,visited,cnt,start,a);
            cnt++;
        }
    }

    unordered_map<int,vector<int>>mp;
    
    //pushing the node or vertex to there respective component in map
    for(int start=0;start<vertices;start++)
    {
        mp[a[start]].push_back(start);
    }

    //printing the component with there respective nodes
    for(int start=0;start<cnt;start++)
    {
        cout<<"Component :"<<start<<" and nodes are : ";
        for(int num: mp[start] )
        {
            cout<<num<<"->";
        }
        cout<<"\b\b  \n";
    }

     return 0;
}

/*
    Test Cases:
    
    Input 1:
    5 3
    1 0
    2 3
    3 4

    Output 1:
    Component :0 and nodes are : 0->1  
    Component :1 and nodes are : 2->3->4  

    Input 2:
    5 5
    0 1
    1 2
    2 0
    3 4
    4 3

    Output 2:
    Component :0 and nodes are : 0->1->2  
    Component :1 and nodes are : 3->4 
     

    Time Complexity  :    O(V+E)
    Space Complexity :    with graph O(V^2) exculding the graph O(V) 
*/