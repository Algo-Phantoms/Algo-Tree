''' 
Swap all the even and odd bit:- 
Topic: Bit-Masking and Bit Manipulation 

Pre-Requisite Knowlegde:
1) HexaDecimal Number 
2) Right Shift and Left Shift Operator.

Note:- 
I) HexaDecimal numbers is a number system with 16 digits, range from 0 to 9 and A to F (representing digits 10 to 15).

HexaDecimal Number <-------> 4-bit Binary Representation
0                                       0000
1                                       0001
2                                       0010
3                                       0011
4                                       0100
5                                       0101
6                                       0110
7                                       0111
8                                       1000
9                                       1001
A (Decimal - 10)                        1010
B (Decimal - 11)                        1011
C (Decimal - 12)                        1100
D (Decimal - 13)                        1101
E (Decimal - 14)                        1110
F (Decimal - 15)                        1111

Understanding the Problem Statement:-
We need to swap the even bits of an integer with odd bits and vice-versa.  

General Algorithm:- 
1) Need to seperate the odd bits from the given number and shift them to the even positions.  
2) Need to seperate the even bits from the given number and shift them to the odd positions.
3) Finally combine the both shifted bits together. 

Example:-
Lets take an integer value 45. Binary Representation of 45 is 00101101.
First step would be creating a bit-mask and seperating odd and even bits.
For the above example inorder to obtain even bits we will use 10101010 bit-mask.
Notice in the above bit-mask all the odd positions are zero. Using 'and'/'&' operator between the given integer and the bit-mask created will give us only the even bits.

            00101101 
        &   10101010
-------------------------
even_bits = 00101000
    
Note all the even bits of the given number are obtained.
Notice that the bit-mask used to obtain even bits can be also written as 0xAAAAAAAA in 32 bit HexaDecimal format.

Now inorder to obtain odd bits we will use 01010101 bit-mask.
Notice in the above bit-mask all the even positions are zero. Using 'and'/'&' operator between the given integer and the bit-mask created will give us only the odd bits.

            00101101 
        &   01010101
--------------------------
 odd_bits = 00000101
    
Note all the odd bits of the given number are obtained.
Notice that the bit-mask used to obtain odd bits can be also written as 0x55555555 in 32 bit HexaDecimal format.

Second step would be shifting the even bits and odd bits.
We need to right shift the even bits by 1 to make them odd bits.  
even_bits >> 1 = 00010100 

We need to left shift the odd bits by 1 to make them even bits.
odd_bits << 1 = 00001010 

Third and final step to combine both the shifted bits together.

even_bits | odd_bits 

                00010100
            |   00001010
---------------------------
final_answer =  00011110 = 30 (Decimal)

'''

#METHOD - 1 - Using HexaDecimal Number
print("METHOD - 1 - Using HexaDecimal Number")
print("\n")
# Function for swapping even and odd bits

def swap_even_odd_bits(int_number):
    
    #STEP_1
    
    #Obtain the Even Bits.
    even_bits = int_number & 0xAAAAAAAA
    
    #Obtain the Odd Bits.
    odd_bits = int_number & 0x55555555
    
    #STEP_2
     
    #Right shift the Even Bits by 1.  
    even_bits >>= 1    

    #Left shift the Odd Bits by 1.  
    odd_bits <<= 1    

    #STEP_3
    
    #Obtain the final number using 'OR'/'|' operator.
    return (even_bits | odd_bits)
    

#Taking an user input
int_number = int(input("Please enter an integer number: "))

#Output
print("The output for",int_number,"after swapping even and odd bits is:",swap_even_odd_bits(int_number))

print("\n")
#METHOD - 2 Using Binary Number
print("METHOD - 2 Using Binary Number")
print("\n")

def swap_even_odd_bits(int_number):
    
    #STEP_1
    
    #Obtain the Even Bits.
    even_bits = int_number & 0b1010101010101010
    
    #Obtain the Odd Bits.
    odd_bits = int_number & 0b0101010101010101
    
    #STEP_2
     
    #Right shift the Even Bits by 1.  
    even_bits >>= 1    

    #Left shift the Odd Bits by 1.  
    odd_bits <<= 1    

    #STEP_3
    
    #Obtain the final number using 'OR' / '|' operator.
    return (even_bits | odd_bits)
    

#Taking an user input
int_number = int(input("Please enter an integer number: "))

#Output
print("The output for",int_number,"after swapping even and odd bits is:",swap_even_odd_bits(int_number))



'''
Test Case: - 

Input 1: 27
where 27 is 0000000011011
Output 1: 39
wher 39 is 00000000100111

Input 2: 56
where 56 is 00000000111000
Output 2: 52 
where 52 is 00000000110100


Time Complexity : O(1)
Since we require fininte number of steps in computing the solution which doesnot grow with the input varaible "int_number" , hence we get the time complexity of order 1 that is constant time.


Space Complexity : O(1)
The space remains constant throughout, hence the space complexity is also O(1) that is constant space.

'''











