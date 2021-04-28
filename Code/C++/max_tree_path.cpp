/*Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another. 
The maximum sum path may or may not go through root.
 For example, in the following binary tree, the maximum sum is 27(3 + 6 + 9 + 0 – 1 + 10). Expected time complexity is O(n)*/

#include<bits/stdc++.h>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

// Recursive function to find the maximum path sum "starting" from the
// given node in a binary tree. The maximum path sum between two nodes
// in a binary tree is updated in the reference variable `result`.
int findMaxPathSum(Node* node, int &result)
{
	// base case: empty tree
	if (node == nullptr) {
		return 0;
	}

	// find maximum path sum "starting" from the left child
	int left = findMaxPathSum(node->left, result);

	// find maximum path sum "starting" from the right child
	int right = findMaxPathSum(node->right, result);

	// Try all possible combinations to get the optimal result
	result = max(result, node->data);
	result = max(result, node->data + left);
	result = max(result, node->data + right);
	result = max(result, node->data + left + right);

	// return the maximum path sum "starting" from the given node
	return max(node->data, node->data + max(left, right));
}

int main()
{
	/* Construct the following tree
			1
		  /   \
		 /     \
		2      10
	   / \    /  \
	 -1  -4  -5   -6
		 /   / \
		3   7   4
			 \
			 -2
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(10);
	root->left->left = new Node(-1);
	root->left->right = new Node(-4);
	root->right->left = new Node(-5);
	root->right->right = new Node(-6);
	root->left->right->left = new Node(4);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(4);
	root->right->left->left->right = new Node(-2);

	int result = numeric_limits<int>::min();
	findMaxPathSum(root, result);
	cout << "The maximum path sum is " << result << endl;

	return 0;
}