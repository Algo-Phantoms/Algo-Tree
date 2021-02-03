#include <bits/stdc++.h>
using namespace std;
int find(string x,string y,int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string x;
    string y;
    cin>>x;
    cin>>y;
    int n=x.length();
    int m=y.length();
    cout<<"Longest Common Subsequence:"<<find(x,y,n,m);
}