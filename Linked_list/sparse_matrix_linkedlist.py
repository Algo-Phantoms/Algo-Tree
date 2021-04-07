'''
Program for Sparse Matrix Representation using Linked List
'''


# Node Class
class Node:
    __slots__ = "row", "col", "data", "next"

    def __init__(self, row=0, col=0, data=0, next=None):
        self.row = row
        self.col = col
        self.data = data
        self.next = next


# Class to convert Sparse Matrix into Linked List
class sparse:

    # Initializing Class Variables
    def __init__(self):
        self.head = None
        self.temp = None
        self.size = 0

    # Function which returns the size of the Linked List
    def __len__(self):
        return self.size

    # Checking if  the Linked List is Empty or not
    def ifempty(self):
        return self.size == 0

    # Function to create Linked List from Sparse Matrix
    def create_new_node(self, row, col, data):

        # New Node
        newnode = Node(row, col, data, None)

        # Checking whether the List is empty or not
        if self.ifempty():
            self.head = newnode
        else:
            self.temp.next = newnode
        self.temp = newnode

        # Incrementing the size
        self.size += 1

    # Function display the contents of the Linked List
    def printlist(self):
        temp = r = s = self.head
        print("Row Position:", end=" ")
        while temp != None:
            print(temp.row, end=" ")
            temp = temp.next
        print()
        print("Column Postion:", end=" ")
        while r != None:
            print(r.col, end=" ")
            r = r.next
        print()
        print("Value:", end=" ")
        while s != None:
            print(s.data, end=" ")
            s = s.next
        print()


# Driver Code
if __name__ == "__main__":

    s = sparse()
    R = int(input("Enter the number of rows:"))
    C = int(input("Enter the number of columns:"))
    sparsematrix = []
    print("Enter the entries row wise:")
    for i in range(R):
        a = []
        for j in range(C):
            a.append(int(input()))
        sparsematrix.append(a)

    for i in range(R):
        for j in range(C):

            # Creating Linked List by only those elements which are non-zero
            if sparsematrix[i][j] != 0:
                s.create_new_node(i, j, sparsematrix[i][j])

    s.printlist()

'''
Enter the number of rows: 2
Enter the number of columns: 3
Enter the entries row wise:
0
0
2
4
0
0
Row Position: 0 1 
Column Postion: 2 0 
Value: 2 4 
'''