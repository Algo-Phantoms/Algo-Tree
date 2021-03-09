/********************* PROGRAM TO CHECK WHETHER A GIVEN NUMBER IS PRIME OR NOT *********************/
#include <iostream>
using namespace std;

//APPROACH NO. 1:- Prime numbers are those numbers which are divisible by only 1 and itself. So, if we want to check
// whether a given number is prime or not, we can check whether the number is divisble by any number from 2 to
// that number. If it's divisible then the number is not prime otherwise, it is a prime number.
int main()
{
    int n;
    cout << "Enter any number to check prime or not\n";
    cin >> n;
    if (n <= 1)
    {
        cout << "The given number is NOT a prime number\n";
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if ((n % i) == 0)
        {
            cout << "The given number is NOT a prime number\n";
            return 0;
        }
    }
    cout << "The given number is a prime number\n";
    return 0;
}

/* NOTE:- The time complexity of above solution is O(N), where N is the given integer. Hence, the above solution has
          linear time complexity.
*/

//APPROACH NO. 2:- We can optimize the above solution in terms of time and space complexity as follows:-

//Here, in this approach instead of checking the divisibility of the given number through all
// numbers from 2 to n i.e., given number, we will check the divisibility till √n (root n)
// since if given number is divisible by root n, then it will also be divisible by their multiples. So, no
// need to check for that.
// FOR EXAMPLE :- If we are checking that if 36 is prime or not, then we will check till only √36 that is 6
// So, now if any number from 2 to 6 divides 36 then of course their multiples will also divide 36.
// So, no need to check for that and we will conclude that the number is NOT prime otherwise, it is prime.
// The code for the same is given below :-

/* int main()
{
    int n;
    cout << "Enter any number to check prime or not\n";
    cin >> n;
    if (n <= 1)
    {
        cout << "The given number is NOT a prime number\n";
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            cout << "The number is NOT prime\n";
            return 0;
        }
    }
    cout << "The number is prime\n";
    return 0;
} */
//NOTE:- The time complexity of above solution is O(√n) which is much more optimized than the previous one.

/*Now, I would like to discuss one special algorithm which is frequently used in Competitive Programming as 
well as in Technical Interviews.
So, the question is that we are required to find all the Prime numbers in a given range that is from 1 to n, 
where n is the given number. So, the name of the algorithm is Sieve of Eratosthenes.
The function snippet for the same is given below:-
*/

/* void seive(int n)
{
    int parray[n + 1]; //Make an array of size n+1 .
    for (int i = 2; i <= (n + 1); i++)
    {
        parray[i] = 1; // Mark all the elements of this array integer 1 i.e., initially consider all
                       // the elements to be prime.
    }

    for (int i = 2; i * i <= n; i++) //Now marking all the multiples of number till √n to 0, since they can't be prime
    {
        if (parray[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                parray[j] = 0;
            }
        }
    }

    //Now, printing all the prime numbers in the given range i.e., those numbers which are marked to 1.
    for (int j = 2; j <= n; j++)
    {
        if (parray[j] == 1)
        {
            cout << j << "\n";
        }
    }
} */

//NOTE:- Time Complexity of Sieve of Eratosthenes Algorithm is O(n*log(log(n))), where n is the number
// till which we wanted to find prime numbers.
