#Ques: Find minimum number of merge operations required to make array palindrome
#Language: Python 3

#Basically, we are comparing array elements from both ends if they are equal then decrementing and incrementing both indexs otherwise we will merge elements of array which is minimum
#input:                         ----->(n) size of array
#                                       ---->in next input line user have to provide space seperated integers

#ouput:                                 ---> will provide minimum numbers of merge operations to make array palindrome

def isPalindrom(arr,n):
    i=0
    j=n-1
    while i<j:
        if arr[i]!=arr[j]:
            return False
        i+=1
        j-=1
    return True

def merge_op(arr,n):
    i=0
    j=n-1
    res=0
    while i<=j:
        if arr[i]==arr[j]:
            i+=1
            j-=1
        elif arr[i]<arr[j]:
            i+=1
            arr[i]+=arr[i+1]
            res+=1
        else:
            j-=1
            arr[j]+=arr[j-1]
            res+=1
    return res

if __name__=="__main__":
    n=int(input('Enter size of array: '))
    arr=list(map(int,input().strip().split(' ')))[:n]

    print('Minimum merge operations to make this array palindrome: ',end="")
    print(merge_op(arr, n))

#Time complexity:O(n)
#Test case-1:
#Enter size of array: 4
#1 4 5 1
#Minimum merge operations to make this array palindrome: 1

#Test case-2:
#Enter size of array: 4
#1 2 2 1
#Minimum merge operations to make this array palindrome: 0
