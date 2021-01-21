#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
       cin >> a[i];
	}
	
	for(int i = 1;i<n ;i++ ){
		for(int j = i; j>0 ; j-- ){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
			else{
				break;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}


	return 0;
}

/* Test case - 
Input - 5
4 3 5 1 2

Output - 
1 2 3 4 5

*/

