  
/*
Tree sort is an online sorting algorithm that builds a binary search tree from the elements to be sorted, and then traverses the tree (in-order) so that the elements come out in sorted order.

* Algorithm:

    Step 1: Take the elements input in an array.
    Step 2: Create a Binary search tree by inserting data items from the array into the binary search tree.
    Step 3: Perform in-order traversal on the tree to get the elements in sorted order.
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(int*array, int size) {
for(int value=0; value<size; value++)
cout << array[value] << " ";
cout << endl;
}

struct Node {
  int keyValue;
  struct Node * left, * right;
};

struct Node * newNode(int item) {
  struct Node * temp = new Node;
  temp -> keyValue = item;
  temp -> left = temp -> right = NULL;
  return temp;
}

void storeSorted(Node * root, int arr[], int & i) {
  if (root != NULL) {
    storeSorted(root -> left, arr, i);
    arr[i++] = root -> keyValue;
    storeSorted(root -> right, arr, i);
  }
}

Node * insert(Node * node, int keyValue) {
  if (node == NULL) return newNode(keyValue);
  if (keyValue < node -> keyValue)
    node -> left = insert(node -> left, keyValue);
  else if (keyValue > node -> keyValue)
    node -> right = insert(node -> right, keyValue);
  return node;
}

void treeSort(int arr[], int n) {
  struct Node * root = NULL;
  root = insert(root, arr[0]);
  for (int i = 1; i < n; i++)
    root = insert(root, arr[i]);
  int i = 0;
  storeSorted(root, arr, i);
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements value:" << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Array before Tree Sorting: ";
  display(arr, n);
  treeSort(arr, n);
  cout << "Array after Tree Sorting: ";
  display(arr, n);
}

/* 
	Test case : 
  INPUT:
	Enter the number of elements : 5
  Enter the elements value:
	4 3 5 1 2

	OUTPUT : 
  Array before Tree Sorting:
	4 3 5 1 2
  Array after Tree Sorting:
	1 2 3 4 5

  Worst complexity: n*log(n) (balanced)
  Average complexity: n*log(n)
  Best complexity: n*log(n)
  Space complexity: n

*/