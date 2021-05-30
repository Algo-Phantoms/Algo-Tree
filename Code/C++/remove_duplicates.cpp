/*

    Problem : Remove duplicates from an unsorted linked list
    Algorithm : This problem can be solved by hashing. The elements are hashed to a hash array and elements with frequency more than 1 are picked only once.

*/
    #include <bits/stdc++.h>
    using namespace std;


    struct Node
    {
        int data;
        struct Node *next;
    }*first=NULL,*second=NULL,*third=NULL;

    // Prints the Linked List
    void Display(struct Node *p)
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }

    //Creates the Linked List
    void Create(int A[],int n)
    {
        int i;
        struct Node *t,*last;
        first=(struct Node *)malloc(sizeof(struct Node));
        first->data=A[0];
        first->next=NULL;
        last=first;
        for(i=1;i<n;i++)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }

    // Removes the duplicates by hashing
    void RemoveDuplicate(struct Node *p)
    {
        int hash[10000] = {0};
        struct Node *temp = p;
        struct Node *ptr;
        struct Node *tail;

        // Checks the frequency of each element by hashing and removes duplicates
        while(temp!=NULL){
            hash[temp->data]++;
            if(hash[temp->data]>1){
                ptr->next = temp->next;
                tail = temp;
                temp=temp->next;
                free(tail);
                continue;
            }
            ptr = temp;
            temp=temp->next;
        }
    }

    int main()
    {
        int n;
        cout<<"Enter the no. of elements\n";
        cin>>n;
        int A[n];
        cout<<"Enter the elements\n";
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Create(A,n);
        RemoveDuplicate(first);
        cout<<"The final list is\n";
        Display(first);
        return 0;
    }

/*

 Test Case 1 :
 Input -   Enter the no. of elements
           10
           Enter the elements
           12 25 48 14 97 52 25 48 32 78
 Output -  The final list is
           12 25 48 14 97 52 32 78

 Test Case 2 :
 Input -   Enter the no. of elements
           15
           Enter the elements
           36 48 75 12 35 36 110 250 12 24 96 12 85 100 75
 Output -  The final list is
           36 48 75 12 35 110 250 24 96 85 100

 Time Complexity : O(n)
 Space Complexity : O(1)
    where 'n' is the number of elements in the list.

 */

