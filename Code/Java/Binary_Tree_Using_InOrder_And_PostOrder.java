// Given a list of unique integers preorder and another list of unique integers inorder,
// representing the pre-order and in-order traversals of a binary tree, 
// reconstruct the tree and return the root.

// Example

// Input

// preorder = [4, 2, 1, 0, 3]
// inorder = [2, 1, 0, 3, 4]

// Output
// 2 1 0 3 4

// Explanation

// The inorder traversal of the above tree is 2 1 0 3 4


import java.util.*;

public class Binary_Tree_Using_InOrder_And_PostOrder{


    // Tree class
    static class Tree{
        int data;
        Tree left;
        Tree right;

        Tree(int data){
            this.data = data;
        }
    }


    // Function to build Tree
    public static Tree buildBinaryTree(int[] preorder, int[] inorder) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int n = inorder.length -1;
        for(int i=0; i<=n; i++){
            map.put(inorder[i], i);
        } 

        return getTree(inorder, preorder, map, 0, n, 0, n);
    }

    // Helper function to build the tree
    public static Tree getTree(int[] inorder, int[] preorder, 
    HashMap<Integer, Integer> map, int inorderStart, 
    int inorderEnd, int preorderStart, int preorderEnd){

        if(inorderStart > inorderEnd || preorderStart > preorderEnd){
            return null;
        }

        int rootData = preorder[preorderStart];
        Tree root = new Tree(rootData);

        int leftInorderStart = inorderStart;
        int leftInorderEnd = map.get(rootData) - 1;
        int rightInorderStart = map.get(rootData) + 1;
        int rightInorderEnd = inorderEnd;

        int leftPreorderStart = preorderStart+1;
        int leftPreorderEnd = leftInorderEnd - leftInorderStart + leftPreorderStart;
        int rightPreorderStart = leftPreorderEnd + 1;
        int rightPreorderEnd = preorderEnd;

        root.left = getTree(inorder, preorder, map, leftInorderStart, leftInorderEnd, leftPreorderStart, leftPreorderEnd);

        root.right = getTree(inorder, preorder, map, rightInorderStart, rightInorderEnd, rightPreorderStart, rightPreorderEnd);

        return root;

    }

    // Function to print the inorder traversal
    public static void print_inorder(Tree root){
        if(root == null){
            return;
        }

        print_inorder(root.left);
        System.out.print(root.data + " ");
        print_inorder(root.right);
    }

    // Main method
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int in_order[] = new int[n];
        int pre_order[] = new int[n];

        for(int i=0; i<n; i++){
            pre_order[i] = input.nextInt();
        }

        for(int i=0; i<n; i++){
            in_order[i] = input.nextInt();
        }

        input.close();

        Tree root = buildBinaryTree(pre_order, in_order);

        print_inorder(root);
    }
}