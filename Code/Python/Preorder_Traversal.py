'''
Definition of Pre-Order Traversal: Process all nodes of a tree by processing the root, then recursively processing all subtrees.
Algorithm of of Preorder(tree) Traversal
Until all nodes are traversed −
Step 1 − Visit root node.
Step 2 − Recursively traverse left subtree.
Step 3 − Recursively traverse right subtree.

'''

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self, root):
        self.root = TreeNode(root)
        
    def preorder_traversal(self, node, path):
        if node:
            path += str(node.val) + ' '
            path = self.preorder_traversal(node.left, path)
            path = self.preorder_traversal(node.right, path)

        return path
   
tree = Tree(1)

tree.root.left = TreeNode(2)
tree.root.right = TreeNode(3)

tree.root.left.left = TreeNode(4)
tree.root.left.right = TreeNode(5)
tree.root.right.left = TreeNode(6)
tree.root.right.right = TreeNode(7)

# Pre-Order Traversal :- root -> left -> right

print(tree.preorder_traversal(tree.root, ''))

'''
Sample Case 1:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Expected Output:- 1 2 4 5 3 6 7
Time Complexity: O(n)
Space Complexity: O(n)

'''
