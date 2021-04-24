/*
    Problem Statement: You are given a sorted array which contains only "0" and "1".
    The task is to find the transition point.
    A transitiom point is where “0” ends and “1” begins.
*/
#include<iostream>
using namespace std;

int transition_point(int a[],int n) 
//here n is the number of elements in the array
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])     
        {
            return i+1;
            // For Ex: If 2nd element is 0 and 3rd is 1 then the function will return 3.

        }
    }
    return -1;     
    //If even after completing the loop we don't get a transition point we return -1.
}

int main()
{
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array (Only 0 or 1)\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        //Ensuring the array has only "0" and "1" as elements
        while(a[i]!=0 && a[i]!=1)
        {
            cout<<"Enter 0 or 1\n only\n";
            cin>>a[i];
        }
    }
    //variable to store transition point
    int transition_pt;
    transition_pt= transition_point(a,n);
    if(transition_pt>=0)
    {
    cout << "Transition point is:\n"<<transition_pt;
    }
    else
    cout<<"There is no transition point";
    return 0;
}
/* 
    TEST CASES
    1) Input:
            Enter the size of the array 
            5
            Enter the elements of the array (Only 0 or 1)
            0 0 1 1 1
      Output:
            Transition point is:
            2
    2) Input:
            Enter the size of the array 
            7
            Enter the elements of the array (Only 0 or 1)
            0 0 0 0 1 1 1
      Output:
            Transition point is:
            4
*/