'''
  In this sorting algorithms we sort 0's, 1's and 2's
  with using any sorting algorithms.
  Time Complexity O(n)
  Space complexity O(1)

   Sample Inputs
    lst=[0,1,2,2,1,1,2,0,1,2]
    lst=[2,2,2,2,1,1,1,1,0,0,0]
'''


#Function to Sort array
def dutch_nat_algo(lst):
    low=0
    high=len(lst)-1
    mid=0
    while mid<=high:
        if lst[mid]==0:
            lst[low],lst[mid]=lst[mid],lst[low]
            low=low+1
            mid=mid+1
        elif lst[mid]==1:
            mid=mid+1
        else:
            lst[high],lst[mid]=lst[mid],lst[high]
            high=high-1
    return lst

#user input

n=int(input("How many element you want Enter"))
lst=[]
for i in range(n):
  lst.append(int(input())

#calling the function
sort_lst=dutch_nat_algo(lst)

#print sorting list
print(sort_lst)

             
'''
      time complexity 0(n)
      space complexity 0(1)


  Sample Output
  
  test case-1
        
        Sort List:
        lst=[0,0,1,1,1,1,2,2,2,2]

  test case-2
        
        Sort List
        lst=[0,0,0,1,1,1,1,2,2,2,2]
'''
