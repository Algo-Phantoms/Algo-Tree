# Tree

A tree is a data structure similar to a linked list but instead of each node pointing simply to the
next node in a linear fashion, each node points to a number of nodes. Tree is an example of a non-
linear data structure. A tree structure is a way of representing the **hierarchical nature** of a structure
in a graphical form.

# Binary Tree
A tree is called binary tree if each node has zero child, one child or two children. Empty tree is
also a valid binary tree. We can visualize a binary tree as consisting of a root and two disjoint
binary trees, called the left and right subtrees of the root.


## Basic Operations

* Inserting an element into a tree
* Deleting an element from a tree
* Searching for an element
* Traversing the tree

## Auxiliary Operations

* Finding the size of the tree
* Finding the height of the tree
* Finding the level which has maximum sum
* Finding the least common ancestor (LCA) for a given pair of nodes, and many more.

#  Binary Search Tree

In binary search trees, all the left subtree elements should be less than root data and all the right
subtree elements should be greater than root data. This is called binary search tree property. Note
that, this property should be satisfied at every node in the tree.

* The left subtree of a node contains only nodes with keys less than the nodes key.
* The right subtree of a node contains only nodes with keys greater than the nodes key.
* Both the left and right subtrees must also be binary search trees.

## Main operations: 

* Find/ Find Minimum / Find Maximum element in binary search trees
* Inserting an element in binary search trees
* Deleting an element from binary search trees

## Auxiliary operations:

* Finding k th -smallest element in tree
* Sorting the elements of binary search tree and many more

## Questions :
* Check if a Binary Tree is a valid Binary Search Tree ----> [Java](/Code/Java/check_valid_BST.java)
* Searching in BST ----> [C++](/Code/C++/searching_in_bst.cpp)
* Construction of binary tree from preorder and inorder traversal ----> [C++](/Code/C++/binary_tree_from_preorder_and_inorder.cpp) 
* Level Order Traversal in BST ----> [C++]() | [Java]() | [Python](/Code/Python/level_order_traversal_binary_tree.py)
* Spiral Traversal of Binary Tree ----> [C++](/Code/C++/spiral_traversal_of_binary_tree.cpp) 




