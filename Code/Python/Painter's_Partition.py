"""

Problem statement: User need to return the Minimum time taken by k painters  to paint the given number of  boards under the condition that each painter can paint continous 
    section of boards and each painter take 1 unit of time to paint 1 unit of board

Solution: This Problem could be solved using binary search in which
          Search Space would be betwween maximum size of the borad and sum of all the board size
          start will be initialised as maximum size of the board
          end will be initialised as sum of all  the board size
          mid would be calculated as (start+end)/2.
          Using painterhelp function we would find the number of painters needed to paint (mid) number of boards
          If painters needed to paint 'mid' number of boards is greater than k then we would  make search space to be between mid and end
          If painters needed to paint 'mid' number of boards is less than k then we would  make search space to be between   start and mid
          Maximum unit painted by the painter would then be multiplied by time given to get the minimum answer

"""

def painterhelp(board,total,b):
    temp = 0
    currentpainters = 1

    for i in range(0,b): 
        temp += board[i] 

        if (temp > total):
            temp = board[i]
            currentpainters += 1

    return currentpainters #painters required to paint (total) unit of boards

def painterdivide(board,p,b):   
    maxi=0;
    total=0;  
    for i in range(0, b):
        if board[i]> maxi :
            maxi=board[i]
        total+=board[i]
    start=maxi #Start intialised as the maximum size of the board
    end=total # end initialised as sum of all the size of the boards

    while(start<end):
        mid=int((start+end)/2)
        painterneeded = painterhelp(board, mid, b) #return total number of painter required to paint (mid) units of board
        if (painterneeded > p): 
            start = mid+1 
        else:
            end=mid
    return start #Maximum units of the board that could be painted by each painter

b = int(input("Enter number of boards : ")) #Taking how many boards to be painted as the input
p= int(input("Enter number of painters available : ")) #Taking input Number of painters 
t= int(input("Enter the time taken by each painter: ")) #Taking input time taken by each painter
print("Enter the size of each board : ")
board = [] #Intialise board array with empty list
for i in range(0, b): 
    ele = int(input()) 
    
    board.append(ele) # Input the size of the boards
answer = painterdivide(board, p, b)
answer*=t; #Minimum time to paint all the boards
print(answer)



"""

TestCaes
Input-1
 2 2 5
 1 10
Output-1
 50

Input-2
 9 3 5
 1 2 3 4 5 6 7 8 9
Output-1
 85
 
Time Complexity  : O(N*log(sum(boards))
Space Complexity : O(1)

"""
