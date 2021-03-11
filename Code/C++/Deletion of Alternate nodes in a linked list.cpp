/*
This Program deletes the alternate nodes of the linked list created by the user.
Language: C++

Logic Used:
After creating a linked list, call the alternate_delete() function.
Traverse the list and unlink/delete and free data of every node at even position.
*/


#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
int data;
node *next;
};

struct node* head=NULL;
struct node* tail=NULL;

void create(int n)
{
    while(n!=0)
    {
        int x;
        cin>>x;
        if (head==NULL)
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            head=temp;
            tail=head;
        }
        else
        {
            node* temp=new node;
            temp->data=x;
            temp->next=NULL;
            tail->next=temp;
            tail=temp;
        }
        n--;
    }
}

void alternate_delete()
{
    if(head==NULL)
    {
        return;
    }
    node *temp1=head;
    node *temp2=head->next;
    while(temp2!=NULL&&temp1!=NULL)
    {
        temp1->next=temp2->next;
        free(temp2);
        temp1=temp1->next;
        if(temp1!=NULL)
        {
            temp2=temp1->next;
        }
    }
}

void display()
{
    node* temp=head;
    while(temp!=NULL)
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
