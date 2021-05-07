/**An array element is a peak if it is NOT smaller than
its neighbours. For corner elements, we need to
consider only one neighbour.
Since an array always have a maximum value therefore an peak element always be there and there can be many peak element.
Approach : We will iterate for entire loop and check if peak element is found.
**/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements in the array : ";
	cin >> n;
	vector<int> v(n);
	cout << "\nEnter the elements of the array : \n";
	for (int i = 0; i < n; i++)
	{
	    cin >> v[i];
	}

	int peak;
	for(int i=0;i<n;i++)
	{
	    if( (i==0 && v[0]>=v[1]) || (i==n-1 && v[n-1]>=v[n-2]) || (v[i]>=v[i-1] && v[i]>=v[i+1]) )
	    {
	        peak = v[i];
	        break;
	    }
	}
	cout << "Peak element : " << peak << "\n";
	return 0;
}

/**
Eg. :
Input: 
7
10 20 15 2 23 90 67

Output: 
Peak element : 20

Time Complexity : O(N)
Space Complexity : O(N)
**/
