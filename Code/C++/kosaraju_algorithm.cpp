/*
Kosaraju's Algorithm finds the strongly connected components in Directed Graph.

It is based on the idea that if one is able to reach a vertex v starting from vertex u,
then one should be able to reach vertex u starting from vertex v and if such is the case,
one can say that vertices u and v are strongly connected or
they are in a strongly connected sub-graph.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;


// function to apply DFS on the original graph and mark the vertices visited
// and putting the last element into the stack
void dfs1(vector<int>* edges, int start, unordered_set<int> &visited, stack<int> &finishStack) {

    // marking vertex visited
    visited.insert(start);

    // exploring all connected vertices
    for (int i = 0; i < edges[start].size(); i++) {

        int adjacent = edges[start][i];

        // if adjacent vertex is not visited
        if (visited.count(adjacent) == 0) {
            dfs1(edges, adjacent, visited, finishStack);
        }
    }

    // inserting the last element into the stack
    finishStack.push(start);
}

// function to apply DFS on the transponsed graph and mark the vertices visited
// and insert the vertices into the component
void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int> & visited) {

    // mark vertex visited
    visited.insert(start);

    // insert the vertex into component set
    component->insert(start);

    // exploring connected vertices
    for (int i = 0; i < edges[start].size(); i++) {
        int adjacent = edges[start][i];

        // if vertex is not visited
        if (visited.count(adjacent) == 0) {
            dfs2(edges, adjacent, component, visited);
        }
    }
}

// function to return all strongly connected graph
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n) {

    // stores visited vertices
    unordered_set<int> visited;

    // stores finished vertices
    stack<int> finishedVertices;

    // calling DFS on unvisited vertices and marking them visited
    for (int i = 0; i < n; i++) {
        if (visited.count(i) == 0) {
            dfs1(edges, i, visited, finishedVertices);
        }
    }

    // stores all Strongly connected components
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

    // empty the visited set
    visited.clear();

    // explore all finished vertices
    while (finishedVertices.size() != 0) {

        // top element from the finished vertices stack
        int element = finishedVertices.top();

        // delete the top element
        finishedVertices.pop();

        // if the top element is already visited
        if (visited.count(element) != 0) {
            continue;
        }

        // contains single strongly connected component
        unordered_set<int>* component = new unordered_set<int>();

        // call DFS on the top vertex and insert all the connected vertices into the component set
        dfs2(edgesT, element, component, visited);

        // insert strongly connected component into the set of all components
        output->insert(component);
    }

    // returns all strongly connected components
    return output;
}

int main() {

    // vertices range from 1 to n
    int n;
    cin >> n;

    // stores edges
    vector<int>* edges = new vector<int>[n];

    // stores transpose of edges
    vector<int>* edgesT = new vector<int>[n];

    // number of edges
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {

        // vertices which are connected
        int u, v;
        cin >> u >> v;

        // inserting edge of (u,v)
        edges[u - 1].push_back(v - 1);

        // inserting transpose i.e (v,u)
        edgesT[v - 1].push_back(u - 1);
    }


    // returns Strongly Connected Components
    auto components = getSCC(edges, edgesT, n);

    // printing the Strongly connected component elements separated by space one on a single line
    auto it = components->begin();
    while (it != components->end()) {
        auto component = *it;
        auto it2 = component->begin();
        while (it2 != component->end()) {
            cout << *it2  + 1 << " ";
            it2++;
        }
        cout << endl;
        delete component;
        it++;
    }

    delete components;
    delete [] edges;
    delete [] edgesT;
}


/*

Test Cases:

Input 1:
6
7
1 2
2 3
3 4
4 1
3 5
5 6
6 5


Output 1:
6 5
2 3 4 1

Input 2:
10
12
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
8 6
8 9
9 8
9 10

Output 2:
6 7 5
10
2 3 4 1
9 8

Time Complexity: O(V + E) – where V is the number of vertices and E is the number of edges.
Space Complexity: O(V)

*/
