/*
    Program: Multiplication of two numbers with representation of  linked list
    Algorithm: 
    1. Initiliased two numbers  num1 and num2 to zero.
    2. Traveresed both the linked list separately.
    3. Add the value of first node to variable num1 for first Linked List and num2 for second Linked List 
    4. From the second node, multiply the variable by 10 first,operate Modulo 10^9+7 to prevent integer overflow. 
        Then add the value of the node to l1 variable for first linked list and l2 variable for second linked list, 
    5. Repeat step 4 until we reach the last node of the list.

*/
#include<iostream>

using namespace std;

//For Linked list Node

struct Node
{
    int input;
    struct Node* next;
    Node(int a)
    {
        input = a;
        next = NULL;
    }
};

// Function for creating a new Node with given info

struct Node *newNode(int input)
{
    struct Node *new_Node = new Node(input);

    return new_Node;
}

Node *reverse(Node **r)
{
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!= NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
// Function for inserting a Node at the beginning of Doubly Linked List

void push(struct Node** head_ref, int new_data)
{
    //allocate Node
    struct Node* new_Node = newNode(new_data);
    //link old list off new Node
    new_Node->next = (*head_ref);
    //move head to point to new Node
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node)
{
    struct Node* temp;
    while(Node != NULL)
    {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
//Multiplication of contents of two Linked Lists
long long multiply_two_lists (struct Node* l1 , struct Node* l2)
{
    long long int num1 = 0, num2 = 0;
    while (l1 || l2)
    {
        if(l1)
        {
            num1 = ( num1* 10 + l1->input)%1000000007;//used Modulo 10^9+7 to prevent integer overflow
            l1 = l1->next;
        }

        if(l2)
        {
            num2 = (num2*10 + l2->input)%1000000007;
            l2 = l2->next;
        }
    }
    return (num1* num2)%1000000007;
}
//Function for printing a Linked List

void printlist(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d", Node->input);
        Node = Node->next;
    }
    printf("\n");
}

// Main Function
int main(void)
{
    int N,M,i,a;
    cout<<"Size of I Linkedlist:\n";
    struct Node* first = NULL;
    cin>>N;
    cout<<"Values for I LinkedList:\n ";
    for(i=0;i<N;i++)
    {
        cin>>a;
        push(&first, a);
    }
    cout<<"Size of II Linkedlist:\n";
    struct Node* second = NULL;
    cin>>M;
    cout<<"Values for II Linkedlist:\n";
    for(i=0;i<M;i++)
    {
        cin>>a;
        push(&second, a);
    }

    reverse (&first);
    reverse(&second);
    long long result = multiply_two_lists(first,second);

    cout<<"Result:\n";
    cout<<result<<endl;
    freeList(first);
    freeList(second);
    return 0;
}

/*
INPUT: 
 Size of I Linkedlist: 
2
Values for I LinkedList: 
 3 4
Size of II Linkedlist: 
1
Values for II Linkedlist: 
2
OUTPUT:
Result: 
68

INPUT:

Size of I Linkedlist:
3
Values for I LinkedList:
 1 2 3
Size of II Linkedlist:
2
Values for II Linkedlist:
1 2

OUTPUT:

Result:
1476

Time Complexity: O(n) here n is the size of the linked list.
Space Complexity: O(n) 
*/