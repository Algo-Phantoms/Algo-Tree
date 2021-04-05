/*
Suppose a sorted array, and a target number is given we can find the closest number from the target value. 
For example if the array is 1,3,4,7,9 and target number is 5, then the closest number to it is 4.
We can solve this by linearly going through the array and keep track of the difference between the target number and current number in array and finding the one with minimum difference.

Find middle of current array
The cases that could arise are:
* arr[mid]==target, then arr[mid] is the closest number
* arr[mid]>target, then
    * target between arr[mid-1] and arr[mid], so simply return minimum of both, or
    * target less than both, then update variable high
* arr[]<target, then
    * target between arr[mid] and arr[mid+1], return minimum of both, or
    * arr[mid] and arr[mid+1] greater than target, then update variable low

*/

#include <iostream>
using namespace std;

int min(int a, int b, int target) {
   if (target - a >= b - target)
      return b;
   else
      return a;
}

int find(int arr[],int target,int n){

    int low=0, high=n, mid=0;
    
    //First checking with the end elements of array
    if(target<=arr[0]){
        return arr[0];
    }
    else if(target>=arr[n-1]){
        return arr[n-1];
    }
    
    //Iterative binary search
    while(low<high){
        mid=(low+high)/2;
        if(arr[mid]==target)
            return arr[mid];

        //If target is less than middle element, then search left portion
        if(arr[mid]>target){

            //If target lies between arr[mid] and arrr[mid-1], take min of the two
            if(mid>0 && arr[mid-1]<target)
                return min(arr[mid-1],arr[mid],target);
            //else
            high=mid;
        }

        //If target is greater than middle element, then search right portion
        else{
            if(mid<n -1 && arr[mid+1]>target)
                return min(arr[mid],arr[mid+1],target);
            low=mid+1;   
        }
    }
    //return the element found
    return arr[mid];
}

int main(){
    int n,target,i,j,arr[100],closest;
    cout<<"Enter number of elements and the array: ";
    cin>>n;
    
    //Array should be sorted(ascending)
      for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout<<"Enter target number: ";
    cin>>target;
    
    //Output the closest number
    closest = find(arr,target,n);
    cout<<"Closest number: "<<closest;
    return 0;
}

/* 
Test cases:

Input-1:
5
1 3 5 6 8
2

Output-1:
Closest number: 1

Input-2:
6
1 3 6 14 17 20
19

Output-2:
Closest number: 20

Input-3:
5
2 6 12 15 15
14

Output-3:
Closest number: 15

Time Complexity: O(logn) where n -> number of elements
Space Complexity: O(1)

*/