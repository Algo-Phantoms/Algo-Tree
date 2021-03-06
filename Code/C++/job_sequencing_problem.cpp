/*
Question: We are given an array of jobs. Jobs contain the job's deadline and it's profit. Every job takes 1 unit of time to complete. We need to find the maximum profit that can be gained by optimally doing the jobs

Thought Process: 
Basically we do take the job first which gives maximum profit and will do it on it's deadline, if the slots are free.
and by doing this what happens is the jobs with maximum profit are done first and nearest to their deadline.
That's why maximum jobs are done
Now to manage the jobs we create an array of size 'maxTime' (which is the maximum deadline timeamong all the jobs).

Algorithm: GREEDY SOLUTION
1. First we iterate over the array and then calculate the maximum deadline among all the jobs i.e maxTime
2. Now we create an array 'timeslots' that will check if that particular timeslot is free or not
3. Now we take the first job (i.e the job with maximum profit)
    3.1 Now starting from the point of it's deadline we keep checking the timeslot if it is free or not and if it is free we fill that spot and add that jobs profit to max_profit and break the loop
4. Then after checking for all the jobs we return the max_profit
*/

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& p1, pair<int,int>& p2)
{
    return p1.second>p2.second;
}
int main()
{
    int n;
    cin>>n;

    int deadline[n];
    int profit[n];
    for(int i=0;i<n;i++)
    cin>>deadline[i];

    for(int i=0;i<n;i++)
    cin>>profit[i];

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({deadline[i],profit[i]});
    }

    sort(v.begin(),v.end(),cmp);

    int maxTime=0;

    for(int i=0;i<n;i++)
    {
        maxTime = max(maxTime, deadline[i]);
    }

    vector<int>timeSlots(maxTime+1, false);
    int jobCount = 0; 
    int max_profit=0;

    for(auto it: v)
    {
        pair<int,int>p = it;


        for(int t=p.first;t>0; t--)
        {
            if(timeSlots[t]==false)
            {
                timeSlots[t]=true;
                max_profit+=p.second;
                jobCount++;
                break;
            }
        }
    }

    cout<<"The no of jobs possible are "<<jobCount<<" with a total profit of "<<max_profit<<endl;

}

/*
Test Case: 
    Input: 
        4
        4 1 1 1
        20 10 40 30
    Output:
        The no of jobs possible are 2 with a total profit of 60
*/