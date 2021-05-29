/*
Tarjan's algorithm for Strongly connected components(SCC)

SCC: It is a subgraph in which there is a path between all pair of vertices.
In Kosaruju Algorithm we require 2 DFS traversal whereas in Tarjan's we require only 1 DFS traversal.

The idea is to use a 'disc' array for storing the discovery time of each node ( It remains unchanged throughout the traversal) and a 'low' array which stores the vertex with lowest accessible discovery time ( It updates ).

When disc[u]=low[u] it will indicate that it will be a head of a SCC.

let u be a node. DFS will be performed on each of its children v one by one, Low value of u can change it two cases:

1) If node v is not visited already, then after DFS of v is complete and we return back to u then
low[u] = min(low[u], low[v])

2) When child v is already visited,then

a) It can be a cross edge then we ignore it
b) A back edge then, we update
low[u] = min(low[u], disc[v]);

We maintain a stack to print all the nodes of a SCC.
*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

// to store the graph
unordered_map<int,vector<int>> adj;
int V;

void DFS(int u,vector<int>& disc,vector<int>& low,stack<int>& mystack,vector<bool>& presentInStack)
{
	static int time = 0; 
	// static so will be initialised only once
	disc[u] = low[u] = time;
	time+=1;
	mystack.push(u); 
	presentInStack[u] = true;
	for(int v: adj[u])
	{
		if(disc[v]==-1)	
        //If v is not visited
		{
			DFS(v,disc,low,mystack,presentInStack);
			low[u] = min(low[u],low[v]); // case 1
		}
	//Differentiate back-edge and cross-edge
        // If it is present in the stack means it is part of current cycle so a back edge
        // If not present in the stack means it has been popped out so a cross edge and we ignore it

		else if(presentInStack[v]==true)
			low[u] = min(low[u],disc[v]); //case 2
	}
    
	// After traversing all the children and updating the low array
	if(low[u]==disc[u])	
	// this indicates u is head node of SCC
	{
		cout<<"SCC is: ";
        //print all the nodes in SCC by popping all the nodes from the stack till we get the current head
		while(mystack.top()!=u)
		{
			cout<<mystack.top()<<" ";
			presentInStack[mystack.top()] = false;
			mystack.pop();
		}
		cout<<mystack.top()<<"\n";
		presentInStack[mystack.top()] = false;
		mystack.pop();
	}
}

void findSCCs_Tarjan()
{
	vector<int> disc(V,-1),low(V,-1);
	// initialise both with -1
	vector<bool> presentInStack(V,false); 
	//to differentiate between a back edge and cross edge
	stack<int> mystack;

	for(int i=0;i<V;++i)
		if(disc[i]==-1) 
	// visit undiscovered nodes
			DFS(i,disc,low,mystack,presentInStack);
}

int main()
{   
    int vertices;
    cin>>vertices;
    V=vertices;
    for(int i=0;i<V;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
	findSCCs_Tarjan();
	return 0;
}

/* Input 1:
7
0 1
1 2
1 3
3 4
4 0
4 5
4 6
5 6
6 5

Output 1:
SCC is 2
SCC is 6 5
Scc is 4 3 1 0

Input 2:
5
1 0
0 2
2 1
0 3
3 4

Output 2:
SCC is 4
SCC is 3
SCC is 1 2 0

Time complexity: O(V+E)
V - no. of vertices
E - no. of edges
Space complexity: O(V)
Total vertices of the graph are stored in map, arrays and stack which makes the complexity of the order O(V).
 
*/ 
