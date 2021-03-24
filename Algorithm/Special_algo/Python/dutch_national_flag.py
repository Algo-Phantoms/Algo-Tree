'''
  In this sorting algorithms we sort 0's, 1's and 2's
  with using any sorting algorithms.
  Time Complexity O(n)
  Space complexity O(1)
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

lst=[2,2,2,1,2,2,2,1,1,1,0,2,0,1]

#calling the function
sort_lst=dutch_nat_algo(lst)

#print sorting list
print(sort_lst)

'''
test case-1
        lst=[0,1,2,2,1,1,2,0,1,2]
        Sort List:
        lst=[0,0,1,1,1,1,2,2,2,2]

test case-2
        lst=[2,2,2,2,1,1,1,1,0,0,0]
        Sort List
        lst=[0,0,0,1,1,1,1,2,2,2,2]
'''