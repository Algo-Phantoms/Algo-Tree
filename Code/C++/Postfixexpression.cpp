//Evaluation of Postfix expression
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
Enter Postfix Expression with out any blank spaces:abc*+                                                              
Enter values ofa:1                                                                                                    
Enter values ofb:2                                                                                                    
Enter values ofc:3                                                                                                    
The given postfix expression is:1 2 3 * +                                                                             
The result of evaluated postfix expression is:7 
2.
Enter Postfix Expression with out any blank spaces:abcd*-+                                                            
Enter values ofa:4                                                                                                    
Enter values ofb:3                                                                                                    
Enter values ofc:2                                                                                                    
Enter values ofd:1                                                                                                    
The given postfix expression is:4 3 2 1 * - +  
The result of evaluated postfix expression is:5 
*/
