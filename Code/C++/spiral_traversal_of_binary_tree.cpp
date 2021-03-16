/*
We need to traverse the binary tree in spiral order. First row will be traversed from right to left,second from left to right and so on. 
NULL is pushed into the queue after every level. If we reach NULL we will print the entire vector(arr) in reverse if flag==0 and forward if flag==1.
After printing we will make the flag reverse and resize the vector to 0. We will keep on doing this process and at the end when the queue becomes empty
we will get the spiral traversal printed.  
*/


#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void spiral_level_order(Node * root) {
    if (root == NULL) return;

    queue < Node * > q;
    vector < int > arr;
    int flag = 0;

    q.push(root);
    q.push(NULL);

    while (q.empty() == false) {
        Node * temp = q.front();
        q.pop();

        //Printing level when NULL arrived
        if (temp == NULL) {

            //Printing in the reverse order
            if (flag == 0) {
                for (auto it = arr.end() - 1; it >= arr.begin(); it--) {
                    cout << * it << " ";
                }
                flag = 1;
            } 
            //Printing in the forward order 
            else {
                for (auto e: arr) {
                    cout << e << " ";
                }
                flag = 0;
            }

            arr.resize(0);

            //To check we have covered entire tree or not
            if (q.size() != 0) q.push(NULL);
            continue;
        }

        arr.push_back(temp -> data);
        if (temp -> left != NULL) q.push(temp -> left);
        if (temp -> right != NULL) q.push(temp -> right);
    }
}

int main() {
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    spiral_level_order(root);

    return 0;
}

/*
Input:
      1         <-
       \  
        7       ->
       / \
      9   4     <-

Output:
1 7 4 9

Input:
      1         <-
     / \
    5   7       ->
       / \
      6   4     <-
         / \
        2   3   ->
Output:
1 5 7 4 6 2 3


Time Complexity: O(Nodes)
Space Complexity: O(Nodes)
*/
