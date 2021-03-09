/* Detection of cycle or loop in a Singly linked list
Their may exist a node in a linked list which may point to another node present already in 
the linked list before it, this leads to formation of loop in the linked list.
Solution: We use hare and tortoise algorithm to solve the problem. We maintain to pointers hare and tortoise . Tortoise pointer move one step at one iteration 
and  hare pointer move by two steps in one iteration. At every iteration we see whether hare is equal to tortoise, if yes then it means there exist a loop in 
the list and we return true. Simultaneosly we also check if tortoise or hare or hare->next is NULL, if yes it means there is no cycle present and we return false.
*/

#include <bits/stdc++.h>
using namespace std;

//Creation of Node class for Linked List
class Node{
    public : 
    int data;
    Node *next;
    explicit Node(int element){
        data = element;
        next = NULL;
    }
};
//Creation of LinkedList class with inserAtEnd function
class LinkedList{
    public: 
    Node * head = NULL;
    Node * tail = NULL;
    void insertAtEnd(int data){
        Node * node = new Node(data);
        if(head==NULL){
            head = node;
            tail = node;
            return;
        }
        tail -> next = node;
        tail = node;
    }
};
//Hare and Tortoise Algorithm
//Both pointers meet at point if their exist a loop in the list ;otherwise any of the pointer encounters null
bool detectCycle(Node *head){
    Node *tortoise = head,*hare = head;
    do{
        if(hare==NULL || hare->next==NULL || tortoise==NULL){
            return false;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }while(hare!=tortoise);
    
    return true;
}
int main(){
    LinkedList *ls = new LinkedList();
    ls->insertAtEnd(1);
    ls->insertAtEnd(2);
    ls->insertAtEnd(3);
    ls->tail -> next = ls->head;
    cout << detectCycle(ls->head) << endl;
    return 0;
}

/*Test Case
Input : 1->2->3
        |    |
        ^----<
Output : 1

Input : 1->2->3->4->5
Output : 0

Time Complexity
O(N)
Space Complexity
O(1)
*/