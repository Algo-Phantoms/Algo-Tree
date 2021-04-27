/*
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Our task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.

eg.) Input: String --> "abcde"
	    Frequency_array---> {5,9,12,13,16}

     Output: 00 01 100 101 11 
*/

#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node{
    char c;
    int frequency;
    
    Node *left, *right;
    
    Node(char c, int frequency)
    {
        this->c = c;
        this->frequency = frequency;
        left = right = NULL;
    }
};

// compare operator that will return the node with larger frequency.
struct compare
{
    bool operator() (Node *l, Node *r)
    {
        return(l->frequency > r->frequency);   
    }
};

// Function to print the nodes.
void print(Node *root, string str)
{
    if(!root)
        return;
        
    if(root->c != '%')
        cout<<str<<" ";
        
    print(root->left, str + "0");
    print(root->right, str + "1");
}

// Huffman Encoding here
void huffmanEncoding(string s, int f[], int n)
{
    Node *left, *right, *top;
    
    priority_queue<Node*, vector<Node*>, compare> minh; // Min-heap 
    
    // Pushing all the nodes in min-heap. The node with least frequency will be at top.
    for(int i = 0; i<n; i++)
    {
        minh.push(new Node(s[i],f[i]));    
    }
    
    
    while(minh.size() != 1)
    {
        left = minh.top();
        minh.pop();
        
        right = minh.top();
        minh.pop();
        
        // The new master node made with the sum of two smallest frequencies taken from top on min-heap. 
        top = new Node('%', left->frequency+right->frequency);
        
        top->left = left;
        top->right = right;
        
        minh.push(top);
    }
    
    print(minh.top(),"");    
}

// main function.
int main() {
	 string s;
         cout<<"Enter the string: ";
	 cin>>s;
	 int n = s.size();
	 int f[n];
         cout<<"Enter Frequency: ";
         for(int i = 0; i<n; i++)
         {
             cin>>f[i];
         } 
	  
	 huffmanEncoding(s,f,n);
	 cout<<endl;
	
	return 0;
}

/* Test Cases -

1) S = "abdefgh"
   F = {20,2,3,45,1,23,8}

   Output = 0 10 11000 110010 110011 1101 111 

2) S = "algorithm"
   F = {1,2,7,6,5,4,8,7,10}

   Output = 00 010 011 100 10100 10101 1011 110 111 


*/

// Time Complexity --> O(nlogn) 

