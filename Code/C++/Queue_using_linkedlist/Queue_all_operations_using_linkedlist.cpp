#include <iostream>
using namespace std;
struct Node //Structure of node
{
public:
    int info;
    Node *next;
} * ptr, *save, *rear, *front, *NEW;
Node *CN(int y) // For creating node
{
    ptr = new Node;
    ptr->info = y;
    ptr->next = NULL;
    return ptr;
}
void insert(Node *NEWPTR)
{
    if (front == NULL)
    {
        front = rear = NEWPTR;
    }
    else
    {
        rear->next = NEWPTR;
        rear = NEWPTR;
    }
}
void Delete() //for deleting a node
{

    if (front == NULL)
        cout << "\nUnderflow!!";

    else
    {
        ptr = front;
        front = front->next;
        delete ptr;
        cout << "\nValue got deleted";
    }
}
/*Time complexity:- O(n)
   Space Complexity:- O(n)*/
void Display(Node *D) //for displaying the queue
{
    if (D != NULL)
    {
        while (D != NULL)
        {
            cout << D->info << "-->";
            D = D->next;
        }
    }
    else
        cout << "Empty!:(";
}

int main()
{
    int a, x;
    char ch = 'y';

    do
    {

        cout << "\nWhat do u want to do with Queue\n1. Insert a node \n2. Delete a node \n3. Display\n Enter your choice:";
        cin >> a;
        switch (a)
        {

        case 1:
        {
            cout << "\nEnter the data of new node :";
            cin >> x;
            NEW = CN(x);
            insert(NEW);
            cout << "\nNew node with value " << x << " is inserted in Queue.";
        }
        break;
        case 2:
        {
            Delete();
            cout << "\nFront node is Deleted Successfully!!";
        }
        break;
        case 3:
        {
            cout << "\nYour queue is:";
            Display(front);
        }
        break;

        default:
            cout << "\nWANT TO DO NOTHING! IT's OK!";
        }
        cout << "\nWant to insert or delete an another node?(Y/N):";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
/* Time complexity for both insertion and deletion is:- O(1)
   Space Complexity:- O(n)*/
