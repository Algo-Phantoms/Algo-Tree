/*

* Merge sort is an example of the divide and conquer strategy.
* Merging is the process of combining two sorted files to make one bigger sorted file.
* Selection is the process of dividing a file into two parts: k smallest elements and n –
 k largest elements.
* Selection and merging are opposite operations :
      *selection splits a list into two lists
      *merging joins two files to make one file
* Merge sort is Quick sort’s complement
* Merge sort accesses the data in a sequential manner
* Merge sort is insensitive to the initial order of its input

*/
#include<iostream>
using namespace std;


void merge(int *a,int *x,int *y,int s,int e){

    int i = s;

    //x start 
    int mid = (s+e)/2;  

    //start of y
    int j = mid+1 ;

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

/* 
    Test case : 
    Input : 6
    4 3 5 6 1 2

    Output : 
    1 2 3 4 5 6 

    Time Complexity : 
    Worst case complexity : Θ(nlogn)
    Best case complexity : Θ(nlogn)
    Average case complexity : Θ(nlogn)
    Worst case space complexity: Θ(n) auxiliary

*/