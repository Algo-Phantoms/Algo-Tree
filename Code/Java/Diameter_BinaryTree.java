
// The diameter of a tree(sometimes called the width) is the number of
// nodes on the longest path between two end nodes.

// The time complexity of the above solution is O(n), 
//where n is the total number of nodes in the binary tree. 

import java.util.concurrent.atomic.AtomicInteger;
 
// A class to store a binary tree node
class Node
{
    int data;
    Node left = null, right = null;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Diameter_BinaryTree
{

    public static int getDiameter(Node root, AtomicInteger diameter)
    {
        // base case: tree is empty
        if (root == null) {
            return 0;
        }
 
        // get heights of left and right subtrees
        int left_height = getDiameter(root.left, diameter);
        int right_height = getDiameter(root.right, diameter);
 
        // calculate diameter "through" the current node
        int max_diameter = left_height + right_height + 1;
 
     /* Return max of following three
          1) Diameter of left subtree
          2) Diameter of right subtree
          3) Height of left subtree + height of right subtree + 1
         */
        diameter.set(Math.max(diameter.get(), max_diameter));
 
        // it is important to return the height of the subtree rooted at the
        // current node
        return Math.max(left_height, right_height) + 1;
    }
 
    public static int getDiameter(Node root)
    {
        AtomicInteger diameter = new AtomicInteger(0);
        getDiameter(root, diameter);
 
        return diameter.get();
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
 
        System.out.print("The diameter of the tree is " + getDiameter(root));
    }
}





    //      1
    //     /\
    //  2      3
    //   \     /\
    //    4   5   6
    //        /\
    //       7  8

