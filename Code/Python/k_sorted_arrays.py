"""
    Input: arr which is a list consisting of k lists which are sorted
    Output: a sorted output array
    Time Complexity: O(Nlogk)
    Space Complexity: O(K)
    Data Structure used: min heap
    Library used: none :), everything is implemented from scratch
"""
class Heap:
    def __init__(self):    
        self.n=0
        self.arr=[]



    #O(logn)
    def heapify(self,i):
        if self.n==0:
            return
        parent=self.arr[i][0]
        if (2*i+2)<self.n:        
            left_child=self.arr[2*i+1][0]
            right_child=self.arr[2*i+2][0]

            min_child_index=-1
            if right_child<left_child:
                #max child is left
                min_child_index=2*i+2
            else:
                #max child is right
                min_child_index=2*i+1

        elif (2*i+1)<self.n:
            min_child_index=2*i+1
        else:
            return

        if parent>self.arr[min_child_index][0]:
            #swap
            self.arr[i],self.arr[min_child_index]=self.arr[min_child_index],self.arr[i]
            #call heapify on the child with which value has been swapped
            self.heapify(min_child_index)

        return


    #O(logn)
    def heap_update_parent(self,i):
        if i<=0:
            return

        parent=(i-1)//2

        if self.arr[parent][0]>self.arr[i][0]:
            #swap
            self.arr[parent],self.arr[i]=self.arr[i],self.arr[parent]
            self.heap_update_parent(parent)
        return


    #insert elements into heap
    def heap_insert(self,val,info):        
        self.arr.append((val,info))
        self.n+=1
        self.heap_update_parent(self.n-1)


    #extract and delete minimum element from the heap
    def heap_pop(self):
        if self.n==0:            
            return "heap is empty"

        min_val=self.arr[0]
        #swap first element with last
        self.arr[0],self.arr[-1]=self.arr[-1],self.arr[0]

        #delete the element
        self.arr.pop()
        self.n-=1

        #heapify
        self.heapify(0)

        return min_val

    #karr = k array
    def merge_k_sorted_arrays(self,karr):
        
        k=len(karr)
        #maximum length of each array
        max_len=[len(arr) for arr in karr]
        #total number of numbers = length of sorted array after merging
        total_num=sum(max_len)
        #an array with pointer to next smallest element
        next_smallest_index=[1 for i in range(k)]
        #add first elements of all the arrays to the heap
        for idx,arr in enumerate(karr):
            val=arr[0]
            self.heap_insert(val,idx)
        sorted_list=[]
        for i in range(total_num):
            popped_value=self.heap_pop()
            min_val = popped_value[0]
            idx = popped_value[1] 
            #print(min_val,idx,heap.arr)           
            sorted_list.append(min_val)
            nsi=next_smallest_index[idx]
            if nsi<max_len[idx]:
                self.heap_insert(karr[idx][nsi],idx)
                next_smallest_index[idx]+=1
        return sorted_list





#Input1
heap=Heap()
karr=[[1,4,6],[2,5,7],[8,9],[0,3]]
sorted_arr=heap.merge_k_sorted_arrays(karr)
print(sorted_arr)

#Input2
heap=Heap()
karr=[[21,42,60],[2,51,70],[80,90],[0,13]]
sorted_arr=heap.merge_k_sorted_arrays(karr)
print(sorted_arr)

