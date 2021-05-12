/*
numbers are coming and we have to tell median after each input

optimal approach
using heaps:
1.keep one maxheap and one minheap
2.partiton the array into two parts

if size of maxheap & minheap not equal then median = top of the larger size heap.
else
median = average of top of both heaps
*/

using namespace std;
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)



priority_queue<int ,vi,greater<int> > pqmin;
priority_queue<int,vi> pqmax;

//insertion in priority queue
void insert(int x){
    if(pqmin.size()==pqmax.size())
    {
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }

        if(x< pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }

    else{

        //two cases possible
        //case 1: size of maxheap > size of minheap
        //case 2: size of minheap > size of maxheap

        if(pqmax.size()> pqmin.size()){
            if(x>=pqmax.top())
            {
                pqmin.push(x);
            }
            else{
                int temp= pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }

        else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

//finding median
double findmedian(){
    if(pqmin.size()==pqmax.size()){
        return (pqmin.top() + pqmax.top())/2.0;
    }
    else if(pqmax.size()> pqmin.size())
        return pqmax.top();
    else{
        return pqmin.top();
    }
}

signed main(){
    insert(10);
    cout<<findmedian()<<endl;

    return 0;
}

/*
input:
 insert(1);
 insert(2);

output: 1
        1.5


input:
 insert(1);
 insert(2);
 insert(3);

output: 1
        1.5
        2


time complexity:O(log(n)
space complexity:O(n)
