/*
This Program deletes the alternate nodes of the linked list created by the user.
Language: C++

Logic Used:
After creating a linked list, call the alternate_delete() function.
Traverse the list and unlink/delete and free data of every node at even position.
*/


#include <iostream>
#include <stdlib.h>
#include <cstddef>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node* head=nullptr;
Node* tail=nullptr;

void create(int n)
{
    while(n!=0)
    {
        int x;
        cin>>x;
        if (head==nullptr)
        {
            Node* temp=new Node;
            temp->data=x;
            temp->next=nullptr;
            head=temp;
            tail=head;
        }
        else
        {
            Node* temp=new Node;
            temp->data=x;
            temp->next=nullptr;
            tail->next=temp;
            tail=temp;
        }
        n--;
    }
}

void alternate_delete()
{
    if(head==nullptr)
    {
        return;
    }
    Node *temp1=head;
    Node *temp2=head->next;
    while(temp2!=nullptr && temp1!=nullptr)
    {
        temp1->next=temp2->next;
        free(temp2);
        temp1=temp1->next;
        if(temp1!=nullptr)
        {
            temp2=temp1->next;
        }
    }
}

void display()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main()
{
    cout<<"Enter no. of nodes in linked list: ";
    int y;
    cin>>y;
    create(y);
    cout<<"Linked List Created: ";
    display();
    cout<<endl<<"Resulting linked list: ";
    alternate_delete();

    display();

}

/*
Input format in test cases:
1st line contains number of nodes in the linked list(n).
2nd line contains value of each node (total n) separated by spaces.

--------------------------------------------------
Test Case 1:
Input:
6
1 2 3 4 5 6

Output:
Linked List Created: 1->2->3->4->5->6->NULL
Resulting linked list: 1->3->5->NULL
---------------------------------------------------
Test Case 2:
Input:
9
1 2 3 4 5 6 7 8 9
Output:
Linked List Created: 1->2->3->4->5->6->7->8->9->NULL
Resulting linked list: 1->3->5->7->9->NULL
----------------------------------------------------

Time Complexity: alternate_delete() function: O(n)
Space complexity: alternate_delete() function: O(1)

*/
