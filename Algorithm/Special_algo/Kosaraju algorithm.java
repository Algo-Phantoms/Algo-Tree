import java.io.*;
import java.util.*;

public class Main {
	public static void main(String args[]) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] st = br.readLine().split(" ");
	    int vtces = Integer.parseInt(st[0]);
	    int edges = Integer.parseInt(st[1]);
	    ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	    for(int i=0;i<vtces;i++){
	        graph.add(new ArrayList<>());
	    }
	    for(int i=0;i<edges;i++){
	        st = br.readLine().split(" ");
	        int u = Integer.parseInt(st[0]) -1;
	        int v = Integer.parseInt(st[1]) -1;
	        graph.get(u).add(v);
	    }
	    System.out.println(kosaraju(graph,vtces));

		}
  // Strongly connected components in a directed graph
		private static int kosaraju(ArrayList<ArrayList<Integer>> graph,int N){
		    // step-1 --> Apply DFS  in given graph And while backtracking add vertex in a stack
		Stack<Integer> st = new Stack<>();
		boolean[] vis = new boolean[N];
		
		for(int i=0;i<N;i++){
		    if(vis[i] == false){
		        dfs(graph,vis,i,st);
		    }
		}
		
		// step-2 --> make a new graph with same vertex but reverse edges
		ArrayList<ArrayList<Integer>> newGraph = transpose(graph,N);
		
		// step-3 --> pop from stack and apply DFS in the poping order and maintain a count of DFS applied
		vis = new boolean[N];
		int count =0;
		while(st.size() > 0){
		    int curr = st.pop();
		    if(vis[curr] == false){
		        dfs(newGraph,vis,curr);
		        count++;
		    }
		}
		
		
			return count;
		}
		private static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[]visited,int curr){ 
		    visited[curr] = true;
		for(int nbrs: graph.get(curr)){
		    if(visited[nbrs] == false){
		        dfs(graph,visited,nbrs);
		        
		    }
		}
	
		    
		}
		private static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[]visited,int curr,Stack<Integer> st){
		    visited[curr] = true;
		    for(int nbrs : graph.get(curr)){
		        if(visited[nbrs] == false){
		            dfs(graph,visited,nbrs,st);
		        }
		    }
		    st.push(curr);
		}
		private static ArrayList<ArrayList<Integer>> transpose(ArrayList<ArrayList<Integer>> graph,int N){
		   ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		   for(int i=0;i<N;i++){
		       result.add(new ArrayList<>());
		   }
		   for(int i=0;i<N;i++){
		       for(int nbrs:graph.get(i)){
		           result.get(nbrs).add(i);
		       }
		   }
		   return result;
		}

}



/*   CONSTRAINTS */
/* 
1<= Vtces <= 10000
1<= edges <= (vtces*(vtces-1))/2
1<= ai, bi <= vtces
*/

/* SAMPLE INPUT
5 6
1 4
1 3
2 4
3 4
4 5
5 1

*/

/* SAMPLE OUTPUT

2

*/
