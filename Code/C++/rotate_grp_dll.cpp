/* Rotation of douly linked list(dll) with given group size

   There is a doubly linked list and if we want to reverse/rotate the elements of it in groups then we can use the following solution. 
   Let size of doubly linked list be 'n' and size of groups be 'k'.
   
   Solution: 
   A recursive function is defined with parameters: head of dll , k group size. 
   1. Initialise three pointers-  cur,next,newh.
   2. cur points to the current node , next points to next node and newh points to head of group of elements in dll to be reversed .
   3. Initially cur = head , next = null , newh = null. 
   4. We traverse the dll for k elements via cur pointer :
      - make next = cur->next
      - now push the cur node as new node at beginning of newh dll
      - now move cur one step ahead ,i.e, cur = next  
   5. Check if next != null , i.e, cur is not pointing to end of dll
      - recursively call for the next group to be reversed and link them accordingly
   6. Now return the newh for modified dll .    
*/ 

#include<bits/stdc++.h>
using namespace std;

//structure for a node of doubly linked list
struct node{                     
    int data;
    node* next;
    node* prev;
};

//function to form a new node with value entered by user 
node* new_node(int val)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;

    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

/*
  function to insert a node at the beginning of doubly linked list
  To get input as : 1 2 3 4 
  We need to enter in order: 4 3 2 1 
  as on entering the node is added in the beginning
*/
void insert_at_beg(node** head ,node* newnode)
{
    newnode->next=(*head); 
    newnode->prev=NULL;
    
    if((*head)!=NULL)
     (*head)->prev = newnode;
    
    (*head)=newnode;   
}

//recursive function to rotate a doubly linked list by given group of size
node* rotate_grp_of_given_size(node* head,int k)
{
    node* cur=head;
    node* next=NULL;
    node* newh=NULL;
    int c=0;
    
    /*
     loop to reverse a group of k or less than k nodes
     by adding each at beginning of dll newh
    */
    while(cur!=NULL && c<k)
    {
        next=cur->next;
        insert_at_beg(&newh,cur);
        cur=next;
        c++;
    }
    
    /*
     checking if next group is present to be reversed 
     and then calling it recursively and linking it accordingly
    */
    if(next!=NULL)
    {
        head->next=rotate_grp_of_given_size(next,k);
        head->next->prev=head;
    }
    
    //return the pointer pointing to new head of reversed group
    return newh;
}

//function to print the elements of doubly linked list
void print(node* head)
{
    while(head!=NULL)
    {
      cout<<(head->data)<<" ";
      head=head->next;
    }
}

//main function
int main()
{
    node* head= NULL;
    
    //Number of nodes
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    
    //values of nodes for dll
    int val;
    cout<<"Enter values for nodes: \n";
    for(int i=0;i<n;++i)
    {
        cin>>val;
        insert_at_beg(&head , new_node(val));
    }
    
    // Group size
    int k;
    cout<<"Enter group size: ";
    cin>>k;
    
    //Input list
    cout<<"List before rotation : ";
    print(head);

    //calling the function for desired rotation of groups
    head=rotate_grp_of_given_size(head, k);

    //Output list
    cout<<"\nList after rotation of groups : ";
    print(head);

    return 0;
}


/* Test Cases:
   1.
    Input: 
      Enter no. of nodes: 6
      Enter values for nodes: 
      3
      4
      6
      1
      5
      7
      Enter group size: 3
   
    Output:  
      List before rotation : 7 5 1 6 4 3
      List after rotation of groups : 1 5 7 3 4 6
   
   2.
    Input: 
      Enter no. of nodes: 5
      Enter values for nodes: 
      2
      9
      5
      3
      1
      Enter group size: 3  

    Output:  
      List before rotation : 1 3 5 9 2
      List after rotation of groups : 5 3 1 2 9   
   
   3.
    Input: 
      Enter no. of nodes: 4
      Enter values for nodes: 
      10
      20
      30
      40
      Enter group size: 8  

    Output:  
      List before rotation : 40 30 20 10
      List after rotation of groups : 10 20 30 40   



    Time Complexity : O(n) where n is the number of nodes
    Space Complexity : O(n) for worst case in recursive function call 
*/