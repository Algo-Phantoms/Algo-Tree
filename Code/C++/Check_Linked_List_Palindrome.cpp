/*
In this code we take values of linked list nodes from user and then call the function "check_palindrome",
to check if given linked list is palindrome or not, by reversing the last half of the linked list and
then comparing it with the first half elements of the linked list.
*/

#include<iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
};

Node* newNode(int n){
	Node* t = new Node;
	t->val = n;
	t->next = NULL;
}

	//this function reverse the given linked list
Node* reverse(Node* N){		
	Node* prev = NULL;
	Node* curr = N;
	Node* right = NULL;
	while(curr!=NULL){
		right = curr->next;
		curr->next = prev;
		prev = curr;
		curr = right;
	}
	return prev;
}

	//this function find the middle element of linked list
Node* middle(Node* N, int n){		
	Node* ans = N;
	for(int i=0;i<n/2;i++){
		ans = ans->next;
	}
	return ans;
}

	//this function checks if given linked list is palindrome or not
bool check_palindrome(Node* N, int n){		
	Node* v = middle(N,n);
	Node* M = reverse(v);
	for(int i=0;i<n/2;i++){
		if(M->val!=N->val){
			return false;
		}
	}
	return true;
}

int main(){
	cout<<"Enter number of Nodes: ";
	int n;
	cin>>n;
	Node* h = new Node;
	Node* head = h;
	
	//this loop convert the input given by user into a linked list
	for(int i=0;i<n;i++){		 
		int a;
		cin>>a;
		h->next = newNode(a);
		h = h->next;
	}
	head = head->next;
	bool p = check_palindrome(head,n);
	
	if(p==true){
		cout<<"Given Linked list is palindrome!";
	}
	else{
		cout<<"Given Linked list is not palindrome!";
	}
	
	return 0;
}

/*
Time Complexity = O(n);
Space Complexity = O(1);
 
If we give following linked list as input - 
3->5->6->8->6->5->3
Output - "Given Linked list is palindrome!"

If we give following linked list as input - 
3->5->6->8->7->5->3
Output - "Given Linked list is not palindrome!"
*/
