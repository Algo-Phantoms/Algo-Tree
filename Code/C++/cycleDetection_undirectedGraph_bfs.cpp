/*Problem Statement : Given an undirected graph, 
return true(1) if cycle in detected in the graph else return false(0).

Theory : 
Undirected graph: Nodes that are connected together, where all the edges are bidirectional.
Cycle in graph : If there is a path from node to itself.
*/

/*Approach 1: Using bfs
1. create adjacency list, and call bfs function from any node suppose 1
2 . In bfs function : 
	1. queue is made to maintain bfs order
	2.push source (here 1) to queue and mark it visited 
	3.while queue is not empty :
		1.get the front element of queue in cur and pop it
		2.iterate over all the other connected nodes of cur and check :
			1.if it is not visited: mark it visited, push it to the queue and mark cur as it's parent in parent array.
			2. if visited:check if cur is the only parent of child , if not this indicates a back edge 
				hence cycle is detected, return true.
	4.return false : i.e edge not detected
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

//adjacency list vector
vector<int>adj[10000];
//array to mark visited nodes
bool vis[100001];
//array to store parent of each node
ll parent[100001];

bool bfs(ll src){
	//visted array initialised fasle
    memset(vis,false,sizeof(vis));

		//queue for bfs order
	    queue<int>q;

		//push 0 to queue and mark node 0 visited(true) in vis array
	    q.push(1);
	    vis[0]=true;
	    while(!q.empty()){
			/*get front element of queue in cur.
			for  ex if q={4,2,1} then cur=4 */
	        int cur=q.front();

			/*pop the front element of queue
			for ex if q={4,2,1} after popping q={2,1} */
	        q.pop();
		
			/*iterate over nodes that are connected to cur
			for ex- adj={{1,2},{3,4},{5,6}}
			if cur=0 then childs are 1,2 */
	        for(int child : adj[cur]){
	            if(vis[child]==false){
	                vis[child]=true;
	                q.push(child);
					//assign parent of child as cur
                    parent[child]=cur;
	            }
				/*if cur is not the parent of child that means there is another 
				node which is connected to child and not it's parent, such edge is called back edge
				presence of back edge in graph indicates cycle in graph hence return true */
                else if(parent[child]!=cur)
                return true;
	        }
	    }
        return false;
}

int main(){
	//user input=n, number of nodes in graph
    ll n; cin>>n;
    ll x,y;
	//creation of adjacency list
    for(ll i=0;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll src=1;
	//starting dfs from node 0
    cout<<bfs(src); 
}

/* Test cases 
3
1 2
2 3
3 1
output : 0

5
1 2
2 1
3 4
4 5
5 1
output:0

5
1 2
3 4
2 4
4 5
1 5
output:1

Time Complexity : O(n) 
Space Complexity: O(n)
*/