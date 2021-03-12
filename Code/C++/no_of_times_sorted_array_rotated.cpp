/* 
* Sorted array is one in which the elements are arranged either in ascending order or in descending order.

* Problem Statement :- A clockwise rotated sorted Array of size n and distinct element is given and we need to find out the number of times it is rotated.

* For this problem, let us consider array is previously arranged in ascending order and then it was rotated.
* Now, to find the number of rotations, we have to search for the smallest element as every element will be 
shifted by same number of positions as the first element is shifted.
* So, by brute force (Linear Search), we need to search for the smallest element 
i.e going through each element and checking whether it is smallest or not and updating the smallest one.
In the worst case, linear search may have a time complexity of O(n).
* So we need some better approach which may take less time as compared to previous one.
* The more accurate way will be to divide the array into two halves every iteration, which will decrease our search space and 
hence decrease the time complexity.

*/

/* ****Algorithm ****
* 1. No. of timess array is rotated = index of minimum element
* 2. Now, after rotation, it's the minimum element that's why smaller than both its right and left.
* 3. Now let's see the solution with little modifications in Binary search algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

int noOfRotation(int arr[],int n){
	//initialising answer with -1
		int ans=-1;
		//if last element is greater than 1st that is array sorted 
		//that's why number of rotation equals zero
		if(arr[0]<arr[n-1]){
			return 0;
		}
		
		//declaring and initializing two pointers l and r 
		//pointing to the leftmost and rightmost element respectively.
		int l=0,r=n-1;
		//iterating the elements until i is less than equal to r
		while(l<=r){

			if(arr[l]<=arr[r])
				return l;
			//finding middle of l and r 
			// (l+r)/2 directly not used as in some cases overflow may occur
			//when n=10^8;
			int mid=l+(r-l)/2;
			//previous denotes previous element 
			//previous element of mid is mid-1
			//as when mid=0 then 0-1= negative
			// an array cannot have negative index
			//therefore adding n 
			//and also array shouldn't be out of bound 
			//that's why modulo n taken
			int previous=(mid+n-1)%n;
			int next=(mid+1)%n;
			//if element less than both previous and mid then return answer
			if(arr[mid]<=arr[next] && arr[mid]<=arr[previous])
				{ans=mid;
				break;}
			//if arr[mid] is greater than arr[l] then search space which in right to mid
			//should be included and left one to be discarded
			if(arr[l]<=arr[mid])
				l=mid+1;
			//if arr[mid] is less than arr[r] then search space which in left to mid
			//should be included and right one should be discarded
			// we will go on decreasing the left search space
			else if(arr[mid]<=arr[r])
				r=mid-1;
		}
		return ans;
}

int main(){
	// t is the no. of test cases
	int t;
	//taking t as input
	cin>>t;
	while(t--){
		//taking no. of elements of the array
		int n;
		cin>>n;
		//declaring the array of size n
		int arr[n];
		//taking array elements as input
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		//calling function
		cout<<noOfRotation(arr,n)<<endl;

	}
	return 0;
}

/* 
	Test cases:-
	
  *	Input format:-
    no. of test cases (t) 
	size of array (n)
	n elements of array 

  *	Output Format:-
	no. of rotations
   
  * Input :-
    2
    8
    5 6 7 8 9 1 2 3
    6
    60 70 80 20 40 50

  * Output :-
  	5
  	3

  =>Detailed explaination:-

  	arr[7] = {5 6 7 8 9 1 2 3}
  	
  	l=0 ,r=7
  	*1st iteration----
  	mid=3;
  	next=4
  	previous=2
  	8<9 but 8>7 therefore l=mid++ =>l=4
  	
  	*2nd iteration----
  	mid=5;
  	next=6;
  	previous=4;
  	9>1 and 1<2
  	therefore ans=mid=5


  * Time complexity: O(n)
  * Space Complexity: O(n)




*/
