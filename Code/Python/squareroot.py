"""
Problem statement: Given an integer,we have to find its square root.If the given number is not a perfect square then we have to find floor(squareroot(x)).
At first, take care of basecases that is when number is 0 or 1 .Now Create variables low=1 and upperbound high=n .Run a loop until low<=high.
Check if the square of middle (middle = (low+high)/2 ) is equal to n, If yes then return middle element.If the square of middle (middle = (low+high)/2) 
is less than or equal to n, If yes then search for a larger value in second half of search space,i.e low= middle+1, update result= middle.
Else search for a smaller value in first half of search space, i.e high = middle – 1 . Print the value of result .

"""
def squareroot(n):
    if n==0  or n==1:
        return n
    low=1
    high=n
    result=-1
    while(low<=high):
        middle=(low+high)//2
        square=middle*middle
        if(square==n): 
            return middle
        elif (square<n):
            low=middle+1
            result=middle
        else:
            high=middle-1
    return result
n=int(input("enter a number :"))
print(squareroot(n))

"""
Test case 1: 
    Enter a number: 8
    Output: 2
Test case 2: 
    Enter a number: 9
    Output: 3
  
Time complexity:O(logn) because the time complexity of binary search is O(logn) where n is the input size.
Space complexity: O(1)
"""
