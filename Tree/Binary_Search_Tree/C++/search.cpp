#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int x){ // constructor
		data = x;
		left = nullptr;
		right = nullptr;
	}

};

node* Insert_into_bst(node* root, int data){

	if(root == nullptr){ // make new node
		root = new node(data);
		return root;
	}

	else if(data < root->data){
        root->left = Insert_into_bst(root->left,data);
	}
	else{
        root->right = Insert_into_bst(root->right,data);
	}

	return root;
}
node* Create_BST(){

	int data; // root node
	cin >> data;

	node* root = nullptr;

	while(data!= -1){ 
		root = Insert_into_bst(root, data);
		cin >> data;
	}

	return root;
}

	
bool search(node* root, int key){

	if(root == nullptr)
		return false;

	if(root->data == key)
		return true;

	else if(root->data > key){
		search(root->left, key);
	}
	else{
		search(root->right, key);
	}

	
}




int main(){

	node* root = Create_BST();
	int ele;
	cin >> ele;
    cout << boolalpha << search(root, ele);
	return 0;
}

/* Test Case - 
 Input - 1 2 3 4 5 6 -1
 4

 Outout - true
 */