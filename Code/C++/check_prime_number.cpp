#include<bits/stdc++.h>
using namespace std;



//Approach when we need to check only one number
int main() {

/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //A number is a prime number if that number is divided by 1 and that number only.
    int number;
    cin >> number;
    
    //Every number is divided by 1 and that number itself
    //So start from 2 and go upto sqrt(number) because, if a number is divided by a a value that is lesser than sqrt(number) then the division value will be greater than sqrt(number) and the vice versa is also true. 
    //So, no need to check using the value more than the sqrt(number).
    /*Let's take an example
        number = 16 
        Also we know that 16 = (1 * 16), (2 * 8), (4 * 4)
        So, if we check using 1, 2a and 4 then no need to check using 8 and 16 again . That's why checking using upto sqrt(given number) is enough.
        Also in this case time complexity decreases O(sqrt(n)) otherwise it would be O(n), which would be very costly in sense of time complexity.
    */   
    
    bool flag = 1; //this variable will help me to store the status of the  given number.
    
    for(int i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0) //it means given number is divided by any value other than 1 and that number itself
        {
            flag = 0; //store 0 in flag variable , means this number is not a prime number and exit the loop.
            break; //to exit from the loop
        }
    }
    
    //output that the number is prime or not.
    if(flag == 1){
        cout << number << " is a prime number." << endl;
    }
    else{
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}
