/*Find Duplicate in array
Problem Statement: Given an array with size "size", the elements inside the array can be present any number of times.
                   Print all the elements whose frequency is greater than 1.
*/

#include <bits/stdc++.h>
using namespace std;

void print_repeat_numbers()
{
    int size;
    //taking the size as input from user
    cin >> size; 
    int input[size];
    // taking input the elements of array
    for (int i = 0; i < size; i++)
    {
        cin >> input[i]; 
    }

    //defining an onordered map for storing the frequencies
    unordered_map<int, int> frequency; 
    //incrementing the frequency for every repeated element
    for (int j = 0; j < size; j++)
    {
        frequency[input[j]]++; 
    }

    cout << "Repeated elements are: ";

    //printing the numbers whose frequency is more than 1 i.e which is repeated
    for (auto x : frequency)
    {
        if (x.second > 1){ 
            cout << x.first << " ";
        }
    }
}

int main()
{
    print_repeat_numbers();
    return 0;
}

/*
Test Cases
1.
Input :
5
1 2 3 2 3
Output :
Repeated elements are: 3 2 

2.
Input :
10
1 1 1 2 2 2 3 4 4 5
Output :
Repeated elements are: 1 2 4 

Time Complexity: O(size), for traversing the elements where size is the length of array
Space Complexity: O(size), space is used for hashmap where size is the length of array
*/
