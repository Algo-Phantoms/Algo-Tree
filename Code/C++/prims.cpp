/*
Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

 -> The idea is to start with an  empty spanning tree
 -> Maintain two sets of vertices. The first set contains the vertices already included in the MST, the other set     contains the vertices not yet included
 -> At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges
 -> After picking the edge, it moves the other endpoint of the edge to the set containing MST.


Following is the C++ implementation of the PRIMS ALGORITHM

*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;


/*The minKey function to find the vertex with
 minimum key value, from the set of vertices
 not yet included in MST
*/
int mininmumKey(int key[], bool mstSet[],int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMinimumSpanningTree(int parent[], vector<vector<int>> graph)
{
  int V=graph.size();
	cout<<"Prims Minimum Spanning Tree \n";
	for (int i = 1; i < V; i++){
    cout<<"Edge "<<parent[i]<<" - "<<i<<" \t "<<"It's weight is "<<graph[i][parent[i]]<<" \n";
  }
}

/* Function to construct and print Minimum Spanning Tree for a graph represented using adjacency
 matrix representation
*/
void primsAlgorithm(vector<vector<int>> graph)
{
	// Array to store constructed MST
  // V - Number of Vertices
  int V=graph.size();
	int parent[V];

	// Key values used to pick minimum weight edge in cut
	int key[V];

	// To represent set of vertices included in Minimum spanning tree
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in minimum spanning tree.
	// Make key 0 so that this vertex is picked as first vertex.
  // Starting to construct the MST from vertex 0
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = mininmumKey(key, mstSet,V);

		// Add the picked vertex u to the MST Set (u included in MST)
		mstSet[u] = true;

		// Update key value and parent index of the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed Minimum spanning tree from Prims Algorithm
	printMinimumSpanningTree(parent, graph);
}


int main()
{

  // Taking the number of vectrices and edges as input
  int v,e;
  cout<<"Enter the number of vertices : ";
  cin>>v;
  cout<<"Enter the number of Edges : ";
  cin>>e;


  // 2D matrix using vectors
  vector<vector<int>> graph;
  vector<int> vec(v,0);
  graph.resize(v);
  for(int i=0;i<v;i++){
   graph[i]=vec;
  }

  cout<<"Enter the Edges : "<<endl;
  // Adding the weight W to corresponding edge from A -> B
  for(int i=0;i<e;i++){
    int start;
    int end;
    int weight;
    cin>>start>>end>>weight;
    graph[start][end]=weight;
    graph[end][start]=weight;
  }

  // PRIMS algorithm function
	primsAlgorithm(graph);

	return 0;
}


/*

Test Cases:

Input 1 :

6 8
0 1 4
0 2 4
1 2 2
2 3 3
2 4 4
2 5 2
3 4 3
4 5 3

Output 1:

Prims Minimum Spanning Tree
Edge 0 - 1       It's weight is 4
Edge 1 - 2       It's weight is 2
Edge 2 - 3       It's weight is 3
Edge 5 - 4       It's weight is 3
Edge 2 - 5       It's weight is 2

Time Complexity of the above program is O(V^2).
Space Complexity of the above program is O(V).

*/
