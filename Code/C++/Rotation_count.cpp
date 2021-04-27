/*

 C++ program to find number of rotations
 in a sorted and rotated array.


In an given sorted array,we will have to find the number of count
of rotation after which we have got this array.Here, we take into
observation the element i which is greater than the element i+1.
After we get this element we calculate the number of rotation that might have occured.
*/



#include<bits/stdc++.h>
using namespace std;
 
// Returns count of rotations for an array
int countRotations(int arr[], int n)
{
   //here we find index of minimum element
    int min = arr[0], min_index;
    for (int i=0; i<n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}
 
// Driver code
int main()
{

    int arr[20],n,i;
    cout<<"enter the number of element\n";
    cin>>n;
    cout<<"now enter the numbers one by one:\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout << countRotations(arr, n);
    return 0;
}

/*

input: {15,16,18,19,1,2,4,6,7}
output:4 //after 4 right rotation of {1,2,4,6,7,15,16,18,19} we get this output

input:{1,2,3,4,5,6}
output:0 //there is no rotation

*/