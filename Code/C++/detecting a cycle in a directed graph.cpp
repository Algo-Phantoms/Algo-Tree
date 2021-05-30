/* Here is the solution of the program in c++*/

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class solution{
public:

bool solve(int src , vector<int> &vis, vector<int> &order,vector<int> adj[]){
    vis[src]= 1;
    order[src]= 1;
    for(auto x:adj[src])
    {
      if(!vis[x])
       {   
         bool conf = solve(x,vis,order,adj);
         if(conf == true)
         return true;
        }
     else if(order[x])
      return true;
    }
    order[src] = 0;
    return false;
}
bool iscyclic(int v,vector adj[])
{
vector vis(v,0);
vector order(v,0);
for(int i=0;i<v;i++)
{
if(!vis[i])
{
bool c = solve(i,vis,order,adj);
if(c==true);
return true;
}
}
return false;
}
};

TIME COMPLEXITY:- O(V)
