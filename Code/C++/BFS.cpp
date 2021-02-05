/*
The BFS algorithm works similar to level – order traversal of the trees. Like level – order
traversal, BFS also uses queues. In fact, level – order traversal got inspired from BFS. BFS
works level by level. Initially, BFS starts at a given vertex, which is at level 0. In the first stage it
visits all vertices at level 1 (that means, vertices whose distance is 1 from the start vertex of the
graph). In the second stage, it visits all vertices at the second level. These new vertices are the
ones which are adjacent to level 1 vertices.
BFS continues this process until all the levels of the graph are completed. Generally queue data
structure is used for storing the vertices of a level.
*/


#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

// for generic
template<typename T>				

class Graph{

	map<T, list<T> > m;
public:
	void AddEdge(T src, T dest, bool nondirectional = true){

		m[src].push_back(dest);
	// bi-directional
		if(nondirectional){				
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

	// like level order traversal
	void BFS(T src){				
		queue<T> q;
		q.push(src);

		map<T, bool> visited;
		visited[src] = true;

		while(!q.empty()){
			T temp = q.front();
			cout<<temp<<" ";

			q.pop();

	// traverse list of neighbours
			for(auto neigh : m[temp]){	
				// if not visited			
				if(!visited[neigh]){				
					q.push(neigh);
					visited[neigh] = true;
				}
			}
		}
	}

};

int main(){

    Graph<int> g;

	//no. of edges
    int n;				

    cin >> n;

    int u, v;

    for(int i=0; i<n; i++){
        cin >> u >> v;
        g.AddEdge(u,v);
    }
   
    g.BFS(0);

    

	return 0;
}

/*

	Test Case :

	Input : 7
	0 1
	0 4
	1 2
	2 3
	2 4
	3 4
	3 5

	Output : 0 1 4 2 3 5

	Input : 6
	0 1
	0 2
	1 2
	2 0
	2 3
	3 3

	Output : 0 1 2 3

	Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
	Space complexity : O(V)

*/