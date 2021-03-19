#Ques: Creating General (N-ary) tree in python

# Firstly, class Treenode is defined to create node everytime with child as empty list
#in the same class Treenode , inner function add_child is defined to store data in child 
# and get_level is a helping function for printing n-ary tree
# finally, print_tree to print tree according to the level on which a particuler data is present


class TreeNode:
    def __init__(self,data):
        self.data = data
        self.child = []
        self.parent = None

    def add_child(self,obj):
        obj.parent=self
        self.child.append(obj)

    def get_level(self):
        lev=0
        p=self.parent
        while p!=None:
            lev+=1
            p=p.parent

        return lev

    def print_tree(self):
        spaces = ' ' * self.get_level() * 3
        prefix = spaces + "==>" if self.parent else ""
       
        print(prefix+self.data)
        if self.child:
            for child in self.child:
               
                child.print_tree()
                

def build_tree():       #this function creates whole tree
    root = TreeNode("Books")      #root node of tree

    math = TreeNode("Maths")     #child-1 of root node
    math.add_child(TreeNode("Algebra")) #child-1-1 of child-1
    math.add_child(TreeNode("Permutation")) #child-1-2 of child-1
    math.add_child(TreeNode("Calculas")) #child-1-3 of child-1

    english = TreeNode("English")      #child-2 of root node
    english.add_child(TreeNode("literature")) #child-2-1 of child-2
    english.add_child(TreeNode("HoneyComb")) #child-2-2 of child-2
    english.add_child(TreeNode("Main Course")) #child-2-3 of child-2

    sci = TreeNode("Science")     #child-3 of root node
    sci.add_child(TreeNode("Physics"))  #child-3-1 of child-3
    sci.add_child(TreeNode("Chemistry")) #child-3-2 of child-3
    sci.add_child(TreeNode("Biology")) #child-3-3 of child-3
    
    hindi = TreeNode("Hindi")     #child-4 of root node
    hindi.add_child(TreeNode("hindi-litrature")) #child-4-1 of child-4
    hindi.add_child(TreeNode("hindi-Main course")) #child-4-1 of child-4

    root.add_child(math)
    root.add_child(english)
    root.add_child(sci)
    root.add_child(hindi)
    return root

if __name__=="__main__":
    root=build_tree()
    root.print_tree()

