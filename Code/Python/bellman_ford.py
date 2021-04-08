'''
    Bellman Ford provides shortest path from a given source to all the vertices in the graph.
    Steps:
        1. Initialize a distance array d as inifinite and intialize the distance to the source as 0, d[0]=0.
        (Distance array stores the distance of the nodes to the given source)
        2. Relax all the edges for V-1 times. For every edge u-v :
            if d[u]+w<d[v]:
                d[v]=d[u]+w
            where d[u]= distance of vertex u from origin
            d[v] = distance of vertex v from origin
            w = weight of the u-v edge
        3. Relax all the edges for one more time and if d[u]+ weight of u-v edge < d[v] then that means that
        there is a negative weight cycle and bellman ford algorithm can't work on graphs with negative weight cycle.
'''

def bellman_ford(n,g):
        # distance array
        d=[float('inf') for i in range(n+1)]
        # initialising the distance of source as 0
        # source here is 1
        d[1]=0
        
        for i in range(n-1):
            for u,v,w in g:
                if d[u]+w<d[v]:
                    d[v]=d[u]+w
        # checking for negative weight cycle
        for u,v,w in g:
            if  d[u]+w<d[v]:
                print("Negative weight cycle")
                break
        else:
            # print the distance of all the vertices from the source
            for i in d[2:]:
                print(i, end=" ")
        return
    
for _ in range(int(input())):
      # n is no of vertices and m is the no of edges
      n,m= list(map(int, input().split()))
      # initialising graph as a list
      g=[]
      for _ in range(m):
          # u-v is a directed edge with v as a weight
          u,v,w=list(map(int, input().split()))
          g.append([u,v,w])

      bellman_ford(n,g)

'''
    Test cases:
    Input 1:
    1
    5 5
    1 2 5
    1 3 2
    3 4 1
    1 4 6
    3 5 5
    Output:
    5 2 3 7

    Input 2:
    1
    3 3
    0 1 -1
    1 2 -2
    2 0 -3
    Output:
    Negative weight cycle

    # time complexity: O(VE), where V is no of vertices and E is no of edges
    # space complexity: O(V+E) for storing adjacency list
'''
