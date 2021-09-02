#Implemented By Kumar Ankit in Python3

#Tim Sort
#It is a Sorting Algorithm Based on Insertion Sort and Merge Sort
#Time Complexity = O(NlogN)
#Used in in-built functions of Java's Arrays.sort(), Python's sorted() and sort()
#How it Works? : Firstly we aim to use Insertion sort and sort small pieces and then using merge sort, we merge them
#Whole array is divided into small blocks called Run
#We then sort these Runs using Insertion Sort and then we combine them using the combine function of merge sort
#Now, if the size of Array is less than Run, we just use Insertion sort
#The size of Run can be from 32 to 64


#How to Implement?
#Firstly we assume that the size of Run is 32
#Then we sort all of them with size equal to Run
#Then we mwege them and double the size of subarray after every iteration


MIN_RUN_SIZE = 32 #declared min run size
 
#This function returns the minimum length of Run such that the length of array is less than or equal to a power of 2
def calcMinRun(length):
    ans=0
    while length>=MIN_RUN_SIZE:
        ans |= length&1
        length>>=1
    return length+ans
 

#Insertion Sort Function
def insertionSort(givenArr, leftpoint, rightpoint):
    for x in range(leftpoint+1, rightpoint+1):
        y=x
        while y>leftpoint and givenArr[y]<givenArr[y-1]:
            givenArr[y],givenArr[y-1] = givenArr[y-1],givenArr[y] #swapping
            y-=1
 
 
#Merge function of merge sort
def merge(givenArr, leftpart, middle, rightpart):
    length1 = middle-leftpart+1
    length2 = rightpart-middle
    leftArray, rightArray = [], [] #breaking the array in two parts
    for i in range(0, length1):
        leftArray.append(givenArr[leftpart+i])
    for i in range(0, length2):
        rightArray.append(givenArr[middle+1+i])
    
    #Merging
    i=0
    j=0
    k=leftpart
    while i<length1 and j<length2:
        if leftArray[i]<=rightArray[j]:
            givenArr[k]=leftpart[i]
            i+=1
        else:
            givenArr[k]=rightpart[j]
            j+=1
        k+=1
 
    #Now if any element remains in LeftArray, copying them
    while i<length1:
        givenArr[k]=leftArray[i]
        k+=1
        i+=1
    #Now if any element remains in RightArray, copying them
    while j<length2:
        givenArr[k]=rightArray[j]
        k+=1
        j+=1
 
 
#Implementing Iterative TimSort
def Tim_Sort(givenArr):
    lengthArr = len(givenArr)
    minimumRun = calcMinRun(lengthArr)
     
    #Sorting each subarray whose size is equal to Run
    for startindex in range(0, lengthArr, minimumRun):
        endindex = min(startindex+minimumRun-1, lengthArr-1)
        insertionSort(givenArr, startindex, endindex)
 
    #Merging and doubling the size
    size=minimumRun
    while size<lengthArr:
        #Meging givenArr[left ... left+size-1] and givenArr[left+size ... left+2*size-1] separately
        #Size is doubled 
        for left in range(0, lengthArr, 2*size):
            mid = min(lengthArr-1, left+size-1) #mid point of array
            right = min(left+2*size-1,lengthArr-1) 
            #Merging subarrays givenArr[left ... mid] and givenArr[mid+1 ... right]
            if mid<right:
                merge(givenAarr, left, mid, right)
        size=2*size #Size is doubled
 
 
#Main Function
if __name__ == "__main__":
    #Can also take userinput here
    arrayElements = [-8, 17, 5, -4, 10, 1, 0, 6, -7, -4, -13, 35, 50, -44, 23]
    #Printing the given array
    print("Given Array is")
    print(arrayElements)
 
    #Calling the timSort function
    Tim_Sort(arrayElements)
 
    #Printing the array after sorting
    print("After Sorting Array is")
    print(arrayElements)