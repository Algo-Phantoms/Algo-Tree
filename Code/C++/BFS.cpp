#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

template<typename T> // for generic

class Graph{

	map<T, list<T> > m;
public:
	void AddEdge(T src, T dest, bool nondirectional = true){

		m[src].push_back(dest);
		if(nondirectional){ // bi-directional
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

	void BFS(T src){ // like level order traversal
		queue<T> q;
		q.push(src);

		map<T, bool> visited;
		visited[src] = true;

		while(!q.empty()){
			T temp = q.front();
			cout<<temp<<" ";

			q.pop();

			for(auto neigh : m[temp]){ // traverse list of neighbours
				if(!visited[neigh]){ // if not visited
					q.push(neigh);
					visited[neigh] = true;
				}
			}
		}
	}

};

int main(){

    Graph<int> g;
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(2,4);
    g.AddEdge(3,4);
    g.AddEdge(3,5);
  
    g.print();
  
    g.BFS(0);

    

	return 0;
}

/*
Output - 0 1 4 2 3 5
*/