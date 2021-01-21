#include <iostream>
using namespace std;

class node{
  
  public:
  	int data;
  	node* next;
  	 node(int x){  //constructor
       data = x;
       next = nullptr;
  	 }

};

class  LinkedList{
public:
	node* head;
	node* tail;
	 LinkedList(){  //constructor
	 	head = nullptr;
	 	tail = nullptr;
	 }
	void insertion_at_head(int x){
		// node create
		node* n = new node(x);
		if(head == nullptr){ //only one node
			head = n;
			tail = n;
		}
		else{
			n->next = head;
			head = n;
		}
	}
	void insertion_at_tail(int x){
		node* n = new node(x);
		if(head == nullptr){ //only one node
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
	}
	void insertion_at_x(int x, int pos){
		node* n = new node(x);
		if(pos<=0){
			insertion_at_head(x);
		}
		else if(pos>length()){
			insertion_at_tail(x);
		}
		else{
		  node* temp = head;
		  int move = 1;
		  while(move < pos-1){
		  	move++;
		  	temp = temp->next;
		  }
		  n->next = temp->next;
		  temp->next = n;

		}
	}
	
	int length(){
		node* temp = head;
		int l = 0;
		while(temp!=nullptr){
			l++;
			temp = temp->next;
		}
	  return l;
	}
	void print(){
		node* temp = head;
		while(temp!=nullptr){
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
	
};
int main() {

	LinkedList l;
	int n;
	cin >> n;
	for(int i=1;i<n;i++){
		l.insertion_at_head(i);
	}
	l.print();
	cout<<"\n";  
	int ele;
	cin >> ele;
	l.insertion_at_tail(ele);

	l.print();
	cout<<"\n"; 
	int pos;
	cin >> ele >> pos;
	l.insertion_at_x(ele,pos);
	l.print();
	cout<<"\n";
	cout<< l.length();

	return 0;
}

/* Test case - 

Input - 
5
6
7 3

Output - 
4 3 2 1 
4 3 2 1 6 
4 3 7 2 1 6 
6

*/