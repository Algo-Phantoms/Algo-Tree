/*Aim: Print all data present in Binary Search Tree in range d1 and d2 
Approach Used : 
(Assumption - Tree is Left Orientated )
Created a recursive function that takes root as a parameter and the range is (d1, d2)
If the value of root’s data is greater than d1, then recursively call in left subtree.
If the value of root’s data is in range, then print the root’s data.
If the value of root’s data is smaller than d2, then recursively call in the right subtree.
No extra space is used in this Approach
Source code : */
import java.util.Scanner;
public class printInRangeBST{
    public static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data = data;
            this.left = this.right = null;
        }
    }
    public static Scanner scn = new Scanner(System.in);
    public static Node insertData(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if(data <= root.data)
            root.left = insertData(root.left, data);
        else if (data > root.data)
            root.right = insertData(root.right, data);
        return root;
    }
    public static void printInRange(Node root, int d1, int d2){
        Node curr = root;
        if(curr == null)  return;
        if(d1 < curr.data)
            printInRange(curr.left,d1,d2);
        if(d1 <= curr.data && d2 >= curr.data)
            System.out.print(curr.data + "\t");
        if(d2 > curr.data)
            printInRange(curr.right,d1,d2);
    }
    public static void main(String[] args) {
        printInRangeBST printInRangeBST = new printInRangeBST();
        System.out.print("Enter root node data: ");
        int rootVal = scn.nextInt();	
        Node node = printInRangeBST.insertData(null, rootVal);	
        System.out.print("Enter no. of elements: ");
        int n = scn.nextInt();	
        System.out.print("Enter elements: ");
		for(int i = 1; i <= n; i++){
            int data = scn.nextInt();
			printInRangeBST.insertData(node, data);
		}
        System.out.print("Enter value of initial and final value: ");
        int d1 = scn.nextInt();
        int d2 = scn.nextInt();
        System.out.print("Elements in range are : ");
		printInRangeBST.printInRange(node,d1,d2);       
	}
}
/*Time Complexity: O(n)
Space Complexity: O(H)
n: no. of nodes
H: height of tree
Test Case 1:
Input - 12
        10
        3 21 1 24 4 26 7 29 9 10
        4 9
Output - 4 7 9 
Test Case 2:
Input - 55
        1
        57
        55 56
Output - 55
Test Case 3:
Input - 50
        9
        25 12 37 30 75 62 60 70 87
        12 65
Output - 12 25 30 37 50 60 62
*/
