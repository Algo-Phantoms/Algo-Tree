/*
We need to write a program to print the middle element in the linked list.
If the number of elements are odd then print the middle element.
If the number of elements are even then print the right part of the middle pair.
*/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    //constructor
    node(int x){               
      data = x;
      next = nullptr;
    }

};

class  LinkedList{
public:
    node* head;
    node* tail;

    //constructor
    LinkedList(){              
       head = nullptr;
       tail = nullptr;
    }
    
    void insert(int x){
        node* n = new node(x);

        //only one node
        if(head == nullptr){                
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
    }
};

int main(){

    LinkedList l;

    //size of linked list
    int n;
    cin>>n;

    //values inside linked list
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        l.insert(temp);
    }

    //middle index
    int mid=n/2;

    node *curr=l.head;
    int j=0;

    //To point to the middle element 
    while(j!=mid)
    {
        curr=curr->next;
        j++;
    }

    cout<<curr->data<<endl;

}

/*

Input:
5
1 2 3 4 5

Output:
3

Input:
6
1 2 3 4 5 6

Output:
4

Time Complexity: O(N)
Space Complexity: O(1)

*/
