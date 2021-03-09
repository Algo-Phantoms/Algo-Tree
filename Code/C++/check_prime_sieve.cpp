#include<bits/stdc++.h>
using namespace std;


#define MAX 1000007


// Create a boolean array  "prime[0..MAX]" 
bool prime[MAX];

void SieveOfEratosthenes()
{
    //Initialize  all entries in prime[] as true.  A value in prime[i] will  finally be false if i is  Not a prime, else true.
    memset(prime, true, sizeof(prime));
    
    
    //Every number is divided by 1 and that number itself
    //So start from 2 and go upto sqrt(number) because, if a number is divided by a a value that is lesser than sqrt(number) then the division value will be greater than sqrt(number) and the vice versa is also true. 
    //So, no need to check using the value more than the sqrt(number).
    /*Let's take an example
        number = 16 
        Also we know that 16 = (1 * 16), (2 * 8), (4 * 4)
        So, if we check using 1, 2a and 4 then no need to check using 8 and 16 again . That's why checking using upto sqrt(given number) is enough.
        Also in this case time complexity decreases O(sqrt(n)) otherwise it would be O(n), which would be very costly in sense of time complexity.
    */   
    
    
    for (int p = 2; p * p <= MAX; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) 
        {
            // Update all multiples of p greater than or equal to the square of it numbers which are multiple  of p and are less than p^2  are already been marked.
            for (int i = p * p; i <= MAX; i += p){
                prime[i] = false;
            }
        }
    }
}


bool isPrime(int n){
    //prime array stores the status of all the numbers upto 10000007, that the number is prime or not.
   
    if(prime[n] == true){
        return true;
    }
    else{
        return false;
    }
}


//Approach when we need to check for more than one numbers, in a single testcase.
int main() {

/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    SieveOfEratosthenes();
    
    int testcase;
    cin >> testcase;
    
    while(testcase --){
        
        //A number is a prime number if that number is divided by 1 and that number only.
        int number;
        cin >> number;
        
        //Every number is divided by 1 and that number itself
        
        bool flag = 1; //this variable will help me to store the status of the  given number.
        
       
        if(isPrime(number) == 0) //if not prime
        {
            flag = 0;
        }
        
        //output that the number is prime or not.
        if(flag == 1){
            cout << number << " is a prime number." << endl;
        }
        else{
            cout << number << " is not a prime number." << endl;
        }
    }
    
    return 0;
}

//Time complexity -> O(MAX *(log(log(MAX))))
//Space complexity -> O(MAX)

/* Example

Let's discuss for '16'
                   2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
prime[16] =       [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

1st iteration:   [1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0]
2nd iteration:   [1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0]
.
.
.
last iterationi:[1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0]

As prime[16] contains 0 so 16 is not a prime number and prime[7] conotains 1 so 7 is a prime number
*/


