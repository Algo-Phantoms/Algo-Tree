/*Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
 * It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'[1]),
 *  and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.*/

/*For each node, first the node is visited and then it’s child nodes are put in a FIFO queue. 

printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root //start from root
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children 
      (first left then right children) to q
    c) Dequeue a node from q.*/

 
/**
 * @author Pallavi Dhere
 *
 */

package bfs_traversal;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;



public class Bfs_Traversal { 
   public Node root; 
  
    // Tree Node 
    static class Node { 
        public int data; 
        public Node left;
        public Node right; 
        public Node(int data) 
        { 
            this.data = data; 
            this.left = null; 
            this.right = null; 
        } 
    } 
  
    // Function to insert nodes in level order 
    public static Node insertLevelOrder(int[] arr, Node root, 
                                                int i) 
    { 
        // Base case for recursion 
        if (i < arr.length) { 
            Node temp = new Node(arr[i]); 
            root = temp; 
  
            // insert left child 
            root.left = insertLevelOrder(arr, root.left, 
                                             2 * i + 1); 
  
            // insert right child 
            root.right = insertLevelOrder(arr, root.right, 
                                               2 * i + 2); 
        } 
        return root; 
    } 
  
    // Function to print tree nodes in bfs fashion 
    public static void bfs(Node node) 
    { 
        ArrayList <Integer> res = new ArrayList <Integer> (0);
        // Base case
        if(node == null)
            System.out.print(" "); 
       // Create an empty queue for level order tarversal
       Queue<Node> q = new LinkedList<>();
       q.add(node);
       while(q.isEmpty() == false)
       {
           // Print front of queue and remove it from queue
            node = q.peek();
            res.add (node.data);
            q.poll();
            System.out.print(node.data + " ");
            System.out.print(" ");

           
           /*Enqueue left child*/
           if(node.left != null)
             q.add(node.left);
             
           /*Enqueue right child*/
           if(node.right != null)
             q.add(node.right);
       }
    } 
  
    // Driver program to test above function 
    public static void main(String args[])throws IOException 
    {    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Number of notes in a tree");
        int t=Integer.parseInt(br.readLine());
        Bfs_Traversal t2 = new Bfs_Traversal(); 
        
        int[] arr; 
        arr=new int[t];
        for(int i=0;i<t;i++) {
            arr[i]=Integer.parseInt(br.readLine());
          }
        
        t2.root = t2.insertLevelOrder(arr, t2.root, 0); 
        t2.bfs(t2.root); 
    } 
}
/*INPUT AND OUTPUT
 *Enter the Number of notes in a tree
5
1
2
3
4
5
1  2  3  4  5  

* Enter the Number of notes in a tree
5
6
7
8
9
4
6  7  8  9  4  
 * 
 * */
/*
 *TIME COMPLEXITY & SPACE COMPLEXITY 
 *
 * Time Complexity: O(n) where n is number of nodes in the binary tree 
 *
*Space Complexity: O(n) where n is number of nodes in the binary tree 

*/