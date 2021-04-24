"""
Problem statement: Given an integer,we have to find its square root.

If the given number is not a perfect square then we have to find floor(squareroot(x))
"""

#solution:


def squareroot(n):
    

    if n==0  or n==1: #if  entered number is 1 or 0  then square root is number itself .So return the entered number .
        return n
# if entered number is not 1 or 0 then perform binary search operation to find squareroot

    low=1
    high=n
    result=-1
    while(low<=high):
        middle=(low+high)//2
        square=middle*middle
        
        if(square==n): # if entered number is a perfect square then return middle value 
            return middle
# if entered number is greater than square value(middle*middle) then we will assign we will search from middle+1 to high and assign middle value to result
        elif (square<n):
            low=middle+1
            result=middle
#if entered number is less than square value(middle*middle) then we will search from low to middle-1
        else:
            high=middle-1

    return result
n=int(input("enter a number :"))
print(squareroot(n))

"""
Time complexity:O(logn)
space complexity: O(1)


Example 1:
    Enter a number: 8
    Output:
    2
    Explanation: Entered number is not 0 or 1 so perform binary search operation.
    i.low=1,high=8 then middle=(low+high)//2 that is middle= (1+8)//2 i.e middle=4; square=(middle*middle)=16
     square>n(16>8) so high=middle-1=4-1 that is high=3

    ii.Now low=1,high=3 then middle=(low+high)//2 then middle=2 ;square=(middle*middle)=4;square<n (4<8)
      so low=middle+1=3 and high=3 and store result value as middle value i.e "2"
    
    iii.Now low=3,high=3 then middle=3 square=(3*3)=9 ;square>n(9>8) then high=middle-1=3-1 that is high=2

    iv.now low=3 and high=2 ,while loop terminates and result value(2)is returned.



Example 2:
    enter a number: 9
    Output:
    3
                                   
       

"""
