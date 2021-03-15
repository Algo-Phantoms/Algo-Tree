/*
Question:

Given number of pages in n different books and m students. 
The books are arranged in ascending order of number of pages. 
Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Approach:

The idea is to use Binary Search. 
We fix a value for the number of pages as mid of current minimum and maximum. 
We initialize minimum and maximum as 0 and sum-of-all-pages respectively. 
If a current mid can be a solution, then we search on the lower half, else we search in higher half.

Now the question arises, how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn't exceed current value. 
To do this, we sequentially assign pages to every student while the current number of assigned pages doesn't exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.

*/

// Code in C++

#include<bits/stdc++.h>
using namespace std;

bool func(int *a,int mid,int n,int m){
    int s = 0;                      //total number of pages given to a particular students
    int student_count = 1;           // initial counter of students
    for(int i=0;i<n;i++){
        if(a[i] > mid) return false;  //it means that number of pages at that point is greater than the allocated pages
        if(s + a[i] > mid){
            student_count++;
            s = a[i];
            
            if(student_count > m) return false;
        }
        else s += a[i];
    }
    return true;
}

int findPages(int *a, int n, int m) {
    int sum = 0;                        // variable to store sum of all pages
    for(int i=0;i<n;i++) sum += a[i];
    //doing binary search here for finding the minimum number of pages
    int low = 0,high = sum;
    int ans = 0;   // variable to store minimum number of pages
    while(low<=high){
        int mid = (low+high)/2;
        if(func(a,mid,n,m)){  //if condition is true then we are updating our ans
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
	int n;                              //size of array
	cin>>n;
	int a[n];           
	for(int i=0;i<n;i++) cin>>a[i];     //taking n elements as a input of an array
	int m;                              //number of students
	cin>>m;
	cout<<findPages(a,n,m);             //printing our answer

	return 0;
}
/*

Time Complexity: O(Nlog(N))
Space Complexity: O(1)


Test Case:

Input 1:
N = 4
Array[] = {12,34,67,90}
M = 2

Output 1:
113  

Explanation 1:
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.

Input 2:
N = 3
Array[] = {15,17,20}
M = 2

Output 2:
32

*/