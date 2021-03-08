#include <bits/stdc++.h>
using namespace std;

//Creation of Node struct for Linked List
struct Node{
    int data;
    Node *next;
    Node(int element){
        data = element;
        next = NULL;
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
    Node * head = new Node(1);
    head -> next = new Node (2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = head->next;
    cout << detectCycle(head);
    return 0;
}

/*Test Case
Input : 1->2->3
           |  |
           ^ --<
Output : 1

Time Complexity
O(N)

Space Complexity
O(1)
*/