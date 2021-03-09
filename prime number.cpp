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
    float N;
  	cin>>N;  // Taking input the number from the user
  	
  	int factor=0; // Variable to store number of factors of the inputted number
  	
  	int x=(int)N; // Variable to store the integer part of the inputted number
	   
  	if(N>=2)  // Checking if the number id greater than equal to 2
  	{
  	if(N-x==0)   //Checking if the inputted no is an integer
  	{
  		for(int i=N ;i>=1;i--)
  		{
  			if(((int)N)%i==0)
  			factor++ ;  //Counting number of factors of the inputted number
			
		}
	
	if(factor==2)
	cout<<N<<" is a prime number."<<endl;
	else
	cout<<N<<" is not a prime number."<<endl;;
  		
	}
	else
	cout<<N<<" is not a prime number."<<endl;
  	
  	}
	else
	cout<<N<<" is not a prime number."<<endl;
	
	return 0;
}


/* Sample input:  5
   Std    output: 5 is a prime number
   
   Sample input: 1.4
   Std    output: 1.4 is not a prime number
   
   Sample input: 1
   Std    output: 1 is not a prime number
   
   Sample input: -4
   Std    output: -4 is not a prime number
   
   Sample input: 11
   Std    output: 11 is a prime number
	*/
