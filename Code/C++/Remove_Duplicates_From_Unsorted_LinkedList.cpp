/*Removal of Duplicate elements from a given unsorted Linked List
  Approch: Take an unorderd map. Initialize two pointers, current and previous 
  pointing on head and null respectively.
  Run a loop until current is null, check for each value if present in map or not.
  If the value is not in map, insert that value.
  Else remove the element by making the previous's next pointing to current's next
  Hence the element is removed as current is running one element ahead of previous.
*/



#include<bits/stdc++.h>
using namespace std;

//Creation of Node class for Linked List
class Node{
public:
	int data;
	Node*next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

//printing the LL nodes after removal of duplicates
void print(Node *root)
{
    Node *temp = root;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = tem->next;
    }
}

//Code to remove Duplicates
Node * removeDuplicates( Node *head) 
{
    unordered_map<int, int> st;
    int i=0;
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL)
    {
        int value = current->data;
        if(st.find(value) != st.end())
        {
            prev->next = current->next;
        }
        else
        {
            st.insert({value, i});
            i++;
            prev = current;
        }
        current = current->next;
    }
    return head;
}

//Main method
int main()
{
    int T;
    cin >> T;
    for(int t=0;t<T;t++)
    {
        int n;
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0;i<n;i++)
        {
            int data;
            cin >> data;
            if(head == NULL)
            {
                head = temp = new Node(data);
            }
            else
            {
                temp->nxt = new Node(data);
                temp = temp->next;
            }
        }

        Solution obj;
        Node *res = obj.removeDuplicates(head);
        print(res);
        cout << endl;
    }
}

/*
Input: 
N = 4
value[] = {5,2,2,4}

Output: 
5 2 4

Time Complexity = O(n)
Space Complexity = O(n)

*/