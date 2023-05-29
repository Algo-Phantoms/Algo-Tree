//Ques: Find the subarry sum in an array of size n such that its sum is greater than x.
//language: C++
//subarray:- A subbarray is a contiguous part of an array.

//input: n (no. of elements)
//       arr[0] arr[1] arr[2] ..... (space seperated integers)
 //      x      
//output: ans  (subarray sum just greater than x)

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool isPresent(int v[],int n,int sum)          //this function checks wheather the provided subarray sum("sum") is possible in this array or not
{
	int i,j,x=0;
	for(i=0;i<n;i++){
		j=i;
		x=0;
		while(j<n && x<sum)         //keep on adding elments from array until it becomes greater than provided sum
		{
			x+=v[j];
			j++;
		}
		if(x==sum)      //checks if subarray sum from i to j is equal to sum(given) or not
		return true;
	}
	return false;
}



int main()
{
	int x,n,i,tot=0,ans,flag=0;
	cin>>n;
	int v[n];
	
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		tot+=v[i];    //finding maximum possible sum 
	}
	cin>>x;   //taking x as input and we need to find that smallest possible subarray sum which is just greater than x
	for(i=x+1;i<=tot;i++){
		//cout<<i<<endl;
		if(isPresent(v,n,i))
		{
			flag=1;
			ans=i;
			break;
		}
		
	}
  if(flag==0)   
    cout<<"Not possible\n";
  else
	cout<<ans<<endl;
	
	return 0;
}

//Time Complexity: O(n^2)
//e.g : input:-5		(n-size of array)
/*		1 4 10 5 2		(arr[]-values of array)
		9			    (sum)
	output:	10			(result- as we are suppose to find the smallest sum greater than sum)
	*/


