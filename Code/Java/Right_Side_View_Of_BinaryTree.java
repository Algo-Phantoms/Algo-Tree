/*
PROBLEM STATEMENT:
Given a binary tree, print the right side view of the tree.
For example:
		    44
		   /  \
		  43    71
		 / \  / 
		1  8 4  
	       /   \
	      64    28
Right side view: 44 71 4 28 
   APPROACH:-
   Iterative Implementation using Queue: In an iterative version , perform a level order traversal on the tree. The idea is 
   to modify level order traversal to maintain nodes at the current level. Then if the current node is the last node of the
   current level , Print it.
*/

import java.util.ArrayDeque;
import java.util.Queue;
 
// A class to store a binary tree node
class Node
{
    int key;
    Node left = null, right = null;
 
    Node(int key) {
        this.key = key;
    }
}
 
class Main
{
    // Iterative function to print the right view of a given binary tree
    public static void printRightView(Node root)
    {
        // return if the tree is empty
        if (root == null) {
            return;
        }
 
        // create an empty queue and enqueue the root node
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(root);
 
        // to store the current node
        Node curr = null;
 
        // loop till queue is empty
        while (!queue.isEmpty())
        {
            // calculate the total number of nodes at the current level
            int size = queue.size();
            int i = 0;
 
            // process every node of the current level and enqueue their
            // non-empty right and right child
            while (i++ < size)
            {
                curr = queue.poll();
 
                // if this is the last node of the current level, print it
                if (i == size) {
                    System.out.print(curr.key + " ");
                }
 
                if (curr.left != null) {
                    queue.add(curr.left);
                }
 
                if (curr.right != null) {
                    queue.add(curr.right);
                }
            }
        }
    }
 
    public static void main(String[] args)
    {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);
        root.right.left.left = new Node(7);
        root.right.left.right = new Node(8);
 
        printRightView(root);
    }
}

/*
TEST CASES:
For Above test case example
    Output: 1 3 6 8
Note: -1 denote a Null Node for given Input.
1.
Input: 20 4 1 64 -1 -1 -1 8 -1 -1 7 34 -1 32 -1 -1 -1
Output: 20 7 34 32
Explanation: The tree will look like this
		    20		<----
		   /  \
		  4    7	<----
		 / \  / 
		1  8 34  	<----
	       /      \
	      64       32	<----
2.
Input: 10 7 8 -1 -1 9 -1 -1 15 18 -1 -1 19 -1 -1
Output: 10 15 19
Explanation: The tree will look like this
	        10			<----
		   /  \
		  7   15		<----
		 / \  /  \
		8   9 18  19	<----

The TIME COMPLEXITY of above solution is O(N) and
SPACE COMPLEXITY is also O(N) ,where N is the Number of nodes in the Tree.

*/
