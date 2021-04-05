/*
A program to check whether the given number is a perfect number or not.

Perfect number is a positive whole number that is equal to the sum of its proper divisors.

The first perfect number is 6 as the sum of its proper positive divisors, 1,2 and 3 is 6.
Other perfect numbers are 28, 496, 8128,etc.
*/

#include<iostream>
using namespace std;


//function to check perfect number
void check_perfect_number(int num)
{

    int sum=0;
    int i;

    for(i=1;i<=(num/2);i++)
    {
        int rem=num%i;

        if(rem == 0)
            sum=sum+i;
    }

        if(num==sum)
            cout<<"You entered a perfect number\n";

        else
            cout<<"Not perfect number\n";

}

//main
int main(){

int number,sum=0,rem,i;

cout<<"Enter number:\n";
cin>>number;

//function call
check_perfect_number(number);

return 0;

}
