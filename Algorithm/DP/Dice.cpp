/*  Counting the number of ways to construct sum 'n' by throwing dice one or more times
    Example for n=3
    Ways to generate 3 -> 1. (1 + 1 + 1)
                       -> 2. (1 + 2 )
                       -> 3. ( 2 + 1 )
                       -> 4. ( 3 )

*/

/* Code in CPP using DP */

//poojasingh
#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD     1000000007
#define mp      make_pair
#define pb        push_back
#define f           first
#define s          second
#define ln "\n"
#define min_heap    priority_queue<ll,vector<ll>,greater<ll>>
#define max_heap     priority_queue<ll>

void code()
{
    ll n;
	cin>>n;
     ll a[n+1]={0};
	a[0]=1;
	for(ll i=1;i<n+1;i++)
	{
	    for(ll j=1;j<=6;j++)
	    {
	        if(j>i)
	        break;
	        a[i]=(a[i]+(a[i-j]))%(1000000007);
	    }
	}
	cout<<a[n]<<endl;
}
int main()
{
    FAST;
	ll t;
	t=1;
	while(t--)
	{
	     code();
	}

	return 0;
}

/* TEST CASES

   INPUT : 1
   OUTPUT : 1

   INPUT : 4
   OUTPUT : 8

*/

/* TIME COMPLEXITY : O(6*n)
   SPACE COMPLEXITY : O(n)
*/
