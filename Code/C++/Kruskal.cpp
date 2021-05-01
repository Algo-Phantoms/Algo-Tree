/*
Kruskal’s Algorithm finds the Minimum Spanning Tree of a Graph,
by starting with one of the edges with minimum weight 
and then trying to include the next minimum-weight edge from the rest of the edges while avoiding formation of any cycles.
This process ends when we have got all N vertices of the Graph under consideration, with (N – 1) edges in the Spanning Tree.


Following is The Core Implementation of Kruskal Algorithm
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class edge
{
public:
    int start, end, weight;
};

class UnionFind
{
    int *parent, *ranks, _size;

public:
    UnionFind();

    UnionFind(int size)
    {
        parent = new int[size];
        ranks = new int[size];
        for (int key = 0; key < size; key++)
        {
            parent[key] = key, ranks[key] = 0;
        }
        _size = size;
    }
    void resize(int size)
    {
        parent = new int[size];
        ranks = new int[size];
        for (int key = 0; key < size; key++)
        {
            parent[key] = key, ranks[key] = 0;
        }
        _size = size;
    }
    int find(int key)
    {
        if (parent[key] == key)
        {
            return key;
        }
        else
        {
            // Path Compression algorithm
            return parent[key] = find(parent[key]);
        }
    }
    bool connected(int x, int y)
    {
        if (find(x) == find(y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            // Union by Rank algorithm
            if (ranks[x] > ranks[y])
            {
                parent[y] = x;
            }
            else if (ranks[x] < ranks[y])
            {
                parent[x] = y;
            }
            else
            {
                parent[x] = y;
                ranks[y]++;
            }
            _size--;
        }
    }
    void clear()
    {
        delete[] parent;
        delete[] ranks;
    }
    int size()
    {
        return _size;
    }
};
bool comparator(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}

vector<edge> kruskalsAlgorithm(vector<edge> Graph, int vertices)
{
    UnionFind uf(vertices);
    vector<edge> spanningTree;
    sort(Graph.begin(), Graph.end(), comparator);
    spanningTree.push_back(Graph[0]);
    uf.merge(Graph[0].start, Graph[0].end);
    for (int i = 1; i < Graph.size(); i++)
    {
        if (!uf.connected(Graph[i].start, Graph[i].end))
        {
            uf.merge(Graph[i].start, Graph[i].end);
            spanningTree.push_back(Graph[i]);
        }
    }
    return spanningTree;
}
int main()
{
    vector<edge> Graph;
    int e, v;
    cin >> e >> v;
    Graph.resize(e);
    for (int i = 0; i < e; i++)
    {
        cin >> Graph[i].start >> Graph[i].end >> Graph[i].weight;
    }
    vector<edge> spanningTree = kruskalsAlgorithm(Graph, v);

    cout << "Edges from Minimum Spanning Tree:\n";
    for (edge x : spanningTree)
    {
        cout << x.start << " " << x.end << " -> It's Weight is " << x.weight << endl;
    }
    return 0;
}

/*

    Test Cases:

    Input 1 : 
    14 9
    0 1 4 
    0 7 8 
    1 2 8 
    1 7 11 
    2 3 7 
    2 8 2 
    2 5 4 
    3 4 9 
    3 5 14 
    4 5 10 
    5 6 2 
    6 7 1 
    6 8 6 
    7 8 7

    Output 1 : 

    Edges from Minimum Spanning Tree:
    6 7 -> It's Weight is 1
    2 8 -> It's Weight is 2
    5 6 -> It's Weight is 2
    0 1 -> It's Weight is 4
    2 5 -> It's Weight is 4
    2 3 -> It's Weight is 7
    0 7 -> It's Weight is 8
    3 4 -> It's Weight is 9


    Input 2 :
    5 4
    0 1 10
    0 2 6
    0 3 5
    1 3 15
    2 3 4

    Output 2 :
    Edges from Minimum Spanning Tree:
    2 3 -> It's Weight is 4
    0 3 -> It's Weight is 5
    0 1 -> It's Weight is 10


    Time Complexity: O(E log V)
    Space Complexity: O(E + V)
    
*/