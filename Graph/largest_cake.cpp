//
//  main.cpp
//  largest_cake
//
//  Created by Madhvi Suri on 27/04/21.
//  Copyright © 2021 Madhvi. All rights reserved.
//


#include<iostream>
using namespace std;
#include<vector>

#include<climits>
int helper(vector<vector<int>> &cake,bool**visited,int i,int j, int n)
{
    if(i>=n||j>=n||i<0||j<0)
    {
        return 0;
    }
    if(cake[i][j]==0)
    {
        return 0;
    }
    if(visited[i][j]==1)
    {
        return 0;
    }
    int ans=0;
    visited[i][j]=1;
    
    //just checking in all the 4 directions and adding their respective ans into our main ans
    //since the piece of the cake can be of any shape but it should be continuous,i.e the connected component of 1's will give you the length of a  piece of cake ;
   
    int small_ans=helper(cake,visited,i-1,j,n);
    ans+=small_ans;
   
    small_ans=helper(cake,visited,i+1,j,n);
    ans+=small_ans;
    
   
    small_ans=helper(cake,visited,i,j-1,n);
    ans+=small_ans;
   
    small_ans=helper(cake,visited,i,j+1,n);
    ans+=small_ans;
    
   
    return ans+1;
    
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool**visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            visited[i][j]=false;
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]==1&& !visited[i][j])
            {
                int small=helper(cake,visited,i,j,n);
                //checking for all the  different size of the cake given  in the input and updating our ans accordingly
                //i.e getting the length of the each connected component of 1's in the graph and updating the ans ;
                ans=max(ans,small);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>cake;
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        cake.push_back(v);
    }
    for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
               cin >> cake[i][j];
           }
       }
    cout<<getBiggestPieceSize(cake, n)<<endl;;
}
