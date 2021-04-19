#Ques: Check weather it is possible to get sum from root node to a leaf node
#language: Python

#We have given binary tree and a sum we need to check weather if the tree has a root-to-leaf path such that adding up all the values along
# the path equals the given number "sum". Return false if no such path can be found. So, Recursively check if left or right child has 
# path sum equal to ( sum – value at current node)


class Tree:
    def __init__(self,data):
        self.right=None
        self.left=None
        self.data=data

    def insert_node(self,data):
        if self.data:
            if data<self.data:
                if self.left:
                    self.left.insert_node(data)
                else:
                    self.left=Tree(data)
            if data>self.data:
                if self.right:
                    self.right.insert_node(data)
                else:
                    self.right=Tree(data)
        else:
            self.data=data

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data, end=" ")
        if self.right:
            self.right.print_tree()

    #this function check weather given sum possible or not from root to any leaf node
    def path_sum(self,sum):
        if self==None:
            if sum==0:
                return True
            else:
                return False
        else:
            res=0
            rem=sum-self.data

            if(rem==0 and self.left==None and self.right==None):
                return True
            if(self.left!=None):
                res= res or self.left.path_sum(rem)
            if(self.right!=None):
                res= res or self.right.path_sum(rem)
            return res


if __name__=='__main__':
    n=int(input('Enter number of nodes: '))
    x=int(input('Root data: '))
    N=Tree(x)
    for i in range(n-1):
        x=int(input('data: '))
        N.insert_node(x)
    N.print_tree()
    sum=int(input('\nEnter sum you want to check: '))
    ans=N.path_sum(sum)
    if ans:
        print("Yes, it is possible!")
    else:
        print("Not possible!")

#Time Complexity: O(n)
#Space Complexity: O(n*logn)

#e.g- 1)
#Enter number of nodes: 5
#Root data: 12
#data: 3
#data: 1
#data: 6
#data: 7
#1 3 6 7 12
#Enter sum you want to check: 11
#Not possible!

#e.g- 2)
#Enter number of nodes: 6
#Root data: 12
#data: 34
#data: 11
#data: 5
#data: 8
#data: 10
#5 8 10 11 12 34
#Enter sum you want to check: 46
#Yes, it is possible!
