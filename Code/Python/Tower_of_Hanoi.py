''' Tower of Hanoi is a very famous mathematical problem. 
You will have three rods and n disks. 
Initially all the n disks are stacked on one rod. You will have one source rod, one helper rod and one destination rod.
The task is to take all those disks from one rod to some other rod following these rules:
     1) We can only one disk can be moved at a time.
     2) There can be no disk mounted on top of a smaller disk.
     3) A disk can be moved only if it is the stack's uppermost disk.

       |           |           |                   |           |           |       
      -|-          |           |                   |           |          -|-      
     --|--         |           |       ---->       |           |         --|--     
    ---|---        |           |                   |           |        ---|---    
   =========   =========   =========           =========   =========   =========   
      A		   B		C		   A	       B	   C

 Program will print the source and destination to transfer each disks for all the steps in chronological order.'''

# This function takes the number of disks and the names of the rods.
#	The idea is to shift one disk from the source to the destination but
#	if there is already mutiple disk on the source then call the same function to put the extra disk on the helper rod and
#	if there is already mutiple disk on the destination then call the same function to put the extra disk on the helper rod. 
 
def Tower_of_Hanoi(n,src,dest,help):

    if(n==0): # defining the base case of the function
        return

    Tower_of_Hanoi(n-1,src,help,dest) # recursively calling the function
    # moving disk from source to helper rod

    print(f"Move from {src} to {dest}")

    Tower_of_Hanoi(n-1,help,dest,src) #moving disk from helper to destination rod

#Driver code of the function
if __name__=='__main__':

    n=int(input("Enter number of rods: "))  # taking the number of rods from the user

    Tower_of_Hanoi(n,'A','B','C')
    # A B C are the name of rods

''' 
TESTCASES:

Sample Input :
   Enter number of rods: 3

Sample Output:
  Move from A to B
  Move from A to C
  Move from B to C
  Move from A to B
  Move from C to A
  Move from C to B
  Move from A to B 



Sample Input:
   Enter number of rods: 2

Sample Output:
   Move from A to C
   Move from A to B
   Move from A to C

   Time Complexity : O(2^n)
   Space Complexity : O(n)
'''
