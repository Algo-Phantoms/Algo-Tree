// C++ Program to sort the given array using bubble sort

#include <bits/stdc++.h> 
using namespace std; 
 
int main()
{

    int i, j, temp = 0, n;
    
	cin>>n;
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}  
    
    for (i = 0; i < n-1; i++)      
   {
       for (j = 0; j < n-i-1; j++)  
       {
       	    // if smaller element found
       	    
            if (arr[j] > arr[j+1])  
            {
            	// swapping elements as required
            	
            	temp = arr[j];      
            	arr[j] = arr[j+1];
            	arr[j+1] = temp;
			} 
	   }
   } 
  
   // print sorted array
   
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
    
    return 0;
}


/*  Test Cases:
    
    Input:
    5
    4 5 12 3 1
    
    Output:
    1 3 4 5 12
    
    Input:
    4
    1 1 2 1
    
    Output:
    1 1 1 2
    
    Time Complexity = O(n^2)
    Space Complexity = O(1)
    
*/
    
