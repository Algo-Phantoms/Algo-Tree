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
        cout<<"Memory problem."<<endl;
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
        cout<<"Queue underflow"<<endl;
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
        cout<<"Queue underflow"<<endl;
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
        cout<<"Queue is empty"<<endl;
        return;
    }

    cout<<"Queue formed : ";

    temp = rear->link;
    do
    {
        cout<<temp->data<<"  ";
        temp = temp->link;

    }while(temp != rear->link);

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
            cout<<"Enter the element for insertion : ";
            cin>>item;
            insertQueue(item);

            break;

        case 2:
            if(deleteElement() == -1)
                cout<<endl;
            else
                cout<<"Deleted element : "<<deleteElement();

            break;

        case 3:
            if(peek() == -1)
                cout<<"Not found"<<endl;
            else
                cout<<"Item at the front of queue is : "<<peek();

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

    Test Cases:
    (1.) Output:

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

    (2.) Output:

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 50

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 1
    Enter the element for insertion : 78

    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 3
    Item at the front of queue is : 50
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 4
    Queue formed : 50  78
    1. INSERT
    2. DELETE
    3. PEEK
    4. DISPLAY
    5. EXIT
    Enter your choice : 5
*/


