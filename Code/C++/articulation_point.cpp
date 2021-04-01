/*
    This Algorithm is to find all Articulation Point in the given undirected graph.
    An Articulation Point is defined as an as a vertex whose removal of self and related edge makes a graph disconnected or increase number of connected components in graph.

    Implementation:
    1. vector<vector<int>> graph is adjacency list representation of graph.
    2. vector<pair<int,int>> bridges store all the bridges in graph.
    3. vector time_entry denote entry time for each vertex "v" in graph.
    4. vector lowest_time is the minimum of time_entry[v] for each vertex "v" in graph.

    Algorithm:
      In a graph, Articulation Points can be found by performing DFS(Depth-First Search).
      Looking through the edges starting from vertex 'v'. V is an Articulation Point if the current edge (v,next_node) is such that none of the vertices next_node or its descendants in the DFS traversal tree has a back-edge to any of its ancestors.


*/

#include<bits/stdc++.h>
using namespace std;


vector< vector<int> > graph;
vector<int> articulation_points;
vector<bool> visited;
vector<int> time_entry, lowest_time;
int timer;

void dfs(int v, int parent = -1)
{
	visited[v] = true;
	time_entry[v] = lowest_time[v] = timer++;
    int children=0;
	for (int u = 0; u < graph[v].size(); u++)
	{
		int next_node = graph[v][u];
		if (next_node == parent)
			continue;

		if (visited[next_node])
		{
			lowest_time[v] = min(lowest_time[v], time_entry[next_node]);
		}
		else
		{
			dfs(next_node, v);
			lowest_time[v] = min(lowest_time[v], lowest_time[next_node]);

			if (lowest_time[next_node] > time_entry[v] && parent!=-1)
				articulation_points.push_back(v);
            ++children;
		}
	}
	if(parent==-1 && children>1)
        articulation_points.push_back(v);
}


int main()
{
	//    Input number of nodes ie "V" and number of edges "E" in graph
	int V, E;
	cin >> V >> E;
	graph.resize(V);
	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    //    Initializing variables and vectors.
	timer = 0;
	visited.resize(V, false);
	time_entry.resize(V, -1);
	lowest_time.assign(V, -1);

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
			dfs(i);
	}

	//    cout << "Articulation Points in given Graph:" << "\n";
	for (int i = 0; i < articulation_points.size(); i++)
	{
		cout << articulation_points[i]<< "\n";
	}

}

/*
    Test Case 1:
        Input:
            5 5
            1 0
            0 2
            2 1
            0 3
            3 4

        Output:
            3
            0



    Test Case 2:
        Input:
            4 3
            0 1
            1 2
            2 3

        Output:
            2
            1


Time Complexity: O(V+E) where V is the number of Vertex and E is the number of Edges.
Space Complexity: O(V+E) where V is the number of Vertex and E is the number of Edges.


*/
