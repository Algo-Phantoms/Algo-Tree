
'''Level order traversal of a binary tree is breadth first traversal for the tree.
I have implemented the solution using queue.
Algorithm: 
For each node, first the node is visited and then it’s child nodes are put in a FIFO queue. 

printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root /*start from root*/
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children 
      (first left then right children) to q
    c) Dequeue a node from q.

Implementation: 
Here is a simple implementation of the above algorithm. Queue is implemented using an array with maximum size of 500. We can implement queue as linked list also.
'''

# Python program to print level 
# order traversal using Queue
 
# A node structure
class Node:
    # A utility function to create a new node
    def __init__(self ,key):
        self.data = key
        self.left = None
        self.right = None
 
# Iterative Method to print the 
# height of a binary tree
def printLevelOrder(root):
    # Base Case
    if root is None:
        return
     
    # Create an empty queue 
    # for level order traversal
    queue = []
 
    # Enqueue Root and initialize height
    queue.append(root)
 
    while(len(queue) > 0):
       
        # Print front of queue and 
        # remove it from queue
        print (queue[0].data)
        node = queue.pop(0)
 
        #Enqueue left child
        if node.left is not None:
            queue.append(node.left)
 
        # Enqueue right child
        if node.right is not None:
            queue.append(node.right)
 
#Driver Code 
root = Node(int(input()))
root.left = Node(int(input()))
root.right = Node(int(input()))
root.left.left = Node(int(input()))
root.left.right = Node(int(input()))
root.right.left=Node(int(input()))
root.right.right=Node(int(input()))
 
print ("Level Order Traversal of binary tree is -")
printLevelOrder(root)

'''
TestCase:
1.

Input :
1 2 3 4 5

Explanation : 
 The tree will look like this
    1
  2   3
 4 5

Output :
Level Order traversal of binary tree is 
1 2 3 4 5 

2.

Input :
15 10 20 8 12 16 25

Explanation:
 The tree will look like this
    15
  10   20
 8 12 16 25

Output :
Level Order traversal of binary tree is 
15 10 20 8 12 16 25 


Time Complexity: O(n) where n is number of nodes in the binary tree 
Space Complexity: O(n) where n is number of nodes in the binary tree 
'''
