/*
We have n jobs and we are given the start and end time of every job and the profit obtanined from the respective job.
Find the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/

/*
Explanation: 
1) Sort the jobs by end time.
2) dp[time] = profit means that within the first time duration we can make the most profit money.
    Initially dp[0] = 0 as we make profit=0 at time=0
3) For each job = [start, end, profit] 
The logic is similar to Knapsack problem. 
    If we don't do this job then nothing will be changed.
    If we do this job binary serach in the dp to find the largest profit we can make before start time s.
    So we also know the maximum current profit that we can make doing this job.

Compare the last elements in the dp. 
we make more money,
it worth doing this job,
then we add the pair [end, curr] to the back of dp. 
Otherwise we don't do this job.
*/


#include <bits/stdc++.h>
using namespace std;

//Comparator to sort the vector according to the end time of jobs
bool comp( vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}

//Binary serach fucntion to find the largest profit we can make before start time s
int binarySearch( vector<vector<int>>& jobs, int index){
    //initializing the low and high for binary search
    int low = 0;
    int high = index - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        //If the end time of mid job is less than equal to start time of the index job 
        if( jobs[mid][1] <= jobs[index][0] ){
            if(jobs[mid+1][1] <= jobs[index][0] ){
                low = mid + 1;
            }
            //if the end time of mid+1th job is more than the start time of the index job return mid
            else
                return mid;
        }
        //if the end time is more than the idexth job then reduce the scope of binary search from low to high-1
        else
            high = mid -1 ;
    }
    //return -1 if find no such job 
    return -1;
}

int main(){

    //Input the number of jobs
    int n;
    cin>>n;

    //Input the start and end time of jobs and profit
    vector<int> start(n);
    vector<int> finish(n);
    vector<int> profit(n);

    for(int i=0;i<n;i++){
        cin>>start[i];
    }

    for(int i=0;i<n;i++){
        cin>>finish[i];
    }

    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    //Initalise a job vector which stores the start and end time and profit of respective jobs
    vector<vector<int>>job(n);

    for(int i=0;i<n;i++)
    {
        job[i]={start[i],finish[i],profit[i]};
    }

    //sort the vector according to end time of the jobs in non-decreasing order
    sort(job.begin(),job.end(),comp);

    //Initialise a dp vector which stores dp[time] = profit means that within the first time duration we can make the most profit money.
    vector<int>dp(n,0);

    dp[0] = job[0][2];

    for(int i=1;i<n;i++){
        //peform a binary search to check if there is a job which ends at starting time of job[i]
        int q = binarySearch(job, i);

        //if the binary search function does not return -1
        if(q!=-1)
            dp[i] = max(dp[i-1], dp[q]+job[i][2]);
        //if returns -1 then we do not include the job
        else
            dp[i] = max(dp[i-1], job[i][2]);
    }

    //Maximum profit will be stored in dp[n-1]
    cout<<"Maximum profit earned is "<<dp[n-1]<<endl;

    return 0;
}

/*
Input: 
    5
    1 2 3 4 6
    3 5 10 6 9
    20 20 100 70 60

Output:
    Maximum profit earned is 150

Time Complexity : O(nlogn) for sorting 
                  O(nlogn) for binary search 
                  where n is the number of jobs 

Space Complexity : O(n) for storing the jobs

*/

