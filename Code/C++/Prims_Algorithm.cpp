/*

Prim's (also known as Jarník's) algorithm is a greedy algorithm
that finds a minimum spanning tree for a weighted undirected graph.
This means it finds a subset of the edges that forms a tree that includes every vertex,
where the total weight of all the edges in the tree is minimized. 
The algorithm operates by building this tree one vertex at a time, from an arbitrary starting vertex,
at each step adding the cheapest possible connection from the tree to another vertex.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector<PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> G;
    int y;
    long long minimumCost = 0;
    PII p;
    G.push(make_pair(0, x));
    while (!G.empty())
    {
        // Select the edge with minimum weight
        p = G.top();
        G.pop();
        x = p.second;
        // Checking for cycle
        if (marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for (int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if (marked[y] == false)
                G.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}

/*
Time Complexity: O((V + E)logV) - V = Vertices & E = Edges


Test cases :

Input 1 : 
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Output 1 : 
19

Input 2 : 
5 7
1 4 5
1 5 3
3 2 6
2 4 5
4 5 6
3 4 2
4 6 2

Output 2 : 
17

*/