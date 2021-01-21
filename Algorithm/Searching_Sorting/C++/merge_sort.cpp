// mergesort
#include<iostream>
using namespace std;


void merge(int *a,int *x,int *y,int s,int e){

  int i = s;

  int mid = (s+e)/2;  //x start 

  int j = mid+1 ;//start of y

  int k = s;

  while(i<=mid && j<=e){
    if(x[i]<y[j]){
      a[k]=x[i];
      k++;
      i++;
    }
    else{
      a[k]=y[j];
      k++;
      j++;
    }
  }
//x is ot fiished
  while(i<=mid){
    a[k]=x[i];
    i++;
    k++;
  }

  while(j<=e){
    a[k]=y[j];
    k++;
    j++;
  }

  return;

}



void mergesort(int *a ,int s ,int e){
  //base case

  if(s==e){
    return;
  }
 \

  int x[100];
  int y[100];

  int mid = (s+e)/2;

  for(int i= s;i<=mid;i++){
    x[i]=a[i];
  }

  for(int i=mid+1;i<=e;i++){
    y[i]=a[i];
  }
  

  //recusion
  mergesort(x,s,mid);
  mergesort(y,mid+1,e);
  //merge 2 sorted array
  merge(a,x,y,s,e);

}


int main()
{
  
  int n;
  cin >> n;

  int a[n];

  for(int i=0;i<n;i++){
    cin >> a[i];
  }


  mergesort(a,0,n-1);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  
  return 0;
}

/* Test case - 
 Input - 6
4 3 5 6 1 2

Output - 
1 2 3 4 5 6 

*/