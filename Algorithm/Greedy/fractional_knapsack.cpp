/*
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
We can take a fraction of a particular item.
*/

#include<bits/stdc++.h>
using namespace std;
void knapsack(int n,float weight[],float profit[],float items[],int knapsack_cap)
{
	float p=0.0;
	bool flag[n];
	float quantity[n];
	int ub=0;//current weight in knapsack
	//An array to store the quantity of ith item that are picked in descending order
	for(int i=0;i<n;i++)
		quantity[i]=0.0;
	for(int i=0;i<n;i++)
	{
		if(ub+weight[i]<=knapsack_cap)
		{
			//If the value is less than the knapsack capacity,total item is considered
			quantity[i]=1;
			ub+=weight[i];
			p+=profit[i];
		
		}
		else
		{
			quantity[i]=(float)(knapsack_cap-ub)/weight[i];
			//Entire knapsack gets filled
			p+=quantity[i]*profit[i];
			break;
		}
	}
	cout<<"Total profit "<<p<<endl;	
	cout<<"Items ratio considered: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<quantity[i]<<" ";
	}	
}

int main()
{
	int n,val,knapsack_cap;
	float temp;
	cout<<"Enter number of items";
	cin>>n;
	float weight[n],profit[n],items[n];
	cout<<"Enter weights of the items"<<endl;
	for(int i=0;i<n;i++)
		cin>>weight[i];
	cout<<"Enter profit for each item"<<endl;
	for(int i=0;i<n;i++)
		cin>>profit[i];
	cout<<"Enter the knapsack capacity"<<endl;
		cin>>knapsack_cap;
	// calculate (profit/weight) ratio for each item
	for(int i=0;i<n;i++){
		items[i]=(float)profit[i]/weight[i];
		cout<<items[i]<<" ";
	}
	//sort the items in descending order based on their ratio
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(items[i]<items[j])
			{
				temp=items[i];
				items[j]=items[i];
				items[i]=temp; 
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
			}
		}
	}
	knapsack(n,weight,profit,items,knapsack_cap);
	return 0;
}
/* Test case 1:
   weights[i]= 10 20 30
   profit[i]= 60 100 120
   knapsack capacity= 50
   
   Output:
   Total profit 240
	Items ratio considered:
	1 1 0.666667
	
	TestCase 2:
	weights[i]=40 10 20 24
	profit[i]=280 100 120 120
	knapsack capacity=60
	
	Output:
	Total profit 440
	Items ratio considered:
	1 1 0.5 0
	
    Time Complexity : O(n*n) ,this problem can solved in O(nlogn) by using a sorting algorithm which takes an O(nlogn)
    Space Complexity: O(n)
*/
