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

/* Test cases - 

Input - 5
1 2 3 4 5
6 

Output- 
Initial array 
1 2 3 4 5 

Final array 
1 2 3 4 5 6

*/