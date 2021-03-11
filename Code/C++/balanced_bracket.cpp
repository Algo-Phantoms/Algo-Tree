/*

* Balanced Bracket is a good implementation of stack where it is checked whther the bracket is balanced or not
* It is a same way in which a compiler check if a bracket is missing or not while checking the syntax
* A bracket is balanced if it satisfies the two condition that
    1. If the total number of opening bracket is equal to the total number of closing bracket
    2. If the bracket open latest should be closed first
* Approach used : 
  First we iterate through each an every bracket in the string and if we find that the bracket
  is an opening bracket then we push it to a stack and if it is a closing bracket then we check the stack, if 
  the stack is empty we return it as an unbalanced bracket because if ')' is a starting bracket then it is an
  unbalaced one.
  if the stack is not empty then we match the bracket at the top of the stack with the current closing bracket
  which ensure that the bracket open latest is closed first. If it does not match then it is an unbalanced bracket
  and if it matches then the current bracket at the opening has the closing bracket so we pop the opening bracket 
  at the top of the stack as it has a corresponding closing bracket.
  After all the operation if the stack is empty then we can ensure that all the opening bracket has a closing bracket
  and we return it balanced else we return unbalanced because the bracket at the top does not have a corresponding 
  closing bracket

*/

#include <bits/stdc++.h>
using namespace std;

//Function to check whether the opening bracket has a closing bracket
bool isMatching(char x, char y)
{
    return (x == '(' && y == ')' || x == '{' && y == '}' || x == '[' && y == ']');
}

//Function to check whether the brackets are balanced or not
bool isBalanced(string str, int n)
{
    //In C++ stl the stack is an inbuild data structure
    //that has exactly same operations as stack
    stack<int> st;
    //Iterating the character in the string one by one
    for (int i = 0; i < n; i++)
    {
        //if it is an opening bracket then push it in the stack
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else
        {
            //Is nothing is pushed then an invalid bracket balanced is
            //returned for eg. ')(' will push nothing and return as unbalanced bracket
            if (st.empty() == true)
                return false;
            //if the bracket present at the top of the stack is not matching with the
            //current character then the latest opening bracket does not have a closing
            //bracket so it returns an unbalanced bracket
            else if (isMatching(st.top(), str[i]) == false)
                return false;
            //If the bracket at the top of the stack is matching with the current character
            //then the current opening bracket in the stack has a opening bracket so the
            //current opening bracket in the stack is popped out
            else
                st.pop();
        }
    }
    //After all the operation if the stack is empty then we can derive that
    //all the opening bracket has a closing bracket and so we return true
    //else if there is any opening bracket left in the stack we return that
    //the bracket is unbalanced
    return (st.empty() == true);
}

int main()
{
    //Fast input output operation by matching the synchronization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //Taking the number of test cases
    int t;
    cin >> t;
    while (t--)
    {
        //Taking string as an input and assuming that
        //the input as '(', ')', '{', '}', '[', and']'
        //i.e only parenthesis
        string str;
        cin >> str;
        //Calculating the length of the string
        int n = str.length();
        //Checking whether the brakets are balanced or not
        bool balanced = isBalanced(str, n);
        if (balanced)
            cout << "Balanced" << endl;
        else
            cout << "Not Balanced" << endl;
    }
    return 0;
}

/*

* Sample Test Cases :

    Input 1:

    2
    (()))
    ({[]})

    Output 1:

    Not Balanced
    Balanced

    Input 2:

    4
    )(
    ({)}
    {}{}
    {})

    Output 2:

    Not Balanced
    Not Balanced
    Balanced
    Not Balanced

* An example to demostrate the above problem :

Input: [{}]
Output: Balanced

Execution:

'[' is an opening bracket so push it in stack
'{' is an opening bracket so push it in stack
'}' is a closing bracket so
    1. check if stack is empty and we find that the stack is not empty and has a size 2
    2. check if the bracket of the top has a closing bracket and we find that top of the stack has '{'
       and the current character is '}' so it matches and we pop the current character in the stack.
'{' is poped out the stack so the size of the stack is 1
']' is a closing bracket so
    1. check if stack is empty and we find that the stack is not empty and has a size 1
    2. check if the bracket of the top has a closing bracket and we find that top of the stack has '['
       and the current character is ']' so it matches and we pop the current character in the stack.
'[' is poped out the stack so the size of the stack is 0 now
    
    so the iteration ends and the stack is empty so we return it as a balanced bracket

* Time Complexity: O(n)
* Auxilary Space: O(n) for stack

*/