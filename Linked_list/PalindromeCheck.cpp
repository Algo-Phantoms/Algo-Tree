   /*Check if the linked list is palindrome or not if yes return true if not return false. Linked list has to be taken as an input from the user.*/

#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node* reverse (Node *save)
       {
          if(save == NULL || save->next == NULL)  
           {
    
               return save;                      // BASE CASE: if it is empty or is of size one
           }
    
           Node *new_head = reverse(save->next);//RECURSIVE CALL
           Node *temp = save->next;      
           temp->next = save;
           save->next = NULL;
           return new_head; 
       }

       bool isPalindrome (Node *head)
       {
           Node *help = head;
           Node *temp = reverse(help);          //reversing the linked list ans saving its head in temp
    
           if(head == NULL) {
               return 1;
           }
           while(temp && help) {
               if(temp->data != help->data) {   //comparing the given input linked list with its reverse
                   return 0;
               }
               else {
                   return 1;
               }
               temp = temp->next;
               head = head->next;
           }
       }

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
/*
----------------------------------------------------------------------------------
SAMPLE TEST CASE 1:
INPUT:
Enter number of test cases:1
enter the linked list(enter -1 at the end of the linked list):3 9 7 9 3 -1
OUTPUT:
true
-------------------------------------------------------------------------------------
SAMPLE TEST CASE 2:

 Enter number of test cases:2
 enter the linked list(enter -1 at the end of the linked list):3 1 3 -1
 true
 1 2 3 -1
 false
 ----------------------------------------------------------------------------------------
TIME COMPLEXITY: O(N) [WHERE N IS THE SIZE OF SINGLY LINKED LIST]
SPACE COMPLEXITY: O(1)
*/
