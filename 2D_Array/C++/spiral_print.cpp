#include<iostream>
using namespace std;

void spiralprint(int a[][30], int r, int c){
	int sr = 0; //start row
	int er = r-1; //end row
	int sc = 0;  // start coloumn
	int ec = c-1; //end column
	int ele = 0;
	while(ele < r*c){
		for(int i=sc; i<=ec;i++){ // top row
			cout << a[sr][i] <<" ";
			ele++;
		}
		sr++;
		if(ele == r*c)
			break;
		for(int i=sr; i<=er;i++){ // last column
			cout << a[i][ec] <<" ";
			ele++;
		}
		ec--;
		if(ele == r*c)
			break;
		for(int i=ec; i>=sc;i--){  // last row
			cout << a[er][i] <<" ";
			ele++;
		}
		er--;
		if(ele == r*c)
			break;
		for(int i=er;i>=sr;i--){  // first coloumn
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

/* Test Cases -

Input - 3 3
1 2 3
4 5 6
7 8 9

 Output - 1 2 3 6 9 8 7 4 5
 */