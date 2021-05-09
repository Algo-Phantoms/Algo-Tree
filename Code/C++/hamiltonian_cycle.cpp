/*
Hamiltonian path in an undirected graph is a path that visits each vertex exactly once.
A Hamiltonian cycle is a Hamiltonian path such that it has an edge from the last evrtex to the last vertex.
Check if there exists a Hamiltonian cycle in the graph.
*/

/*
Backtracking algorithm
We will represent the graph as an adjacency matrix. 
Create an empty array to keep track of the cycle and add vertex 0 to it.
Add other vertices starting from vertex 1. 
Before adding any vertex check for whether it is adjacent to the previously added vertex and not already added.
If the above condition fulfills we add the vertex as a part of solution otherwise return false.
*/

#include<bits/stdc++.h>
using namespace std;
//declare the number of vertcies globally
int vertices;

//Utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian cycle constructed
bool isSafe(int v, vector<vector<int>>& graph, int path[], int pos){

    //if an edge does not exists between the two vertcies return false
    if(graph[path[pos-1]][v] == 0){
        return false;
    }

    //Check if the vertex already exists in the Hamiltonian cycle costructed 
    for(int i = 0 ; i < pos; i++){
        //if it exists it cannot be included again so return false
        if(path[i] == v)
            return false;
    }
    return true;
}

/*Recursive utilty function to find the hamiltonian cycle*/
bool hamiltonianCycle(vector<vector<int>>& graph, int path[], int pos){
    if(pos == vertices){
        //if we have reached the last vertex and there exists an edge between the last vertex and the starting vertex then return true
        if(graph[path[pos-1]][path[0]] == 1)
            return true;
        //if the edge does not exists return false
        else
            return false;
    }

    
    for(int v = 1 ; v < vertices ; v++){
        //Check if it is safe to puth vertex v at position pos in the Hamiltonian cycle
        if(isSafe(v, graph, path, pos)){
            path[pos] = v;
            
            //recur to construct rest of the path
            if(hamiltonianCycle(graph, path, pos+1) == true)
                return true;

            //if adding vertex does not lead to a solution then remove it i.e initialise path[pos]=-1
            path[pos] = -1;
        }
    }

    //If no vertex can be added to the Hamiltonian cycle constructed so far return false.
    return false;
}


int main(){
    
    //Input number of vertices
    cin>>vertices;

    //Input number of edges
    int edges;
    cin>>edges;

    vector<vector<int>> graph( vertices , vector<int> (vertices, 0));

    //Take input of the edges
    for( int i = 0 ; i < edges ; i++ ){
        int u , v;
        cin >> u >> v;
        //Store the edges in adjacency matrix
        graph[u][v]=1;
        graph[v][u]=1;
    }

    /*Initialise the path array with -1*/
    int *path = new int[vertices];

    for(int i = 0 ; i < vertices ; i++)
    path[i] = -1;

    /*put vertex 0 as the first vertex in the path
    If the Hamiltonian cycle exists then the path can be started from any point*/
    path[0] = 0;

    if(hamiltonianCycle( graph , path , 1 ) == false){
        cout<<"Hamiltonian cycle does not exists."<<endl;
    }
    else{
        cout<<"One of the Hamiltonian cycles is : ";

        //print the vertices of hamiltonian path
        for( int i = 0 ; i < vertices ; i++ )
        cout<<path[i]<<" ";

        //again print the the starting vertex to show a cycle
        cout<<path[0]<<endl;
    }

    return 0;
}

/*
Input : 
    6
    6
    0 1
    1 2
    2 3
    3 4
    4 5
    5 0

Output: 
    One of the Hamiltonian cycles is : 0 1 2 3 4 5 0

Input:
    5
    5
    0 1
    1 2
    0 3
    3 4
    0 4

Output:
    Hamiltonian cycle does not exists.

Time Complexity: O(N!) where N is the numebr of vertices
*/