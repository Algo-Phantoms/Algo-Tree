/*
The DFS algorithm starts at a vertex u in the graph. By starting at vertex u it considers the edges
from u to other vertices. If the edge leads to an already visited vertex, then backtrack to current vertex u.
If an edge leads to an unvisited vertex, then go to that vertex and start processing from that vertex. 
That means the new vertex becomes the current vertex. Follow this process until we reach the dead-end. 
*/

#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

template<typename T>				// for generic

class Graph{

	map<T, list<T> > m;
public:
	void AddEdge(T src, T dest, bool nondirectional = true){

		m[src].push_back(dest);
		if(nondirectional){				// bi-directional
			m[dest].push_back(src);
		}
	}

	void print(){
		for(auto i : m){
			cout << i.first<<" -> ";
			for(auto j: i.second){
				cout<<j<<" -> ";
			}
			cout<<"\n";
		}
	}
	void DFS_helper(T src, map<int, bool> &visited){

		cout << src <<" ";

		visited[src] = true;
		for(auto i : m[src]){
			if(!visited[i]){
				DFS_helper(i, visited);
			}
		}
	}

	void DFS(T src){ 
		map<int, bool> visited;

	    DFS_helper(src, visited);

	}

};

int main(){
  Graph<int> g;
  int n;				//no. of edges

  cin >> n;

  int u, v;

  for(int i=0; i<n; i++){
  	cin >> u >> v;
  	g.AddEdge(u,v);
  }


  g.DFS(0);


  return 0;
}

/*

Test Case :

Input : 
0 1
0 4
1 2
2 3
2 4
3 4
3 5

output - 0 1 2 3 4 5 

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V)

*/