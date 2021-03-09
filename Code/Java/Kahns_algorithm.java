/*
Kahn's Algorithm in Java
The algorithm gives us a topological sort for the given directed graph. If the graph is cyclic it returns as no topological sort for the graph is possible.

Steps:

1: Firstly compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

2: Pick all the vertices with in-degree as 0 and add them into a queue.

3: Remove a vertex from the queue and then increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of any neighboring node is reduced to zero, then add that node to the queue.

4: Repeat 3 until the queue is empty.

5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
*/
import java.util.*; 
  
// Class to represent a graph 
class Graph { 
    // No. of vertices 
    int V; 
  
    // An Array of List which contains 
    // references to the Adjacency List of 
    // each vertex 
    List<Integer> adj[]; 
    // Constructor 
    public Graph(int V) 
    { 
        this.V = V; 
        adj = new ArrayList[V]; 
        for (int i = 0; i < V; i++) 
            adj[i] = new ArrayList<Integer>(); 
    } 
  
    // Function to add an edge to graph 
    public void addEdge(int u, int v) 
    { 
        adj[u].add(v); 
    } 
    // prints a Topological Sort of the 
    // complete graph 
    public void topologicalSort() 
    { 
        // Create a array to store 
        // indegrees of all 
        // vertices. Initialize all 
        // indegrees as 0. 
        int indegree[] = new int[V]; 
  
        // Traverse adjacency lists 
        // to fill indegrees of 
        // vertices. This step takes 
        // O(V+E) time 
        for (int i = 0; i < V; i++) { 
            ArrayList<Integer> temp 
                = (ArrayList<Integer>)adj[i]; 
            for (int node : temp) { 
                indegree[node]++; 
            } 
        } 
  
        // Create a queue and enqueue 
        // all vertices with indegree 0 
        Queue<Integer> q 
            = new LinkedList<Integer>(); 
        for (int i = 0; i < V; i++) { 
            if (indegree[i] == 0) 
                q.add(i); 
        } 
  
        // Initialize count of visited vertices 
        int cnt = 0; 
  
        // Create a vector to store result 
        // (A topological ordering of the vertices) 
        Vector<Integer> topOrder = new Vector<Integer>(); 
        while (!q.isEmpty()) { 
            // Extract front of queue 
            // (or perform dequeue) 
            // and add it to topological order 
            int u = q.poll(); 
            topOrder.add(u); 
  
            // Iterate through all its 
            // neighbouring nodes 
            // of dequeued node u and 
            // decrease their in-degree 
            // by 1 
            for (int node : adj[u]) { 
                // If in-degree becomes zero, 
                // add it to queue 
                if (--indegree[node] == 0) 
                    q.add(node); 
            } 
            cnt++; 
        } 
  
        // Check if there was a cycle 
        if (cnt != V) { 
            System.out.println( 
                "There exists a cycle in the graph"); 
            return; 
        } 
  
        // Print topological order 
        for (int i : topOrder) { 
            System.out.print(i + " "); 
        } 
    } 
} 
// Driver program to test above functions 
class Main { 
    public static void main(String args[]) 
    { 
        // Create a graph given in the above diagram 
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Graph g = new Graph(n); 
        for(int i=0;i<n;i++) {
           int k=sc.nextInt();
           int l=sc.nextInt();
           g.addEdge(k,l);
        }  
      
        System.out.println( 
            "Following is a Topological Sort"); 
        g.topologicalSort(); 
    } 
} 

/*
Test cases:
1.
Input:->
5 7
0 1
0 2
0 3
1 3
1 4
4 3
Output:->
Topological Order:
0 1 2 4 3
2.
Input:->
6 6
5 2
5 0
4 0
4 1
2 3
3 1
Output:->
Topological Order:
4 5 2 0 3 1
3.
Input:->
5 5
0 1
1 2
2 3
3 4
4 0
Output:->
No topological sort possible, there exists a cycle
Time complexity: O(n+m) //Order of Sum of number of edges and vertices.
Auxillary Space: O(n)   //Order of number of vertices
*/
