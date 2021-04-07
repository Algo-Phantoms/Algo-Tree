/*

 * DAG--> Directed Acyclic Graph
 * We will be given a Weighted Directed Acyclic Graph (DAG) and a source vertex 's' in it,
 * we have to find the longest distances from 's' to all other vertices in the given graph.

 * Concept Required--
   1) Topological Sort
   2) Graph will be Directed 


*/
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define mod             1000000007
using namespace std;
 

vector<int> order;  // for maintaining order vector


// Implementing Topological Sort

void topo(int src,vector<int> &vis,vector<vector<pair<int,int> > > g){
    vis[src] = 1;
    for(auto x:g[src]){
        if(!vis[x.first])
            topo(x.first,vis,g);
    }
    order.push_back(src);  // adding vertex to order vector when a particular vertex is leaving its stack frame
}


int32_t main() {
    
    int v,e;
    cin>>v>>e;   // Input vertex and edges

    int src;
    cin>>src;

    // input of a graph as a adjency list
    vector<vector<pair<int,int> > > g(v);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    
    vector<int> vis(v,0); // maintaning a visited array
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topo(i,vis,g);                    
        }                                  
    }
    vector<int> dist(v);  // distance vector containing maximum distance from source vertex to ith vertex
    for(int i=0;i<v;i++) dist[i] = INT_MIN;
    dist[src] = 0;
    for(int i=v-1;i>=0;i--){
        if(dist[order[i]]!=INT_MIN){
            for(auto x:g[order[i]]){
                int v = dist[x.first];
                int w = x.second;
                int u = dist[order[i]];
                if(u + w > v)
                    dist[x.first] = u + w;
            }
        }
    }

    // printing all the maximum distance

    for(int i=0;i<v;i++){
        if(i!=src and dist[i]!=INT_MIN){
            cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
        }
    }
    
    return 0;

}

/*

Test Cases--

Input 1:

6 7
1
0 1 5
1 5 5
5 3 2
3 2 20
4 2 10
5 2 50
1 4 2

Output 1:

1 -> 2 = 55
1 -> 3 = 7
1 -> 4 = 2
1 -> 5 = 5


Input 2:

7 8
0
0 1 1
1 2 5
2 6 10
2 5 12
2 3 4
3 5 20
3 4 15
4 6 2

Output 2:

0 -> 1 = 1
0 -> 2 = 6
0 -> 3 = 10
0 -> 4 = 25
0 -> 5 = 30
0 -> 6 = 27


Time Complexity-- O(V+E), where V = No. of Vertex and E = No. of Edges

Space Complexity-- O(V), where V = No. of vertex, (assuming input graph is given)

*/