/*Find Duplicate in array
Problem Statement: Given an array with size "size", the elements inside the array can be any number of times.
                   Print all the elements whose frequency is greater than 1.
*/

#include <bits/stdc++.h>
using namespace std;

void print_repeat_numbers()
{
    int size;
    cin >> size; //taking the size as input from user
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i]; // taking input the elements of array
    }

    unordered_map<int, int> frequency; //defining an onordered map for storing the frequencies
    for (int j = 0; j < size; j++)
    {
        frequency[input[j]]++; //incrementing the frequency for every repeated element
    }

    cout << "Repeated elements are: ";

    for (auto x : frequency)
    {
        if (x.second > 1)
        { //printing the numbers whose frequency is more than 1 i.e which is repeated
            cout << x.first << " ";
        }
    }
}

int main()
{
    print_repeat_numbers(); //calling for the function in the main
    return 0;
}

/*
Test Case 1:
Input -
5
1 2 3 2 3
output -
Repeated elements are: 3 2 

Test Case 2:
Input -
10
1 1 1 2 2 2 3 4 4 5
output -
Repeated elements are: 1 2 4 

Time Complexity: O(size), for traversing the elements
Space Complexity: O(size), space is used for hashmap
*/

