// Approach
/*
Create a copy of 1st node and insert it between 1st node & 2nd of the original Linked List,
create a copy of 2nd node and insert it between 2nd node & 3rd node of the original linked list.
Continue this and add the copy of Nth node after the Nth node.
Now copy the random link using the following code:
	original_node->next->random_link = original_node->random_link->next;  
Now restore the original linked list and the copied linked list using the following code(single loop):
	original_node->next = original_node->next->next;
	copied_node->next = copied_node->next->next;
Ensure that original_node->next is NULL and return the cloned list
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	//Node->data
    int data;    
    //Node->next
    Node *next;  
    //Node Random Pointer
    Node *arb;	
    //Constructor of a node
    Node(int x) {      
        data = x;
        next = NULL;
        arb = NULL;
    }
};

// Print linked list
void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
    		k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

//Declaring a function to clone the linked list 
Node *copyList(Node *head);     

//To append a node in a linked list
void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } 
	else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

//checking if resultant linked list is cloned properly from the original linked list.
bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;
    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    //if lengths are not equal
    if (len1 != len2) 
		return false;
    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {        
        if(temp1==temp2)
            return false;        
        if (temp1->data != temp2->data)
			return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } 
		else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
        else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

//main function
int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;        
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;
            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;
            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }
            // when both a is greater than n
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        //read finished
        generated_addr = head;
        Node *res = copyList(head);
        Node *cloned_addr = res;        
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head) {
    Node *iter = head; 
    Node *front = head;
    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != NULL) {
        front = iter->next;
        Node *copy = new Node(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }
    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != NULL) {
        if (iter->arb != NULL) {
          iter->next->arb = iter->arb->next;
        }
        iter = iter->next->next;
    }
    // Third round: restore the original list, and extract the copy list.
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;
    while (iter != NULL) {
        front = iter->next->next;
        // extract the copy
        copy->next = iter->next;
        // restore the original list
        iter->next = front;              
        copy = copy -> next; 
        iter = front;
    }
    return pseudoHead->next;
}

/* 
INPUT:
N = 4, M = 2
value = {a, b, c, d}
pairs = {{1, 2}, {2, 4}}
Output: 1

Input:
N = 4, M = 2
value[] = {j, k, l, m}
pairs[] = {{1, 1}, {3, 4}}
Output: 1

Note: If the Linked list is cloned properly then output is 1 else 0.

Time Complexity : O(n)
Space Complexity : O(1)
*/
