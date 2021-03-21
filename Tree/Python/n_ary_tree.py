#Ques: Create a general (N-ary) tree 
#Language: Python

#Firstly, class treenode is defined with several inner functions including "__init__" for creating tree node with chils as list and #intitially storing 'None' as address of parent, "add_child" add data in child list, there is a helping function named "get_level" as #well to get the level of a child node while printing its value and finally "print_tree" function prints tree with according to its #level .

#And function "build_tree" creats the whole tree using class "TreeNode"



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
        prefix = spaces + "|__" if self.parent else ""
        print(prefix + self.data)
        if self.child:
            for child in self.child:
                child.print_tree()

def build_tree():
    root = TreeNode("Electronics")

    laptop = TreeNode("Laptop")
    laptop.add_child(TreeNode("Mac"))
    laptop.add_child(TreeNode("Surface"))
    laptop.add_child(TreeNode("Thinkpad"))

    cellphone = TreeNode("Cell Phone")
    cellphone.add_child(TreeNode("iPhone"))
    cellphone.add_child(TreeNode("Google Pixel"))
    cellphone.add_child(TreeNode("Vivo"))

    tv = TreeNode("TV")
    tv.add_child(TreeNode("Samsung"))
    tv.add_child(TreeNode("LG"))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(tv)
    return root

if __name__=="__main__":
    root=build_tree()
    root.print_tree()

#Output you will recieve: Electronics
#           |__Laptop
#               |__Mac
#               |__Surface
#               |__Thinkpad
#           |__Cell Phone
#               |__iPhone
#               |__Google Pixel
#               |__Vivo
#           |__TV
#               |__Samsung
#               |__LG
