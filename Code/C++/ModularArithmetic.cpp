/* Program that performs ADDDTION,SUBTRACTION, MULTIPLICATION, DIVISION, POWER.
so, we are taking inputs 'a' and 'b' for above operaitions and also given MOD 'm'.
All of them have constraints 1 to 10^50000

Explaining the main points- 

1 .  For performing DIVISION (a/b) we have to calculate the multiplicative inverse of 'b' first. The value of x should be in { 1, 2, … m-1}, i.e., in the range of integer 
modulo m. ( Note that x cannot be 0 as a*0 mod m will never be 1 )
The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

2.  As our inputs are larger (10^50000) we cannot store them using long long int or any other datatype, so we are going to store them in string and convert it into 
long long int datatybe, after gradually and simulteneously calulating modulo operation.

3.  For above,  According to Feramts Little Theorem  
         a^(p-1) mod p   =  1, When p is prime.
   From this, as of the problem, M is prime, express A^B mod M as follows: 
          A^B mod M = ( A^(M-1) * A^(M-1) *.......* A^(M-1) * A^(x) ) mod M          
   Where x is B mod M-1 and A ^ (M-1) continues B/(M-1) times
   Now, from Fermat’s Little Theorem,  
           A ^ (M-1) mod M = 1.
           A^B mod M = ( 1 * 1 * ....... * 1 * A^(x) ) mod M
   Hence mod B with M-1 to reduce the number to a smaller one and then use power() method to compute (a^b)%m. 
            
   
TIME COMPLEXITY - 
        to convert inputs into modular value it will take bits 500000*log(10) approx O(1).
        
        to calculate  addition subtraction multiplication the time complexity is O(1).
        to calculate division and power it will take O(Log m) time complexity, where is modulo given, Since after converting long input string to a number it will be under 'm'.

*/




#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define MOD 1000000007
#define ftio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //This is just used for fast input output operations

ll m,md;
ll gcd(ll a,ll b,ll *x,ll *y); // Function declaration

ll inverse(ll b,ll m){   // see point 1
    ll x,y;
    ll g=gcd(b,m,&x,&y);
    if (g != 1) 
        return -1;
    
    return (x%m + m) % m; 
    
}
ll gcd(ll a, ll b, ll *x, ll *y) // Extended Euclidean algorithm to claculate GCD;
{
    if (a == 0) 
    { 
        *x = 0;
        *y = 1; 
        return b; 
    } 
  
    ll x1, y1;  
    ll g = gcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return g; 
}
ll gcd1(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd1(b, a % b);  
      
} 

ll modm(string s){ // see point 2
     ll number = 0; 
    for (ll i = 0; i < s.length(); i++) 
    { 
        number = (number*10 + (s[i] - '0')); 
        number %= m; 
    } 
    return number; 
}
int main()
{
    ftio;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        string si,x,y;
        cin>>si>>x>>y;
        cin>>m;
        
        if(si=="+"){
            a=modm(x);
            b=modm(y);
            cout<<((a+b) % m)<<"\n";
        }
        else if(si=="-"){
           a=modm(x);
            b=modm(y);
            cout<<((a-b + m) % m)<<"\n"; // to handle the underflow, we have to add the mod value and then calculate the modulo operation
        }
        else if(si=="*"){
           a=modm(x);
            b=modm(y);
            cout<<((a*b) % m)<<"\n";
        }
        else if(si=="^"){
             ll res = 1;      
             
            a=modm(x);
            md=m;
            m-=1;   // see point 3
            
            b=modm(y);
            m=md;
            if (a == 0) cout<<0<<"\n"; 
          else{
            while (b > 0)  // calculating a^b after performing modular operation on them
            {  
                if (b & 1)  
                    res = (res*a) % m;  
                a = (a*a) % m;
                b = b>>1; //Similar to  b=b/2
                  
            }
            cout<<(res%m)<<"\n";
          }    
        }
        else{
            a=modm(x);
            b=modm(y);
            ll g = gcd1(a,b);
            if(g!=1){
                a=a/g;
                b=b/g;
            }
            ll inv = inverse(b, m); // see the explaination above 
            if (inv == -1) 
               cout <<-1<<"\n"; 
            else
               cout<< (a * inv) % m <<"\n";
        }
        
        

        
    }
    return 0;
}



/*
Sample Input 1 
5
+ 2 3 2
- 14 6 3
* 11 3 5
/ 9 4 7
^ 3 3 11
Sample Input 2
5
+ 20986 303835 298
- 148765 60000 393
* 11937 3973632 59
/ 19 4 5
^ 100000000000 1000009875 7

Output 1
1
2
3
4
5
Ouput 2
1
340
12
1
6
*/

