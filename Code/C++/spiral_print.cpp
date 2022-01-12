/*
	To print the elements of a 2D matrix in spiral order
	Example: The given matrix is:
		  7 3 4
		  2 6 9
		  4 7 8
		 The spiral print order is:
		  7 3 4 9 8 7 4 2 6	
*/

#include<iostream>
using namespace std;

void spiralprint(int a[][30], int r, int c){

	//start row
	int sr = 0;

	//end row 
	int er = r-1; 

	// start coloumn
	int sc = 0;  

	//end column
	int ec = c-1; 
	int ele = 0;
	while(ele < r*c){

		// top row
		for(int i=sc; i<=ec;i++){ 
			cout << a[sr][i] <<" ";
			ele++;
		}
		sr++;
		if(ele == r*c)
			break;

		// last column
		for(int i=sr; i<=er;i++){ 
			cout << a[i][ec] <<" ";
			ele++;
		}
		ec--;
		if(ele == r*c)
			break;

		// last row
		for(int i=ec; i>=sc;i--){  
			cout << a[er][i] <<" ";
			ele++;
		}
		er--;
		if(ele == r*c)
			break;

		// first coloumn
		for(int i=er;i>=sr;i--){  
			cout << a[i][sc] <<" ";
			ele++;
		}
		sc++;

	}

}

int main() {

	int a[30][30];

	int r, c;
	cin >> r >>c;

	for(int  i = 0; i < r; i++ ){
		for(int j =0; j < c; j++){
			cin >> a[i][j];
		}
	}

	spiralprint(a,r,c);

	return 0;
}

/* 
	Test Cases :

	Input : 3 3
	1 2 3
	4 5 6
	7 8 9

	Output : 1 2 3 6 9 8 7 4 5
 */
