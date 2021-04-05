'''
ALGORITHM: MAXIMUM COUNT OF A CHARACTER IN A STRING

HOW IT WORKS:
Algorithm takes a string as a user input. It will then count the frequency/maximum count of each character in a string.

CONSTRAIN:
1. Algorithm is case insensitive, means lower case alphabets and uppar case alphabets are identical
2. Anything other than chracters [a-z][A-Z] is ignored

COMPLEXITY OF ALGORITHM:
1. Time complexity: O(n); where n is the length of user input
2. Space complexity: O(1); array of size 26, which is constant  
'''


#take user input 
user_input = input("enter string: ")
output={}

#initialize count of each character of [a-z] as 0
for i in range(26):
    output[chr(i+97)]=0

#character count
print("count of each character")
for i in user_input:
    #if it is lower case alphabet
    if ord(i) in range(97,123):
        output[i]=output[i]+1
    #if it is uppar case alphabet 
    elif ord(i) in range(65,91):
        t=chr(ord(i)+32)
        output[t]=output[t]+1
    else:
        continue
for i in output:
    print(i, output[i])


'''
TEST CASE 1:
input: 'hello Worl2222d'
output:
a 0
b 0
c 0
d 1
e 1
f 0
g 0
h 1
i 0
j 0
k 0
l 3
m 0
n 0
o 2
p 0
q 0
r 1
s 0
t 0
u 0
v 0
w 1
x 0
y 0
z 0


TEST CASE 2:
input: '1234#4$/OOOPs!:'
output:
a 0
b 0
c 0
d 0
e 0
f 0
g 0
h 0
i 0
j 0
k 0
l 0
m 0
n 0
o 3
p 1
q 0
r 0
s 1
t 0
u 0
v 0
w 0
x 0
y 0
z 0
'''
