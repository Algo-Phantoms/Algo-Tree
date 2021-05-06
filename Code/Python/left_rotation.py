#Ques: Rotate an array of size n , x number of times.
#language : Python
#input: Enter size of array:      ----->user will be asked for no. of elemnts which is to be insert in an array
#       Give data:                ----->now user have to provide space seperated integers
#       Enter the number of times array should be rotated from left:                ----->no. of times user want aray to be rotated from left


#output:         ---->prints spaces seperated integers rotated several times from left


n = int(input('Enter size of array:'))
rot = []
print('Give data: ')
rot=list(map(int,input().split()))

pos = int(input('Enter the number of times array should be rotated from left:'))

for i in range(pos):
    temp = rot[0]
    for j in range(1, n):
        rot[j - 1] = rot[j]
    rot[n-1] = temp

for k in range(0, n):
    print(rot[k],end=" ")
    
#Time Complexity: O(n*k)            size of  array * no. of time array to be rotated
#Space: O(1)                        fixed amount of space is required

#e.g:    
# Enter size of array:7
# Give data: 
# 12 11 3 13 5 6 7 
# Enter the position from where u want left rotation:2
# 3 13 5 6 7 12 11 


# Enter size of array:5
# Give data: 
# 1 2 3 4 5
# Enter the position from where u want left rotation:2
# 3 4 5 1 2
