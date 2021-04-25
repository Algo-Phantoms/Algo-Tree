/*
Given a 2 dimensional integer array a with given rows and columns.
Print the array in spiral form in clockwise direction. 
*/

#include<bits/stdc++.h>
using namespace std;
//function that will print the 2D array in spiral form
void spiral(int m,int n,int a[][1000])
{
    //these variables will trace the index of starting and ending row as well as column
    int sr=0,er=m-1,sc=0,ec=n-1;
    while(sr<=er && sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        cout<<a[sr][i]<<" ";
        sr++;
        if(ec>sc)
        {
            for(int i=sr;i<=er;i++)
            cout<<a[i][ec]<<" ";
        }
        ec--;
        if(er>sr)
        {
            for(int i=ec;i>=sc;i--)
            cout<<a[er][i]<<" ";
        }
        er--;
        for(int i=er;i>=sr;i--)
        cout<<a[i][sc]<<" ";
        sc++;
    }
}
int main()
{
    //these variables will store the value of row and columns
    int m,n;
    cout<<"Enter the values of row and column respectively : ";
    cin>>m>>n;
    //the matrix will store the values entered by user
    int a[m][1000];
    cout<<"Enter the values of the matrix : "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Array after printing it in spiral form : ";
    //calling the function
    spiral(m,n,a);
    return 0;
}

/*
Sample Input :
Enter the values of row and column respectively : 3 5
Enter the values of the matrix : 
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
Output :
Array after printing it in spiral form : 1 2 3 4 5 10 15 14 13 12 11 6 7 8 9 
*/

/*
Time Complexity : O(m*n)
Space Complexity : O(1)
*/
