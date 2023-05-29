/* Problem statement : Print the negative weight cycle if present in the given DAG graph 
Solution : Bellman Ford Algorithm helps us to find if there is any negative cycle present in the graph.
Bellman Ford uses the logic : If distance from source vertex to any other vertex is getting updates even after n-1 iterations (where n is no. of vertices)
then there is a negative cycle in the graph. 
Using this algo and keeping a parent array, so whenever the distance is getting updated we store by which connection it is getting updated and 
when we detect a cycle we traverse back to print the vertices in the cycle.*/

import java.util.*;

public class negative_cycle {

    static void neg_cycle(int v, int m, int[][] edges, int src) {
        int[] dist = new int[v]; // dist array stores the minimum possible distance of each vertex from the
                                 // source vertex.
        int[] parent = new int[v]; // parent array stores the parent vertex of each vertex.
        for (int i = 0; i < v; i++) {
            dist[i] = 1000000; // Initialized to Infinity (practically to a very large value).
            parent[i] = -1;
        }
        dist[src] = 0;
        for (int i = 0; i < v - 1; i++) {
            for (int j = 0; j < m; j++) {
                int x = edges[j][0];
                int y = edges[j][1];
                int wt = edges[j][2];
                if (dist[x] != 1000000 && dist[y] > dist[x] + wt) { // If value of dist[y] is less than dist[u]+wt(u,v)
                                                                    // then dist[v],parent[v] gets updated.
                    dist[y] = dist[x] + wt;
                    parent[y] = x;
                }
            }
        }
        int vert = -1; // To check for negative cycle.
        for (int i = 0; i < m; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            int wt = edges[i][2];
            if (dist[x] != 1000000 && dist[y] > dist[x] + wt) { // Even after v-1 iterations if dist[v] can be updated
                                                                // then we have encountered an negative weight cycle.
                vert = x;
                // System.out.println(x + " " + y);
                break;
            }
        }
        if (vert == -1)
            System.out.println("No negative cycle found in the graph!!");
        else {
            ArrayList<Integer> elements = new ArrayList<>();
            int p = vert;
            while (p != vert || elements.size() < 1) { // Backpropagating throught the obtained vertex using the parent
                                                       // array.
                elements.add(p + 1);
                p = parent[p];
            }
            elements.add(p + 1);
            Collections.reverse(elements);
            for (int x : elements) // Printing the elements in the cycle.
                System.out.print(x + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int v = sc.nextInt();
        System.out.println("Enter the number of edges: ");
        int m = sc.nextInt();
        int[][] edges = new int[m][3]; // To store the edges. edges[i][0] represent from vertex, edges[i][1]
                                       // to vertex and edges[i][2] represents the weight of the ith edge.
        System.out.println("Enter the number of start,end and weight of the edges(vertices index starts from 1): ");
        for (int i = 0; i < m; i++) {
            edges[i][0] = sc.nextInt() - 1; // Vertcies 1 to v are stored as 0 to v-1.
            edges[i][1] = sc.nextInt() - 1;
            edges[i][2] = sc.nextInt();
        }
        neg_cycle(v, m, edges, 0); // Passing any random source value to run the bellman ford algo.
    }
}

// Time Complexity : O(V*E) where V is the number of vertices and E is the
// number of edges. Space Complexity : O(E + V) E - to store the edges and V to
// stores the dist and parent arrays.

// Sample Input 1:
// Enter the number of vertices:
// 5
// Enter the number of edges:
// 5
// Enter the number of start,end and weight of the edges:
// 1 2 1
// 2 3 1
// 3 4 3
// 4 5 -3
// 5 1 -3

// Sample Output 1:
// 1 2 3 4 5 1

// Sample Input 2:
// Enter the number of vertices:
// 5
// Enter the number of edges:
// 5
// Enter the number of start,end and weight of the edges:
// 1 2 1
// 2 3 2
// 4 5-3
// 5 2-3

// Sample Output 2:
// 2 3 4 5 2
