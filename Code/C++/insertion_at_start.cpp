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

    for(int i=n;i>=1;i--){
       arr[i] = arr[i-1];
    }

    arr[0] = element;

    cout<<"Final array \n";
    for(int i=0;i<=n;i++){
      cout<<arr[i]<<" ";
    }

  return 0;
}

/*
  Input : 5
  1 2 3 4 5
  6

  Output : 
  Initial array 
  1 2 3 4 5 

  Final array 
  6 1 2 3 4 5
*/