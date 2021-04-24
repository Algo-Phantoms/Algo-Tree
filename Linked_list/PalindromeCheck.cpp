/*Check if the linked list is palindrome or not if yes return true if not return false. Linked list has to be taken as an input from the user.*/
Node* reverse(Node *save)
{
   if(save==NULL || save->next==NULL)  
    {

        return save;
    }
    
    Node *new_head = reverse(save->next);
    Node *temp = save->next;      
    temp->next = save;
    save->next = NULL;
    return new_head; 
}
bool isPalindrome(Node *head)
{
    Node *help=head;
  Node *temp = reverse(help);
    
    if(head==NULL){
        return 1;
    }
    while(temp && help){
        if(temp->data != help->data){
            return 0;
        }
        else{
            return 1;
        }
        temp = temp->next;
        head = head->next;
    }
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
TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/



