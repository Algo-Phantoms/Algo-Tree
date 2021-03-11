''' Problem : To check if a given graph is bipartite graph or not.
What is a bipartite graph : If the nodes of a graph can be divided into two sets such that there is no such edge which connects nodes of the same set.
Solution : If we consider two colors blue and green, if we could color the nodes such that there is no edge connecting same colored nodes then we can say that the graph is bipartite.

We use : 0 for not yet colored node.
         1 for green colored node.
         2 for blue colored node.
We use adjacency list to store the graph and bfs method to traverse through the nodes (using queue data structure).
'''

def check_bipartite(adj_list):
    #Let the starting node be node 1.
    nodes = len(adj_list)
    node_colors = [0]*nodes    #Initally all the nodes are uncolored.
    queue = []
    queue.append(0)
    node_colors[0] = 1    #Assign green to the first node.

    while queue:
        curr_node = queue.pop()
        to_assign = 1
        if node_colors[curr_node] == 1:    #If the current node has color green adjacent nodes should be assigned blue.
            to_assign = 2

        for adj_node in adj_list[curr_node]:
            if node_colors[adj_node]!=0 and node_colors[adj_node]!=to_assign:    #If the adjacent node is already colored and if it matches the color of current node then we have an edge between same colored nodes.
                return False
            else:
                node_colors[adj_node] = to_assign
                queue.append(adj_node)
    '''
    There might be nodes with no vertices. We don't consider in this case because they can be added to any set.
    '''

    return True    #We haven't encountered any edge between same same colored nodes.


nodes = int(input("Enter the no. of nodes: "))    #Scan the no. of nodes. 
edges = int(input("Enter the no.of edges: "))    #Scan the total no. of edges.
adj_list = [[] for node in range(nodes)]  #Creating an adjacency list.

print("Enter the edge from vertex and to vertex indices")
for edge in range(edges):
    fro,to = map(int,input().split())    #Edge between which two nodes.(Numbering from 1 to nodes).
    adj_list[fro-1].append(to-1)    #As the list indexing start from 0.

if(check_bipartite(adj_list)):
    print("The given graph is a bipartite graph")
else:
    print("The given graph is not a bipartite graph")

'''
Time Complexity : O(nodes + edges) as we traverse using bfs with adjacency list. 
Space Complexity : O(nodes + edges) For the adjacency list.
'''

'''
Test Cases: 

Sample Input 1: 
Enter the no. of nodes: 6
Enter the no.of edges: 7
Enter the edge from vertex and to vertex indices
1 5
1 3
1 2
2 6
3 4
5 4
4 6

Sample Output 1: 
The given graph is not a bipartite graph.

Explanation:
There is no such way to color nodes which meet the requirements.

Sample Input 2: 
Enter the no. of nodes: 6
Enter the no.of edges: 6
Enter the edge from vertex and to vertex indices
1 5
1 3
1 2
2 6
3 4
5 4

Sample Output 2: 
The given graph is a bipartite graph.

Explanation: 
Colors of the nodes can be as following: 
1 => green
2 => blue
3 => blue
4 => green
5 => blue
6 => green
'''
