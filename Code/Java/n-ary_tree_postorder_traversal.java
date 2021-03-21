/* N-ary Tree Postorder Traversal
	 * In N-ary Tree Or Generic Tree a Node can have N no. of children
	 * Traversal means visiting every node of a tree single time
	 * In Postorder Traversal children data of root Node are printed from LEFT to RIGHT and then root data is printed first   */

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
	
        public class n-ary_tree_postorder_traversal
	{	        
	                //For taking the input of N-ary Tree
			public static TreeNode<Integer> take_input(Scanner s) 
			{
				int node_data;
				System.out.println("Enter next node data");
				node_data = s.nextInt();
				TreeNode<Integer> root = new TreeNode<Integer>(node_data);
				System.out.println("Enter number of children for " + node_data);
				int child_count = s.nextInt();
				for (int i = 0; i < child_count; i++) 
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
			
			//For printing the tree in postorder-traversal
			public static void postorder(TreeNode<Integer> root) 
			{
				if (root == null) //This is used to handle the edge case: If tree is empty 
				    return;
				
				// All the children of current node
				for(TreeNode child: root.children)
				{
					postorder(child);
				}
				
				// Print the current node's data
				System.out.print(root.data + " ");
			}
		
			public static void main(String[] args) 
			{
				Scanner s= new Scanner(System.in);

				TreeNode<Integer> root = take_input(s);
				print(root);
				System.out.println();
				System.out.println("Postorder of N-ary Tree:");
				postorder(root);
			
			}
			/*Sample Input1 [1 3 3 2 5 0 6 0 2 0 4 0]
			 *        This will Print Tree as : 1:3,2,4,
                                                            3:5,6,
                                                            5:
                                                            6:
                                                            2:
                                                            4:

			 *   Explaination => Root Node 1 => 3 children [3,2,4]
			 *                   Root Node 3 => 2 children [5,6]
			 *                   Root Node 5 => 0 child (NULL)
			 *                   Root Node 6 => 0 child (NULL)
			 *                   Root Node 2 => 0 child (NULL)
			 *                   Root Node 4 => 0 child (NULL)
			 *   OUTPUT: 5 6 3 2 4 1 */
			
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
			 *   OUTPUT: 2 6 14 11 7 3 12 8 4 13 9 10 5 1   */
			
			/* Time Complexity => O(N logN) 
			 * Space Complexity => O(depth of recursion tree)*/
			 
	}
