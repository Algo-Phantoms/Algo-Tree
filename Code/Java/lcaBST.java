/*Aim: lowest common ancestors in a binary tree.
Approach Used : (Recursive Approach)
Start traversing the tree from the root node.
1. If the current node itself is one of p or q, we would mark a variable mid as True and continue the search for the other node in the left and right branches.
2. If either of the left or the right branch returns True, this means one of the two nodes was found below.
3. If at any point in the traversal, any two of the three flags left, right or mid become True, this means we have found the lowest common ancestor for the nodes p and q.
Source code : */
import java.util.Scanner;
public class lcaBT{
    private Node ans;
    public static class Node{
        int data;
        Node left;
        Node right;
        Node ans = null;
        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    public static Scanner scn = new Scanner(System.in);
    private boolean recurseTree(Node currentNode, Node p, Node q) {
        if (currentNode == null) {
            return false;
        }
        int left = this.recurseTree(currentNode.left, p, q) ? 1 : 0;
        int right = this.recurseTree(currentNode.right, p, q) ? 1 : 0;
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;
        if (mid + left + right >= 2) {
            this.ans = currentNode;
        }
        return (mid + left + right > 0);
    }
    public Node findLCA(Node root, Node p, Node q) {
        this.recurseTree(root, p, q);
        return this.ans;
    }
    public static void main(String[] args) {
        lcaBT lca = new lcaBT();
        Node node = new Node(3);
        node.left = new Node(5);
        node.left.left = new Node(6);
        node.left.right = new Node(2);
        node.left.right.left = new Node(7);
        node.left.right.right = new Node(4);
        node.right = new Node(1);
        node.right.left = new Node(0);
        node.right.right = new Node(8);
        System.out.print(lca.findLCA(node,node.left,node.right));       
	}
}
/*Time Complexity: O(n)
Space Complexity: O(n)
Test Case 1:
Input - 3,5,1,6,2,0,8,null,null,7,4 
        node.left : 5
        node.right : 1
Output - 3 
Test Case 2:
Input - 1,2,3,4,5,6,7
        node.left : 4
        node.right : 5
Output - 2
*/
