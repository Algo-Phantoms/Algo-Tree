/*

	Sorting a linkedlist using merge sort algorithm. 

	Merge sort algorithm can be basically devided into 3 main steps
	1) dividing the array into 2 equal halfs
	2) calling merge sort on both the halfs which results in two sorted array
	3) merging both sorted array

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

//	dividing linkedlist into 2 linkedlist of equal size
void Split(Node *head, Node **a, Node **b)
{
    Node *slow = head;
    Node *fast = head;
    // incrementing slow pointer by one and fast pointer by two
    while (fast->next and fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

// merging two sorted linkedlist
Node *Merge(Node *a, Node *b)
{

    Node *result = NULL;

    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    if (a->data <= b->data)
    {
        result = a;
        result->next = Merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}

// mergesort funtion
void mergesort(Node **head)
{

    // when linkedlist is empty or has only one node
    if (!(*head) || !(*head)->next)
    {
        return;
    }
    // a and b are will be head of resuting linkedlist (after divison into two)
    Node *a;
    Node *b;
    Split(*head, &a, &b);

    // calling mergesort on both half linkedlit
    mergesort(&a);
    mergesort(&b);

    // merging both divided linkedlist
    *head = Merge(a, b);
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

    mergesort(&head);

    cout << "Linkedlist after sorting ->" << endl;
    printlist(head);

    return 0;
}

/*

Test Case:

	Input: 3 5 1 10
	Output: 1 3 5 10


	Input: 33 51 7 9 100
	Output: 7 9 33 51 100

Time Complexity: O(nLogn)
Space Complexity: O(1)

*/