/* N-ary Tree Inorder Traversal
 * In N-ary Tree Or Generic Tree a Node can have N no. of children
 * Traversal means visiting every node of a tree single time
 * In Inorder Traversal all the children data of root Node are printed from LEFT to RIGHT Except Last child then root data is printed and then the last child  */

import java.util.*;

	// Definition for a TreeNode.
	class TreeNode<T> 
	{
		public T data;
		public ArrayList<TreeNode<T>> children;

		public TreeNode(T data) 
		{
			this.data = data;
			children = new ArrayList<>();
		}

	}

	public class n-ary_tree_inorder_traversal 
	{
		//For taking the input of N-ary Tree
		public static TreeNode<Integer> take_input(Scanner s) 
		{
			int n;
			System.out.println("Enter next node data");
			n = s.nextInt();
			TreeNode<Integer> root = new TreeNode<Integer>(n);
			System.out.println("Enter number of children for " + n);
			int childCount = s.nextInt();
			for (int i = 0; i < childCount; i++) 
			{
				TreeNode<Integer> child = take_input(s);
				root.children.add(child);
			}
			return root;
		}
		
		//For printing the N-ary Tree 
		public static void print(TreeNode<Integer> root) 	
		{
			String s = root.data + ":";
			for (int i = 0; i < root.children.size(); i++) 
			{
				s = s + root.children.get(i).data + ",";
			}
			System.out.println(s);
			for (int i = 0; i < root.children.size(); i++) 
			{
				print(root.children.get(i));
			}
		}
			
		//For Printing the N-ary in Inorder Traversal			
		public static void inorder(TreeNode node)
		{
			if (node == null)
			return;
			 
			 // Total children count
			 int total = node.children.size();

			 // All the children except the last
			 for (int i = 0; i < total - 1; i++)
			 inorder((TreeNode) node.children.get(i));
			 
			  // Print the current node's data
			  System.out.print("" + node.data + " ");
			 
			  // Last child
			  if(total>0)
			  inorder((TreeNode) node.children.get(total - 1));
		}
		
			
		public static void main(String[] args) 
	        {
			Scanner s = new Scanner(System.in);

			TreeNode<Integer> root = take_input(s);
			print(root);
			System.out.println();
			System.out.println("Inorder of N-ary Tree:");
			inorder(root);
				
		}
			  /*Sample Input1 [1 3 3 1 5 0 2 1 6 0 4 0]
				 *        This will Print Tree as : 1:3,2,4,
				 				    3:5,
								    5:
								    2:6,
								    6:
								    4:

				 *   Explaination => Root Node 1 => 3 children [3,2,4]
				 *                   Root Node 3 => 1 child [5]
				 *                   Root Node 5 => 0 child (NULL)
				 *                   Root Node 2 => 1 child [6]
				 *                   Root Node 6 => 0 child (NULL)
				 *                   Root Node 4 => 0 child (NULL)
				 *   
				 *   OUTPUT: 3 5 2 6 1 4  */
				
				/* Sample Input2 [1 4 2 0 3 2 6 0 7 1 11 1 14 0 4 1 8 1 12 0 5 2 9 1 13 0 10 0]
				 *          This will Print Tree as : 1: 2,3,4,5,
		                                                      2:
		                                                      3: 6,7,
		                                                      6:
								      7: 11,
								     11: 14,
								     14:
								      4: 8,
								      8: 12,
		                                                     12:
		                                                      5: 9,10,
		                                                      9: 13,
		                                                     13:
		                                                     10:
		                                             
		         *    Explaination => Root Node 1  => 4 children [2,3,4,5]
				 *                    Root Node 2  => 0 child (NULL)
				 *                    Root Node 3  => 2 children [6,7]
				 *                    Root Node 6  => 0 child (NULL)
				 *                    Root Node 7  => 1 child [11]
				 *                    Root Node 11 => 1 child [14]
				 *                    Root Node 14 => 0 child (NULL)
				 *                    Root Node 4  => 1 child [8]
				 *                    Root Node 8  => 1 child [12]
				 *                    Root Node 12 => 0 child (NULL)
				 *                    Root Node 5  => 2 children [9,10]
				 *                    Root Node 9  => 1 child [13]
				 *                    Root Node 13 => 0 child (NULL)
				 *                    Root Node 10 => 0 child (NULL)
				 *  
				 *   OUTPUT: 2 6 3 7 11 14 4 8 12 1 9 13 5 10   */
				
				/* Time Complexity => O(n) 
				 * Space Complexity => O(depth of recursion tree)
				 *                     Best-case:- N(logN)
				 *                     Worst-case:- O(N) */
	}
