/*
Find the intersection node of two singly linked lists
*/

/*
Example: The given two linked lists are
            1st: 5->10->15->20->25
            2nd: 7->8->10->15->20->35
        These two linked lists intersect at node with value 10
        
Please note: These intersecting nodes are on the same memory location

To achieve this-- 
1. Naive Approach:
    Use 2 nested for loops for travsersing individually for both the linked lists and check if the two nodes are same 
    If the nodes are same return the node and break the for loop.
    This approach will lead to n*m no of comparisons where 
        n-length of 1st linked list
        m-length of second linked list
    
    Time Complexity: O(n*m)
    Auxillary Space Required: O(1)
    This solution will not work for very large linked lists.So we require a optimised solution

2. Optimised solution:
    Algorithm:
        1.First check if head of one of the linked lists is NULL. If the condition is true then return NULL.
        2.Initialise two pointers a and b to headA and headB respectively.
        3.Traverse throught the nodes of the linked list
            3.1 If pointer a reaches to the end of the linked list then assign it to headB.
            3.2 Similarly if pointer b reaches to the end of the linked list then assign it to headA.
            3.3 Once both of them go reassigning they will be equidistant from the collision point.
            3.4 If both the pointers meet at a point then it is the intersection point and break the while loop
        4. After second iteration if there is no intersectin node then it reaches NULL.

    Time Complexity: O(n+m)
    Auxillary Space Required: O(1)

*/ 
        
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
};

//Utility function to find intersection of node of linked list
Node* pointOfIntersection(Node* headA, Node* headB)                     
{
    //If one of the head is NULL then the intersection point will be NULL (corner test case)
    if(headA==NULL || headB==NULL)                                      
    {
        return NULL;
    }

    //Initialising 2 pointers to head nodes
    Node* a = headA;                                                    
    Node* b = headB;

    while(a!=b)
    {
        /*If the pointer reaches end of the linked list that is it NULL then reassign it to head of another linked list 
        else move it to next node*/
        a = a == NULL ? headB : a->next;    

        /*If there is a intersection node then the while loop breaks and returns the node   
        else it returns NULL.*/                         
        b = b == NULL ? headA : b->next;                                
    }

    return a;                                                           
                                                                        
}


int main(){
    
    /*
    Create two linked linked lists

        1st: 5->10->15->20->25
        2nd: 7->8->10->15->20->25
    
    */

   //head node of 1st linked list
    Node* headA = new Node();       
    headA->val = 5;

    //head node of second linked list
    Node* headB = new Node();       
    headB->val = 7; 

    Node* newNode;

    //Creation of 2nd linked list  
    newNode = new Node();               
    newNode->val = 8;
    headB->next = newNode;


    //Creation of 1st linked list
    newNode = new Node();           
    newNode->val = 10;
    headA->next = newNode;
    headB->next->next=newNode;

    newNode = new Node();            
    newNode->val = 15;
    headA->next->next = newNode;

    newNode = new Node();
    newNode->val = 20;
    headA->next->next->next = newNode;

    newNode = new Node();
    newNode->val = 25;
    headA->next->next->next->next = newNode;

    //Initialising tail of linked list to NULL
    headA->next->next->next->next->next=NULL;      
    
    Node* point = NULL;

    point = pointOfIntersection(headA,headB);

    cout<<"The intersection node of linked list is "<<point->val<<endl;;
    return 0;
    
}

/*
    Time Complexity: O(n+m)
    Auxillary Space Required: O(1)
*/
/* 
Test Case:

Input:
    1st: 5->10->15->20->25
    2nd: 7->8->10->15->20->25

Output: 
    The intersection node of linked list is 10

*/