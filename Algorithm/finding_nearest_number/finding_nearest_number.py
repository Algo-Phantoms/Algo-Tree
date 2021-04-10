#PROBLEM STATEMENT :TO FIND NEAREST NUMBER IN AN ARRAY.

#storing user inputted array in a list using map  
r = list(map(int,input("\nEnter the array : ").split()))
p = list(map(int,input("\nEnter the element : ").split()))
s=p[0]
#added p in r
r.extend(p)
#arranged whole list in ascending order using sort 
r.sort()
# removed duplicates from the list
a = []
for i in r:
    if i not in a:
        a.append(i)
#calculated length of final list         
n=len(a)
#loop for calculating nearest number from the list 
for i in range(0,n,1):
    if(a[i]==s):
        if(a[i]==a[0]):
            print(a[1])
        elif(a[i]==a[n-1]):
            print(a[n-2])
        else:
            c=a[i-1]
            d=a[i+1]
           
            e=d-s
            f=s-c
#printing the nearest number from the list            
            if(abs(e)<abs(f)):
                print(d)
            elif(abs(e)==abs(f)):
                print(c)
                print(d)
            else:
                print(c)

#SAMPLE TEST CASES:
                
#sample test cases 1 :

#Enter the array : 2 4 5 6

#Enter the element : 1
#2

#sample test cases 2 :

#Enter the array : 1 2 4 5

#Enter the element : 6
#5                

#sample test cases 1 :
#Enter the array : 1 2 5 6

#Enter the element : 4
#5                
   
