'''
Inorder Traversal 
Definition of In Order traversal : Process all nodes of a tree by recursively processing the left subtree, then processing the root, and finally the right subtree
In-order traversal is mainly used to print the values, stored in the nodes of a binary search tree, in ascending order. 
Algorithm of Inorder(tree) Traversal
1.Traverse the left subtree, i.e., call Inorder(left-subtree)
2.Visit the root.
3.Traverse the right subtree, i.e., call Inorder(right-subtree)

'''


class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self, root):
        self.root = TreeNode(root)

    def inorder_traversal(self, node, path):
        if node:
            path = self.inorder_traversal(node.left, path)
            path += str(node.val) + ' '
            path = self.inorder_traversal(node.right, path)

        return path
      
tree = Tree(1)

tree.root.left = TreeNode(2)
tree.root.right = TreeNode(3)

tree.root.left.left = TreeNode(4)
tree.root.left.right = TreeNode(5)
tree.root.right.left = TreeNode(6)
tree.root.right.right = TreeNode(7)

# In-Order Traversal :- left -> root -> right

print(tree.inorder_traversal(tree.root, ''))

'''
Sample Case 1:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Expected Output:- 4 2 5 1 6 3 7
Time Complexity: O(n)
Space Complexity: O(n)

'''
