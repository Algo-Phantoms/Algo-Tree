/*Menu driven Program to perform all the operation on Doubly linked list using classess.
Doubly linked list is a type of linked list in which each node apart from storing its data has two links.
The first link points to the previous node in the list and the second link points to the next node in the list. 
In this program you will be given a Menu and you have to choose which operation You want to perform on the Doubly link list. 
According to your choice the program will perform the operation on the Doubly link list.*/

#include <iostream>
#include <cstdlib>
using namespace std;

//Basic structure of a node in doubly linked list consisting of value and two pointers of the node.
class node
{
public:
    int data;
    node *next;
    node *prev;
};
class Doubly_linklist
{
    node *start;
    node *last;

public:
    Doubly_linklist()
    {
        start = nullptr;
        last = nullptr;
    }
    void creation();
    void traversal();
    void insertion_at_beginning();
    void insertion_at_end();
    void insertion_after_given_index();
    void insertion_at_index();
    void deletion_at_beginning();
    void deletion_at_end();
    void deletion_at_index();
};

//Function for creating a new node.
void Doubly_linklist::creation()
{
    node *new_node = new node;
    cout << "\nEnter the info of the node ";
    cin >> new_node->data;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    if (start == nullptr)
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
void Doubly_linklist::traversal()
{
    node *ptr = start;
    node *p = last;
    int count = 0;
    if (ptr == nullptr|| p == nullptr)
    {
        cout << "List is empty " << endl;
    }
    else
    {
        cout << "\ntraversing from left from right ";
        while (ptr != nullptr)
        {
            cout << "\nInfo of node at index " << count << "--> " << ptr->data;
            ptr = ptr->next;
            count += 1;
        }
        count -= 1;
        cout << "\nTransversing from right to left ";
        while (p != nullptr)
        {
            cout << "\nInfo of node at index " << count << "--> " << p->data;
            p = p->prev;
            count -= 1;
        }
    }
}

//Function for inserting a node in beginning.

void Doubly_linklist::insertion_at_beginning()
{
    node *new_node = new node;
    cout << "\nEnter the info of the node ";
    cin >> new_node->data;
    if (start == nullptr && last == nullptr)
    {
        new_node->prev = nullptr;
        new_node->next = nullptr;
        start = last = new_node;
    }
    else
    {
        new_node->prev = nullptr;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
}

//Function for inserting new node at end of list.

void Doubly_linklist::insertion_at_end()
{
    node *new_node = new node;
    cout << "\nEnter the info of node ";
    cin >> new_node->data;
    if (last == nullptr)
    {
        cout << "\nList is empty ";
    }
    else
    {
        new_node->next = nullptr;
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
    }
}

// Function for inserting new node next to given position(index) in list.

void Doubly_linklist::insertion_after_given_index()
{
    node *ptr = start;
    node *new_node = new node;
    cout << "\nEnter the info of the node you want to insert";
    cin >> new_node->data;
    int count = 0, index;
    cout << "\nEnter the location where you want to insert new node";
    cin >> index;
    if (index < count)
    {
        cout << "\nInvalid position ";
    }
    else if (start == nullptr || last == nullptr)
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

void Doubly_linklist::insertion_at_index()
{
    node *new_node = new node;
    node *ptr = start;
    cout << "\nEnter the info of the node you want to insert";
    cin >> new_node->data;
    int count = 0, index;
    cout << "\nEnter the location where you want to insert new node";
    cin >> index;
    if (index < count)
    {
        cout << "\nInvalid position ";
    }
    else if (start == nullptr || last == nullptr)
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

void Doubly_linklist::deletion_at_beginning()
{
    node *ptr = start;
    if (start == nullptr && last == nullptr)
    {
        cout << "\nList is empty ";
    }
    else if (start->next == nullptr)
    {
        start = nullptr;
        last = nullptr;
        free(start);
        free(last);
    }
    else
    {
        start = start->next;
        start->prev = nullptr;
        ptr->next = nullptr;
    }
}

//Fuction for deleting a node from end.

void Doubly_linklist::deletion_at_end()
{
    node *temp = last;
    if (start == nullptr && last == nullptr)
    {
        cout << "\nList is empty ";
    }
    else if (start->next == nullptr)
    {
        start = nullptr;
        last = nullptr;
        free(start);
        free(last);
    }
    else
    {
        last = last->prev;
        last->next = nullptr;
        temp->prev = nullptr;
        free(temp);
    }
}

//Fuction for deleting a node from any index.

void Doubly_linklist::deletion_at_index()
{
    node *ptr = start;
    node *ptr_1 = start->next;
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
    Doubly_linklist D1;
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
        D1.creation();
        cout << "\n Node created successfully";
        break;
    }
    case 2:
    {
        D1.insertion_at_beginning();
        cout << "\n Node Inserted successfully at beginning";
        break;
    }
    case 3:
    {
        D1.insertion_at_end();
        cout << "\n Node Inserted successfully at End";
        break;
    }
    case 4:
    {
        D1.insertion_at_index();
        cout << "\n Node Inserted successfully at Given position";
        break;
    }
    case 5:
    {
        D1.insertion_after_given_index();
        cout << "\n Node Inserted successfully after a given index";
        break;
    }
    case 6:
    {
        D1.deletion_at_beginning();
        cout << "\n Node Deleted successfully from beginning";
        break;
    }
    case 7:
    {
        D1.deletion_at_end();
        cout << "\n Node Deleted successfully from End";
        break;
    }
    case 8:
    {
        D1.deletion_at_index();
        cout << "\n Node Deleted successfully from given position";
        break;
    }
    case 9:
    {
        D1.traversal();
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

    /*complexity of traversing is
   Time complexity:- O(n)
   Space complexity:-O(n)
   
   complexity of inserting node 
   Time complexity:- O(1) 
   Space complexity:- O(1)
   
   complexity of deleting node 
   Time complexity:- O(1) 
   Space complexity:- O(1)
   */
}
