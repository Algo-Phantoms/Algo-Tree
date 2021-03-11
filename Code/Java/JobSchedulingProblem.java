/*
Problem Statement:
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.
Steps:
1.Create a job class & Sort the jobs objects based on startTime.
2.Storage[i] indicates the maximum profit that can be obtained if i only take jobs from i to n-1
3.Calculate storage[i] by picking the maximum of profits made by [including the ith job & max on the right side(from i+1 till n) 
  which doesn't overlap with the current job] & [excluding the current job (which is storage[i+1])].
4.Return the maximum profit.
*/
import java.util.Arrays;
import java.util.Scanner;
public class JobSchedulingProblem {
	class Job implements Comparable<Job>{
        int start;
        int end;
        int profit;
        Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
        public int compareTo(Job otherJob) {
            return this.start - otherJob.start;
        }
    }
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i=0; i<n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        Arrays.sort(jobs);
        int[] storage = new int[n];
        storage[n-1] = jobs[n-1].profit;
        for (int i=n-2; i >=0; i--) {
        	storage[i] = Math.max(jobs[i].profit, storage[i+1]);
            for (int j=i+1; j < n; j++) {
                if (jobs[i].end <= jobs[j].start) {
                	storage[i] = Math.max(storage[i], jobs[i].profit + storage[j]);
                    break;
                }
            }
        }
        return storage[0];
    }
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int startTime[] = new int[n];
        for( int i = 0; i < n; i++ ) {
        	startTime[i] = sc.nextInt();
        }
        int endTime[] = new int[n];
        for( int i = 0; i < n; i++ ) {
        	endTime[i] = sc.nextInt();
        }
        int profit[] = new int[n];
        for( int i = 0; i < n; i++ ) {
        	profit[i] = sc.nextInt();
        }
        JobSchedulingProblem maxprofit = new JobSchedulingProblem();
        System.out.println("Maximum Profit: "+ maxprofit.jobScheduling(startTime, endTime, profit));
        sc.close();
	}
}
/*
Sample Test Case 1: 
Sample Input  1: n = 4 , startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70}
Sample Output 1: Maximum Profit: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , Profit obtained 120 = 50 + 70.

Sample Test Case 2:
Sample Input  2: n = 5 , startTime = {1,2,3,4,6}, endTime = {3,5,10,6,9}, profit = {20,20,100,70,60}
Sample Output 2: Maximum Profit: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Time range [1-3]+[3-6]+[6-9] , Profit obtained 150 = 20 + 70 + 60.

Sample Test Case 3:
Sample Input  3: n = 3 , startTime = {1,1,1}, endTime = {2,3,4}, profit = {5,6,4}
Sample Output 3: Maximum Profit: 6

Time Complexity : O(N^2)
Space Complexity: O(N)
*/
