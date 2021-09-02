#Ques: Creating heap class.
#language: Python3

#Creating min and max heap using list

#input: Enter 1 for max-heap 2 for min-heap:            --->type 1 for max heap or 2 for min heap
#1)To insert data                                       ---->then user will be asked with diffrent option and has to choice from them  in few cases output will be printed
#2)To remove data from end
#3)To get the top element
#4)To print heap
#5)To end process


class heap:
    def __init__(self):
        self.arr=[]

    def insert_value(self,data):
        self.arr.append(data)
        arrange(self.arr,len(self)-1)

    def insert_value_again(self,data):
        self.arr.append(data)
        arrange_again(self.arr,len(self)-1)

    def print_heap(self):
        l=len(self.arr)
        for i in range(l):
            print(self.arr[i],end=" ")

    def __len__(self):
        return len(self.arr)

    def peek(self):
        if self.arr.__len__()==0:
            print('Heap is empty!')
            return
        else:
            return self.arr[0]
    def pop(self):
        if self.arr.__len__()==0:
            print('Heap is empty!')
            return
        else:
            self.arr.pop()
            return self.arr


def swap(heap,i,j):
    (heap[i],heap[j])=(heap[j],heap[i])

def arrange(heap,ind):
    for i in range(ind):
        if heap[i]<heap[ind]:
            swap(heap,i,ind)

def arrange_again(heap,ind):
    for i in range(ind):
        if heap[i]>heap[ind]:
            swap(heap,i,ind)


if __name__=="__main__":

    hp=heap()
    hp1=heap()
    x=int(input('Enter 1 for max-heap 2 for min-heap:'))
    if x==1:
        while(1):
            run = int(input('\n1)To insert data\n2)To remove data from end\n3)To get the top element\n4)To print heap\n5)To end process\n'))
            if run==1:
                d=int(input('Data:'))
                hp.insert_value(d)
            elif run==2:
                hp.pop()
            elif run==3:
                print(hp.peek())
            elif run==4:
                hp.print_heap()
            else:
                break
    else:
        while (1):
            run = int(input('\n1)To insert data\n2)To remove data from end\n3)To get the top element\n4)To print heap\n5)To end process\n'))
            if run == 1:
                d = int(input('Data:'))
                hp1.insert_value_again(d)
            elif run == 2:
                hp1.pop()
            elif run == 3:
                print(hp1.peek())
            elif run == 4:
                hp1.print_heap()
            else:
                break

#Time complexity in inserting data: O(logn)         ---->where n is size of heap
#Time complexity in poping data: O(1)
#Time complexity in printing data: O(n)                 ---->where n is size of heap
#Time complexity in finding top element: O(1)
#Space complexity: O(1)
"""
input: 
Enter 1 for max-heap 2 for min-heap:1

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:12

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:3

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:5

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
4
12 5 3 2 
1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
3
12

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
4
12 5 3 
1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
5

input:
Enter 1 for max-heap 2 for min-heap:2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:-2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:0

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:4

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
1
Data:3

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
4
-2 0 2 3 4 
1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
3
-2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
2

1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
4
-2 0 2 3 
1)To insert data
2)To remove data from end
3)To get the top element
4)To print heap
5)To end process
5


"""


