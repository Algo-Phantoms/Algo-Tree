/*
In wave-printing programs we print the elements of the matrix in a certain wave form. 
The wave might start from the first element and end-up to the last element or it might be in 
reverse order too . 
We are using column-wise wave printing here . 

for example :-      
					1  2  3
					4  5  6
					7  8  9

					1   7   5   3   9    <--- Such kind of wave manner would be used to traverse and print the elements . 
					  4   8   2   6

Approach :-
	- We will use while loop and will iterate upto last column number(it will be our primary loop)
	- Under the primary loop , we will use if-else statements to determine the odd and even column number
	- then , for even column , we will go top to bottom and for odd , bottom to top and will print in such manner only . 
*/

#include<iostream>
using namespace std;

void waveprint(int a[][30], int r, int c){
	for(int column = 0; column < c; column++){
		if(column%2==0){
			// even -->print top to botom

            for(int row = 0; row < r; row++){
            	cout << a[row][column]<<" ";
            }
		}
		else{
			// odd --> print bottom to top
			for(int row = r-1; row>=0;row--){
				cout<<a[row][column]<<' ';
			}

		}
	}
	return;
}

int main(){


	int a[30][30];

	int r, c;
	cin >> r >>c;

	for(int  i = 0; i < r; i++ ){
		for(int j =0; j < c; j++){
			cin >> a[i][j];
		}
	}

	waveprint(a,r,c);


	return 0;
}


/* 
	Test case :

	Input : 3 3
	1 2 3
	4 5 6
	7 8 9

	Output : 1 4 7 8 5 2 3 6 9 

	Time Compexity of waveprint() : O(c*r)
	Space Complexity of waveprint() : O(1)
*/