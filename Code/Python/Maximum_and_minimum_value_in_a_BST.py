'''
ALGORITHM: FINDING MAXIMUM AND MINIMUM VALUE OF A NODE IN BINARY SEARCH TREE

IMPLEMENTATION:
Binary Search Tree(BST) is a special kind of binary tree in which right subtree has value greater than root node and left subtree has value less than root node and this is applicable to every node in binary tree.
Here, first we will create Binary Search Tree(BST). From the property of BST, we can conclude that maximum value node will be the one which has no right child. Similarly, minimum value node will be the one which has no left child.

TIME COMPLEXITY: O(n)
If the BST created is left-skewed, then time complexity of finding minimum value will be O(n)
If the BST created is right-skewed, then time complexity of finding maximum value will be O(n) 
'''



class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    #create Binary Search Tree
    def createBST(self, value):
        #if it is first node
        if self.root==None:
            self.root = Node(value)

        #else find position for a node 
        else:
            current = self.root
            while True:
                if value<current.data:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(value)
                        break
                elif value>current.data:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(value)
                        break
                else:
                    break


    #finding maximum value
    def MaximumValue(self):
        if self.root==None:
            print("Oops! tree is empty!")
        else:
            temp=self.root
            while temp.right!=None:
                temp=temp.right
            print("Maximum value is "+str(temp.data))

    #finding minimum value 
    def MinimumValue(self):
        if self.root==None:
            print("Oops! tree is empty!")
        else:
            temp=self.root
            while temp.left!=None:
                temp=temp.left
            print("Minimum value is "+str(temp.data))


tree = BST()
size = int(input("enter number of nodes: "))

for i in range(size):
    print("enter value "+str(i+1)+":")
    tree.createBST(int(input()))
    
tree.MaximumValue()
tree.MinimumValue()



'''
TEST CASE 1:
Input:
enter number of nodes: 0
Output:
Oops! tree is empty!
Oops! tree is empty!

TEST CASE 2:
Input:
enter number of nodes: 3
enter value 1:
1
enter value 2:
6
enter value 3:
2
Output:
Maximum value is 6
Minimum value is 1
'''
