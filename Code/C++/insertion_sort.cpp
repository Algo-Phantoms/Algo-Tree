/*
Insertion sort is a simple and efficient comparison sort. In this algorithm, each iteration removes
an element from the input data and inserts it into the correct position in the list being sorted. The
choice of the element being removed from the input is random and this process is repeated until
all input elements have gone through.

 * Algorithm :
	Every repetition of insertion sort removes an element from the input data, and inserts it into the
	correct position in the already-sorted list until no input elements remain. Sorting is typically done
	in-place. The resulting array after k iterations has the property where the first k + 1 entries are
	sorted.Each element greater than x is copied to the right as it is compared against x.
*/

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

/* 
Test case : 
Input - 5
4 3 5 1 2

Output : 
1 2 3 4 5

Time Complexity : 
	Worst case complexity: Θ(n^2 )
	Best case complexity: Θ(n)
	Average case complexity: Θ(n^2 )
	Worst case space complexity: O(n^2 ) total, O(1) auxiliary
*/

