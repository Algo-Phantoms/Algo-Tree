
class Node: # Node class
    def __init__(self,data):        
        self.data = data
        self.ptr = None
         
def is_palindromedrome(head): # Function to check if the linked list is palindrome or not
     
    p_element = head #Temporary pointer
    temp_stack = [] # Declare a temporary stack
     
    is_palindrome = True
 
    while p_element != None: # Push all elements of the list in temp_stack
        temp_stack.append(p_element.data)
        p_element = p_element.ptr
  
    while head != None:  # Iterate in the list to check by popping from the temp_stack
       
        i = temp_stack.pop() # Get the top most element
    
        if head.data == i: # Check if data is not same as popped element
            is_palindrome = True
        else:
            is_palindrome = False
            break
 
        head = head.ptr
         
    return is_palindrome
 
i,l = input("Input the number of node: "),[] #Input the number of nodes or values in list 

for _ in range(1,i+1): #Input values and assigning them to nodes
  temp_1= input("Enter value for node no "+_+" : ")
  temp_2 = Node(temp_1)
  l.append(temp_2)
  if _ > 1:
     l.append(temp_1)

for _ in range(0, i): # Initialize the next pointer of every current pointer
   if _ != i-1:
      l[_].ptr = l[_+1]
   else:
       l[_].ptr = None

print("is_palindromedrome:", is_palindromedrome(l[0]))
