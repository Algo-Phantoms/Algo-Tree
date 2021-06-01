/*
This method is about deleting any node in the given linked list without the use of head pointer
in this menthod we are going to apporoach like this:
1. we will start off by storing the node next to given node in a pointer.
2. the next step would be copying the data of pointer in the given current node.
3. then storing the next node to pointer in link part of current node. 
4. ans the last step of freeing up the used memory manually using free().
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Node {
  int info;
  struct Node *next;
  Node(int x) {
    info = x;
    next = NULL;
  }
}*head;



void insert()
{
    int n,k,data;
    Node *temp;
    scanf("%d",&n);

    for(k=0; k<n; k++)
    {
        scanf("%d",&data);
        if(k==0)
        {
            head=new Node(data);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(data);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}
void printLL(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->info);
        node = node->next;
    }
    cout << endl;
}
Node *find(Node* head, int search)
{
    Node* curr = head;
    while (curr != NULL)
    {
        if (curr->info == search)
            break;
        curr = curr->next;
    }
    return curr;
}


void deleteNodewohead(Node *node_ptr);
int main(void)
{    int tests,a,n,data;

    scanf("%d",&tests);
    while(tests--)
    {
        insert();
        scanf("%d",&a);
      
        Node *dele = find(head, a);
        if (dele != NULL && dele->next != NULL)
        {
            deleteNodewohead(dele);
        }
        printLL(head);
    }
    return(0);
}
void deleteNodewohead(Node *node)
{
  //It is assumed that the node asked to delete is not the last node but we can always try this :-

//         if(node->next!=NULL)
//         {
//         *node=*node->next;
//         return;
//         }
//         node=NULL;
   if(!node->next){
       return;
   }
   Node *delet= node->next;
   node->info=delet->info;
   node->next=delet->next;
   free(delet);
}


/*
sample case 1:
Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30.
Sample case 2:
Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.
Time complexity--> O(1)
Auxilliary Space--> O(1)
*/
