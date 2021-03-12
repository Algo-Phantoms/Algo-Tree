


public class GetConnectedComponets{
    //Given an undirected graph, print ArrayList of all connected components. 
    //For example consider the following graph.
    //  1-3  2-4
    //  |           output=[[1, 3, 5],[2, 4]] components
    //  5           

    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList < Edge > [] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList < > ();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            graph[v1].add(new Edge(v1, v2, wt));
            graph[v2].add(new Edge(v2, v1, wt));
        }

        ArrayList < ArrayList < Integer >> comps = new ArrayList < > ();

        boolean[] vis=new boolean[vtces];
         for(int v=0;v<vtces;v++){
             if(vis[v]==false){
             ArrayList<Integer> comp=new ArrayList<>();
             drawTreeGeneralComp(graph,v,comp,vis);
             comps.add(comp);}
         }
        System.out.println(comps);
        //to get no. of connected components
        System.out.println(comps.size());
    }
     public static void drawTreeGeneralComp(ArrayList < Edge > [] graph, int src, ArrayList<Integer> comp, boolean[] vis){
         vis[src]=true;
         comp.add(src);
         for(Edge e : graph[src]){
             if(!vis[e.nbr]){
             drawTreeGeneralComp(graph, e.nbr, comp, vis);}
         }
    }

    // input format
// 7 no of vtces
// 5 no of edges
// 0 1 10  }
// 2 3 10  } 
// 4 5 10  }graph components
// 5 6 10  }
// 4 6 10  }
//  Output
// [[0, 1], [2, 3], [4, 5, 6]] different connected components


// Sample Input
// 7
// 5
// 0 1 10
// 2 3 10
// 4 5 10
// 5 6 10
// 4 6 10
// Sample Output
// [[0, 1], [2, 3], [4, 5, 6]]
}