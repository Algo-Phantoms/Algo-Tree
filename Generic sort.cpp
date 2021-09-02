

#include <bits/stdc++.h>
using namespace std;

template <class T>
void sortArray(T a[], int n)
{ 
    bool b = true;
	while (b) {
		b = false;
		for (size_t i=0; i<n-1; i++) 
		{
			if (a[i] > a[i + 1]) 
			{
				T temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				b = true;
			}
		}
	}
}


template <class T>
void printArray(T a[], int n)
{
	
	for(size_t i=0;i<n;i++){
	    cout << a[i] << " ";
	}
	cout << endl;
}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	int n, q, i;
	cin>>n>>q;
	
	int intArr[n];
	string strArr[n];
    float floatArr[n];
    
	switch(q)
	{
	    case 1:
	    for(i=0; i<n; i++)
	    {
	        cin>>intArr[i];
	    }
	    sortArray(intArr, n);
    	printArray(intArr, n);
    	break;
        
        case 2:
	    for(i=0; i<n; i++)
	    {
	        cin>>strArr[i];
	    }
	    sortArray(strArr, n);
    	printArray(strArr, n);
    	break;
    	
        case 3:
	    for(i=0; i<n; i++)
	    {
	        cin>>floatArr[i];
	    }
	    sortArray(floatArr, n);
    	printArray(floatArr, n);
    	break;
	}
    }

	return 0;
}
 


/*Input:
3 3
34.23 -4.35 3.4
Output: 
-4.35 3.4 34.23 
Explanation:
The array is of floating type. After
sorting the elements of array are as
such:  -4.35 3.4 34.23
  */
