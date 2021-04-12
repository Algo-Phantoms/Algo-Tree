#include <bits/stdc++.h>
using namespace std;

#define N 5

/*
Instead of storing a single element at a node,
unrolled linked lists store an array of elements at a node.

The below program is a simple unrolled linked list with 5 nodes
containing a variable number of elements in each.
It also traverses the created list.
*/

//Unrolled Linked List Class
class Unrolled
{
    public:
        int arr[N];
        Unrolled *ptr;
        int capacity;       //it is the capacity of number of elements.
};

//Printing all the elements of unrolled linked list.
//Print elements in current node and moving to next node.
void display(Unrolled *ull)
{
    int i;
    while(ull != NULL)
    {
        for(i=0 ; i < ull->capacity ; i++)
            cout<< ull->arr[i]<<"  ";
        ull = ull->ptr;
    }
}


int main()
{
    Unrolled *ul1;

    int threshold;
    threshold = ((N/2)+1);

    //dynamically allocating the four nodes
    Unrolled* head = new Unrolled;
    Unrolled* second = new Unrolled;
    Unrolled* third = new Unrolled;
    Unrolled* fourth = new Unrolled;

    //putting values in the first node
    head->capacity = threshold;

    head->arr[0] = 1;
    head->arr[1] = 2;
    head->arr[2] = 3;
    //link first node with the second node
    head->ptr = second;
    second->capacity = threshold;


    //putting values in the second node
    second->arr[0] = 4;
    second->arr[1] = 5;
    second->arr[2] = 6;
    //link second node with the third node
    second->ptr = third;
    third->capacity = threshold;


    //putting values in the third node
    third->arr[0] = 7;
    third->arr[1] = 8;
    third->arr[2] = 9;
    //link third node with the fourth node
    third->ptr = fourth;
    fourth->capacity = threshold;

    //putting values in the fourth node
    fourth->arr[0] = 10;
    fourth->arr[1] = 11;
    fourth->arr[2] = 12;
    //the last or the fourth node will point to null
    fourth->ptr = NULL;

    display(head);

    return 0;
}

/*
    Complexity:
    Time complexity : O(n)

    Test Case 1-
    Input: 1  2  3  4  5  6  7  8  9  10  11  12
    Output:
    1  2  3  4  5  6  7  8  9  10  11  12

    Test Case 2-
    Input: 10 20 30 40 50 60 70 80 90 100 110 120
    Output:
    10 20 30 40 50 60 70 80 90 100 110 120
*/

