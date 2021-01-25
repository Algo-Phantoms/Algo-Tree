#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){             // a-current element, b-parent
       if(minHeap){
          return a < b;
       }
       else{
          return a > b;
       }
    }
    void heapify(int ind){
        int left = 2*ind;
        int right = 2*ind +1;

        int min_idx = ind;              //for pointing the idx
        int last = v.size()-1;

        //find the correct place for min_idx

        if(left <=last && compare(v[left],v[ind])){             //cmpare with left if it is  smaller then min_idx will be left
            min_idx = left;
        }
        if(right <= last && compare(v[right],v[min_idx])){              // compare new min_idx with right
            min_idx = right;
        }

        if(min_idx!=ind){
             swap(v[ind],v[min_idx]);
             heapify(min_idx);
        }

    }
public:

	Heap(int default_size = 10, bool type = true){
         v.reserve(default_size);               // vector will not expand untill its size == 10
         v.push_back(-1);
         minHeap = type;
	}

	void push(int d){
        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;
         
        //keep pushing to the top till you reach a root node or stop midway because current element is already greater than parent

        while(idx > 1 and compare(v[idx],v[parent]) ){
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
	}

	int top(){
       return v[1];
	}

	void pop(){
         int last = v.size() - 1;
         swap(v[1],v[last]);                // swap first and last element and then remove
         v.pop_back();
         heapify(1);                // for maintaining heap order property
	} 

    bool empty(){
       return v.size()==1;
    }
};

int main(){

	Heap h;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
       int no;
       cin >> no;
       h.push(no);
	}

	//remove all the elements one by one
	while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
	}

 return 0;
}

/*

Test case :

Input : 5
3 2 4 5 1

Output : 1 2 3 4 5

Time Complexity : O(log N)
Space Complexity : O(log N)

*/