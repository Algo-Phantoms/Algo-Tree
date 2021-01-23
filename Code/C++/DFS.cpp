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
    g.AddEdge(0,1);
    g.AddEdge(0,4);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(2,4);
    g.AddEdge(3,4);
    g.AddEdge(3,5);
    
     
    g.DFS(0);
    

	return 0;
}

/*
output - 0 1 2 3 4 5 
*/