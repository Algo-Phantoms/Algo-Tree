#include <bits/stdc++.h>
using namespace std;

#define N 5

//Unrolled Linked List Node
struct node
{
    int arr[N];
    node *ptr;
    int capacity;       //it is the capacity of number of elements.
};                      //if number of elements i.e. capacity == size i.e. N then we cannot insert any element.

//Printing all the elements of unrolled linked list
void display(node *ull)
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
    node *ul1;

    int threshold;
    threshold = ((N/2)+1);

    //dynamically allocating the four nodes
    node* head = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;

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
    Test Case -

    Output ;
    1  2  3  4  5  6  7  8  9  10  11  12


*/
