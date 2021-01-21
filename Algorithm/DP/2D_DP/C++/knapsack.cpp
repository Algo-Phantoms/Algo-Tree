#include <iostream>
using namespace std;

int topdown(int price[],int weigth[],int n,int capacity,int dp[][100]){

	if(n==0 || capacity==0){
		dp[n][capacity] = 0;
		return 0;
	}



	if(dp[n][capacity]!=-1){
		return dp[n][capacity];
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
		inc = price[n-1] + topdown(price,weigth,n-1,capacity-weigth[n-1],dp); // include
	} 
	exc =  0 +  topdown(price,weigth,n-1,capacity,dp); // exclude


	dp[n][capacity] = max(inc,exc); // take minimum 
	return max(inc,exc);

}

int bottom_up(int price[], int weight[],int n, int capacity){

	int dp[100][100] = {0};

	for(int items = 0; items<=n;items++){
		for(int wei = 0; wei<=capacity;wei++){
			if(items==0 || wei == 0){ 
				dp[items][wei] = 0;
			}
			else{

				int inc = 0, exc = 0;
				if(wei >= weight[items-1]){
					inc = price[items-1] + dp[items-1][wei-weight[items-1]]; // include

				}
				exc = 0 + dp[items-1][wei];  // exclude

				dp[items][wei] = max(inc, exc); // take minimum
			}
		}
	}

  return dp[n][capacity];
}

int main()
{
	int price[100];
	int weigth[100];

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> price[i];
	}
	for(int i=0; i<n; i++){
		cin >> weigth[i];
	}

	int capacity;
	cin>>capacity;

	int dp[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}

	cout<<"Top down - "<<topdown(price,weigth,n,capacity,dp)<<endl;
	cout<<"Bottom up - "<<bottom_up(price,weigth,n,capacity);
	return 0;
}
 
 /*
 Test Case - 
 Input - 4
 10 20 10 15
 2 2 3 1
 30

 Output - 
 Top down - 55
 Bottom up - 55
*/