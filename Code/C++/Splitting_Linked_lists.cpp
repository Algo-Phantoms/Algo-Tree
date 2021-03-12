
/*
This Program splits the linked list into two parts.
Language: C++

Logic Used:
If it's number of nodes in the linked list is even(2n) then both the lists contains n nodes.
If the original list contains odd number of nodes(2n+1) then 1st list contains n+1 nodes and 2nd contains n nodes.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

//initializing structure
struct node{
int data;
node *next;
};

struct node* head=NULL;
struct node* tail=NULL;

//Function to create a linked list
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

struct node* list1=NULL;
struct node* list2=NULL;

//Split Function
void split()
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    int n=0;
    temp=head;
    while(n!=(count-1)/2)
    {
        temp=temp->next;
        n++;
    }
    list1=head;
    list2=temp->next;
    temp->next=NULL;
}

void display(struct node* list)
{
    node* temp=list;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    cout<<"Enter no. of nodes in linked list: ";
    int y;
    cin>>y;
    create(y);
    cout<<"Linked List Created: ";
    display(head);
    split();
    cout<<"Split-ed Linked List: ";
    display(list1);
    display(list2);


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
Split-ed Linked List: 1->2->3->NULL
4->5->6->NULL
---------------------------------------------------
Test Case 2:
Input:
7
1 2 3 4 5 6 7
Output:
Linked List Created: 1->2->3->4->5->6->7->NULL
Split-ed Linked List: 1->2->3->4->NULL
5->6->7->NULL
----------------------------------------------------

Time Complexity: alternate_delete() function: O(n)
Space complexity: alternate_delete() function: O(n)

*/
