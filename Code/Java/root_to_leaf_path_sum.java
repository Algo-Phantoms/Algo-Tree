
/*
Problem Statement-
We need to find that whether there is a possible path from root node to any leaf node in given binary tree.

Algorithm-
In order to check this we need to traverse through all the possible paths
We start traversing from the root node and we keep on subtracting the node value from the required sum.
if we reach a leaf node with sum=0 ,it means there exist such path 
else there does not exist any such path.

*/
package Code.Java;
import java.io.*;
import java.util.*;

class Node {
    int val;
    Node left, right;

    // constructor

    Node(int data) {
        val = data;
        left = null;
        right = null;
    }
}

public class root_to_leaf_path_sum {
    static Node add(Node root, int val) {
        if (root == null) {
            root = new Node(val);
        } else if (val <= root.val) {
            root.left = add(root.left, val);
        } else {
            root.right = add(root.right, val);
        }
        return root;
    }

    static boolean hasPathSum(Node root, int sum) {
        if (root == null) {
            return false;
        }
        if (root.left == null && root.right == null && sum - root.val == 0) {
            return true;
        }
        return (hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val));
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int val1 = sc.nextInt();
        Node node = new Node(val1);
        for (int i = 1; i < n; i++) {
            int val = sc.nextInt();
            add(node, val);
        }
        int sum = sc.nextInt();
        boolean ans = hasPathSum(node, sum);
        System.out.println(ans);
        sc.close();
        return;
    }
}

/*
 * Test Case 1:
 * 
 * Input: 4 1 7 9 4 50
 * 
 * Output: false
 * 
 * Test Case 2:
 * 
 * Input: 5 5 1 7 6 8 6
 * 
 * Output: true
 * 
 * Time Complexity- O(n) 
   Space Complexity-O(height)
 */
