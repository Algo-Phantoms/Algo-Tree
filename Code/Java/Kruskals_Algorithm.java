/*
Spanning Tree : It's a subgraph or a tree which connect every vertex of the give weighted graph

Minimum Spanning Tree (MST) : There are more than one Spanning Tree available for a graph but the
spanning tree whose sum is smallest among all spanning tree, is called Minimum Spanning tree of
that given graph.

Kruskal's algorithm is a algorithm to find the MST of a graph, In this algorithm we find the minimum
weight of a edge. We are using disjoint set to solve this problem. We sort the graph array according
to their edges and put the minimum edge and check if adding this edge can cause cycle or not using
union and find. If it is not causing a cycle it will added in MST.
*/
import java.io.*;
import java.util.*;

public class Kruskals_Algorithm {

    // A class to represent a weighted Graph
    static class Graph implements Comparable<Graph>
    {
        int src, dest, weight;

        public Graph(int src, int dest, int weight){
            this.src=src;
            this.dest=dest;
            this.weight=weight;
        }

        // Comparator function used for sorting according to their weights
        public int compareTo(Graph compareEdge)
        {
            return this.weight - compareEdge.weight;
        }
    }
    // A class to represent a subset for union-find
    static class subset
    {
        int parent, rank;
    }

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
            Graph[] graph = new Graph[E];
            // store V vertices with total E edges in between them
            // and represent the graph as a matrix
            for (int i=0; i<E; i++){
                String[] s = reader.readLine().trim().split("\\s+");
                int u = Integer.parseInt(s[0]);
                int v = Integer.parseInt(s[1]);
                int w = Integer.parseInt(s[2]);
                Graph g = new Graph(u,v,w);
                graph[i]=g;
            }
            KruskalMST(graph,V);
        }
    }
    // A function to find absolute root of an element (uses path compression technique)
    static int find(subset[] subsets, int i)
    {
        // find absolute root and make root as parent of i (path compression)
        if (subsets[i].parent != i)
            subsets[i].parent
                    = find(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

    // A function for doing union of two sets of x and y (using union by rank method)
    static void union(subset[] subsets, int x, int y)
    {
        int rootOfx = find(subsets, x);
        int rootOfy = find(subsets, y);

        // Attach smaller rank tree to root of high rank tree (Union by Rank)
        if (subsets[rootOfx].rank < subsets[rootOfy].rank){
            subsets[rootOfx].parent = rootOfy;
        } else if (subsets[rootOfx].rank > subsets[rootOfy].rank){
            subsets[rootOfy].parent = rootOfx;
        } else {
            // If ranks are same, then make one as root and increment its rank by one
            subsets[rootOfy].parent = rootOfx;
            subsets[rootOfx].rank++;
        }
    }
    static void KruskalMST(Graph[] graph, int V )
    {
        // for storing the minimum MST
        Graph[] minMST = new Graph[V];

        // Sort the graph according to their weight
        Arrays.sort(graph);

        // allocating memory for creating V subsets
        subset[] subsets = new subset[V];
        for (int i = 0; i < V; ++i)
            subsets[i] = new subset();

        // creating V subsets with single elements
        for (int v = 0; v < V; ++v)
        {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        int i = 0;
        int e = 0;
        // Number of edges to be taken is equal to V-1
        while (e < V - 1)
        {
            // Pick the smallest edge
            Graph next_edge = graph[i++];

            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);

            // Check adding this edge make a cycle or not if not then add it unless move
            // for next iteration
            if (x != y) {
                minMST[e++] = next_edge;
                union(subsets, x, y);
            }
            // Else discard the next_edge
        }

        printKruskalsMST(minMST, e);
    }

    // print MST stored in minMST[]
    private static void printKruskalsMST(Graph[] minMST, int e) {

        System.out.println("MST using Kruskal's Algorithm :");
        int minimumCost = 0;
        for (int i = 0; i < e; ++i)
        {
            System.out.println("For this included Edge "+minMST[i].src + " - " + minMST[i].dest + " weight is " + minMST[i].weight);
            minimumCost += minMST[i].weight;
        }
        System.out.println("Minimum Cost Spanning Tree "
                + minimumCost);
    }
}
/*
1
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
MST using Kruskal's Algorithm
For this included Edge 2 - 3 weight is 4
For this included Edge 0 - 3 weight is 5
For this included Edge 0 - 1 weight is 10
Minimum Cost Spanning Tree 19

6 5
0 1 11
0 2 2
0 3 31
0 4 24
0 5 28
MST using Kruskal's Algorithm :
For this included Edge 0 - 2 weight is 2
For this included Edge 0 - 1 weight is 11
For this included Edge 0 - 4 weight is 24
For this included Edge 0 - 5 weight is 28
For this included Edge 0 - 3 weight is 31
Minimum Cost Spanning Tree 96

3 3
0 1 5
0 2 1
1 2 3
MST using Kruskal's Algorithm :
For this included Edge 0 - 2 weight is 1
For this included Edge 1 - 2 weight is 3
Minimum Cost Spanning Tree 4

Time Complexity : O(E logE) or O(E logV)

*/