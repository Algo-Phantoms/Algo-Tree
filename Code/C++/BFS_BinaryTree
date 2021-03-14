//BFS(Breadth-First Search) is a tree traversal technique where a node and its neighbours are visited first and then the neighbours of neighbours. In simple terms, it traverses level-wise from the source. First, it traverses level 1 nodes (direct neighbours of source node) and then level 2 nodes (indirect neighbours of source node) and so on. The BFS can be used to determine the level of each node from a given source node.
#include <bits/stdc++.h>
using namespace std;

//Considering a Binary tree where every node has a left and right child.
class TreeNode{
public:
	int num; //value at the node being referred to
	TreeNode * right; //pointer pointing to the right child of the node
	TreeNode * left; //pointer pointing to the left child of the node

	TreeNode(int num){
		this->num= num;
		right= NULL;
		left= NULL;
	}
};

//Creating a Tree by calling this function recursively for the left and right of the node created in the current function call
TreeNode* createtree(){
	int n; cin>>n;
	if(n==-1){
		//Assuming that '-1' means that the node is actually a NULL pointer.
		cout<<"Returning to the parent node as -1 is assumed to be a NULL pointer"<<endl;
		return NULL;
	} 
		

	TreeNode* root= new TreeNode(n);
	cout<<"Enter the value of the left child of the node with value "<<n<<" : "<<endl;
	root->left= createtree();
	cout<<"Enter the value of the right child of the node with value "<<n<<" : "<<endl;
	root->right= createtree();
	cout<<"Returning to the parent node"<<endl;

	return root;
}

//the vector will contain the order in which the tree has been traversed using the BFS traversal algorithm
vector<int> bfs(TreeNode* root){
	//BFS can be implemented using a queue. 
	vector<int> vec;

	if(root == NULL){
		//if the root is NULL then we have nothing to traverse upon and we return an empty array/vector(in C++) here.
		return vec;
	}

	queue<TreeNode*> q; //A queue to push in the root we have till now encountered
	q.push(root);

	while(!q.empty()){
		//The loop runs till the queue is not empty because when the queue is empty then it means that all the nodes have been traversed.
		TreeNode * curr= q.front();
		q.pop();

		if(curr == NULL){
			continue; 
		}

		vec.push_back(curr->num);

		if(curr->left != NULL) 
			q.push(curr->left);
		if(curr->right != NULL)
			q.push(curr->right);
	}

	return vec;
}

int main(){
	cout<<"Enter the number you wish to insert as the root in the Tree: "<<endl;
	TreeNode * root= createtree();

	vector<int> bfsorder= bfs(root);
	cout<<"\nThe BFS traversal of the Binary Tree created above is as follows: \n\n";
	for(int i=0; i<bfsorder.size()-1; i++)
	{
		cout<<bfsorder[i]<<" , ";
	}
	cout<<bfsorder[bfsorder.size()-1]<<endl<<endl;
	return 0;
}


//Sample Test Case

// For a Binary Tree:
//      5
//     / \
//    6   7
//   / \   \
//  8   9   10
//
// Traversal will occur in the following manner and the output would be:
// 5, 6, 7, 8, 9, 10
