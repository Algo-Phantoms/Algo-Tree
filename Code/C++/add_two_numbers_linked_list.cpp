// Approach
/*Traverse both lists and One by one pick nodes of both lists and add the values.
If the sum is more than 10 then make carry as 1 and reduce sum. 
If one list has more elements than the other 
then consider remaining values of this list as 0.
*/

#include<bits/stdc++.h>
using namespace std;

//Creation of Node class for Linked List
class Node{
public:
	int data;
	Node*next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

// Inserted At the end of linked list function 
Node* buildList(int size){
    int val;
    cin>> val;
    Node* head = new Node(val);
    Node* tail = head;
    for(int i=0; i<size-1; i++){
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}
// Displaying the list function
void printList(Node* n){
    while(n) {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

// Reversing the Lisked List
Node* reverse(Node* head) {
	if (head->next == NULL || head == NULL)
		return head;
	Node* shead = reverse(head->next) ;
	Node* temp = head->next;
	temp->next = head;
	head->next = NULL;
	return shead;	
}

// Adding two Linked List to get the Sum of nodes function
Node* addTwoLists(Node* first, Node* second){
    first = reverse(first);
    second = reverse(second);
    Node* sum = NULL;
    int carry = 0;
    while(first != NULL || second != NULL || carry != 0) {
        int newVal = carry;
        if(first)
            newVal += first->data;
        if(second)
            newVal += second->data;
        
        carry = newVal / 10;
        newVal = newVal % 10;
        Node* t = new Node(newVal);
        t->next = sum;
        sum = t;
        if(first)
            first = first->next;
        if(second)
            second = second->next;
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n;
        Node* first = buildList(n);
        cin>>m;
        Node* second = buildList(m);

        Node* res = addTwoLists(first,second);
        printList(res);
    }
return 0;
}

/* 
Test Case 1:

Input :
1
2
9 5 
2    
8 3  
Output  :
1 7 8 


Test Case 2:

Input :
1    
3    
1 9 5
3    
2 0 6 
Output : 
2 0 6 

Time Complexity: O(m + n) // m, n are the no. of nodes
Space Complexity: O(m + n)

*/
