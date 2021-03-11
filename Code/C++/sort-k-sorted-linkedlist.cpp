/*

	Sorting a k sorted linkedlist. 

	Sorting a k sorted linkedlist can be basically divided into 3 main steps
	1) inserting first k elements in priority queue
	2) setting current element as queue's top element
	3) inserting next element
	4) continuing this process till last element of the linkedlist 

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// printing the list
void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// inserting new nodes in the list
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// comparision function for inserting in the priority queue
struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return (p1->data > p2->data);
    }
};

void Ksort(Node **head, int k)
{
    // doing nothing if linkedlist is empty or contains only one node
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newhead = NULL, *last;

    for (int i = 0; head != NULL and i <= k; i++)
    {
        pq.push(*head);
        *head = (*head)->next;
    }

    while (!pq.empty())
    {
        if (newhead == NULL)
        {
            newhead = pq.top();
            newhead->prev = NULL;
            last = newhead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        if ((*head) != NULL)
        {
            pq.push(*head);
            *head = (*head)->next;
        }
    }

    last->next = NULL;
    *head = newhead;
}

int main()
{

    Node *head = NULL;
    int x = 2;

    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 2);

    printlist(head);
    Ksort(&head, x);
    printlist(head);

    return 0;
}

/*

Test Case

	Input: 
		linkedlist: 3 2 6 4
		k: k 
	Output: 2 3 4 6


	Input: 
		linkedlist: 1 2
		k: 2
	Output: 1 2

	Time Complexity: O(nLogk)
	Space Complexity: O(k)
*/
