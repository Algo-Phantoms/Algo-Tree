/*

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph.

It is applicable for:

* Both directed and undirected graphs
* All edges must have None-Negative weights
* Graph must be connected

*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef pair<int, int> pii;

// Graph -> Vector - Pair
vii *Graph;

// It Stores the Distance of every other node from start.
vi Distance;

void Dijkstra(int start, int N)
{
    // min heap
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    Distance.assign(N, INF);
    Distance[start] = 0;
    Q.push({0, start});
    while (!Q.empty())
    {
        int v1 = Q.top().second;
        Q.pop();
        for (auto &c : Graph[v1])
        {
            int v2 = c.first;
            int weight = c.second;
            if (Distance[v2] > Distance[v1] + weight)
            {
                Distance[v2] = Distance[v1] + weight;
                Q.push({Distance[v2], v2});
            }
        }
    }
}

int main()
{
    // N - total no of nodes, M - no. of edges
    // v1, v2 and weight are the end vertices and the weight associated with an edge
    // start is the sStarting Point from where we have to find Shortest Path
    int N, M, v1, v2, weight, start;
    cin >> N >> M;
    Graph = new vii[N + 1];

    for (int i = 0; i < M; ++i)
    {
        cin >> v1 >> v2 >> weight;
        Graph[v1].push_back({v2, weight});
        Graph[v2].push_back({v1, weight});
    }
    cin >> start;
    Dijkstra(start, N);

    for (int i = 0; i < N; i++)
        cout << "Distance From " << start << " to Node " << i << " is " << Distance[i] << " " << endl;
    cout << endl;

    return 0;
}

/*
Test Cases:

Input 1 :
5
5
0 1 17
0 2 2
0 3 9
0 4 24
0 5 28
1

Output 1 :
Distance From 1 to Node 0 is 17 
Distance From 1 to Node 1 is 0 
Distance From 1 to Node 2 is 19 
Distance From 1 to Node 3 is 26 
Distance From 1 to Node 4 is 41 


Input 2 :
4
4
0 1 11
0 2 2
0 3 31
0 4 24
0 5 28
1

Output 2 :
Distance From 0 to Node 0 is 0
Distance From 0 to Node 1 is 11
Distance From 0 to Node 2 is 2
Distance From 0 to Node 3 is 31 

Time complexity : O(ElogV) where E is no. of Edges and V are no. of Vertices

Space Complexity: O(V^2)
*/