/*
Spanning Tree : It's a subgraph or a tree which connect every vertex of the give weighted graph

Minimum Spanning Tree (MST) : There are more than one Spanning Tree available for a graph but the
spanning tree whose sum is smallest among all spanning tree, is called Minimum Spanning tree of
that given graph.

Prims algorithm is a algorithm to find the MST of a graph, In this algorithm we find the minimum
weight of a edge which is already not included in MST and add in the MST
*/
import java.io.*;

public class Prims_Algorithm {
    public static void main(String[] args) throws IOException {
        // Read InputStream for taking user input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        //Number of testcases
        int t = Integer.parseInt(reader.readLine());
        while (t-- > 0) {
            String[] st = reader.readLine().trim().split("\\s+");
            //Number of vertices
            int V = Integer.parseInt(st[0]);
            //Number of edges
            int E = Integer.parseInt(st[1]);
            //Create a matrix to represent the graph
            int[][] Graph = new int[V][V];
            // store V vertices with total E edges in between them
            // and represent the graph as a matrix
            for (int i=1; i<=E; i++){
                String[] s = reader.readLine().trim().split("\\s+");
                int u = Integer.parseInt(s[0]);
                int v = Integer.parseInt(s[1]);
                int w = Integer.parseInt(s[2]);
                Graph[u][v]=w;
                Graph[v][u]=w;
            }
            minSpanningTree(Graph,V);
        }
    }
    static void minSpanningTree(int[][] Graph, int V)
    {
        // Array to store constructed MST
        int[] parent = new int[V];

        //optimizedWeight[i] will hold the shortest optimizedWeight from src to i
        int[] optimizedWeight = new int[V];

        // selectedMSTSet[i] will true if vertex i is included in shortest path
        Boolean[] selectedMSTSet = new Boolean[V];

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < V; i++) {
            optimizedWeight[i] = Integer.MAX_VALUE;
            selectedMSTSet[i] = false;
        }

        // Distance of source vertex from itself is always 0
        optimizedWeight[0] = 0;

        parent[0] = -1;

        // Find shortest path for all vertices
        for (int i = 0; i < V - 1; i++) {
            // Pick the minimum optimizedWeight vertex from the set of vertices not yet included.
            int u = minWeight(optimizedWeight, selectedMSTSet, V);

            // Mark the picked vertex as included
            selectedMSTSet[u] = true;

            // Update optimizedWeight value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < V; v++)

                // Update optimizedWeight[v] only if is not in selectedMSTSet, there is an edge
                // from u to v, and total weight of path from src to v through u is smaller than
                // current value of optimizedWeight[v] because we want minimum optimizedWeight
                if (!selectedMSTSet[v] && Graph[u][v] != 0 && Graph[u][v] < optimizedWeight[v]){
                    optimizedWeight[v] = Graph[u][v];
                    parent[v] = u;
                }
        }
        printMST(parent,Graph, V);
    }

    static int minWeight(int[] distance, Boolean[] includedVertex, int V) {
        // Initialize min value
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (!includedVertex[v] && distance[v] <= min) {
                min = distance[v];
                min_index = v;
            }

        return min_index;
    }
    // print the MST stored in parent[]
    static void printMST(int[] parent, int[][] graph, int V)
    {
        int totalWeight = 0;
        for (int i = 1; i < V; i++){
            System.out.println("For this included Edge "+parent[i] + " - " + i + " weight is " + graph[i][parent[i]]);
            totalWeight += graph[i][parent[i]];
        }
        System.out.println("Thus total weight of MST is "+totalWeight);
    }
}
/*
3
6 5
0 1 17
0 2 2
0 3 9
0 4 24
0 5 28
For this included Edge 0 - 1 weight is 17
For this included Edge 0 - 2 weight is 2
For this included Edge 0 - 3 weight is 9
For this included Edge 0 - 4 weight is 24
For this included Edge 0 - 5 weight is 28
Thus total weight of MST is 80
6 5
0 1 11
0 2 2
0 3 31
0 4 24
0 5 28
For this included Edge 0 - 1 weight is 11
For this included Edge 0 - 2 weight is 2
For this included Edge 0 - 3 weight is 31
For this included Edge 0 - 4 weight is 24
For this included Edge 0 - 5 weight is 28
Thus total weight of MST is 96
3 3
0 1 5
0 2 1
1 2 3
For this included Edge 2 - 1 weight is 3
For this included Edge 0 - 2 weight is 1
Thus total weight of MST is 4

    Time complexity : O(V^2) V = no. of Vertices
    Space Complexity: O(V^2)
*/