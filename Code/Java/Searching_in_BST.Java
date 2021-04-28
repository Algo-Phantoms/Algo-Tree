/*
Searching in BST:
Function returns true if there is node in the tree equal to "data".
The solution will be done using recursion. If element is less than the present node data then search in left, else search in right. There will be two base cases
i) if node data is equal to desired data return true
ii)If node reached to null return false.
*/


import java.io.*;
import java.util.*;
public class Main {
  public static class Node {                   // Node class
    int data;
    Node left;
    Node right;

    Node(int data, Node left, Node right) {      
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }
   public static class Pair {                    // used in construction of BST
    Node node;
    int state;

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[] arr) {    // construction of BST
    Node root = new Node(arr[0], null, null);
    Pair rtp = new Pair(root, 1);

    Stack<Pair> st = new Stack<>();
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0) {
      Pair top = st.peek();
      if (top.state == 1) {
        idx++;
        if (arr[idx] != null) {
          top.node.left = new Node(arr[idx], null, null);
          Pair lp = new Pair(top.node.left, 1);
          st.push(lp);
        } else {
          top.node.left = null;
        }

        top.state++;
      } else if (top.state == 2) {
        idx++;
        if (arr[idx] != null) {
          top.node.right = new Node(arr[idx], null, null);
          Pair rp = new Pair(top.node.right, 1);
          st.push(rp);
        } else {
          top.node.right = null;
        }

        top.state++;
      } else {
        st.pop();
      }
    }

    return root;
  }




  public static boolean find(Node node, int data){ // function for searching in BST

      if(node==null)                        //  if we reached null this means no such data is present in the tree

      {
          return false;                     // return false
      }

     if(data==node.data)                    // if node.data is equal to desired data this means data is present in the tree  
     {
         return true;                       // return true
     }

     else if(data<node.data)
    {
        return find(node.left,data);        // if data is less then node.data this means it can only be present in the left part according to BST properties.
    }

    else
    {
        return find(node.right,data);     // if data is greater it will be present in right part 
    }


  }  

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    Integer[] arr = new Integer[n];
    String[] values = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      if (values[i].equals("n") == false) {
        arr[i] = Integer.parseInt(values[i]);
      } else {
        arr[i] = null;
      }
    }

    int data = Integer.parseInt(br.readLine());

    Node root = construct(arr);

    boolean found = find(root, data);    // calling function

    System.out.println(found);         // printing result
  }

}



/*
Test case 1 : 
input : 19
        50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
        70
output : true
Time Complexity : O(height)
Space Complexity : O(n)
*/

/*
Test case 2 : 
input : 23
        50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
        61
output : false
Time Complexity : O(height)
Space Complexity : O(n)
*/
