# Tree

A tree is a data structure similar to a linked list but instead of each node pointing simply to the
next node in a linear fashion, each node points to a number of nodes. Tree is an example of a non-
linear data structure. A tree structure is a way of representing the **hierarchical nature** of a structure
in a graphical form.

# Binary Tree
A tree is called binary tree if each node has zero child, one child or two children. Empty tree is
also a valid binary tree. We can visualize a binary tree as consisting of a root and two disjoint
binary trees, called the left and right subtrees of the root.

## Properties of a Binary Tree
* In any binary tree,maximum number of nodes on level l is 2 ** l, where l >= 0.
* Maximum number of nodes pssible in a binary tree of heiht h is 2 ** h - 1.
* Minimum number of nodes possible in a binary tree of height h is h.
* For any non-empty binary tree, if n is the number of nodes and e is the number of edges, then n = e + 1
* For any non-empty binary tree T, if n0 is the number of leaf nodes(degree = 0) and n2 is the number 
of internal node(degree = 2), then n0 = n2 + 1
* Height of a complete binary tree with n number of nodes is [log(n+1) base 2].

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

## Array representation of binary tree
* The root is at location 1.
* For any node with index i, 1 < i <= n, (for some n)
	* PARENT(i) = [i/2] (For the node when i=1, there is no parent)
	* LCHILD(i) = 2 * i (If 2 * i > n, then i has no left child)
	* RCHILD(i) = 2 * i + 1 (If 2 * (i+1) > n, then i has no right child)

* Maximum & minimum size that an array may require to store a binary tree with n number of nodes are
	* Size (max) = 2 ** n - 1
	* Size (min) = 2 ** [log(n+1) base 2] - 1
  
## Tree Traversal

* Traversal operation is a frequently used operation on a binary tree.
* This operation is used to visit each node in the tree exactly once.
* A full traversal on a binary tree gives a linear ordering of the data in the tree.
	* For an example, if the binary tree contains an arithmetric expression, then its traversal may
give us the expression in infix notation, postfix notation or prefix notation.

## Different ways of traversing
* Now a tree can be traversed in various ways.
* For a systematic traversal, it is better to visit each node (starting from the root) and its sub trees in the same fashion.
* There are *six* such possible ways:

			  R
		      /   \
		     T1    T2

	* R T1 T2 --> Pre-order traversal
	* T1 R T2 --> In-order traversal
	* T1 T2 R --> Post-order travsersal
	* T2 T1 R (mirror replica of R T1 T2)
	* T2 R T1 (mirror replica of T1 R T2)
	* R T2 T1 (mirror replica of T1 T2 R)
	
## Pre-order binary tree traversal
* Visit the root node R.
* Traverse the left sub-tree of R in preorder
* Traverse the right sub-tree of R in preorder

## In-order binary tree traversal
* Traverse the left sub-tree of R in inorder
* Visit the root node R
* Traverse the right sub-tree of R in order

## Insertion operation

* To search for the existence of a node in the given binary tree
after which an insertion to be made, and
* To establish a link for the new node.


## Deletion operation

* To search for the existence of a node in the the given binary 
tree, which node to be deleted
* To adjust the links among parent and child nodes of the deleted node


## Merging operation
* Suppose, T1 and T2 are two binary trees, T2 can be merged 
with T1 if all the nodes from T2, one by one, is inserted into
the binary tree T1(insertion may be as internal node when it has to maintain certain property or maintain
property or may be as external nodes)


# Binary Search Tree

* A binary tree T is termed as binary search tree(or binary sorted tree) if each
node N of T satisfies the following property
	* The value at N is greter than every value in the left sub-tree of N and
	less than every value in the right sub-tree of N.
* Searching for a data in a binary search tree is much faster than in
arrays or linked lists.


## Insertion of a key into a BST
* Insertion operation on a binary dearch tree is conceptually very simple
* It is in fact, one step more than the special operation
* To insert a node with data, say ITEM, into a tree is to be searched starting from the root node.
* If ITEM is found, do nothing; otherwise, ITEM is to be inserted at the dead end where search halts


## Deletion of a key from a BST
* **CASE 1:** N is the leave node
* **CASE 2:** N has exactly one child
* **CASE 3:** N has two children

## Traversing a binary search tree
* All the traversal operations for binary tree are applicable to binary search trees without any alteration.
* It can be verified that inorder traversal on a binary search tree will give the sorted order of data in ascending order
* If we require to sort a set of data, a binary search tree can be built with those data
and then inorder traversal can be applied
* This method of sorting is known as *binary sort* and this is why binary search tree is also termed as binary sorted tree
* This sorting method is considered as one of the efficient sorting method
* The minimum value is at the left-most node
* The maximum value is at the right-most node

## Applications of binary search trees
* For efficient searching.
* For sorting data in increasing order
* For indexing records in files


## Main operations: 

* Find/ Find Minimum / Find Maximum element in binary search trees
* Inserting an element in binary search trees
* Deleting an element from binary search trees

## Auxiliary operations:

* Finding k th -smallest element in tree
* Sorting the elements of binary search tree and many more

## Questions :
* Searching in BST ----> [C++](/Code/C++/searching_in_bst.cpp) 



