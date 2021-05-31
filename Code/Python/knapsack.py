# For each item you are given its weight and its value. You want to maximize the total value of all the 
# items you are going to put in the knapsack such that the total weight of items is less than knapsack’s capacity. What is this maximum total value?

# To consider all subsets of items, there can be two cases for every item:
# 	(1) the item is included in the optimal subset, 
# 	(2) not included in the optimal set. Therefore, the maximum value that can be obtained from n items is max of following two values.

# Maximum value obtained by n-1 items and W weight (excluding nth item).
# Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).
# If weight of nth item is greater than W, then the nth item cannot be included and case 1 is the only possibility.

# Approach :
# 	 we can see that the dp solution with states (i,j) will depend on state (i-1, j) or (i-1, j-wt[i-1]). 
# 	 In either case the solution for state (i,j) will lie in the i-1th row of the memoization table. 
# 	 So at every iteration of the index, we can copy the values of current row and use only this row for building the 
# 	 solution in next iteration and no other row will be used. Hence, at any iteration we will be using only a single 
# 	 row to build the solution for current row. Hence, we can reduce the space complexity to just O(W).


def top_down(value, weight, capacity):
    """Return the maximum value of items that doesn't exceed capacity.
 
    value[i] is the value of item i and weight[i] is the weight of item i
    for 1 <= i <= n where n is the number of items.
 
    capacity is the maximum weight.
    """
    n = len(value) - 1
 
    # m[i][w] will store the maximum value that can be attained with a maximum
    # capacity of w and using only the first i items
    m = [[-1]*(capacity + 1) for _ in range(n + 1)]
 
    return knapsack_helper(value, weight, m, n, capacity)
 
 
def knapsack_helper(value, weight, m, i, w):
    """Return maximum value of first i items attainable with weight <= w.
 
    m[i][w] will store the maximum value that can be attained with a maximum
    capacity of w and using only the first i items
    This function fills m as smaller subproblems needed to compute m[i][w] are
    solved.
 
    value[i] is the value of item i and weight[i] is the weight of item i
    for 1 <= i <= n where n is the number of items.
    """
    if m[i][w] >= 0:
        return m[i][w]
 
    if i == 0:
        q = 0
    elif weight[i] <= w:
        q = max(knapsack_helper(value, weight,
                                m, i - 1 , w - weight[i])
                + value[i],
                knapsack_helper(value, weight,
                                m, i - 1 , w))
    else:
        q = knapsack_helper(value, weight,
                            m, i - 1 , w)
    m[i][w] = q
    return q

    
def bottom_up(value, weight, capacity):
    """Return the maximum value of items that doesn't exceed capacity.
 
    value[i] is the value of item i and weight[i] is the weight of item i
    for 1 <= i <= n where n is the number of items.
 
    capacity is the maximum weight.
    """
    n = len(value) - 1
 
    # m[i][w] will store the maximum value that can be attained with a maximum
    # capacity of w and using only the first i items
    m = [[-1]*(capacity + 1) for _ in range(n + 1)]
 
    for w in range(capacity + 1):
        m[0][w] = 0
 
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            if weight[i] > w:
                m[i][w] = m[i - 1][w]
            else:
                m[i][w] = max(m[i - 1][w - weight[i]] + value[i], 
                              m[i - 1][w])
 
    return m[n][capacity]
 
 
n = int(input('Enter number of items: '))
value = input('Enter the values of the {} item(s) in order: '
              .format(n)).split()
value = [int(v) for v in value]
value.insert(0, None) # so that the value of the ith item is at value[i]
weight = input('Enter the positive weights of the {} item(s) in order: '
               .format(n)).split()
weight = [int(w) for w in weight]
weight.insert(0, None) # so that the weight of the ith item is at weight[i]
capacity = int(input('Enter maximum weight: '))
ans = top_down(value, weight, capacity)
print('Top Down- ', ans)
ans = bottom_up(value, weight, capacity)
print('Bottom up- ', ans)


# OUTPUT
# Enter number of items: 3
# Enter the values of the 3 item(s) in order: 60 100 120
# Enter the positive weights of the 3 item(s) in order: 10 20 30
# Enter maximum weight: 50
# Top Down- 220
# Bottom Up- 220