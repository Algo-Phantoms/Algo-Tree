/*
Deletion into a singly-linked list has the following function:
1. Deleting a node at the specific location given by the user.
	• Update the next of previous node to be deleted.
	• Free the memory of deleted node.

*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class node{

  public:
  	int data;
  	node* next;

  	//constructor
  explicit node(int x){
       data = x;
       next = NULL;
  	 }

};

class  LinkedList{
public:
	node* head;
	node* tail;

	//constructor
	 LinkedList(){
	 	head = NULL;
	 	tail = NULL;
	 }

	void insertion(int x){
		node* n = new node(x);

		//only one node
		if(head == NULL){
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
	}


	int length(){
		node* temp = head;
		int l = 0;
		while(temp!=NULL){
			l++;
			temp = temp->next;
		}
	  return l;
	}
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
	int delete_at(int loc)
	{
	    node* prev = head;
	    node* curr = head;
	    int x;
	    if (loc==1)
        {
            head=curr->next;
            x=curr->data;
            free(curr);
        }
        else
        {
            while(loc!=2)
            {
                prev = prev->next;
                loc--;
            }
            curr = prev->next;
            prev->next=curr->next;
            curr->next=NULL;
            x=curr->data;
            free(curr);
        }
        return x;
	}

};
int main() {

	LinkedList l;
    l.insertion(1);
    l.insertion(2);
    l.insertion(3);
    l.insertion(4);
    l.insertion(5);
    l.insertion(6);
    l.insertion(7);
    cout<<"Original Linked List: ";
	l.print();
	cout<<"\n";
	int n;

    while(l.length()!=0)
    {
        cout<<"Enter the location(0 to exit): ";
        cin>>n;
        if(n==0)
        {
            l.print();
            return 0;
        }
        if(n>l.length())
        {
            cout<<"Insufficient Elements.Try again."<<endl;
            continue;
        }
        int x;
        x=l.delete_at(n);
        cout<<"\nDeleted Element: "<<x<<endl;
    }
    cout<<endl<<"List Empty";

	return 0;
}

/*

Test Case 1:
Input: 2 3 1 2
Output: 2 4 1 5

Test Case 2:
Input: 5 1 5 1
Output: 5 1 7 2





*/
