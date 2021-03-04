/*
At any point of time, we know the index of the first element in the Array .All we need to do for deleting an element
at the start is to increment the iterator index by 1 and print the array as output.
*/
#include<iostream>
using namespace std;

int main(){

   int n;
   cin >> n;

   int array[10000];


    for(int i=0;i<n;i++){
       cin >> array[i];
    }


    cout<<"Initial array \n";
    for(int i=0;i<n;i++){
      cout<<array[i]<<" ";
    }
    cout<<"\n";


    cout<<"Final array after deleting the first element \n";
    for(int i=1;i<n;i++){
       cout<<array[i]<<" ";
    }

return 0;
}

/*
  Test case :
  Input : 5
  1 2 3 4 5

  Output :
  Initial array
  1 2 3 4 5
  Final array
  2 3 4 5
  Time Complexity : O(1)
  Space Complexity : O(1)
*/
