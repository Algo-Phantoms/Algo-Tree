/*Let's say we want to count the number of divisors of a number. One way is to check all numbers up to √n and check if n divides that
number. The other way is to get its prime factorization and get the product of (exponent + 1) through combinatorics. Either method is
O(√n) on average, thus O(n√n) if done for all numbers up to n.But what if a problem asks us to print the number of divisors of all
numbers from 1 to 10^7 under 3 seconds? An O(n√n) algorithm will be too slow! When I tried counting divisors using the square root method,
it ran for about 61 seconds on my computer. That definitely won't run in time.

Here comes the Eratosthenes sieve approach to our rescue.We can use sieve approach to count the number of divisors more efficiently and elegantly.
We will now see the implementation of the sieve approach in the below code */

//C++ Program to count the number of divisors of an integer using Sieve Approach
#include<bits/stdc++.h>
using namespace std;

vector<int> primesieve(int *p,int n){
    p[0]=p[1]=0;
    p[2]=1;

    //Let us Mark all odd numbers as prime numbers
    for(int i=3;i<=n;i+=2)
    {
        p[i]=1;
    }

    //Sieve Login to mark non prime number as 0
    //1.Iterate over odd numbers 
    for(int i=3;i<=n;i+=2){
        if(p[i])
        {
            //Mark all the multiples of that number as not prime
            //2.Take a jump of 2i starting from i*i
            for(int j=i*i;j<=n;j+=2*i){
                p[j]=0;
            }
        }
    }
    vector<int> primes;
    //Since 2 is a prime number add it in the vector
    primes.push_back(2);

    //Add the numbers into the vector whose Indexes still contains 1(which means they are prime number)
    for(int i=3;i<=n;i+=2){
        if(p[i]==1){
            primes.push_back(i);
        }
    }

    //Return the vector
    return primes;
}

//Function returns the count of divisors a number will have
int no_of_divisors(int m,vector<int> &primes)
{
    int ans=1;
    //Start iterating over the vector from 0th index or we can say from first prime number
    int i=0;
    int p=primes[i];
    //Compute the power of that prime number on which we are iterating
    while(p*p<=m)
    {
        if(m%p==0)
        {
            //Count basically denotes what is the power
            int count=0;
            while(m%p==0)
            {
                count++;
                m=m/p;
            }
            ans=ans*(count+1);
        }
        //go to next prime number
        i++;
        p=primes[i];
    }
    //If we have a prime number left whose power is 1
    if(m!=1)
    {
        ans=ans*2;
    }
    return ans;
}

//Main Function
int main()
{
    int n=1000;
    int arr[n];
    //Taking input of array elements
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }
    
    //Building a vector of prime numbers 
    vector<int> primes = primesieve(arr,n);

    cout<<"Enter the number whose divisors you want to count :"<<endl;
    int number;
    cin>>number;

    //Calling the function which will count dividors of a number
    int divs=no_of_divisors(number,primes);
    cout<<"Total Divisors of the entered number are "<<divs<<endl;
 
    return 0;
}

/*
Two Test case you can try out with this code-

Testcase-1
Enter the number whose divisors you want to count :
60
Total Divisors of the entered number are 12

Testcase-2 
Enter the number whose divisors you want to count :
10
Total Divisors of the entered number are 4
*/

/*
Time Complexity - O(nlogn)
Space Complexity - O(n)
*/