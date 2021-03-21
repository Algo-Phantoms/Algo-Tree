#Ques: Check weather it is possible to get sum from root node to a leaf node
#language: python


class new_node:                                 #this creates node having data and right and left with default value None
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

#def insert(root,data):
 #   if root==None:
  #      return new_node(data)
   # else:
    #    if root.data==data:
     #       return root
      #  elif root.data>data:
       #     root.right=insert(root.right,data)
        #elif data>root.data:
         #   root.left=insert(root.left,data)

    #return root


def inorder(root):
    if root:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)

#this function check weather given sum possible or not from root to any leaf node
def path_sum(root,sum):
    if root==None:
        if sum==0:
            return True
        else:
            return False
    else:
        res=0
        rem=sum-root.data

        if(rem==0 and root.left==None and root.right==None):
            return True
        if(root.left!=None):
            res= res or path_sum(root.left,rem)
        if(root.right!=None):
            res= res or path_sum(root.right,rem)
        return res


if __name__=='__main__':
    root=new_node(11)
    root.left=new_node(12)
    root.right=new_node(21)
    root.left.right=new_node(5)
    root.left.left=new_node(30)
    root.right.right = new_node(15)
    root.right.left = new_node(3)
    sum=47
    print(path_sum(root,sum))
    
#output: True