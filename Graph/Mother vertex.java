import java.io.*;
import java.util.*;


public class Main{
    	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] st = br.readLine().split(" ");
		int n = Integer.parseInt(st[0]);
		int m = Integer.parseInt(st[1]);

		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			st = br.readLine().split(" ");
			int u = Integer.parseInt(st[0]) - 1;
			int v = Integer.parseInt(st[1]) - 1;
			graph.get(u).add(v);
		}

		System.out.println(findMotherVertex(n, graph));
	}
    public static int findMotherVertex(int N, ArrayList<ArrayList<Integer>>graph){
      //step-1 --> apply DFS in graph and while backtracking add vertex to stack
		Stack<Integer> st = new Stack<>();
		boolean[] visited = new boolean[N];
		for(int i=0;i<N;i++){
		    if(visited[i] == false){
		        dfs(graph,visited,i,st);
		    }
		}
      // step-2 --> either the top of stack is the answer i.e mother vertex or there is no mother vertex then return -1
		int ans = st.pop();
		visited = new boolean[N];
		count=0;
      // step-3 --> check from the top of stack and travel in the graph and maintain a count if count is equal to number of vertex then that value is our answer and for every dfs increment count by 1
		dfs(graph,visited,ans);
	if(count == N){
	    return ans +1;
	}	else{
	    return -1;
	}
		
       	}
       	static int count;
       	
       	private static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[] visited,int curr,Stack<Integer> st){
       	    visited[curr] = true;
       	    for(int nbrs:graph.get(curr)){
       	        if(visited[nbrs] == false){
       	            dfs(graph,visited,nbrs,st);
       	        }
       	    }
       	    st.push(curr);
       	}
       	
       	private static void dfs(ArrayList<ArrayList<Integer>> graph,boolean[]visited,int curr){
       	    visited[curr] = true;
       	    count++;
       	    for(int nbrs:graph.get(curr)){
    if(visited[nbrs] == false){
        dfs(graph,visited,nbrs);
    }       	        
       	    }
       	}
       	
       	
}



/* CONSTRAINTS

1<= N <= 10000
1<= M <= (N*(N-1))/2
1<= ai, bi <= N

*/

/* SAMPLE INPUT

4 3
1 2
2 3
3 4
*/

/* SAMPLE OUTPUT

1

*/
