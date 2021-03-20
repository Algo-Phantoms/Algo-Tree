/* Merging two sorted linked lists, and returning a final sorted list.

Steps:

1. Take the sorted linked elements input into the vector and create  linked list with the vector elements.

2. We will be using Merge Sort's  merge logic to merge the two sorted linked list.

3. send the two linked list  to the function merge.

4. There are 2 conditions to check
        a) If both linked list are empty , it will return NULL
        b) If either of the linked list is empty, simply return return the other one.

5. If above all the conditions are false, so compare the current elements of the linked list and store smaller value of the both linked list 
   in the result linked list.
   After that call the merge function again with  next position of the linked list used and the position of the linked list which is not used.


*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
};

node *createNode(int val)
{
    node *newnode =  new node();
    newnode->val=val;
    newnode->next=NULL;
    return newnode;
}
//node creation  function
node* createLinkedList(vector<int>v)
{
    node *head=NULL;
    node *temp=NULL;

    for(int i=0;i<v.size();i++)
    {
        if(i==0)
        {
            node *newnode= createNode(v[i]);
            temp=newnode;
            head=temp;
        }
        else{
            node *newnode = createNode(v[i]);
            temp->next=newnode;
            temp=temp->next;
        }
    }
    return head;
}

// for mergeing both the linked list.
node* merge(node* head1,node* head2)
{
    if(head1==NULL and head2==NULL)
    {
        return NULL;
    }
    else if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }

    node *result=NULL;
       // comparing current element of the linked list
    if(head1->val<=head2->val)
    {
        node* newnode=createNode(head1->val);
        result=newnode;

        // calling merge and sending the next postion of head1.
        result->next = merge(head1->next,head2);
    }
    else{
        node* newnode=createNode(head2->val);
        result=newnode;
        // calling merge and sending the next postion of head2.
        result->next = merge(head1,head2->next);
    }
    return result;
}

void display(node* head)
{   
    cout<<"Sorted Merged Linked List"<<"\n";
    while(head!=NULL)
    {   
        
        cout<<head->val<<" ";
        head=head->next;
    }
}



int main()
{
    node *head1=NULL,*head2=NULL;
    cout<<"Enter the size of the linked list 1:- ";
   
    int size;
    cin>>size;
    vector<int>v;
    int x;

    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    head1=createLinkedList(v);
    v.clear();
    cout<<"Enter the size of the linked list 2:- ";
    cin>>size;

     for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    head2=createLinkedList(v);

    node *merged=NULL;

    merged = merge(head1,head2);

    display(merged);



return 0;

}



    /*  TESTCASES

    1.
        Enter the size of the linked list 1:- 3
        3
        4
        5
        Enter the size of the linked list 1:- 5
        6
        7
        8
        9
        10
        Sorted Merged Linked List     
        3 4 5 6 7 8 9 10



    2.
        Enter the size of the linked list 1:- 0
        Enter the size of the linked list 2:- 5    
        1
        3
        5
        6
        7
        Sorted Merged Linked List     
        1 3 5 6 7 

    TIME COMPLEXITY- O(m+n)   {where m and n are the lengths of the two lists to be merged}
    SPACE COMPLEXITY- o(m+n)



    */