""" Ques: Create a general (N-ary) tree
Language: Python
Firstly, class treenode is defined with several inner functions including "__init__" for creating tree node with chils as list and #intitially storing 'None' as address of parent, "add_child" add data in child list, there is a helping function named "get_level" as #well to get the level of a child node while printing its value and finally "print_tree" function prints tree with according to its #level .
And function "build_tree" creats the whole tree using class "TreeNode"
"""

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.child = []
        self.parent = None

    def add_child(self, obj):
        obj.parent = self
        self.child.append(obj)

    def get_level(self):
        lev = 0
        p = self.parent
        while p != None:
            lev += 1
            p = p.parent

        return lev

def print_tree(root):
    s = root.data + " child nodes=> "
    for i in root.child:
        s = s + i.data
        s += ", "
    print(s)
    for i in root.child:
        print_tree(i)

def build_tree():
    print('Enter data of root node:',end=" ")
    data = input()
    root = TreeNode(data)
    no_node = int(input('Enter number of nodes for this root node:'))
    for i in range(no_node):
        d = build_tree()
        root.child.append(d)
    return root


if __name__ == "__main__":
    root = build_tree()
    print_tree(root)

"""e.g. 1

#input:

#Enter data of root node:2
#Enter number of nodes for this root node:3
#Enter data of root node:3
#Enter number of nodes for this root node:0
#Enter data of root node:4
#Enter number of nodes for this root node:2
#Enter data of root node:5
#Enter number of nodes for this root node:0
#Enter data of root node:6
#Enter number of nodes for this root node:0
#Enter data of root node:7
#Enter number of nodes for this root node:0

#Output: 

#2 child nodes=> 3, 4, 7, 
#3 child nodes=> 
#4 child nodes=> 5, 6, 
#5 child nodes=> 
#6 child nodes=> 
#7 child nodes=> 

 daigram:
                2
               / | \
               3 4  7
                / \   
                5  6 

Enter data of root node:a
Enter number of nodes for this root node:3
Enter data of root node:b
Enter number of nodes for this root node:2
Enter data of root node:s
Enter number of nodes for this root node:0
Enter data of root node:t
Enter number of nodes for this root node:2
Enter data of root node:w
Enter number of nodes for this root node:0
Enter data of root node:r
Enter number of nodes for this root node:0
Enter data of root node:e
Enter number of nodes for this root node:2
Enter data of root node:u
Enter number of nodes for this root node:0
Enter data of root node:v
Enter number of nodes for this root node:0
Enter data of root node:r
Enter number of nodes for this root node:2
Enter data of root node:x
Enter number of nodes for this root node:0
Enter data of root node:y
Enter number of nodes for this root node:0
a child nodes=> b, e, r, 
b child nodes=> s, t, 
s child nodes=> 
t child nodes=> w, r, 
w child nodes=> 
r child nodes=> 
e child nodes=> u, v, 
u child nodes=> 
v child nodes=> 
r child nodes=> x, y, 
x child nodes=> 
y child nodes=> 

 diagram:
                    a
               /    |     \ 
              b     e      r
             /\     /\     /\
            s  t    u v    x  y
               /\           
               w r



  """
#Time complexity: O(n)          ->number of nodes
#Space complexity: O(n)         ->number of nodes



