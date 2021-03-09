# Linked List

A linked list is a data structure used for storing collections of data. A linked list has the following
properties.

• Successive elements are connected by pointers

• The last element points to NULL

• Can grow or shrink in size during execution of a program

• Can be made just as long as required (until systems memory exhausts)

• Does not waste memory space (but takes some extra memory for pointers). It allocates memory as list grows.

###  Main Linked Lists Operations

• **Insert:** inserts an element into the list

• **Delete:** removes and returns the specified position element from the list

### Auxiliary Linked Lists Operations

• Delete List: removes all elements of the list (disposes the list)

• Count: returns the number of elements in the list

• Find nth node from the end of the list

## Questions :
* Insertion ----> [C++](/Code/C++/insertion_in_linked_list.cpp)

// A linked list node  
class node  
{  
    public: 
    int data;  
    node *next;  
};  


void push(node** head_ref,int new_data)  
{  node* new_node=new node();  
    new_node->data=new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
} 

void insertAfter(node* prev_node, int new_data)   
{   
    if (prev_node == NULL)   
    {   
        cout << "the given previous node cannot be NULL";   
        return;   
    }
    // allocateing new node
    node* new_node = new node();  
    // Puting in the data  
    new_node->data = new_data;   
    // Making changes  
    new_node->next = prev_node->next;   
    // next of prev_node as new_node  
    prev_node->next = new_node;   
}  

   
void append(node** head_ref, int new_data)   
{     
    node* new_node = new Node();    
    Node *last = *head_ref;    
    new_node->data = new_data;   
    new_node->next = NULL;     
    if (*head_ref == NULL)   
    {   
        *head_ref = new_node;   
        return;   
    }     
    while (last->next != NULL)   
        last = last->next;     
    last->next = new_node;   
    return;   
}  

// prints contents    
void Print(node *n)  
{  
    while (n != NULL)  
    {  
        cout<<" "<<n->data;  
        n = n->next;  
    }  
}  

int main()  
{  
    node* head = NULL;    
    append(&head, 5);  
      //it will become 4->5->NULL  
    push(&head, 4);  
      //will be 2->4->5->NULL  
    push(&head, 2);  
      //will become 1->2->4->5->NULL  
    append(&head, );  
    // Insert 3 after 4. 
    // list becomes 5->4->3->2->1->NULL  
    insertAfter(head->next, 3);  
      cout<<"Linked list is: ";  
    Print(head);  
      return 0;  
}  