/*
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the 
elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 
 */

#include<iostream>
using namespace std;

void permutation(char a[], int i){
	
	if(a[i]=='\0'){				// base
		cout<<a<<"\n";
		return;
	}
	for(int j=i;a[j]!='\0';j++){
		swap(a[i],a[j]);
		permutation(a,i+1);
		swap(a[i],a[j]);
	}
}

int main() {

	char a[100];
	cin >> a;
	permutation(a,0);
	return 0;
}

/*

Input : abc

Output :
abc
acb
bac
bca
cba
cab

Time Complexity: O(n*n!)
Space Complexity: O(n*n!)

*/