#include<iostream>
#include<unordered_map>
using namespace std;

int longestsubarry(int arr[],int n,int k){
    
                // csum, index
    unordered_map<int, int> m; 
    int pre = 0;

    int len = 0;

    for(int i=0;i<n;i++){
        pre += arr[i];

        if(pre==k){
                        //i+1 because 0 based indexing
           len = max(len, i+1); 
        }
                    //repeating number
        if(m.find(pre-k)!=m.end()){ 
                        //i - first occurence of csum

           len = max(len, i - m[pre-k]);         }
        else{
                //store the first occ
          m[pre] = i;
        }
    }
    return len;
}

int main(){
     int n,k;
     cin >> n>>k;

     int arr[n];

     for(int i=0;i<n;i++){
         cin >> arr[i];
     } 

     cout<<longestsubarry(arr,n,k);
  
  return 0;
}

/* Test case
Input -
6 15
10 5 2 7 1 9

Output- 
4
*/




