/*
-WORD WRAP PROBLEM
-Given an array of size n that contains size of words and maximum width of a line. Arrange the words in such a way that each line does not exceeds the maximum width.
-Give space after each word except the last one(you can give extra spaces as well)
-Print 2*L space separated integers, L being the number of lines required to adjust the words with maximum width that shows from which word to word in each line

-DYNAMIC APPROACH
-Make all possible lines and store cost of each line in a two dimensional table
-Optimize the final cost,i.e,calculate the minimum cost arrangement
-Keep track of from where the optimized cost is coming from 
-Print the optimized cost recursively 
*/

#include <bits/stdc++.h>
#define inf INT_MAX
#define ll long long int 
using namespace std;
//recursive function to print the required soluton,  uses p[] to print the solution.
ll printwordwrap(ll p[],ll n){
        //starts traversing from back till it get 1
	//once 1 is achieved it prints the required value and from where it came from
	ll lineno;
	if(p[n]==1){
		lineno=1;
		cout<<"Line number "<<lineno<<": From word number "<<p[n]<<" to "<<n<<"\n";
	}
	else{
		lineno=printwordwrap(p,p[n]-1)+1;
	        cout<<"Line number "<<lineno<<": From word number "<<p[n]<<" to "<<n<<"\n";
	}
	return lineno;
}

int main() {
	//no. of words
	ll n;
	cin>>n;
	//length of each word
	ll a[n+1];
	for(ll i=1;i<=n;i++)
	cin>>a[i];
        //max width of a line
	ll max;
	cin>>max;
	//space[.][.] contains the number of spaces in a single line
	ll space[n+1][n+1];
	//cost[.][.] contains the cost of particular line
	ll cost[n+1][n+1];
	//opcost[.] contains the cost of optimized solution
	ll opcost[n+1];
	//p[.] for printing the final solution through recursive function printp(...)
	//it keeps track of the path,i.e, from where the optimized cost is coming
	ll p[n+1];
	//loop for calculating space[.][.] when words are arranged in a line
	for(ll i=1;i<=n;i++)
	{
		space[i][i]=max-a[i];
		for(ll j=i+1;j<=n;j++)
		{
			space[i][j]=space[i][j-1]-a[j]-1;
		}
	}
	//loop for calculating cost of particular line when words are arranged in asingle line
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			if(space[i][j]<0)
			{
			//to avoid the condition when words cannot be arranged in one line
				cost[i][j]=inf;
			}
			else if(j==n && space[i][j]>=0)
			cost[i][j]=0;
			else cost[i][j]=space[i][j]*space[i][j];
		}
	}
	
	opcost[0]=0;
	//loop for calculating optimized cost and arrangement of words
	for(ll i=1;i<=n;i++)
	{
		opcost[i]=inf;
		for(ll j=1;j<=i;j++)
		{
			if(opcost[j-1]!=inf && cost[j][i]!=inf && opcost[j-1]+cost[j][i] < opcost[i])
			{
				opcost[i]=opcost[j-1]+cost[j][i];
				p[i]=j;
			}
		}
	}
	//calling printwordwrap(...)
	printwordwrap(p,n);
	cout<<"\n";
	return 0;
}


/*

TEST CASES

-Test-Case 1

Input:
18
7 2 4 2 10 4 6 2 7 2 1 9 3 2 10 4 2 2
20

Output:
Line number 1: From word number 1 to 3
Line number 2: From word number 4 to 6
Line number 3: From word number 7 to 10
Line number 4: From word number 11 to 14
Line number 5: From word number 15 to 17
Line number 6: From word number 18 to 18


-Test-Case 2

Input:
6
4 2 2 7 2 4 
16

Output:
Line number 1: From word number 1 to 3
Line number 2: From word number 4 to 6


Time Complexity - O(n*n)
Space Complexity - O(n*n)

*/

