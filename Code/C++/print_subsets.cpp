/*
Given a character array of size n, print all the subsets of the set .

Approach:

* Start from num = 2^n - 1 upto 0.
* Consider the binary representation of num with n bits.
* Start from the leftmost bit which represents 1, the second bit represents 2 and so on until nth bit which represents n.
* Print the number corresponding to the bit if it is set.
* Perform the above steps for all values of num until it is equal to 0.

*/

#include<iostream>
#include<cstring>
using namespace std;

void subset(char c[]){
   
    int l = strlen(c)-1;
    // 2^n - total subsets
    int tot = 1<<l; 
    for(int mask=0;mask<tot;mask++){
        
    	for(int i=0;i<l;i++){
    		int f = 1<<i; 
            //setbit
    		if(mask & f){ 
    			cout << c[i];
    		}
    	}
    	cout << "\n";
    }
}

int main(){

    int n;
    cin >> n;
    char c[n];
    cin >> c;
    subset(c);
    return 0;
}

/*

    Test Case : 

    Input : 
    3
    ABC

    Output : 

    A
    B
    AB

    Time Complexity: O(n*2^n)
    Space Complexity: O(1)

*/