# A class to store a binary tree node
class Node:
    def __init__(self, key=None, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right


# Recursive function to perform preorder traversal on the tree and fill the map.
# Here, the node has `dist` horizontal distance from the tree's root,
# and the `level` represents the node's level.
def printBottom(root, dist, level, dict):

    # base case: empty tree
    if root is None:
        return

    # if the current level is more than or equal to the maximum level seen so far
    # for the same horizontal distance or horizontal distance is seen for
    # the first time, update the dictionary
    if dist not in dict or level >= dict[dist][1]:
        # update value and level for the current distance
        dict[dist] = (root.key, level)

    # recur for the left subtree by decreasing horizontal distance and
    # increasing level by 1
    printBottom(root.left, dist - 1, level + 1, dict)

    # recur for the right subtree by increasing both level and
    # horizontal distance by 1
    printBottom(root.right, dist + 1, level + 1, dict)


# Function to print the bottom view of a given binary tree
def printBottomView(root):

    # create a dictionary where
    # `key` —> relative horizontal distance of the node from the root node, and
    # `value` —> pair containing the node's value and its level
    dict = {}

    # perform preorder traversal on the tree and fill the dictionary
    printBottom(root, 0, 0, dict)

    # traverse the dictionary in sorted order of their keys and
    # print the bottom view
    for key in sorted(dict.keys()):
        print(dict.get(key)[0], end=' ')


# the time complexity is O(n.log(n)) and requires O(n) extra space where n is the size of binary tree.


if __name__ == '__main__':

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.left.right = Node(8)

    printBottomView(root)


# (horizontal distance —> (node’s value, node’s level))
# -1 —> (7, 4)
# 0 —> (5, 3)
# 1 —> (8, 4)
# 2 —> (6, 3)
