/*
Java Code for coversion of String Roman Numeral to Decimal Int.
A string in roman number format is to be converted to an integer. 
Using the following symbols.
I->1
V->5
X->10
L->50
C->100
D->500
M->1000.

--Solution Approach--
Convert the Roman Numeral string into Roman Symbols (character).
Map each symbol of Roman Numerals with its value.
Take symbol one by one from starting from index 0:
– If current value of symbol is greater than or equal to the value of next symbol --> Add this value to the total value.
– else --> Subtract this value by adding the value of next symbol to the total value.

eg. Input = XXIV -> (X = 10) + (X = 10)+ (IV = 4) = 24
	Output = 24

*/






import java.io.*;
import java.util.*;

class RomanNumeralStringConversion
{

	public static void main(String[] args) throws IOException 
	{
       	    BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        
            String roman = br.readLine().trim();
            RomanToNumber rn = new RomanToNumber();
            System.out.println(rn.romanToDecimal(roman));
        
    	}
}

class RomanToNumber {
	public int romanToDecimal(String str) 
	{
		//total result
		int res = 0;  

		//Using Java HashMap for mapping

		HashMap<Character,Integer> hm = new HashMap<Character,Integer>();

		hm.put('I',1);
		hm.put('V',5);
		hm.put('X',10);
		hm.put('L',50);
		hm.put('C',100);
		hm.put('D',500);
		hm.put('M',1000);

		//Variable  for comparision of prev valuue
		int pre = 0; 
		
		for(int i = str.length()-1 ; i >=0  ; i--)
		{
		    int x = hm.get(str.charAt(i));
		    
		    //if value at i greater than previous value  --> VI = 6 ( 5 + 1 )
		    if(x>=pre) 
			res = res + x;
		    else
			    //if value at i less than previous value  --> IV = 4 ( -1 + 5 )
			res = res - x; 
		   
			//Storing previous value for comparision
				pre = x;
		}

		return res; 
	}
}


/*

Test case 1:
Input: LXVII
Output: 67

Test case 2: 
Input: DIVX
Output: 504

Time Complexity: O(n)
Space  Complexity: O(1)
where n = length of input string.


*/
