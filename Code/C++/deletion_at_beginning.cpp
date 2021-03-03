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

    cout<<"Final array after deletion\n";
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
  
  Final array after deletion
  2 3 4 5 
  
  Time Complexity : O(1)
  Space Complexity : O(1)
*/
