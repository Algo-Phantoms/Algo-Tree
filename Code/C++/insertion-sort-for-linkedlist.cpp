/*

	Sorting a linkedlist using insertion sort algorithm. 

	Insertion sort algorithm can be basically devided into 3 main steps
	1) Selecting the key node from linkedlist
	2) Adding key to it's correct place in sorted array

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// printing linkedlist
void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// inserting new nodes
void insert(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// inserting key to correct index in sorted linkedlist
void insert(int val, Node *A)
{
    Node *itr1 = A;
    Node *itr2 = A->next;
    while (itr2 != NULL and itr2->data < val)
    {
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    itr1->next = new Node();
    itr1->next->data = val;
    itr1->next->next = itr2;
}

// insertion sort function which is selectiong elements one by one as key
void insertionSortList(Node **head)
{
    Node *sorted = new Node();
    sorted->data = INT_MIN;
    Node *itr = *head;
    while (itr != NULL)
    {
        insert(itr->data, sorted);
        itr = itr->next;
    }
    *head = sorted->next;
}

int main()
{
    Node *head = NULL;
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 10);

    cout << "Linkedlist before sorting ->" << endl;
    printlist(head);

    insertionSortList(&head);

    cout << "Linkedlist after sorting ->" << endl;
    printlist(head);

    return 0;
}

/*

Test Case

	Input: 3 5 1 10
	Output: 1 3 5 10


	Input: 33 51 7 9 100
	Output: 7 9 33 51 100

	Time Complexity: O(n*n)
	Space Complexity: O(n)
*/