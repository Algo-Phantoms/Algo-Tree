
# Program to find the negative cycle in the graph
# Here BellmanFord's Algorithm is used to find the negative cycle in Graph

# Time Complexity: O(V*E) 
# Space Complexity : O(V)

class Edge:
	def __init__(self):
		self.src = 0
		self.dest = 0
		self.weight = 0

# Structure to represent a directed
# and weighted graph
class Graph:

	def __init__(self):
		
		# V. Number of vertices, E.
		# Number of edges
		self.V = 0
		self.E = 0
		
		# Graph is represented as
		# an array of edges.
		self.edge = []
	
# Creates a new graph with V vertices
# and E edges
def createGraph(V, E):
	graph = Graph()
	graph.V = V
	graph.E = E
	graph.edge = [Edge() for i in range(graph.E)]
	return graph

# Function runs Bellman-Ford algorithm
# and prints negative cycle (if present)
def NegativeCycleBellmanFord(graph, src):
	V = graph.V
	E = graph.E
	dist =[1000000 for i in range(V)]
	parent =[-1 for i in range(V)]
	dist[src] = 0

	# Relax all edges |V| - 1 times.
	for i in range(1, V):
		for j in range(E):
	
			u = graph.edge[j].src
			v = graph.edge[j].dest
			weight = graph.edge[j].weight

			if (dist[u] != 1000000 and
				dist[u] + weight < dist[v]):
			
				dist[v] = dist[u] + weight
				parent[v] = u

	# Check for negative-weight cycles
	isNeg = -1
	for i in range(E):
		u = graph.edge[i].src
		v = graph.edge[i].dest
		weight = graph.edge[i].weight

		if (dist[u] != 1000000 and
			dist[u] + weight < dist[v]):
			
			# Store one of the vertex of
			# the negative weight cycle
			isNeg = v
			break
		
	if (isNeg != -1):	
		for i in range(V):	
			isNeg = parent[isNeg]

		# To store the cycle vertex
		cycle = []	
		v = isNeg
		
		while (True):
			cycle.append(v)
			if (v == isNeg and len(cycle) > 1):
				break
			v = parent[v]

		# Reverse cycle[]
		cycle.reverse()

		# Printing the negative cycle
		for v in cycle:	
			print(v, end = " ");			
		print()
	# No negative cycle in Graph
	else:
		print("No negative cycle in Graph")

# Driver Code
if __name__=='__main__':
	
	# Number of vertices in graph
	V = int(input())

	# Number of edges in graph
	E = int(input())
	graph = createGraph(V, E)

	# Given Graph
	
    # Format Of input
    # src dest weight
	for i in range(E):
	    (src, dest, weight) = map(int, input().split())
	    graph.edge[i].src = src
	    graph.edge[i].dest = dest
	    graph.edge[i].weight = weight
	# Function Call
	NegativeCycleBellmanFord(graph, 0)

''' 
Test Case #1
    Input
    5
    5
    0 1 1
    1 2 2
    2 3 3
    3 4 -3
    4 1 -4

    Output
    1 2 3 4 1 

Test case #2
    Input
    5
    5
    0 1 1
    1 2 2
    2 3 3
    3 4 3
    4 1 4
    
    Output
    No negative cycle in Graph

'''


