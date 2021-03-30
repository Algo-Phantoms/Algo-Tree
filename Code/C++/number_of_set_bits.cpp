#include <iostream>
using namespace std;

int setBit(int number);

int main()
{
    int setBits, number;
    cout << "Enter the number" << endl; //It takes the number to find number of set bits
    cin >> number;

    setBits = setBit(number); //number is passed to function

    cout << "Number of setbits " << setBits << endl;
    return 0;
}
int setBit(int number)
{ //function for finding number of setbits

    int count = 0, rbs;
    while (number != 0)
    {
        rbs = number & -number; // it calculates the right most set bit
        number = number - rbs;
        count++;
    }
    return count;
}

/* 
    Test case 1: 
    Input :  89

    Output : 4

    Test case 2: 
    Input :  129

    Output : 42

  
    Time complexity:O(n)

    space complexity:O(1)

*/