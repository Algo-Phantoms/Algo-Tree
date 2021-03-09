#include <iostream>

using namespace std;

typedef struct sll
{
int data;
struct sll*next;
}node;
node *head;

void create()
{
node *temp=NULL, *ne;
char ch;
int no;
do
{
ne=new node;
cout << "Enter number:" << endl;
cin >> no;
ne->data=no;
ne->next=NULL;
if(head==NULL)
{
head=ne;
temp=ne;
}
else
{
temp->next=ne;
temp=ne;
}
cout << "Any other node y or n:" << endl;
cin >> ch;
}while(ch=='y');
}
void display()
{
node *temp;
temp=head;
if(temp==NULL)
cout << "NULL" << endl;
else
{
while(temp!=NULL)
{
cout << "     " << temp->data;
temp=temp->next;
}
}
}
void inserthead()
{
node *new1;
new1 = new node;
cout << "Enter data for new node:" << endl;
cin >> new1->data;
new1->next = NULL;
new1->next = head;
head = new1;
}
void insertlast()
{
node *new1, *temp;
new1 = new node;
cout << "Enter data for new node:" << endl;
cin >> new1->data;
new1->next = NULL;
temp = head;
while(temp->next!=NULL)
{
temp = temp->next;
}
temp->next = new1;
}
void insertafter()
{
int p;
cout << "Enter the position to added:" << endl;
cin >> p;
node *new1 = new node;
cout << "Enter data for new node:" << endl;
cin >> new1->data;
new1->next = NULL;
node *temp = head;
for(int i=0;i<p;i++)
{
temp = temp->next;
}
new1->next = temp->next;
temp->next = new1;
}
void search()
{
node *temp;
int key, flag=0;
temp = head;
cout << "Enter the key no to be search:" << endl;
cin >> key;
while(temp!=NULL)
{
if(temp->data == key)
{
flag = 1;
break;
}
temp = temp->next;
}
if(flag == 1)
cout << "Match is found" << endl;
else
cout << "Match is NOT found" << endl;
}
void delete_head()
{
node *temp;
temp = head;
head = head->next;
delete temp;
}
void delete_tmp()
{
node *temp, *tail;
temp = head;
while(temp->next!=NULL)
{
tail = temp;
temp = temp->next;
}
tail->next = NULL;
delete temp;
}
void delete_position()
{
int p;
cout << "Enter position to be deleted" << endl;
cin >> p;
node *temp, *current;
current = head;
for(int i=0; i<p; i++)
{
temp = current;
current = current->next;
}
temp->next = current->next;
delete current;
}
 int main()
{
int c;
char che;
do
{
cout << " choice 1:Create 2:display 3:insert_head 4:insert_last 5:insert_after 6:search 7:delete_head 8:delete_tmp 9:delete_at_particular_position " << endl;
cout << "Enter your choice:" << endl;
cin >> c;
switch(c)
{
case 1: create();
break;
case 2: display();
break;
case 3: inserthead();
break;
case 4: insertlast();
break;
case 5: insertafter();
break;
case 6: search();
break;
case 7: delete_head();
break;
case 8: delete_tmp();
break;
case 9: delete_position();
}
cout << "do you want to continue y or n:" << endl;
cin >> che;
}while(che=='y');

return 0;
}
