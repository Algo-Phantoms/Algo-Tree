/*In insertion at postion we shift all elements from the (last index) to (position index- 1) by one position to the right and 
insert the new element in arr[position-1]*/


#include <iostream>
using namespace std;

int main()

{

    int n;
    cin>>n;

    int array[1000];

    for(int i=0;i<n;i++){
    cin>>array[i];
    }

    int element;
    cin>>element;

    cout<<"Initial array:\n";
    for(int i=0;i<n;i++){
    cout<<array[i]<<" ";
    }
    cout<<"\n";

    int position;
    cin>>position;

    for(int i=n-1;i>=position-1;i--){
      array[i+1]=array[i];
    }

    array[position-1]=element;

    cout<<"Final array:\n";
    for(int i=0;i<=n;i++){
      cout<<array[i]<<" ";
    }
    return 0;
}
/*
  Input : 5
  1 2 3 4 5
  6-element
  3-position
  Output : 
  Initial array 
  1 2 3 4 5 
  Final array 
  1 2 6 3 4 5
  Time complexity: O(n)
  Space complexity: O(n)
*/
