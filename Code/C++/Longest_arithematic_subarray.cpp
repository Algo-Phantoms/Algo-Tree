/*An arithmetic array is an array that contains at least two integers and the difference between 
consecutive integer are equal. Example:- [9,10] , [3,3,3] , [9,7,5,3]
WAP to input an array of size n and find the lenght of longest contigous arithematic subarray

Test case 1:-

input- 8
       17 8 16 24 30 4 2 5
       
output- 3

Test case 2:-

input- 7
       4 5 6 6 6 6 6

output:- 5
*/

#include <iostream>

using namespace std;

int main()
{
    int n;//size of array
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++)//enter the values in the array
    {
        cin>>a[i];
    }
    
    int ans=2;//maximum arithematic subarray length
    
    int pd= a[1]-a[0];//previous common difference
    int j=2;
    
    int curr=2;//denotes the current arithematic subarray
    
    while(j<n)
    {
        if(pd==a[j]-a[j-1])
        curr++;// arithematic array including a[i]
        else
        {
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans=max(ans,curr);// finds the length of the max array
        j++;
    }

    cout<<ans<<endl;
    return 0;
}
