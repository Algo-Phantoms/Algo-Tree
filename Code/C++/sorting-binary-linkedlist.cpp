/*

	Sorting a binary linkedlist 

	Sorting binary linkedlist algorithm can be basically divided into 2 main steps
	1) counting the no. of 0's and 1's
	2) chaning the array data according to our count of 0's and 1's

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

Node *sort_binary(Node *A)
{
    // array to count the no. of 0's and 1's
    int count[2] = {0, 0};
    Node *ptr = A;
    while (ptr != NULL)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = A;
    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
    return A;
}

int main()
{
    Node *head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 0);

    cout << "Linkedlist before sorting ->" << endl;
    printlist(head);

    sort_binary(head);

    cout << "Linkedlist after sorting ->" << endl;
    printlist(head);

    return 0;
}
/*

Test Case

	Input: 0 1 1 0
	Output: 0 0 1 1


	Input: 1 1 1 1 0
	Output: 0 1 1 1 1

	Time Complexity: O(n)
	Space Complexity: O(1)
*/
