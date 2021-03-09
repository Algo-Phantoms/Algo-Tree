/**
    Problem Statement : 
        You are given a set of non-negative integers and the task is to divide the set in two half such that the sum of the elements of
        both the subsets are equal.

    Approach : 
        To consider all subsets of items, there can be two cases for every item:
            (1) the item is included in the optimal subset, 
            (2) not included in the optimal set. Therefore, the maximum value that can be obtained from n items is max of following two values.

        we will use the top down approach of Dynamic programming to solve this problem. At first we will calculate the sum of the 
        entire array and check if the value is odd or even. If the value is odd then it is sure that we will not be able to divide the set
        according to given problem and if the sum is even then We will create a 2D array (dp[][]) of size 
        (n+1)(sum/2+1). The value of dp[i][j] will be true if there exists a subset of elements from arr[0….i] with sum value = ‘j’. 
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
                if(j!=0)
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

//Function to check whether we can divide the array in two parts
//having the same sum 
bool equal_sum_partition(int arr[], int n)
{
    int i,sum=0;

    //calculating the sum of the array
    for(i=0;i<n;i++)
    {
        sum += arr[i];
    }

    //if the sum of the elements of the array is an odd number
    if(sum%2!=0)
    {
        return false;
    }

    //if the sum is an even number
    return subset_sum(arr, sum/2, n);
}

//main method
int main()
{
    int arr[100], n, i;

    //taking input from the user
    cout << "Enter the number of elements : ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout << "Enter element at index "<< i << " : ";
        cin >> arr[i];
    }

    //function calling
    if(equal_sum_partition(arr,n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;  
}

/*
    Test Cases : 
    1. arr = [2, 5, 9, 12, 11, 1]
       Output : Yes

    2. arr = [2, 65, 7, 34, 12, 90]
       Output : No

    Time Complexity : O(sum*n)
    Space Complexity : O(sum*n)
*/