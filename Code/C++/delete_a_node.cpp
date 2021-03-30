#include <iostream>
using namespace std;
struct node
{
    int data; //struct of node
    struct node *next;
};

struct node *delete_node(struct node *head, int number); //function for deleting the node
int main()
{
    int number;
    struct node *head = NULL;
    cout << "Enter the number of nodes"; //number of node in linked list
    cin >> number;
    while (number--) //creating linkedlist
    {
        int value;
        cout << "Enter the data for node" << endl;
        cin >> value;
        struct node *temp = (struct node *)malloc(sizeof(node));
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *lastNode = head;
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = temp;
        }
    }
    cout << "Enter the node value to be deleted" << endl;
    cin >> number;
    head = delete_node(head, number); //function for deleting the particular node
    while (head != NULL)              //loop for printing the linked list
    {
        cout << head->data << " ";
        head = head->next;
    }
}
struct node *delete_node(struct node *head, int number)
{
    struct node *temp, *p;
    if (head == NULL)
    {
        cout << "list is empty";
        return head;
    }
    if (head->data == number)
    { //node to be deleted is first node
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    p = head;
    while (p->next != NULL)
    { //deletion  in between or at the end
        if (p->next->data == number)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            return head;
        }
        p = p->next;
    }
    cout << number << " is not present in the list" << endl; //node is not present in the list
    return head;
}

/* 
  Test case 1: 

  Input : 4
  1 2 3 4
  4

  Output : 
  1 2 3
   
  Test case 2: 

  Input : 4
  1 2 3 4
  1

  Output : 
  2 3 4 

  Time Complexity : O(n)
  Space Complexity : O(1)
*/
