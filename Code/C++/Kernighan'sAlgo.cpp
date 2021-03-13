/*


kernighans algorithm  To calculate the number of setbits in a given Number .
setbits are the bits whose value is 1 , and
unset bits are whose value is 0
when we change the number from decimal to binary


*/


#include <bits/stdc++.h>
using namespace std ;

int KernighanAlgo (int n ) {

	int count = 0 ;
	while (n) {
		n = (n & (n - 1)) ;
		count ++ ;
	}
	return count ;
}



int main ()
{
	int n ;
	cin >> n ;
	cout << KernighanAlgo (n) ; // calling the above function

	return 0 ;
}


/*


Test Cases :
	For 1 : In 1 we have only 1 set bit ,  0001 Hence the output for this test case will be 1
	For 15 : In 15 we have total 4 set bits  1111 Hence the output for this test case will be 4


Time Complexity for Kernighan's algorithm is O(log(N))


*/