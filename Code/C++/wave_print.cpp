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


/* Test case -

 Input - 3 3
1 2 3
4 5 6
7 8 9

Output - 1 4 7 8 5 2 3 6 9 
*/