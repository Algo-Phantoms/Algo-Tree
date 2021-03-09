/*This program contains the insert element algo.
 * Here you can create linked list using insert and also insert
 * new number at last using the same function*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

void insert(int x) {
    struct Node *t = new Node;
    t->next = NULL;
    t->data = x;
    if (first == NULL) {
        first = last = t;
    } else {
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    cout<<"Enter No. of elements you wish to insert in linked list :";
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int x;
        cout<<"Enter Element :";
        cin>>x;
        insert(x);
    }
    cout<<"Elements of linked list are :"<<endl;
    display(first);
    cout<<"Enter new number to be inserted :";
    int x;
    cin>>x;
    insert(x);
    cout<<"Elements of linked list are :"<<endl;
    display(first);
    return 0;

}



/* Sample output 1
Enter No. of elements you wish to insert in linked list : 5
Enter Element : 12
Enter Element : 56
Enter Element : 23
Enter Element : 41
Enter Element : 33
Elements of linked list are :
12
56
23
41
33
Enter new number to be inserted :78
Elements of linked list are :
12
56
23
41
33
78
*/

/* Sample output 2
Enter No. of elements you wish to insert in linked list :4
Enter Element : 25
Enter Element : 50
Enter Element : 75
Enter Element : 100
Elements of linked list are :
25
50
75
100
Enter new number to be inserted : 125
Elements of linked list are :
25
50
75
100
125
*/

