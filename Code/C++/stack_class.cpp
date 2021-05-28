/*
Stack is a linear data structure which follows a particular order in which the operations are performed.
The order may be LIFO(Last In First Out) or FILO(First In Last Out).
This is the implementation of stack class using pointers.
*/

#include <iostream>
using namespace std;

template<typename T>
class node{
public:
	T data;
	node<T>* next;
	// constructor
	node(T x){
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

	//push(data) inserts data into stack
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

    //pop() removes the last inserted element from the stack
	void pop(){
	   if(count>0){
       count--;
       node<T>* temp = head;
       head = head->next;
       delete temp;
       }
	}

    //size() returns the total number of elements available in a stack
	int size(){
       return count;
	}

    //empty() or IsEmpty() indicates whether any elements are stored in the stack or not
	bool empty(){
       return head == nullptr;
	}

	//top() returns the last inserted element without removing it
	T top(){
        return head->data;
	}

    //display() it prints all the elements available in the stack
    void display()
    {
        if (empty())
            return;
        T x = top();
        pop();
        display();
        cout << x << " ";
        push(x);
    }

	//change(index,data) it changes the element at the given position
    void change(int index, T newVal)
    {
        if (empty())
            return;
        T x = top();
        pop();
        if (count == index) {
            push(newVal);
            return;
        }
        change(index,newVal);
        push(x);
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
    s.display();
    s.change(1,0); //5,10
    cout<<"\n";
    s.display();

    return 0;
}

/*
	Test Case :
	Input : 5
	Output :
    5
    4
    4
    0
    1 2 3 4
    1 0 3 4

    Input : 8
    Output:
    8
    7
    7
    0
    1 2 3 4 5 6 7
    1 2 3 4 5 10 7

	Time Complexity of Push() : O(1)
	Time Complexity of Pop() : O(1)
	Time Complexity of Size() : O(1)
	Time Complexity of IsEmptyStack() : O(1)
	Time Complexity of IsFullStack() : O(1)
	Time Complexity of DeleteStack() : O(1)
	Time Complexity of Display() : O(n)
	Time Complexity of Change() : O(n)

	Space Complexity (for n push operations) : O(n)
*/
