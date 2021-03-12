/*  Add Two Numbers represented by the linked lists

Algorithm used : Let's generalize the two numbers addition algorithm on paper ,
                 Taking a number num = 0 
                 Starting from the last digit of the numbers , 
                 sum = add both the digits + previous carry (if any)
                 sum%10 is the carry, that is to be added in the digit (one position less)of num;
                 sum/10 is the digit for the current position of the num

                 That's the similar algorithm has been implemented in the code below using linked list

                 After adding linked list1 and linked list2 the linked list 1 comes out as the result sum;
*/

#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Node{

    /* Node Class is the blueprint or we can say datatype of the Linked list block used
    in the code */

    /* Private data members */
    int data;
    Node *next;
    
    public:
    Node(int d){

        data = d;
        next = NULL;
    }
    Node(int d, Node* n){
        
        data = d;
        next = n;
    }
    
    int getData(){
        /* Function returns the value of the data variable */
        return data;
    }

    Node * getNext(){
        /* Function returns the value of next variable */
        return next;
    }
    
    void addData( int d){
        /* Function is used to update the value of data variable */
        data = d;
    }

    void addNext( Node* n){
        /* Function is used to update/initialize the value next variable */
        next = n;
    }

};

void printTheList(Node *head) {

    /*Function prints the Linked List of type Node* while traversing list in forward */
    
    if(head == NULL) return; /* End of the Linked List*/

    printTheList( head->getNext() );

    cout << head->getData() ;

}

Node *createLinkedList( string num , int index){

    /* Function is to create linked list of the number's digits in reverse order */
    
    if (index < 0) return NULL;

    int x = num[index] - 48 ; /* Char to Int conversion */
    
    Node *newNode = new Node(x); /* Memory allocation for  new Linked List block */

    newNode->addNext( createLinkedList(num , index - 1 )) ;

    return newNode;
}

Node *AddTwoLinkedListNumbers( Node *head1, Node *head2, int carry=0){

    if(head1 == NULL && head2 == NULL){

        if(carry != 0){

            Node *temp = new Node( carry );
            
            return temp ;
        }
        return NULL;
    }

    if( head1 == NULL ){

        head1 = head2;
        head2 = NULL;

    }
    
    carry += head1->getData();

    if(head2!=NULL){

        carry += head2->getData();

        head2 = head2->getNext();
    }

    head1->addData( carry%10 );
    
    carry = carry/10;

    head1->addNext( AddTwoLinkedListNumbers( head1->getNext(), head2, carry));
    
    return head1;

}
int main() {

    string num1;
    string num2;
    cout << "Enter the number 1 " << num1 << endl;
    cin >> num1 ;
    cout << "Enter the number 2 " << num2 << endl;
    cin >> num2;
    
    /* Creating Linked List of the Number,s digits in reverse order*/

    Node *head1 = createLinkedList( num1 , num1.length()-1 ); /* Linked list 1 */

    Node *head2 = createLinkedList( num2 , num2.length()-1 ); /* Linked list 2 */

    // Adding the two Numbers in Linked lists created , and storing the result in Linked List 1

    head1 = AddTwoLinkedListNumbers( head1, head2) ;
    
    /* To know the sum , print the linked list 1 */

    printTheList( head1 );
    cout<<endl;

}


/*
Sample Input/Output
    Sample Input 1: 
        Enter the number 1: 23
        Enter the number 2: 22
    Sample Output 1:
        45

    Sample Input 2:
        Enter the number 1: 1000
        Enter the number 2: 1
    Sample Output 2:
        1001

    Sample Input 3:
        Enter the number 1: 99
        Enter the number 2: 5
    Sample Output 3:
        104

Complexitiy Analysis :

    Time complexity : O(n+m) , n and m is the length of two number's linked list
    Auxillary Space : O(1), In this code we have stored the result in linked list 1 only ,
                      haven't utilized any extra space

*/
