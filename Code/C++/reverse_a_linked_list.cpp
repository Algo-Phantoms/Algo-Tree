/*
The following algorithm is used for reversing a linked list:
    1. Initialize three pointers: prev, curr and ahead.
    2. curr points to the current node we're at, prev to its previous node and ahead points to the node that comes after curr.
    4. Initially curr = head and prev = nullptr.
    3. We traverse the linked list until curr becomes null.
    4. Make ahead = curr->next
    5. Now make curr's pointer point to prev i.e. curr->next = prev
    6. Move prev one step further i.e. prev = curr
    7. Move curr one step further i.e curr = ahead
    8. After the loop terminates, prev will be pointing to the new head i.e the last node in the list. So make head = prev
*/
#include<bits/stdc++.h>
using namespace std;

//Defining the structure of a node 
class Node{
    public:
    int data;
    Node *next;
};
class linked_list{
    //Head points to the first node in the list
    Node *head;
    public:
    linked_list(){
        head = nullptr;
    }
    
    //This method inserts a node in the beginning of the list
    void insert_at_beginning(int data){
        if(head==nullptr){
            head = new Node;
            head->data = data;
            head->next = nullptr;
            return;
        }
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
    
    //This method prints the list
    void print_list(){
        Node *n = head;
        while(n!=nullptr){
            cout<<n->data<<" ";
            n=n->next;
        }cout<<endl;
    }
    //Method for reversing the list
    void reverse_list(){
        Node *prev = nullptr, *curr = head, *ahead;
        while(curr!=nullptr){
            ahead = curr->next;
            curr->next = prev;
            prev=curr;
            curr=ahead;
        }
        head = prev;
    }
};
int main(){
    //Number of nodes
    int n; cin>>n;
    linked_list a;
    int value;
    //Constructing the linked list 
    for(int i=0;i<n;i++){
        cin>>value;
        a.insert_at_beginning(value);
    }
    cout<<"Your list: "<<endl;
    //Prints the inputed list
    a.print_list();
    //Reverses the list
    a.reverse_list();
    cout<<"Reversed list "<<endl;
    //Prints the reversed list
    a.print_list();
    return 0;
}
/*
Test Cases:

1.
Input:
5
10 20 30 40 50

Output:
Your list: 
50 40 30 20 10 
Reversed list 
10 20 30 40 50

2.
Input:
1
10

Output:
Your list: 
10 
Reversed list 
10

3.
Input:
8
10 20 30 40 50 60 70 80

Output:
Your list: 
80 70 60 50 40 30 20 10 
Reversed list 
10 20 30 40 50 60 70 80

Time Complexity : O(n) n is the number of nodes.
Space Complexity : O(1)
*/
