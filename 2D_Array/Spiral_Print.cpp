#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
 
void spiral_Print(int m, int n,int a[R][C])
{
    int i, k = 0, l = 0;
 
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
        for (i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}
 
int main()
{
    int a[R][C],i,j;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            cin>>a[i][j];
        }
    }
     
    spiral_Print(R, C, a);
    return 0;
}

/*Time complexity of the above solution is : O(m*n)
  Space complexity of the above solution is :O(1) as no extra space is required*/
