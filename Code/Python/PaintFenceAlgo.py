'''
DESCRIPTION:
Given a fence with n posts and k colors , find out the number of ways of painting the fence 
such that atmost 2 adjacent posts have the same color. Suppose we have a single post, The 
number of ways of painting the fence with k colors is k Now we consider 2 posts, Then the number
of ways of painting the second fence with the same color as the first post is k, and the number
of ways of painting the second post with a different color is k*(k-1) as we have k-1 colors that
are different from the first post's color. So the total number of ways of painting 2 fences is
k*(k-1) + k. Now we consider 3 posts, Then the number of ways of painting the third fence same 
as the second fence is the number of ways of painting the second fence with a different color 
that is k*(k-1). The number of ways of painting the third fence using a different color is equal
to the total number of ways of painting the second fence * (k-1). Hence the total number of ways 
of painting 3 fences is k*(k-1) + (k+k*(k-1))*(k-1).This way we can find the total number of ways 
of painting n fences
'''
# PYTHON CODE

# Paint Fence Algorithm returns count of ways to color n posts using k colors 
# Total posts
n = int(input("Enter No. of posts"))   
# Total colours
k = int(input("Enter No. of colors"))


M=10**9+7
SUM = k     # k-ways to colour first post

com= 0
uni = k

# Color filling from second post
for i in range (2, n+1): 
    com= uni

    # (k-1) methods for next post
    uni= SUM*(k-1)
    uni= uni% M
    
    SUM= (com+uni)%M  # total choices
    
    
print (SUM) # result of possibilities

'''
Time Complexity : O(n)
Space Complexity: O(n)

Test Case 1:
Enter No. of posts 2
Enter No. of colors 4

OUTPUT - 16

Test Case 2:
Enter No. of posts 3
Enter No. of colors 5

OUTPUT - 120

Test Case 3:
Enter No. of posts 3
Enter No. of colors 2

OUTPUT - 6
'''