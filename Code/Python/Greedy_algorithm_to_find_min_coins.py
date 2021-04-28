#  Find Minimum number of Coins in C++



def findMin(V):

    deno = [1, 2, 5, 10, 20, 50,
            100, 500, 1000]
    n = len(deno)


    ans = []


    i = n - 1
    while (i >= 0):


        while (V >= deno[i]):
            V -= deno[i]
            ans.append(deno[i])

        i -= 1


    for i in range(len(ans)):
        print(ans[i], end=" ")



if __name__ == '__main__':
    n = 153
    print("Min_numbers of coins for", n, ": ", end="")
    findMin(n)

# n = 153
# 4 (100,50,2,1)


# n = 3
# 2 {2,1}
#Time Complexity: O(n) 
 #Space Complexity: O(1)
