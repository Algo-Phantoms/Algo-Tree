/* ROW WISE SUM OF A 2D ARRAY :
For a given 2-D integer type array of size (N x M), find and print the sum of each of the row elements in a single line, separated by a single space.*/

#include <iostream>
using namespace std;

void row_wise_sum(int *arr,int r,int c)
{
    for (int i = 0; i < r ; i++)
    {
        int sum = 0;
        for (int j = 0; j < c ; j++)
        {
            sum += *((arr + i * c) + j);
        }
        cout << sum << " ";
    }
}

int main()
{
    int rows,cols;
    cout<<"Enter the number of rows and columns:";
    cin >> rows >> cols;
    int arr[rows][cols];

    cout<<"Enter the elements of the 2D array:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<"Row-wise Sum:"<<endl;
    row_wise_sum(&arr[0][0],rows,cols);
    return 0;
}
/* EXAMPLE 1:
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

Time Complexity - O(N * M)
Space Complexity - O(1) */
