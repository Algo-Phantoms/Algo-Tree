/*Here we are printing the matrix in clockwise direction*/

#include <iostream>
#define ll long long
using namespace std;
int main() {
    ll row,col;
    cin>>row>>col;
    ll mat[row][col];
    for(ll i=0;i<row;i++)
    {
        for(ll j=0;j<col;j++)
        cin>>mat[i][j];
    }
    ll start_row=0,start_col=0,end_row=row-1,end_col=col-1;
    while(start_row<=end_row and start_col<=end_col)
    {
        for(ll j=start_col;j<=end_col;j++)
        {
            cout<<mat[start_row][j]<<" ";
        }
        start_row++;
        for(ll j=start_row;j<=end_row;j++)
        {
            cout<<mat[j][end_col]<<" ";
        }
        end_col--;
        for(ll j=end_col;j>=start_col;j--)
        {
            cout<<mat[end_row][j]<<" ";
        }
        end_row--;
        for(int j=end_row;j>=start_row;j--)
        {
            cout<<mat[j][start_col]<<" ";
        }
        start_col++;
    }
    return 0;
}

/*


        Test case 1:

        4 4         //no of rows and columns
        11 12 13 14 //matrix
        21 22 23 24
        31 32 33 34
        41 42 43 44


        OUTPUT:
        11 12 13 14 24 34 44 43 42 41 31 21 22 23 33 32




        Test case 2:

        6 4
        11 13 15 17
        19 12 14 16
        18 10 21 23
        25 27 29 22
        24 26 28 30
        31 33 35 37


        OUTPUT:
        11 13 15 17 16 23 22 30 37 35 33 31 24 25 18 19 12 14 21 29 28 26 27 10


*/
