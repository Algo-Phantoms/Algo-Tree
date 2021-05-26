/*   Rearranged negative and positive array elements alternatively  */

/* CODE IN PYTHON */

a=[]
n=int(input("Enter array size and elements=\n"))
for i in range(0,n):
   m = int(input())
   a.append(m)


for i in range(0,n):
      if (i%2==0):
           if(a[i]>=0):
             for j in range(i+1,n):
                 if(a[j]<0):
                     x=a[j]
                     a[j]=a[i]
                     a[i]=x
      else:
           if(a[i]<0):
             for j in range(i+1,n):
                 if(a[j]>=0):
                     x=a[j]
                     a[j]=a[i]
                     a[i]=x

print("Final array elements=\n")
print(a)


/* TEST CASES

1.   INPUT:   6
              1 2 -3 -4 -1 4


    OUTPUT:    Final array elements=
              [-1, 2, -4, 1, -3, 4]


2.   INPUT:    5
               0 1 -1 -2 -2


     OUTPUT:   Final array elements=
               [-2, 1, -2, 0, -1]
*/

/*  TIME AND SPACE COMPLEXITY

    TIME : 0(n*log n)
     SPACE: O(1)
 */
