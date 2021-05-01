/*
    In this problem we are provided with the stock prices of various days and we have to find
    the span of each day. The span of ith day is the total number of consecutive days 
    before it that had stock prices strictly less than the ith day. the minimum span of a day is 1.
    For Ex:
           Input: 
                  5 
                  100 10 80 29 4
           Output: 
                  1 1 2 1 1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  //Taking input
  int n;
  cout<<"Enter number of days\n";
  cin>>n;
  int a[n],span[n];
  for(int i=0;i<n;i++)
  {
    cout<<"Enter price of stock on day "<<i<<"\n";
    cin>>a[i];
  }
  
  //Creating a stack to calculate span of each day
  stack<int> s;
  
  for(int i=0;i<n;i++)
  {
    
    //This pops out the elements that are smaller than a[i] out of the stack
     while((!s.empty()) && a[s.top()]<=a[i])
     {
       s.pop();
     }
    
    // If the stack this empty it means that a[i] is the largest value
    //So its span is i+1
    if(s.empty())
    {
      span[i]=i+1;
    }
    else
    {
      span[i]=i-s.top();
    }
    
    //In the end we push a[i] in the stack to compare it with other elements
    s.push(i);
  }
  
  //Printing the span of each day
  for(int i=0;i<n;i++)
  {
    cout<<span[i]<<" ";
  }
  
}

/*      TEST CASES

    1) INPUT:
               7
               100 20 40 30 5 101 70
       OUTPUT:
                1 1 2 1 1 6 1
    
    2) INPUT:
               6
               10 200 40 39 51 101 
       OUTPUT:
                1 2 1 1 3 4 
                
*/
           
