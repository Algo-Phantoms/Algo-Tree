/* A number is said to be a prime number if it has only two factors which are 1 and the number itself.
   For examle, 2 is a prime number as it has 2 factors which are 2 and 1. Similarly 3 is also a prime number as it has only two factors which are 3 and 1.
    
   The first number in the set of prime numbers is 2. 
   1 is not a prime number.
   
   The following program checks if a number is a prime number or not.
   
   */
   
  #include <iostream>
  using namespace std;
  int main()
{
    int N;
  	cin>>N;  // Taking input the number from the user
  	
    if(N>=2 )   //Checking if the inputted no is greater than equal to 2
  	{
  		int factor=0; // Variable to store number of factors of the inputted number
  		
  		for(int i=N ;i>=1;i--)
  		{
  			if(N%i==0)
  			factor++ ;  //Counting number of factors of the inputted number
			
		}
	
	    if(factor==2)
	    cout<<N<<" is a prime number."<<endl;
 	    else
	    cout<<N<<" is not a prime number."<<endl;
  		
	}
	
	else
	cout<<N<<" is not a prime number";
	
  	return 0;
}


/* Sample input:  5
   Std    output: 5 is a prime number
   
   Sample input: 9
   Std    output: 9 is not a prime number
   
   Sample input: 1
   Std    output: 1 is not a prime number
   
   Sample input: -4
   Std    output: -4 is not a prime number
   
   Sample input: 11
   Std    output: 11 is a prime number
   
   Time complexity: O(N)
   Space complexity: O(1)
	*/
