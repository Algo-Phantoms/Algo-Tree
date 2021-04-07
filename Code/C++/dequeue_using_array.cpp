#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

/*
DeQueue or Double Ended Queue is a type of queue in which insertion
and removal of elements can be performed from either front or rear.
*/
class DeQueue
{
private:
    int a[20] , front , rear;

public:
    DeQueue()
    {
        front = rear = -1;
    }

    //This operation adds an element at the front.
    void startInsert(int item)
    {
        if(front == -1)
        {
            front = 0;
            a[++rear] = item;
        }

        else if(front != 0)
            a[--front] = item;

        else
            cout<<"Overflow condition!";
    }

    //This operation adds an element to the rear.
    void endInsert(int item)
    {
        if(rear >= SIZE-1)
            cout<<"Overflow Condition!";

        else
        {
            if(front == -1)
            {
                front++;
                rear++;
            }
            else
                rear = rear+1;

            a[rear] = item;
        }
    }

    //This operation deletes an element from the front.
    deleteFront()
    {
        if(front == -1)
        {
            cout<<"DeQueue is empty!"<<endl;
        }

        else
        {
            cout<<"Deleted element is :"<<a[front]<<endl;

            if(front == rear)
            {
                front = rear = -1;
            }
            else
                front = front + 1;
        }
    }

    //This operation deletes an element from the rear.
    deleteRear()
    {
        if(front == -1)
        {
            cout<<"DeQueue is empty!"<<endl;
        }

        else
        {
            cout<<"Deleted element is :"<<a[rear]<<endl;

            if(front == rear)
                front = rear = -1;

            else
                rear = rear - 1;
        }
    }

    //This operation displays all the element of the DeQueue.
    void display()
    {
        if(front == -1)
            cout<<"DeQueue is empty"<<endl;

        else
        {
            cout<<"Queue formed is : ";
            for(int i=front ; i<=rear ; i++)
                cout<<a[i]<<"  ";
        }
    }
};


int main()
{
    DeQueue d;
    int choice,item;
    while(1)
    {
        cout<<endl;
        cout<<"1. Insert in beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Delete from front"<<endl;
        cout<<"4. Delete from rear"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter the element for insertion : ";
            cin>>item;
            d.startInsert(item);
            break;

        case 2:
            cout<<"Enter the element for insertion : ";
            cin>>item;
            d.endInsert(item);
            break;

        case 3:
            d.deleteFront();
            break;

        case 4:
            d.deleteRear();
            break;

        case 5:
            d.display();
            break;

        case 6:
            exit(0);

        default:
            cout<<"IVALID CHOICE!";
        }
    }
    return 0;
}


/*
    Complexities:
    Insertion --> O(1)
    Deletion ---> O(1)
    Display-----> O(n)

    Test Cases:

    Output(1):
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 1
        Enter the element for insertion : 10

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 2
        Enter the element for insertion : 20

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 2
        Enter the element for insertion : 30

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 5
        Queue formed is : 10  20  30
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 3
        Deleted element is :10

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 4
        Deleted element is :30

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 5
        Queue formed is : 20
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 6


    Output(2):
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 1
        Enter the element for insertion : 5

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 2
        Enter the element for insertion : 10

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 2
        Enter the element for insertion : 15

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 5
        Queue formed is : 5  10  15
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 4
        Deleted element is :15

        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 5
        Queue formed is : 5  10
        1. Insert in beginning
        2. Insert at end
        3. Delete from front
        4. Delete from rear
        5. Display
        6. EXIT
        Enter your choice : 6
*/
