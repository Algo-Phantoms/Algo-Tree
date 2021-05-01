/*
Insertion into a singly-linked list has three cases:

1. Inserting a new node before the head (at the beginning)
	• Update the next pointer of new node, to point to the current head.
	• Update head pointer to point to the new node.

2. Inserting a new node after the tail (at the end of the list)
	• New nodes next pointer points to NULL.
	• Last nodes next pointer points to the new node.

3. Inserting a new node at the middle of the list (random location)
	• If we want to add an element at position 3 then we stop at position 2. That means we
	traverse 2 nodes and insert the new node. For simplicity let us assume that the
	second node is called position node. The new node points to the next node of the
	position where we want to add this node.
	• Position node’s next pointer now points to the new node.


*/

#include <iostream>
using namespace std;

class node{
  
  public:
  	int data;
  	node* next;

  	//constructor
  	 node(int x){ 				
       data = x;
       next = nullptr;
  	 }

};

class  LinkedList{
public:
	node* head;
	node* tail;

	//constructor
	 LinkedList(){				
	 	head = nullptr;
	 	tail = nullptr;
	 }
	void insertion_at_head(int x){
		
		// node create
		node* n = new node(x);
			
		//only one node			
		if(head == nullptr){				
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

		//only one node
		if(head == nullptr){				
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

/* 

	Test case : 

	Input : 
	5
	6
	7 3

	Output : 
	4 3 2 1 
	4 3 2 1 6 
	4 3 7 2 1 6 
	6

	Time Complexity :

	Insertion at start : O(1)
	Insertion at end : O(N)
	Insertion at random position : O(N) 

	Space Complexity : O(N)

*/