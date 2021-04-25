''' 
Swap all the even and odd bit:- 
Topic: Bit-Masking and Bit Manipulation 

Pre-Requisite Knowlegde:
1) HexaDecimal Number 
2) Right Shift and Left Shift Operator.

Note:- 
It's important to know that Hexadecimal number '5' and 'A' (decimal number 10) is written as 0101 and 1010 in binary format respectively.

General Algorithm with an Example:-
Lets take an integer value 45. Binary Representation of 45 is 00101101.
I) Create a bit-mask and seperate odd and even bits.
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

II) Shift the even bits and odd bits.
We need to right shift the even bits by 1 to make them odd bits.  
even_bits >> 1 = 00010100 

We need to left shift the odd bits by 1 to make them even bits.
odd_bits << 1 = 00001010 

III) Combine both the shifted bits together.

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
print("The output for", int_number ,"after swapping even and odd bits is:", swap_even_odd_bits(int_number))

print("\n")
#METHOD - 2 Using Binary Number
print("METHOD - 2 Using Binary Number")
print("\n")
# Function for swapping even and odd bits

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
print("The output for", int_number ,"after swapping even and odd bits is:", swap_even_odd_bits(int_number))

'''
Test Case: - 

Input 1: 27
where 27 is 00000000011011
Output 1: 39
wher 39 is 00000000100111
           
Input 2: 56
where 56 is 00000000111000
Output 2: 52 
where 52 is 00000000110100
            
Time Complexity : O(1)
The number of steps required to in computing the solution is finite.
Note that the finite number of steps doesnot grow with our input varaible "int_number".
Therefore we conclude that the Time Complexity is of order 1 that is constant time.

Space Complexity : O(1)
The space remain constant throughout the program.
This implies that the space complexity is also of order 1 that is constant space.
'''