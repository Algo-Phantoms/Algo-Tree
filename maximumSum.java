/*
Problem Statement-
We need to find maximum sum path from any node to any node in a binary tree.

Algorithm-
In order to check this we need to traverse through all the possible paths.
We start traversing from the one node and we keep on storing the max result in a variable.

*/

import java.io.*;
import java.util.*;

//Creating basic tree data structure
class Node {
	int val;
	Node left,right;
	// constructor

	Node(int data){
		val=data;
		left=null;
		right=null;
	}
}

public class maximumSum {
    static int ans;
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        Node root=new Node(-10);
        root.left=new Node(9);
        root.right=new Node(20);
        root.right.left=new Node(15);
        root.right.right=new Node(7);

        ans=Integer.MIN_VALUE;
        maxSum(root);
        System.out.println(ans);

		sc.close();
		return;
    }

    // An recursive function to find the maximum sum along any path.
    // Stores the result in a variable named as answer.
    public static int maxSum(Node root){
        if (root == null) return 0;
        int left = Math.max(0, maxSum(root.left));
        int right = Math.max(0, maxSum(root.right));
        ans = Math.max(ans, left + right +root.val);
        return Math.max(left, right) +root.val;
    }
}
/*
Time Complexity-O(n);
Space Complexity-O(n);

*/
