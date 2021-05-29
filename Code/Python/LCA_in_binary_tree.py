'''
PROBLEM STATEMENT:
Given a binary tree with its root node and two nodes, a and b, present in
the tree. The task is to find the lowest common ancestor of a and b.
The input is in preorder and -1 denotes a null value.
For example:
Input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
let a = 1, b = 6
The above input will have the following structure:
    3
   / \
  4   5
  \   /
   6  1
Output: 3, as 3 is the lowest common ancestor of 1 and 6
'''


# A class to create a node
class Node:
    # Constructor to initialize node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# A function to builfd the tree in preorder form
def BuildTree():
    d = int(input())
    if d == -1:
        return None
    root = Node(d)
    root.left = BuildTree()
    root.right = BuildTree()
    return root


# A function to find lowest common ancestor of the two entered nodes
def LCA(root, a, b):
    # base case
    if root is None:
        return None
    if root.data == a or root.data == b:
        return root
    # Recursive calls
    leftans = LCA(root.left, a, b)
    rightans = LCA(root.right, a, b)
    if leftans is not None and rightans is not None:
        return root
    elif leftans is not None:
        return leftans
    else:
        return rightans


print("Enter values in a binary tree:")
# A function call to build the tree and return root node
root = BuildTree()
print("Enter a and b:")
# Assuming a and b are present in the tree
a = int(input())
b = int(input())
# CA stores the lowest common ancestor of a and b
CA = LCA(root, a, b)
print("LCA of", a, "and", b, "is", CA.data)


'''
TEST CASES:
1.
Input:
Enter values in a binary tree:
3
4
-1
6
-1
-1
5
1
-1
-1
-1
Enter a and b:
3
6
Output: LCA of 3 and 6 is 3

2.
Input:
Enter values in a binary tree:
2
4
6
-1
7
-1
-1
3
-1
-1
5
-1
-1
Enter a and b:
5
7
Output: LCA of 5 and 7 is 2

TIME COMPLEXITY: O(n), due to a single traversal of the tree
where, 'n' denotes the number of nodes in the tree.
SPACE COMPLEXITY: O(1), no extra space used.
'''
