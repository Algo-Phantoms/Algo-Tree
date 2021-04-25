/*
Dijkstra's algorithm is an algorithm for finding the shortest paths between
a source to all other vertices in the given graph.
It is applicable for:
* Both directed and undirected graphs
* All edges must have None-Negative weights
* Graph must be connected
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Dijkstra {
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
            int srt = Integer.parseInt(reader.readLine());
            dijkstra(Graph,V,srt);
        }
    }
    static void dijkstra(int[][] Graph, int V, int src)
    {
        //distance[i] will hold the shortest distance from src to i
        int[] distance = new int[V];

        // includedVertex[i] will true if vertex i is included in shortest path
        Boolean[] includedVertex = new Boolean[V];

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < V; i++) {
            distance[i] = Integer.MAX_VALUE;
            includedVertex[i] = false;
        }

        // Distance of source vertex from itself is always 0
        distance[src] = 0;

        // Find shortest path for all vertices
        for (int i = 0; i < V - 1; i++) {
            // Pick the minimum distance vertex from the set of vertices not yet included.
            int u = minDistance(distance, includedVertex, V);

            // Mark the picked vertex as included
            includedVertex[u] = true;

            // Update distance value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < V; v++)

                // Update distance[v] only if is not in includedVertex, there is an edge
                // from u to v, and total weight of path from src to v through u is smaller than
                // current value of distance[v] because we want minimum distance
                if (!includedVertex[v] && Graph[u][v] != 0 && distance[u] != Integer.MAX_VALUE && distance[u] + Graph[u][v] < distance[v])
                    distance[v] = distance[u] + Graph[u][v];
        }
        printDijkstra(distance,V, src);
    }

    static int minDistance(int[] distance, Boolean[] includedVertex, int V) {
        // Initialize min value
        int min = Integer.MAX_VALUE, min_index = -1;

        for (int v = 0; v < V; v++)
            if (!includedVertex[v] && distance[v] <= min) {
                min = distance[v];
                min_index = v;
            }

        return min_index;
    }
    static void printDijkstra(int distance[], int V, int src)
    {
        for (int i = 0; i < V; i++)
            System.out.println("Distance of vertex "+i +" from source "+src+" is "+ distance[i]);
    }
}
/*
Test Case:
Input 1 :
3
6 5
0 1 17
0 2 2
0 3 9
0 4 24
0 5 28
0
Output 1 :
Distance of vertex 0 from source 0 is 0
Distance of vertex 1 from source 0 is 17
Distance of vertex 2 from source 0 is 2
Distance of vertex 3 from source 0 is 9
Distance of vertex 4 from source 0 is 24
Distance of vertex 5 from source 0 is 28
Input 2 :
6 5
0 1 17
0 2 2
0 3 9
0 4 24
0 5 28
1
Output 2 :
Distance of vertex 0 from source 1 is 17
Distance of vertex 1 from source 1 is 0
Distance of vertex 2 from source 1 is 19
Distance of vertex 3 from source 1 is 26
Distance of vertex 4 from source 1 is 41
Distance of vertex 5 from source 1 is 45
Input 3 :
6 5
0 1 11
0 2 2
0 3 31
0 4 24
0 5 28
0
Output 3 :
Distance of vertex 0 from source 0 is 0
Distance of vertex 1 from source 0 is 11
Distance of vertex 2 from source 0 is 2
Distance of vertex 3 from source 0 is 31
Distance of vertex 4 from source 0 is 24
Distance of vertex 5 from source 0 is 28
    Time complexity : O(V^2) V = no. of Vertices
    Space Complexity: O(V^2) V = no. of Vertices

*/
