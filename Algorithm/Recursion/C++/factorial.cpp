#include<iostream>
using namespace std;

 int fact(int n){
 	if(n==0)
 		return 1;
 	int ans = n*fact(n-1);

 	return ans;
 }

 int main() {

 	int n;
 	cin >> n;
 	cout<<fact(n);
 	return 0;
 }

/* Test case - 
 Input - 6
 Output - 720
 */