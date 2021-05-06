/* C++ CODE TO SHOW DIFFERENT OPERATIONS ON 2D ARRAY:
Implementation of operations on two different matrices, say A and B, like -
1. Multiplication(A × B)
2. Subtraction(A - B)
3. Addition(A + B)
4. Inverse(A^(-1) and B^(-1)), by checking the order of matrix as well.
*/

#include<iostream>
using namespace std;

// Function to find the sum of two matrices
void addition_of_matrices(int rows, int cols, double a[][20],double b[][20])
{
    int sum[rows][cols];

    for(int  i = 0; i < rows; i++)
    {
	for(int j =0; j < cols; j++)
        {
		sum[i][j] = a[i][j] + b[i][j];
	}
    }

    for(int  i = 0; i < rows; i++ )
    {
	for(int j =0; j < cols; j++)
        {
		cout << sum[i][j] << "\t";
	}
        cout << endl;
    }
}

// Function to find the difference of two matrices
void subtraction_of_matrices(int rows, int cols, double a[][20],double b[][20])
{
    int sub[rows][cols];

    for(int  i = 0; i < rows; i++)
    {
	for(int j = 0; j < cols; j++)
        {
		sub[i][j] = a[i][j] - b[i][j];
	}
    }

    for(int  i = 0; i < rows; i++ )
    {
	for(int j =0; j < cols; j++)
        {
		cout << sub[i][j] << "\t";
	}
        cout << endl;
    }

}

// Function to find the product of two matrices
void product_of_matrices(int rows, int cols, double a[][20],double b[][20])
{
    int mul[rows][cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            mul[i][j] = 0;

            for(int k=0; k < cols ; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int  i = 0; i < rows; i++ )
    {
	for(int j = 0; j < cols; j++)
        {
		cout << mul[i][j] << "\t";
	}
        cout << endl;
    }
}

// Function to find the inverse of matrix
void inverse_of_matrices(int n, double a[][20])
{
    double det = 0;   // Determinant
    double adj[n][n];

    if(n == 2)
    {
        det = (a[0][0] * a[1][1] - a[1][0] * a[0][1]);
        if(det == 0)
        {
            cout << " Inverse cannot be calculated! ";
            return;
        }

        swap(a[0][0],a[1][1]);
        a[0][1] = -a[0][1];
        a[1][0] = -a[1][0];

        for(int i = 0; i < 2 ; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << (a[i][j] / det) <<"\t";
            }
            cout << endl;
        }
    }

    if(n == 3)
    {
        for(int i = 0;i<3;i++)
        {
            det += (a[0][i] * ((a[1][(i+1)%3] * a[2][(i+2)%3]) - (a[1][(i+2)%3] * a[2][(i+1)%3])));

        }
        if(det == 0)
        {
            cout << "Inverse cannot be calculated!";
            return;
        }

        else
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << ((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3]))/det << "\t";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
	double a[20][20], b[20][20];
	int rows, cols;
	cout << "Enter the number of rows and columns: ";
	cin >> rows >> cols;
	cout << "\nEnter the elements of matrix A: "<<endl;
	for(int  i = 0; i < rows; i++ )
	{
		for(int j =0; j < cols; j++)
		{
			cin >> a[i][j];
		}
	}

	cout << "\nEnter the elements of matrix B: "<<endl;
	for(int  i = 0; i < rows; i++ )
	{
		for(int j =0; j < cols; j++)
		{
			cin >> b[i][j];
		}
	}

	cout<<"\nADDITION OF TWO MATRICES: "<<endl;
	addition_of_matrices(rows,cols,a,b);

	cout<<"\nSUBTRACTION OF TWO MATRICES: "<<endl;
	subtraction_of_matrices(rows,cols,a,b);

	if(rows == cols)
        {
		cout<<"\nMULTIPLICATION OF TWO MATRICES: "<<endl;
		product_of_matrices(rows,cols,a,b);

		// Formula for finding inverse of a matrix: A^(-1) = adj(A) / det(A)
		cout<<"\nINVERSE OF MATRIX A: "<<endl;
		inverse_of_matrices(rows,a);
        }
	return 0;
}
/* OUTPUT 1:
Enter the number of rows and columns: 2 2

Enter the elements of matrix A:
3 4 5 6

Enter the elements of matrix B:
1 5 -4 2

ADDITION OF TWO MATRICES:
4       9
1       8

SUBTRACTION OF TWO MATRICES:
2       -1
9       4

MULTIPLICATION OF TWO MATRICES:
-13     23
-19     37

INVERSE OF MATRIX A:
-3      2
2.5     -1.5

OUTPUT 2:
Enter the number of rows and columns: 3 3
Enter the elements of matrix A:
1 2 4 2 3 5 2 1 0
Enter the elements of matrix B:
1 4 6 0 0 2 3 5 2

ADDITION OF TWO MATRICES:
2       6       10
2       3       7
5       6       2

SUBTRACTION OF TWO MATRICES:
0       -2      -2
2       3       3
-1      -4      -2

MULTIPLICATION OF TWO MATRICES:
13      24      18
17      33      28
2       8       14

INVERSE OF MATRIX A:
5       -4      2
-10     8       -3
4       -3      1
Time Complexity: O(n^2)
Space Complexity: O(n^2) */
