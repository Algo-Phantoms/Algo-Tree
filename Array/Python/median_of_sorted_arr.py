#Ques:  Find median of two sorted arrays of different sizes.
#Language: Python3

#First of all we will merge two provided arrays and then we will have the middle most element from resultent array as provided arrays are sorted so each we will compare elements from both array and will put minimum amoung them in resultent array

#input:             ---->first size of first array
#                   ---->in next line user will provide space seperated integers
#                       --->then size of second array
#                                     --->at last space seperated integers for second array
#output:             ----->first line would contain median of resultant array
#                       ---->last line will give us resultant space seperated resultant array

def merge_array(arr1,arr2):
    i=0
    j=0
    n=len(arr1)
    m=len(arr2)
    res=[]
    while(i<n and j<m):
        if arr1[i]<arr2[j]:
            res.append(arr1[i])
            i+=1
        elif arr2[j]<arr1[i]:
            res.append(arr2[j])
            j+=1
        elif arr2[j]==arr1[i]:
            res.append(arr2[j])
            j+=1
            i+=1
    while i<n:
        res.append(arr1[i])
        i+=1
    while j<m:
        res.append(arr2[j])
        j+=1
    return res

if __name__=="__main__":
    n=int(input())

    arr1=list(map(int, input("Enter the list numbers separated by space ").strip().split()))[:n]
    m = int(input())
    arr2=list(map(int, input("Enter the list numbers separated by space ").strip().split()))[:m]
    ans=merge_array(arr1,arr2)
    x=len(ans)
    print("Median of array after merging these two arrays: ",end="")
    print(ans[x//2])
    for i in range(len(ans)):
        print(ans[i],end=" ")

#Time Complexity: O(m + n)                  ----->To merge both the arrays O(m+n) time is needed
#Space Complexity: O(1)                         ------>No extra space is required

#e.g-1
#5
#Enter the list numbers separated by space -5 3 6 12 15
#1
#Enter the list numbers separated by space -12
#Median of array after merging these two arrays: 6
#-12 -5 3 6 12 15
#e.g-2
#5
#Enter the list numbers separated by space -5 3 6 12 15
#6
#Enter the list numbers separated by space -12 -10 -6 -3 4 10
#Median of array after merging these two arrays: 3
#-12 -10 -6 -5 -3 3 4 6 10 12 15