/* circular linkedlist is a linkedlist in which the first element points to the last element and the
 last element points to the first element. */

#include <bits/stdc++.h> 

using namespace std; 


class Node { 
    public:
    int data; 
    Node* next; 
}; 


Node* newNode(int data) 
{ 
    //allocation of memory
    Node* newcopy = new Node; 
    newcopy->data = data; 
    newcopy->next = NULL; 
    return newcopy; 
} 

//  to reverse the circular linked list 
/*
STEPS:
1.Check if the node is NULL or not.
2.Initalize three pointers pre, curr and last.
3.Move the last pointer.
4.Link current node to the previous one.
5.Make previous node as current node.
6.Make current node as last node.
7.Now repeat the above process.
8.Now we need to adjust the links so that the last node can point to the first one.
*/

void reverse(Node** k) 
{ 

    if (*k == NULL) 
        return; 
    Node* pre = NULL; 
    Node* curr = *k; 
    Node* last; 
      do
      { 
        last = curr->next; 
        curr->next = pre; 
        pre = curr; 
        curr = last; 
      }  while (curr != (*k));


    (*k)->next = pre; 
    *k = pre; 
} 

// printing circular linked list 
void dispaly(Node* head) 
{ 
    if(head==NULL)
    cout<<"nothing to display";
    else
    {
       Node * temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
    }
}   


int main() 
{ 

    Node* head = newNode(5); 
    head->next = newNode(6); 
    head->next->next = newNode(7); 
    head->next->next->next = newNode(8); 
    head->next->next->next->next = head; 

    cout << "circular linked list: "; 
    dispaly(head); 
    cout<<endl;
    reverse(&head); 
    cout << "Reversed circular linked list: "; 
    dispaly(head); 

    return 0; 
} 

/* OUTPUT
circular linked list: 5678
Reversed circular linked list: 8765


Time Complexity :O(n)
Space Complexity :O(n) 

*/