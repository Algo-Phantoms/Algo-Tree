#include <iostream>
#include <cstdlib>
using namespace std;

//Basic structure of a node in doubly linked list consisting of value and two pointers of the node.
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *start = NULL, *last = NULL;

//Function for creating a new node.
void creation()
{
    struct node *new_node = new struct node;
    cout << "\nEnter the info of the node ";
    cin >> new_node->data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (start == NULL)
    {
        start = last = new_node;
    }
    else
    {
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}

//Function for visiting each node once in the list.
/* Time complexity:- O(n)
   Space complexity:-O(n)
*/
void traversal()
{
    struct node *ptr = start;
    struct node *p = last;
    int count = 0;
    if (ptr == NULL || p == NULL)
    {
        cout << "List is empty " << endl;
    }
    else
    {
        cout << "\ntraversing from left from right ";
        while (ptr != NULL)
        {
            cout << "\nInfo of node at index " << count << "--> " << ptr->data;
            ptr = ptr->next;
            count += 1;
        }
        count -= 1;
        cout << "\nTransversing from right to left ";
        while (p != NULL)
        {
            cout << "\nInfo of node at index " << count << "--> " << p->data;
            p = p->prev;
            count -= 1;
        }
    }
}

//Function for inserting a node in beginning.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void insertion_at_beginning()
{
    struct node *new_node = new struct node;
    cout << "\nEnter the info of the node ";
    cin >> new_node->data;
    if (start == NULL && last == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        start = last = new_node;
    }
    else
    {
        new_node->prev = NULL;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
}

//Function for inserting new node at end of list.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void insertion_at_end()
{
    struct node *new_node = new struct node;
    cout << "\nEnter the info of node ";
    cin >> new_node->data;
    if (last == NULL)
    {
        cout << "\nList is empty ";
    }
    else
    {
        new_node->next = NULL;
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}

// Function for inserting new node next to given position(index) in list.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void insertion_after_given_index()
{
    struct node *ptr = start;
    struct node *new_node = new struct node;
    cout << "\nEnter the info of the node you want to insert";
    cin >> new_node->data;
    int count = 0, index;
    cout << "\nEnter the location where you want to insert new node";
    cin >> index;
    if (index < count)
    {
        cout << "\nInvalid position ";
    }
    else if (start == NULL || last == NULL)
    {
        cout << "\nList is empty ";
    }
    else if (index == 4)
    {
        insertion_at_end();
    }
    else
    {
        while (count != index)
        {
            ptr = ptr->next;
            count += 1;
        }
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

//Function to insert a node at given index.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void insertion_at_index()
{
    struct node *new_node = new struct node;
    struct node *ptr = start;
    cout << "\nEnter the info of the node you want to insert";
    cin >> new_node->data;
    int count = 0, index;
    cout << "\nEnter the location where you want to insert new node";
    cin >> index;
    if (index < count)
    {
        cout << "\nInvalid position ";
    }
    else if (start == NULL || last == NULL)
    {
        cout << "\nList is empty ";
    }
    else if (index == 0)
    {
        insertion_at_beginning();
    }
    else
    {
        while (count != index - 1)
        {
            ptr = ptr->next;
            count += 1;
        }
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

//Fuction for deleting a node from beginning.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void deletion_at_beginning()
{
    struct node *ptr = start;
    if (start == NULL && last == NULL)
    {
        cout << "\nList is empty ";
    }
    else if (start->next == NULL)
    {
        start = NULL;
        last = NULL;
        free(start);
        free(last);
    }
    else
    {
        start = start->next;
        start->prev = NULL;
        ptr->next = NULL;
    }
}

//Fuction for deleting a node from end.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void deletion_at_end()
{
    struct node *temp = last;
    if (start == NULL && last == NULL)
    {
        cout << "\nList is empty ";
    }
    else if (start->next == NULL)
    {
        start = NULL;
        last = NULL;
        free(start);
        free(last);
    }
    else
    {
        last = last->prev;
        last->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
}

//Fuction for deleting a node from any index.
/* Time complexity:- O(1) 
   Space complexity:- O(1)
*/
void deletion_at_index()
{
    struct node *ptr = start;
    struct node *ptr_1 = start->next;
    int index;
    cout << "\nEnter the index where you want to delete the node ";
    cin >> index;
    int count = 0;
    if (index == 0)
    {
        deletion_at_beginning();
    }
    else if (index < 0)
    {
        cout << "\nInvalid index ";
    }
    else if (index == 4)
    {

        deletion_at_end();
    }
    else
    {
        while (count != index - 1)
        {
            ptr = ptr->next;
            ptr_1 = ptr_1->next;
            count += 1;
        }
        ptr->next = ptr_1->next;
        ptr_1->next->prev = ptr;
        free(ptr_1);
    }
}

//Menu driven program to perform all the operations of doubly linked list.
int main()
{
    int ch;
read:
    cout << "\n************Menu*************";
    cout << "\n 1. create ";
    cout << "\n 2. Insertion at beginning ";
    cout << "\n 3. Insertion at end ";
    cout << "\n 4. Insert at index ";
    cout << "\n 5. Insert after index";
    cout << "\n 6. Delete from beginning ";
    cout << "\n 7. Delete from end ";
    cout << "\n 8. Delete from specified location";
    cout << "\n 9. Traverse ";
    cout << "\nEnter your choice ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        creation();
        cout<<"\n Node created successfully";
        break;
    }
    case 2:
    {
        insertion_at_beginning();
        cout<<"\n Node Inserted successfully at beginning";
        break;
    }
    case 3:
    {
        insertion_at_end();
        cout<<"\n Node Inserted successfully at End";
        break;
    }
    case 4:
    {
        insertion_at_index();
        cout<<"\n Node Inserted successfully at Given position";
        break;
    }
    case 5:
    {
        insertion_after_given_index();
        cout<<"\n Node Inserted successfully after a given index";
        break;
    }
    case 6:
    {
        deletion_at_beginning();
        cout<<"\n Node Deleted successfully from beginning";
        break;
    }
    case 7:
    {
        deletion_at_end();
        cout<<"\n Node Deleted successfully from End";
        break;
    }
    case 8:
    {
        deletion_at_index();
        cout<<"\n Node Deleted successfully from given position";
        break;
    }
    case 9:
    {
        traversal();
        break;
    }
    }
    int s;
    cout << endl
         << "\nDo you want to continue?" << endl;
    cout << "\nPress 1 to continue and any other number to exit";
    cin >> s;
    if (s == 1)
        goto read;
    else
        exit(0);
    return 0;
}
