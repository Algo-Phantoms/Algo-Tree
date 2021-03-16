'''
A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges 
share an endpoint. A maximum matching is a matching of maximum size (maximum number of edges). 
In a maximum matching, if any edge is added to it, it is no longer a matching. There can be more 
than one maximum matchings for a given Bipartite Graph.

Maximum Bipartite Matching (MBP) problem can be solved by converting it into a flow network
'''
# Python program to find 
# maximal Bipartite matching(kahn's Algorithm). 

class GFG: 
	def __init__(self,graph): 

		self.graph = graph 
		self.ppl = len(graph) 
		self.jobs = len(graph[0]) 

	def bpm(self, u, matchR, seen): 

		for v in range(self.jobs): 

			if self.graph[u][v] and seen[v] == False: 

				seen[v] = True

				if matchR[v] == -1 or self.bpm(matchR[v], matchR, seen): 
					matchR[v] = u 
					return True
		return False

	def maxBPM(self): 

		matchR = [-1] * self.jobs 

		result = 0
		for i in range(self.ppl): 

			seen = [False] * self.jobs 
			
			if self.bpm(i, matchR, seen): 
				result += 1
		return result 

bpGraph =[[0, 1, 1, 0, 0, 0], 
		[1, 0, 0, 1, 0, 0], 
		[0, 0, 1, 0, 0, 0], 
		[0, 0, 1, 1, 0, 0], 
		[0, 0, 0, 0, 0, 0], 
		[0, 0, 0, 0, 0, 1]] 

g = GFG(bpGraph) 

print ("Maximum number of applicants that can get job is %d " % g.maxBPM()) 

'''
1.Input:
5 5
0 1
1 2
2 3
3 4
4 0

Output :Maximum number of applicants that can get job is 5 

2.Input:
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Output :Maximum number of applicants that can get job is 5 

Time complexity: O(n+m) //Order of Sum of number of edges and vertices

Auxillary Space: O(n)   //Order of number of vertices

This implementation requires O((M+N)*(M+N)) extra space.

'''

