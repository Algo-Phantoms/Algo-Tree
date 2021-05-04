//Evaluation of Postfix expression

/*A postfix expression is a combination of operands and operators in which the operators are placed after the operands.
In the Evaluation of the postfix expression, we are given a string which contains postfix expression.We have to evaluate that expression.
The main idea of the evaluation of postfix expression is as follows:
While reading the expression from left to right we should push the element in the stack if it is an operand.
Pop the two operands from the stack, if the element is an operator and then evaluate it.
Push back the result of the evaluation. Repeat it till the end of the expression.
*/

#include <iostream>
#include <math.h>
using namespace std;

class stack {
  int top;
  float stk[50];
  public:
    stack() {
      top = -1;
    }
  void push(float p) {
    stk[++top] = p;
  }
  float pop() {
    return stk[top--];
  }
};

int main()

{
  char p[50];
  float data[50], a, b;
  stack st;
  cout << "Enter Postfix Expression with out any blank spaces:";
  cin >> p;
  int i = 0;
  while (p[i] != '\0') {
    if (isalpha(p[i])) {
      cout << "Enter values of" << p[i] << ":";
      cin >> data[i];
    }
    i++;
  }
  p[i] = ')';
  i = 0;
  while (p[i] != ')') {
    switch (p[i]) {
    case '+':
      a = st.pop();
      b = st.pop();

      st.push(b + a);
      break;
    case '-':
      a = st.pop();
      b = st.pop();
      st.push(b - a);
      break;
    case '*':
      a = st.pop();
      b = st.pop();
      st.push(b * a);
      break;
    case '/':
      a = st.pop();
      b = st.pop();
      st.push(b / a);
      break;
    case '^':
      a = st.pop();
      b = st.pop();
      st.push(pow(b, a));
      break;
    default:
      st.push(data[i]);
    }
    i++;
  }
  p[i] = '\0';
  cout << "The given postfix expression is:";
  for (i = 0; p[i]; i++)

  {
    if (isalpha(p[i]))
      cout << data[i] << " ";
    else
      cout << p[i] << " ";
  }
  cout << "\nThe result of evaluated postfix expression is:" << st.pop();
}

/* Test cases:
1.
Input:

Enter Postfix Expression with out any blank spaces:abc*+                                                              
Enter values ofa:1                                                                                                    
Enter values ofb:2                                                                                                    
Enter values ofc:3

Output:

The given postfix expression is:1 2 3 * +                                                                             
The result of evaluated postfix expression is:7 

2.
Input:

Enter Postfix Expression with out any blank spaces:abcd*-+                                                            
Enter values ofa:4                                                                                                    
Enter values ofb:3                                                                                                    
Enter values ofc:2                                                                                                    
Enter values ofd:1 

Output:

The given postfix expression is:4 3 2 1 * - +  
The result of evaluated postfix expression is:5 

Time Complexity : O(n) where 'n' is the size of the given string.
Space Complexity: O(n) because we used the stack space for 'n' characters.
*/
