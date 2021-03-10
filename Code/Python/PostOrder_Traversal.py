'''
Post Order Traversal
Definition of Post Order traversal : Process all nodes of a tree by processing the root, then recursively processing all subtrees
Post-order traversal is one of the multiple methods to traverse a tree. It is mainly used for tree deletion.
Algorithm of Postorder(tree) Traversal 
1. Traverse the left subtree, i.e., call Postorder(left-subtree)
2. Traverse the right subtree, i.e., call Postorder(right-subtree)
3. Visit the root.

'''

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self, root):
        self.root = TreeNode(root)
        
    def postorder_traversal(self, node, path):
        if node:
            path = self.postorder_traversal(node.left, path)
            path = self.postorder_traversal(node.right, path)
            path += str(node.val) + ' '

        return path

   
tree = Tree(1)

tree.root.left = TreeNode(2)
tree.root.right = TreeNode(3)

tree.root.left.left = TreeNode(4)
tree.root.left.right = TreeNode(5)
tree.root.right.left = TreeNode(6)
tree.root.right.right = TreeNode(7)

# Post-Order Traversal :- left -> right -> root

print(tree.postorder_traversal(tree.root, ''))

'''
Sample Case 1:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Expected Output:- 4 5 2 6 7 3 1
Time Complexity: O(n)
Space Complexity: O(n)

'''

