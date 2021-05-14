def prefixToPostfixIterative(expression):
    myStack = []

    operators = set(['+','-','*','/'])

    # Scan each letter from last
    for ind, letter in reversed(list(enumerate(expression))):
        # If expression is operand, push it to stack
        if letter not in operators:
            myStack.append(letter)
        else:
            firstExp = myStack.pop()
            secondExp = myStack.pop()
            result = firstExp + secondExp + letter
            # Append it as operand + operand + operator
            myStack.append(result)
    return myStack.pop()

def prefixToPostfixRecursive(expression):
    operators = set(['+', '-', '*', '/'])
    # Pass index by reference by using a list
    # This is the python workaround of passing int by reference
    def helper(expr, index):
        if index[0] == len(expr):
            return

        curr_char = expr[index[0]]
        # If expression is operand, return it
        if curr_char not in operators:
            return curr_char
        else:
            index[0] += 1
            left = helper(expr, index)
            index[0] += 1
            right = helper(expr, index)
            # Append it as operand + operand + operator
            return left + right + curr_char

    cur_index = [0]
    return helper(expression, cur_index)

prefixStringTestCases = ['+*AB/CD', '++A*BCD', '+-435', '+++ABCD']
for test_case in prefixStringTestCases:
    print('-' * 50)
    print('Prefix to Postfix final expr(Iterative): %s -> %s' % (test_case, prefixToPostfixIterative(test_case)))
    print('Prefix to Postfix final expr(Recursive): %s -> %s' % (test_case, prefixToPostfixRecursive(test_case)))
