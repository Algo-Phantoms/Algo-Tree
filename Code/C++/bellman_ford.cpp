/* 
# Bellman Ford's Algorithm:
Bellman Ford algorithm helps us find the shortest path from a vertex(root) to all other vertices of a weighted 
graph. It can be implemented using DP. It uses principal of relaxation Which states that assume the same result 
(infinity here) for all the elements (nodes here) from the root node beforehand and then tweak these values 
according to a certain condition.
Similarly, in Bellman ford's algorithm loop runs for (|v|-1) times and each iteration tweaks the distance value
according to the below condition:

if ( assumed distance of  node a+distance between node a and another node b connected by an edge < assumed distance of node b)
{
    updated distance of b =  assumed distance of  node a + distance between node a and another node b  connected by an edge
}
It is similar to Dijkstra's algorithm but it can work with graphs with negative weights.

# Time Complexity:
It is O(e*(v-1)) where v and e represents no. of vertices and edges respectively.
- For completed graph:
no. of edges = v(v-1)/2
because in connected graph, each vertex is connected with every other node.
So. time complexity will be (v(v-1)/2)v which is equivalent to O(v^3)
- For Graph incomplete graphs:
no. of edges = v
So. time complexity will be v(v-1) which is equivalent to O(v^2)
- Worst Time Complexity: O(v^3).

# Space Complexity:
It is O(v+e) and O(v^2) when using adjacency list and adjancency matrix respectively.

# Advantage Of Bellman Ford Algorithm:
- It can calculate the shortest path in the graphs having negative weight edges whereas Dijkstra can't.
- A very important application of Bellman Ford is to check if there is a negative cycle in the graph.

# Drawbacks of Bellman Ford Algorithm:
If a graph contains a cycle whose all edges sum is negative then Bellman Form Algorithm will give the
wrong result because that cycle will reduce the total path distance by coming back to the same point.
That's why Algo will keep on changing the distance values even after (|v|-1)th relaxation cycle .

# why would one even have edges with negative weights in real life?
Negative weight edges might seem useless at first but they can explain a lot of phenomena like 
cashflow, heat released/absorbed in a chemical reaction etc.
For instance, if there are different ways to reach from one chemical A to another chemical B, each method will have sub-reactions involving both heat dissipation and absorption.

Implementation:
*/

#include<bits/stdc++.h>
using namespace std;
const int EDGES = 2e5;
const int NODES = 1e5;
const int MAX = 1e9;
vector<int> v[EDGES];
int dis[NODES];
int main(){
for(int i = 0; i < NODES; i++){
    dis[i] = MAX;
}
for(int i = 0; i < EDGES; i++){
    v[i].clear();
}
int nodes, edges, start_node, end_node, dist;
cin >> nodes >> edges;
for(int i = 0; i < edges; i++){
    cin >> start_node >> end_node >> dist;
    v[i].push_back(start_node);
    v[i].push_back(end_node);
    v[i].push_back(dist);
}
dis[1] = 0; //Assuming the source node is 1.
for(int i = 0; i < nodes-1; i++){
    int j = 0;
    while(v[j].size() != 0){
        if(dis[v[j][0]]+v[j][2]<dis[v[j][1]]){
            dis[v[j][1]] = dis[v[j][0]]+v[j][2];
        }
        j++;
    }
}
for(int i = 1; i <= nodes; i++){
    cout<< dis[i] << "\n";
}
return 0;
}

/*
Test Case:
    Input:
        5 5
        1 2 5
        1 3 2
        3 4 1
        1 4 6
        3 5 5

    Output: 
        5 2 3 7
*/