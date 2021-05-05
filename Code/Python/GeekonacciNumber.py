'''
Description : 
        Geek created a random series and given a name geek-onacci series. Given four 
        integers x, y, z, N. x, y, z represents the first three numbers of geek-onacci series. 
        Find the Nth number of the series. The nth number of geek-onacci series is a sum of the 
        last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers).
'''


# Python Code ->
 
# calculating N-th Geekonacci Number

def Search(x, y, z, n) :
   
    # Stores the value

    List = [0] * n
 
    # First three values

    List[0] = x
    List[1] = y
    List[2] = z
 
    # Loop to move

    for i in range(3, n):
 
        # Updation of the values
        List[i] = (List[i - 1] + Listi - 2] + List[i - 3])
     
    # Return the last element 
    return List[n - 1]


# main code
x,y,z,n = int(input().split) 

print(Search(x, y, z, n))


'''
Time complexity : O(log N)  # N refers to total inputs in array
Space complexity : O(1)



Test Case 1 :

Input :  
 1 3 2 4

Output : 
 6

Test Case 2 :

Input :
 1 3 2 6

Output :
 19

Test Case 3 :

Input :  
 1 3 2 5

Output : 
 11

'''
