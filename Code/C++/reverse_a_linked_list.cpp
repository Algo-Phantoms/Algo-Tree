#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class linked_list{
    Node *head;
    public:
    linked_list(){
        head = nullptr;
    }
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
    int n; cin>>n;
    linked_list a;
    int value;
    for(int i=0;i<n;i++){
        cin>>value;
        a.insert_at_beginning(value);
    }
    cout<<"Your list: "<<endl;
    a.print_list();
    a.reverse_list();
    cout<<"Reversed list "<<endl;
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

Time Complexity : O(n)
Space Complexity : O(1)
*/