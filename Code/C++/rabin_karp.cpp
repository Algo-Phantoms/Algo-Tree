#include<iostream>
using namespace std;
#define int long long int

const int mod = 1e9+7;
const int p = 31;
int powr(int a, int b){ // binary exponentiation(a^b %m) - o(log b)
     int res = 1;
     while(b){

       if(b & 1LL){
          res *= a;
          res %= mod;
       }
       b /= 2;
       a *= a;
       a %= mod;
     }
     return res;
}

int inv(int a){ 
   
   //a^-1 % m
	return powr(a, mod-2); //fermats little theorem
}

int poly_hash_string(string s){ // hash function
   
   int p_powr = 1;
   int hash = 0;

   for(int i=0;i<s.size();i++){
      hash += (p_powr*(s[i]-'a' + 1));
      p_powr *= p;
      p_powr *= mod;
      hash %= mod;
   }

   return hash;
   
}

int32_t main(){
    
    string text = "ababab", pat = "aba";

    int pat_hash = poly_hash_string(pat);
     
    int n = text.size(), m = pat.size();

    int text_hash = poly_hash_string(text.substr(0,m));

    if( text_hash == pat_hash){ // found at index 0
       cout<<0;
    }

    for(int i=1;i+m <= n;i++){ // rolling hash
       int new_hash = text_hash;
       //[i-1] th
       // removed the [i-m] char
       new_hash = (new_hash - (text[i-1] - 'a' + 1) + mod) % mod;

       //divide by p (make 1 power less)
       new_hash *= inv(p);
       new_hash %= mod;

       //add 
       new_hash = new_hash + (text[i+m-1] - 'a' + 1) * powr(p, m-1);
       new_hash %= mod;

       if(new_hash == pat_hash){
         cout<< i <<"\n";
       }
       text_hash = new_hash;
    }
    
   return 0;
}

/* Output - 0*/