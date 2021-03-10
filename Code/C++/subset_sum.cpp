/*
    Problem Statement : 
        You are given a set of non-negative integers and a sum and the task is to find out if there is any subset of the given set
        with sum equal to the given sum.

    Approach : 
        To consider all subsets of items, there can be two cases for every item:
            (1) the item is included in the optimal subset, 
            (2) not included in the optimal set. Therefore, the maximum value that can be obtained from n items is max of following two values.

        we will use the top down approach of Dynamic programming to solve this problem. We will create a 2D array (dp[][]) of size 
        (n+1)(sum+1). The value of dp[i][j] will be true if there exists a subset of elements from arr[0….i] with sum value = ‘j’. 
*/

#include <iostream>
using namespace std;

//Function to calculate the subset sum
bool subset_sum(int arr[], int max_sum, int n)
{
    int i,j;
    //top down matrix
    bool dp[n+1][max_sum+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=max_sum;j++)
        {
            //To fill the first column
            if(j==0){
                dp[i][j] = true;
            }

            //To fill the first row
            else if(i==0){
                dp[i][j] = false;
            }

            //for filling the rest of the cell
            else{

                //if the current array element is greater then the current max_sum
                //condition for ecluding the array element
                if(arr[i-1]>max_sum){
                    dp[i][j] = dp[i-1][j];
                }

                //Condition for including the array element
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
    }
    //answer will be the last cell of the dp matrix
    return dp[n][max_sum];
}

//main method
int main()
{
    int arr[100], n, i, max_sum;
    cout << "Enter the number of elements : ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout << "Enter element at index "<< i << " : ";
        cin >> arr[i];
    }
    cout << "Enter the sum : ";
    cin >> max_sum;
    //function calling
    if(subset_sum(arr,max_sum,n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;    
}

/*
    Test Cases : 
    1. arr[3, 22, 41, 35, 6, 12]
       max_sum = 9
       Output : Yes

    2. arr[2, 19, 4, 3, 62, 12]
       max_sum = 27
       Output : No

    Time Complexity : O(sum*n)
    Space Complexity : O(sum*n)
*/