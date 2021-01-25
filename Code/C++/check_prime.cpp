#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long

const int n = 1000000;
bitset<1000000> b;
vector<int> primes;

void sieve() {
 
    //set all bits
    b.set();

    b[0]=b[1] = 0;

    for(ll i=2; i<=n;i++){
       if(b[i]){
         primes.push_back(i);
         for(ll j=i*i; j<=n;j = j+i){
           b[j]=0;
         }
       }
    }
}

bool isPrime(ll no){
   if(no<=n){
      return b[no]== 1? true : false;
    }

    for(ll i=0;primes[i]*(ll)primes[i]<=no;i++){
        if(no%primes[i] ==0 ){
            return false;
        }
    }
    return true;
}
int main(){

	sieve();
  int n;
  cin >> n;

	if(isPrime(n)){
      cout<<"yes";
	}
	else {
      cout<<"no";
	}

   return 0;
}

/* 
 Test case :

 Input : 45
 Output : no

 */