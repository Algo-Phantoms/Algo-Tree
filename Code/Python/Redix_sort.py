# function for radix sort
def radixsort(MyList):
  n = len(MyList)
  max = MyList[0]
  
  #find largest element in the Array
  for i in MyList:
    if max < i:
      max = i
  
  #Counting sort is performed based on place. 
  #like ones place, tens place and so on.
  place = 1
  while max/place > 0:
    countingsort(MyList, place)
    place *= 10  

def countingsort(MyList, place):
  n = len(MyList)
  output = [0 for i in range(0,n)]
  
  #range of the number is 0-9 for each place considered.
  freq = [0 for i in range(0,10)]
  
  #count number of occurrences in freq array
  for i in range(0,n):
    freq[(MyList[i]//place)%10] += 1
  
  #Change count[i] so that count[i] now contains actual 
  #position of this digit in output[] 
  for i in range(1,10):
    freq[i] += freq[i - 1]      
  
  #Build the output array 
  for i in range(n-1,-1,-1):
    output[freq[(MyList[i]//place)%10] - 1] = MyList[i] 
    freq[(MyList[i]//place)%10] -= 1
  
  #Copy the output array to the input Array, Now the Array will 
  #contain sorted array based on digit at specified place
  for i in range(0,n): 
    MyList[i] = output[i]   

#print a list
def PrintList(MyList):
  for i in MyList:
    print(i, end=" ")
  print("\n") 
  
# test the code                 
MyList = [101, 1, 20, 50, 9, 98, 27, 153, 35, 899]
print("Original List")
PrintList(MyList)

radixsort(MyList)
print("Sorted List")
PrintList(MyList)