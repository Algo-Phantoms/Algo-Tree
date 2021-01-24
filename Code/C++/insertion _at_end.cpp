/*
At any point in time, we know the index of the last element of the Array, 
as we've kept track of it in our length variable. All we need to do for inserting an element 
at the end is to assign the new element to one index past (n-1) the current last element.
*/ 

#include<iostream>
using namespace std;

int main(){

   int n;
   cin >> n;

   int arr[10000];


    for(int i=0;i<n;i++){
       cin >> arr[i];
    }

    int element;
    cin >> element;
    cout<<"Initial array \n";
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<"\n";



    arr[n] = element;
    cout<<"Final array \n";
    for(int i=0;i<=n;i++){
       cout<<arr[i]<<" ";
    }

return 0;
}

/* Test cases : 

Input : 5
1 2 3 4 5
6 

Output : 
Initial array 
1 2 3 4 5 

Final array 
1 2 3 4 5 6

Time Complexity : O(1)
Space Complexity : O(1)

*/