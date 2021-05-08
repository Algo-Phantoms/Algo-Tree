"""Ques: Get the minimum element of the stack in O(1)
Language: Python 3

We are creating a global list as stack("stack") and another stack as supporting stack("support_stack"), we are keeping elements in #sorted order in support_stack so that when we need minimum element from stack we can easily return the first elemet of support_stack #stack
Basically, we have created a menu driven program providing various options like inserting element in stack,deleting any element from #stack, getting minimum element and printing elements of stack

input:Wanna create a stack?(y/n)                   ----> enter y to continue process or n to stop
Menu:
0.Quit process
1.Push into stack
2.Delete from stack
3.Print data
4.Get minimum                                          ------>select from these
"""

#Global variables

stack=[]

support_stack=[]
def insert_stk(stk,data):
    stk.append(data)

def remove(data):
    global stack
    global support_stack
    if len(stack)>=1:
        temp=[]
        temp1=[]
        for i in stack:
            if i==data:
                continue
            temp.append(i)
        stack.clear()
        for i in temp:
            insert_stk(stack,i)
        for i in support_stack:
            if i==data:
                continue
            temp1.append(i)
        support_stack.clear()
        for i in temp1:
            insert_stk(support_stack,i)
        return 1
    else:
        return -100000

def result():
    for i in range(len(stack)):
        print(stack[i],end=" ")
    print()
   
def get_min():
    global support_stack
    if len(support_stack)>0:
        return support_stack[0]
    else:
        return -1


if __name__=="__main__":
    flag=1
    t_supp=-1
    t_main=-1
    yon=input('Wanna create a stack?(y/n)')
    if yon=='y':
        while(flag!=0):
            print("Menu:")
            print("0.Quit process")
            print("1.Push into stack")
            print("2.Delete from stack")
            print("3.Print data")
            print("4.Get minimum")
            flag=int(input())
            if flag==1:
                ele=int(input('Enter data: '))
                insert_stk(stack,ele)
                t_main+=1
                if t_supp>=0:
                    f=0
                    for i in range(len(support_stack)):
                        if ele < support_stack[i]:
                            f=1
                            support_stack.insert(i,ele)
                            break
                    t_supp+= 1
                    if f!=1:
                        insert_stk(support_stack,ele)

                elif t_supp==-1:
                    t_supp+=1
                    insert_stk(support_stack,ele)
            elif flag==2:
                d=int(input('Data to be deleted: '))
                y=remove(d)
                if y==-100000:
                    t_main-=1
                    print('Empty stack!')
                else:
                    print('Deleted!!')
            elif flag==3:
                result()
                print()
            elif flag==4:
                ans=get_min()
                if ans!=-1:
                    print("So minimum value inside stack is: ",end="")
                    print(ans)
                else:
                    print("Oops! stack is empty")
    print('Okay bye there!')


#Time comlpexity: O(1) ---->inserting an element
#                 O(1) ---->poping an element ,O(n) for deleting any particuler element where n is number of elements inside stack
#                 O(1)  --->getting minimum element from stack

#Space Complexity : O(n) , where n is number of elements present inside stack

"""e.g
input: Wanna create a stack?(y/n)y
       Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       1
output: Enter data: 11
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       1
output: Enter data: 12
inout: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       1
output: Enter data: 3
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       1
output: Enter data: 5
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       1
output: Enter data: 2
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       3
output: 11 12 3 5 2  
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       2
output: Data to be deleted: 2
        Deleted!!
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       3
output: 11 12 3 5  
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       4
output: So minimum value inside stack is: 3
input: Menu:
       0.Quit process
       1.Push into stack
       2.Delete from stack
       3.Print data
       4.Get minimum
       0
output:Okay bye there!
"""

