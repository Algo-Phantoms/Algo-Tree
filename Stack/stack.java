
/*
 *                    Implementation of Stack in Java
 *         
 * Stack is a linear structure which follows a particular order in 
 * which the operations are performed. 
 * The order is Last In First Out (LIFO).
 */
import java.util.*;
class Stack {
    static final int MAX = 1000;
    static int top;
    static int a[] = new int[MAX]; // Maximum size of Stack

    boolean isEmpty()
    {
        return (top < 0);
    }

    Stack()
    {
        top=-1;
    }
    // Pushing element on the top of the Stack 
    boolean push(int x)
    {
        if(top>=(MAX-1)){
            System.out.println("Stack Overflow");
            return false;
        }
        else {
            a[++top]=x;
            System.out.println(x + " pushed into stack");
            return true;
        }
    }
    // Popping element from the top of the Stack
    int pop()
    {
        if(top<0){
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x=a[top--];
            return x;
        }
    }
    // Displaying element on the top of the Stack
    int peek()
    {
        if(top<0){
            System.out.println("Stack Underflow");
            return 0;
        }
        else {
            int x=a[top];
            return x;
        }
    }

    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        Stack s=new Stack();
        System.out.println("No. of elements to be added in Queue :");
        int n=in.nextInt();
        for(int i=0;i<n;i++)
        {
            int input=in.nextInt();
            s.push(input);
        }
        System.out.println("Top Element :"+a[top]);
        System.out.println(s.pop() + " Popped from stack");
        System.out.println("Top Element after Pop operation :"+a[top]);
        in.close();
    }
}

/*
 *   Test Case 1:
 *   No. of elements to be added in Stack :
   4
   4
   4 pushed into stack 
   3
   3 pushed into stack
   2
   2 pushed into stack
   1
   1 pushed into stack
   Top Element :1
   1 Popped from stack
   Top Element after Pop operation :2
 *    
 *   Test Case 2:
*    No. of elements to be added in Stack :
   5
   5 
   5 pushed into stack
   4
   4 pushed into stack 
   3
   3 pushed into stack
   2
   2 pushed into stack
   1
   1 pushed into stack
   Top Element :1
   1 Popped from stack
   Top Element after Pop operation :2
   Top Element :2
   2 Popped from stack
   Top Element after Pop operation :3
   Top Element :3
   3 Popped from stack
   Top Element after Pop operation :4
 * 
 * 
 * Time Complexity is
 * Insertion(Push) O(1) 
 * Deletion(Pop)  O(1) 
 * Space Complexity is O(n) , n is the size of the Stack.

 */

 