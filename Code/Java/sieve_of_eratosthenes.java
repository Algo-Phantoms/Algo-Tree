import java.util.Arrays;
import java.util.Scanner;

class sieve_of_eratosthenes{
    void Sieve_of_Eratosthenes(int upper_range){

    /*Creating a Boolean Array to store all Prime Number of Inputed Range
    we use (n+1) to avoid negative index as the index of array start with 0.*/
    boolean prime_number[] = new boolean[upper_range+1]; 

    Arrays.fill(prime_number, true); // Initializing all the value of prime_number array to true
    
    for (int num= 2; num* num<= upper_range; num++) // Checking the factor of the Number In Range
		{
			// If Multiple of the number is not found, then it is a Prime Number

			if (prime_number[num] == true) 
			{
				/* If multiples of number found then its not prime , 
                So here Updating that Number index to false*/

				for (int i = num* num; i <= upper_range; i += num)
					prime_number[i] = false;
			}
		}

		// Printing all Prime Numbers in Complete Range
		for (int i = 2; i <= upper_range; i++)
		{
			if (prime_number[i] == true) // Checking True value at Each Index
				System.out.print(i + " ");
		}
	}


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Upper Value of the Range ");
        int upper_range_number = sc.nextInt();

        sieve_of_eratosthenes obj = new sieve_of_eratosthenes(); // Creating the Object 

        System.out.println("The Prime Number In Given range Is:- \n");
        obj.Sieve_of_Eratosthenes(upper_range_number); // Calling object to get the Result

    }
    
}
