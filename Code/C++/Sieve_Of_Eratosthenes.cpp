#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes (Algorithm)
/* This is an algorithm used to find prime numbers in a range. 

   STEPS :-
       
        1) Let us assume we have to find all the prime numbers from 2 to n.
           We take an boolean array of size (n+1) and intialize all the values
           as true. (Assuming all are primes at the beginning, we make changes
           in it in further steps).
        
        2) Then we start a linear traversal from 2 to n. (We skip 0 and 1 because
           we already know that they are not primes).

        3) In each iteration we check if the value is true or not. If the value is
           true, then it means that is a prime number. So, we print that as 
           an answer.
        
        4) MOST IMPORTANT PART --
           We then run a loop inside the current loop in which we traverse 
           through all the multiples of the current number (prime) and make
           them false. (Quite clear that multiples of any prime numbers will
           be a composite number, i.e not a prime number).

        EXAMPLE -
           For simplicity let us take a small example.
           Let n=10,so we have to find all primes from 2 to 10.

           Initial Array : F F T T T T T T T T T  (n+1 size)
                           0 1 2 3 4 5 6 7 8 9 10 (0 and 1 are not primes)
            
            Then we run the loop from 2 to n. (indices)
            We look for the first true value (i.e prime), we get 2.
            We then make all the multiples of 2 as false.
            
            We get F F T T F T F T F T F
                   0 1 2 3 4 5 6 7 8 9 10
            And similarly we repeat the steps...
    
    Time Complexity : O(nlog(logn))
         
    Please follow the code carefully and match up the steps.
    Below is the C++ implementation. 
    There is a void function sieve(), that takes an integer and it prints 
    the primes in this range.
*/

void sieve(int n){
    bool arr[n+1];                      // Defining boolean array
    for(int i=0;i<=n;i++){
        arr[i]=true;                    // Initializing all values as true
    }
    arr[0]=false;                       // 0 is not prime
    arr[1]=false;                       // 1 is not prime
    for(int i=2;i<=n;i++){      
        if(arr[i]==true){               // Current number is prime
            cout<<i<<" ";               // Printing the prime
            for(int j=i*i;j<=n;j+=i){
                /* We start from j=i*i instead of j=i*2 
                   because all the non-primes before will
                   be made false by the multiples of the 
                   primes that came before.
                */
                arr[j]=false;
            }
        }
    }
}

//main function
int main(){
    int n;   
    cin>>n;   // Taking input
    sieve(n); // Function call
    return 0;
}

/* TEST CASES - 

    1) input  : 10
       output : 2 3 5 7 
    2) input  : 15
       output : 2 3 5 7 11 13
    
    END...
*/