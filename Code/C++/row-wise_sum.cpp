/* ROW WISE SUM OF A 2D ARRAY */

#include <iostream>
using namespace std;

void row_wise_sum(int arr[][50],int r,int c)
{
    for (int i = 0; i < r ; i++)
    {
        int sum = 0;
        for (int j = 0; j < c ; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

int main()
{
    int arr[50][50];
    int rows,cols;
    cout<<"Enter the number of rows and columns:";
    cin >> rows >> cols;

    cout<<"Enter the elements of the 2D array:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Row-wise Sum:"<<endl;
    row_wise_sum(arr,rows,cols);
    return 0;
}


/*

EXAMPLE 1:

Enter the number of rows and columns:3 4

Enter the elements of the 2D array:
1 2 3 4
0 -2 -1 3
-6 2 1 11

Row-wise Sum:
10 0 8


EXAMPLE 2:

Enter the number of rows and columns:3 3
Enter the elements of the 2D array:
1 2 3
6 4 2
4 5 7
Row-wise Sum:
6 12 16

*/
