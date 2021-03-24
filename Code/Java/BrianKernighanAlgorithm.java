/*
	Brian Kernighan's algorithm :
		This algorithm is used for counting the number of set bits in a number in the most efficient way.
		
	Approach for the algorithm:
		1.Given a number n if we carefully observe the binary representation of n and n-1 we will find that
		 in n-1, all bits from the rightmost set bit of n will be inverted 
		 
		Let us see an example:
			consider n=28
			It's Binary representation is ->  000.....11100   (32 bit)
			now Binary representation of (28-1) will be ->  000...11011  (32 bit)
			
			we can clearly observe the above property with this
			
		2. Now we will take a bitwise and(&) of the n and n-1. this will turn off the rightmost set bit of n
		   continuation from previous example:
		   n=28		->	000...11100
		   n-1=27	->	000...11011
		   ------------------------
		   n&(n-1)	->	000...11000
		   ------------------------
		   
		   Here we can see that rightmost set bit of n is turned off (means it becomes 0)
		   
		3. we will keep doing this until n becomes 0
 
 */
package opensourcecontributiongssoc;

import java.util.*;

public class BrianKernighanAlgorithm {
	
	// function which will count the number of set bits of a digit using Brian Kernighan's algorithm
	// which takes number as an argument and return the number of set bits in it.
	
	static int countSetBits(int number) {
		
		// variable to count the number of set bits which is initialized to 0
		int count = 0; 	
		
		// this loop will run till the number becomes 0
		while(number > 0) {		
			number = (number & (number-1));
			
			// increase the count variable 
			count++;
		}
		
		// return the number of set bits(count variable)
		return count;
		
	}

	public static void main(String[] args) {
		
		// scanner class to take input from the user
		Scanner sc = new Scanner(System.in);
		
		// Taking an integer value as input
		int digit = sc.nextInt();
		
		// calling the countSetBits function which will return the number of set bits and storing the result
		// in a variable called answer
		int answer = countSetBits(digit);
		
		// printing out the output
		System.out.println("The number of set bits in "+ digit + " is: "+ answer);
	}
}

/*
 	Test Cases:
 		1. input- 55
 		   output- 5
 		   
 		2. input- 145
 		   output- 3
 		   
 	Time Complexity  : O(number of set bits in the input)
 	Space complexity : O(1)  
 */
