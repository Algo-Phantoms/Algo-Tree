/*
Queue is a data structure in which insertion is done at one end and deletion is done at the other end as 
it follows the principle of First In First Out(FIFO). We are implementing queue using circular singly-linked list,
so we will craete class and then perform various function like: enqueue, dequeue, peek, display, isEmpty, isFull on it.
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    struct Node *link;
};
Node *rear;

//This function will check if the Queue is empty or not.
int isEmpty()
{
    if(rear == NULL)
        return 1;
    else
        return 0;
}

//This function will insert elements into the Queue.
void insertQueue(int item)
{
    Node *temp = new Node;
    temp->data = item;

    if(temp == NULL)
    {
        cout<<"\nMemory problem."<<endl;
        return;
    }

    if(isEmpty()) //If queue is empty.
    {
        rear = temp;
        temp->link = rear;
    }
    else
    {
        temp->link = rear->link;
        rear->link = temp;
        rear = temp;
    }
}

//This function will delete the front element of Queue.
int deleteElement()
{
    int item;
    Node *temp;

    if(isEmpty())
    {
        cout<<"\nQueue underflow"<<endl;
        return -1;
    }

    if(rear->link == rear)  //If only one element is present
    {
        temp = rear;
        rear = NULL;
    }

    else
    {
        temp = rear->link;
        rear->link = rear->link->link;
    }

    item = temp->data;
    delete temp;
    return item;
}

//This function will return the front element
int peek()
{
    if(isEmpty())
    {
        cout<<"\nQueue underflow."<<endl;
        return -1;
    }

    return rear->link->data;
}

//This function will display elements of Queue
void display()
{
    Node *temp;
    if(isEmpty())
    {
        cout<<"\nQueue is empty"<<endl;
        return;
    }

    cout<<"\nQueue formed : ";

    temp = rear->link;
    do
    {
        cout<<temp->data<<"  ";
        temp = temp->link;

    }while(temp != rear->link);
    cout<<endl;
}


int main()
{
    int choice,item;
    while(1)
    {
        cout<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. PEEK"<<endl;
        cout<<"4. DISPLAY"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter the element for insertion : ";
            cin>>item;
            insertQueue(item);

            break;

        case 2:
            if(deleteElement() == -1)
                cout<<endl;
            else
                cout<<"\nDeleted element : "<<deleteElement()<<endl;

            break;

        case 3:
            if(peek() == -1)
                cout<<"\nNot found"<<endl;
            else
                cout<<"\nItem at the front of queue is : "<<peek()<<endl;

            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            cout<<"IVALID CHOICE!";
        }
    }
}

/*
    Time Complexity:
    Insertion -  O(1)
    Deletion -   O(n)
    Peek -       O(1)
    isEmpty -    O(1)

    Space Complexity: O(n), as we are using linked list of n-nodes.
    
    
    Sample Input/Output:

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1

    Enter the element for insertion : 10

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1

    Enter the element for insertion : 20

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1

    Enter the element for insertion : 30

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 3

    Item at the front of queue is : 10

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 4

    Queue formed : 10  20  30

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 5

*/
