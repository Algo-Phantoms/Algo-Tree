//WAP TO FIND SUM OF ALL ELEMENTS IN BINARY TREE.
//CODE:
import java.io.*;
import java.util.*;
public class SumOfAllDataInBinaryTree {
  public static class Node {
    int data;
    Node left;
    Node right;
    Node(int data, Node left, Node right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }
  }
  public static class Pair {
    Node node;
    int state;
    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }
  public static Node construct(Integer[] arr) {
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
  public static int sum(Node node) {
    if(node == null) return 0;
    int left = sum(node.left);
    int right = sum(node.right);
    return left + right + node.data;
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
    Node root = construct(arr);
    int sum = sum(root);
    System.out.println(sum);
  }
}
/* COMPLEXITY: O(n)
TEST CASES:
INPUT: n: 19
n-elements : 50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
OUTPUT: 448 */
