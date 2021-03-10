# The Kahn's algorithm gives us a topological sort for the given directed graph. If the graph is cyclic it returns as no topological sort for the graph is possible.
# Steps:
# 1: Firstly compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
# 2: Pick all the vertices with in-degree as 0 and add them into a queue.
# 3: Remove a vertex from the queue and then increment count of visited nodes by 1. Decrease in-degree by 1 for all its neighboring nodes.
#    If in-degree of any neighboring node is reduced to zero, then add that node to the queue.
# 4: Repeat these 3 steps until the queue is empty.
# 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph, else print
#    the nodes in topologiocal sorted manner.


from collections import defaultdict

#Represent a class of Graph
class Graph:
    def __init__(self,vertices):
        '''Initialize vertices and dictionary containing adjacency list'''
        self.v=vertices
        self.graph=defaultdict(list)    

    #Function to add an edge in graph
    def addEdge(self,u,v):
        self.graph[u].append(v)

    #Function for topological sort
    def topological_sort(self):
        indegree=[0]*self.v

        for i in self.graph:
            for j in self.graph[i]:
                indegree[j]+=1

        queue=[]
        for i in range(self.v):
            if(indegree[i]==0):
                queue.append(i)

        count=0
        top_order=[]
        while(queue):
            pop_ele=queue.pop(0)
            top_order.append(pop_ele)

            for i in self.graph[pop_ele]:
                indegree[i]-=1

                if(indegree[i]==0):
                    queue.append(i)

            count+=1

        if(count==self.v):
            print("Topological sort : ",end='')
            print(top_order)
        else:
            print("Topological Sort is not possible in this graph because there exist a cycle")


n=int(input("Enter no of vertices : "))
g=Graph(n)
# m=int(input("Enter no of path: "))
for i in range(n):
    u,v=input("Enter source and destination of a path: ").split()
    g.addEdge(int(u),int(v))
g.topological_sort()


# Test cases:

# 1. Input:->
# Enter no of vertices : 6
# Enter source and destination of a path: 5 2
# Enter source and destination of a path: 5 0
# Enter source and destination of a path: 4 0
# Enter source and destination of a path: 4 1
# Enter source and destination of a path: 2 3
# Enter source and destination of a path: 3 1
# Output:->
# Topological sort : [4, 5, 2, 0, 3, 1]

# 2. Input:->
# Enter no of vertices : 6
# Enter source and destination of a path: 5 5
# Enter source and destination of a path: 0 1
# Enter source and destination of a path: 1 2
# Enter source and destination of a path: 2 3
# Enter source and destination of a path: 3 4
# Enter source and destination of a path: 4 0
# Output:->
# Topological Sort is not possible in this graph because there exist a cycle

# Time complexity: O(V+E) //Order of Sum of number of edges and vertices
# Auxillary Space: O(V)   //Order of number of vertices

