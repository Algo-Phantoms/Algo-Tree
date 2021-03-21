#Ques: Check weather a string is a palindrome or not by the help of doubly linked list
#language: Python 3

#input: Enter a string: s         // here user will provide a string 
#output: True or False          //check wheather a string palindrome or not

#firstly, we will create a doubly linked list in which data part contains each character of the string
#then in "isPalindrom" function in "doubly_linked_list" class we will use head and tail iterator of doubly linked list and will compare each data part and retuens True or False accordingly.

class Node(object):          # Create Single linked node everytime
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class doubly_linked_list(object):
    def __init__(self):           #sets defalut value as None at iterators and 0 at data part
        self.head = None
        self.tail = None
        self.count = 0

    def append_item(self, data):
        # Append an item
        new_item = Node(data, None, None)
        if self.head is None:
            self.head = new_item
            self.tail = self.head
        else:
            new_item.prev = self.tail
            self.tail.next = new_item
            self.tail = new_item
        self.count += 1

    def iter(self):
        # Iterate the list
        current = self.head
        while current:
            item_val = current.data
            current = current.next
            yield item_val

    def print_foward(self):    #prints dll
        for node in self.iter():
            print(node,end=" ")

    def isPalindrom(self):     #palindrome checker function
        temp=self.head
        end=self.tail

        while temp!=None:
            if temp.data!=end.data:
                return False
            temp=temp.next
            end=end.prev

        return True



if __name__=="__main__":
    s=input('Enter string: ')

    items = doubly_linked_list()
    for i in s:
        items.append_item(i)
    print(items.isPalindrom())
    #items.print_foward()
