#include <iostream>
using namespace std;

template<typename T> // for data

class node{
public:
	T data;
	node<T>* next;
	node(T x){ // constructor
		data = x;
		next = nullptr;
	}
};

template<typename T>
class Stack{
public:
	node<T>* head;

	int count;
	Stack(){
		head = nullptr;
		count = 0;
	}
	void push(T x){
		count++;
		node<T>* n = new node<T>(x);
        if(head == nullptr){
        	head = n;
        }
        else{
        	n->next = head;
        	head = n;
        }
	}

	void pop(){
	   if(count>0){
       count--;
       node<T>* temp = head;
       head = head->next;
       delete temp;

       }
	}

	int size(){
       return count;
	}

	bool empty(){
       return head == nullptr; // or count == 0
	}

	T top(){
      return head->data;
	}

};
int main()
{
	Stack<int> s;
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		s.push(i);
	}
	cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
    cout << s.size()<< "\n";
    cout << s.empty() << "\n";
    while(!s.empty()){  // print all elements
    	cout << s.top()<<"\n";
    	s.pop();
    }
	return 0;
}


/* Test Case -
 Input -5

Output - 
5
4
4
0
4
3
2
1

*/