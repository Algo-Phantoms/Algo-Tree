 # A binary tree is a general tree that works with a constraint that each
 #parent can only have 2 child nodes

 # The three things to remember for a bianry search tree is that:
     # 1. The left values of the child nodes are always smaller than the value of parent node
     # 2. The right values of the child nodes are always greater than value of parent node
     # 3. The elements aren't duplicated

  #There are three types of traversal possible in a Binary Search Tree:
      # 1. In order Traversal
      # 2. Pre order Traversal
      # 3. Post order Traversal

# To create a Binary Search Tree, we ca  proceed this way:

    class BinarySearchTree:
        def __init__(self,data):
            self.data=data
            self.left=None
            self.right=None 

        def add_child(self,child):             # we create child nodes here
            if child==self.data:
                return                          #since we BST doesn't permit duplicates

            if child<self.data:                  # we will add the child node to the left
                if self.left:                    #what if there already exists a left node?
                    self.left.add_child(child)   #we recursively call the add child function on the left node, considering it as parent
                else:
                    self.data=BinarySearchTree(child)      #else we normally add the child node

            if child>self.data:                     # we will add the child to the right of the parent node and follow same steps as we did for left side
                if self.right:
                    self.right.add_child(child)
                else:
                    self.data=BinarySearchTree(child)

        # Now we proceed to traversal

        # In order traversal: We first traverse the left sub-tree, then the root nodes followed by the right sub-tree

        def in_order_traversal(self):
            elements=[]          # we will append the elements of the tree in this list as we go with our transversal

            if self.left:         # traversing the left subtree
                elements += self.left.in_order_traversal()

            elements.append(self.data)   #base node traversal

            if self.right:        #traversing the right sub tree
                elements += self.right.in_order_traversal()
            return elements     #we return the in order traversal list of elements

        #Pre Order traversal: We first traverse the root node followed by the left sub-tree and right sub-tree respectively

        def pre_order_traversal(self):
            elements=[]          # we will append the elements of the tree in this list as we go with our transversal

            elements.append(self.data)   #base node traversal

            if self.left:         # traversing the left subtree
                elements += self.left.in_order_traversal()

            if self.right:          #traversing the right sub tree
                elements += self.right.in_order_traversal()

            return elements        #we return the in order traversal list of elements

        #Post Order Traversal: We first travel the left sub-tree then the right sub-tree followed by the root node

         def pre_order_traversal(self):
            elements=[]          # we will append the elements of the tree in this list as we go with our transversal

            if self.left:         # traversing the left subtree
                elements += self.left.in_order_traversal()

            if self.right:          #traversing the right sub tree
                elements += self.right.in_order_traversal()

            elements.append(self.data)   #base node traversal

            return elements        #we return the in order traversal list of elements