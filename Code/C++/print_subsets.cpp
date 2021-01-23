#include<iostream>
#include<cstring>
using namespace std;

void subset(char c[]){
   
  int l = strlen(c)-1;
  int tot = 1<<l; // 2^n - total subsets
  for(int mask=0;mask<tot;mask++){
  	for(int i=0;i<l;i++){
  		int f = 1<<i; 
  		if(mask & f){ //setbit
  			cout << c[i];
  		}
  	}
  	cout << "\n";
  }
}

int main(){

	char c[]={'A','B','C'};
	subset(c);
	return 0;
}

/*
 Output - 

A
B
AB
*/