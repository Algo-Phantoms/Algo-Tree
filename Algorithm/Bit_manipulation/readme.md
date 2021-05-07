 # Bit Manipulation

We all have been dealing with decimal, float, char and string. They are excellent way of storing data as they are in user readable form. But when we start to deal with data of very large size, they data structures are tough to handle, and demands high time and space complexity. That's where Bit manipulation plays an important role, and are the most optimum choice to follow.

Bit Manipulation is majorly used in Data compression, Data Encryption/Decryption. In order to encode, decode or compress files we have to extract the data at bit level. Bitwise Operations are faster and closer to the system and sometimes optimize the program to a good level.

<h5> Binary representation </h5> 1 byte comprises of 8 bits and any integer or character can be represented using bits in computers, which we call its binary form(contains only 1 or 0) or in its base 2 form.

> For characters, we use ASCII representation, which are in the form of integers which again can be represented using bits as explained above.

### Bitwise Operators:

There are different bitwise operations used in the bit manipulation. Bit operations are fast and can be used in optimizing time complexity. Some common bit operators are:

- <h4> NOT ( ~ ):</h5> Bitwise NOT is an unary operator that flips the bits of the number i.e., if the ith bit is 0, it will change it to 1 and vice versa. Bitwise NOT is nothing but simply the one’s complement of a number. Lets take an example.

    **e.g.**
    -   N = 5 = (101)2
        ~N = ~5 = ~(101)2 = (010)2 = 2

- <h4> AND ( & ):</h5> Bitwise AND is a binary operator that operates on two equal-length bit patterns. If both bits in the compared position of the bit patterns are 1, the bit in the resulting bit pattern is 1, otherwise 0.
    
    **e.g.**
    -   A = 5 = (101)2 , B = 3 = (011)2 
        A & B = (101)2 & (011)2= (001)2 = 1

- <h4> OR ( | ): </h5> Bitwise OR is also a binary operator that operates on two equal-length bit patterns, similar to bitwise AND. If both bits in the compared position of the bit patterns are 0, the bit in the resulting bit pattern is 0, otherwise 1.

    **e.g.**
    -   A = 5 = (101)2 , B = 3 = (011)2

        A | B = (101)2 | (011)2 = (111)2 = 7

- <h4> XOR ( ^ ):</h4> Bitwise XOR also takes two equal-length bit patterns. If both bits in the compared position of the bit patterns are 0 or 1, the bit in the resulting bit pattern is 0, otherwise 1.

    **e.g.**
    -   A = 5 = (101)2 , B = 3 = (011)2
        A ^ B = (101)2 ^ (011)2 = (110)2 = 6

- <h4>Left Shift ( << ):</h4> Left shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the left and append 0 at the end. Left shift is equivalent to multiplying the bit pattern with
    
    **e.g.**
    -   1 << 1 = 2
    -   1 << 2 = 4


- <h4>Right Shift ( >> ):</h4> Right shift operator is a binary operator which shift the some number of bits, in the given bit pattern, to the right and append 1 at the end. Right shift is equivalent to dividing the bit pattern with 2k ( if we are shifting k bits ).

    **e.g.**
    - 4 >> 1 = 2
    - 6 >> 1 = 3


## Questions :

- Bitwise Operator Overloading ---->[C++](Code/C++/Bitwise_op_overloading.cpp)
- Counting Set Bits from 0 to N ---->[C++](/Code/C++/ Counting_Set_Bits_from_0_to_N.cpp)
- Brian Kernighan's Algorithm ----> [C++](/Code/C++/Brian_Kernighan.cpp) | [Java](/Code/Java/BrianKernighanAlgorithm.java) | [Python](/Code/Python/Brian_Kernighan's_Algorithm.py)
- Swap Even and Odd Bits Algorithm ----> [Python](/Code/Python/Swap_even_odd_bits.py)

