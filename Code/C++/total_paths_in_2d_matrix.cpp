/*
This is a recursive solution where we can transverse in positive x or positive y OR vise-versa.
We cannot take one positive and another negative because it will create some cases were we are not 
moving (+1 + -1 =0 ) that will create a infinite loop.
Complexity of solution can be reduced by using dynamic programming aproach.
*/

#include<bits/stdc++.h>
using namespace std;

int total_possible_path(int x,int y,int a,int b) // All possible paths from a,b to x,y where a < x or b < y
{                                                // Because we cannot move backwards(negative) x or y axis
    if(x==a && y==b)
    {
        // If we reach our destination we count one in total paths
        //total_paths++;
        return 1;
    }

    if(x>a || y> b) 
    {
        //If we moved beyond a or b we will return 0 because we cannot move backwards
        return 0;
    }

    return total_possible_path( x+1, y, a, b) + total_possible_path( x, y+1, a, b);
           //moving one step in x direction   +   moving one step in y direction
    
}


int main()
{
   int x,y,a,b;
   //integer is used because recursively calculating for large value will take very long time
   cout<<"Enter x and y co-ordinate of point of starting location: \n";
   //Taking x, y co-ordinate of point of starting location
   cin>>x>>y; 

   cout<<"Enter x and y co-ordinate of point to reach :\n";
   //Taking x, y co-ordinate of point to reach
   cin>>a>>b;

   if(x<a || y<b)
   // Assuming x is less than a because we can travel in positive direction only ; same with y and b
   //We will print total unique possible paths from x,y to a,b 
   cout<<"\nTotal possible paths are : "<<total_possible_path(x,y,a,b);

   else
   // If x is greater or y is greater we will find reverse path 
   // Reverse of total paths will be same a,b and x,y
   // We will print total unique possible paths from x,y to a,b 
   cout<<"\nTotal possible paths are : "<<total_possible_path(a,b,x,y);


}

/* 
Test Case 1 :
Input: 0,0 and 2,2      
Output : 6

Test Case 2 :
Input: 2,2 and 0,2
Output:1

Time Complexity : O(2^n);
*/
