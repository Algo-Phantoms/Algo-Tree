// C++ program to get intersection point of two linked list
//      Approch
//
// Get count of the nodes in the first list, let count be c1.
// Get count of the nodes in the second list, let count be c2.
// Get the difference of counts d = abs(c1 – c2)
//Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes 
//Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)



#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* Function to get the counts of node in a linked list */
int getCount(Node* head);

/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2);

/* function to get the intersection point of two linked
lists head1 and head2 */
int getIntesectionNode(Node* head1, Node* head2)
{

	// Count the number of nodes in
	// both the linked list
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	// If first is greater
	if (c1 > c2) {
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else {
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}
}

/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2)
{
	// Stand at the starting of the bigger list
	Node* current1 = head1;
	Node* current2 = head2;

	// Move the pointer forward
	for (int i = 0; i < d; i++) {
		if (current1 == NULL) {
			return -1;
		}
		current1 = current1->next;
	}

	// Move both pointers of both list till they
	// intersect with each other
	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2)
			return current1->data;

		// Move both the pointers forward
		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
	Node* current = head;

	// Counter to store count of nodes
	int count = 0;

	// Iterate till NULL
	while (current != NULL) {

		// Increase the counter
		count++;

		// Move the Node ahead
		current = current->next;
	}

	return count;
}

// Driver Code
int main()
{
	int numb1,num2,b,d;
	cin>>numb1>>numb2;
	Node* newNode;
	for(int i=0;i<numb1;i++)
	{
		Node* head1 = new Node();
		cin>>b;
		head1->data=b;
		if(i+1<numb1)
		head1=head1->next;
		else
			head1->next = NULL;
	}
	for(int i=0;i<numb2;i++)
	{
		Node* head2 = new Node();
		cin>>d;
		head2->data=d;
		if(i+1<numb2)
		head2=head2->next;
		else
			head2->next=NULL;
	}
	
	

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}

// Time Complexity: O(m+n)    where m and n is the node of two linked list
// Auxiliary Space: O(1)
// Input    numb1 =5, numb2 = 3
//	     3
//            \
//              6
//               \
//                9    10
//                 \  /
//                  15
//                   |
//                   30


// Output     15

// Input  numb1 = 4 numb2 = 4
//	 2   4
//        \ /
//         3 
//         |
//         5
//         |
//         7

// Output 3
