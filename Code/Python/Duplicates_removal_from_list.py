"""
Removing duplicates from an array-list
Example:
    Input array-list: [1,2,2,3,4,4,4,5,6,6,8,6,7]
    Output: [1,2,3,4,5,6,8,7]

The best approach to solve this challenge is using a second list to check if the data is duplicated.
By taking each element in the old list and check if it is duplicated or not in the new list with appending if not duplicated, We can make sure that the new list is completely unique
"""

#let the list called L
def delete_duplicates(L):
    newlist = []
    for element in L:
        if not element in newlist: #if the element doesn't exist in the newlist
            newlist.append(element)#append the element

    return newlist #return the newlist


#start of code execution
if __name__ == "__main__":
    print("list: 1 2 3 4 5")
    L = list(map(int, input("Enter list > ").split(" ")))

    print("Before duplicate removal: {}".format(L))
    newlist = delete_duplicates(L)
    print("After duplicate removal: {}".format(newlist))

"""
Test cases:

    Input array-list: 1 2 2 3 4 4 4 5 6 6 8 6 7
    Output:
        Before duplicate removal: [1, 2, 2, 3, 4, 4, 4, 5, 6, 6, 8, 6, 7]
        After duplicate removal: [1, 2, 3, 4, 5, 6, 8, 7]

    Input: 1 5 6 4 8 9 1 2 5 2 5 3 4 5 7 8 2 1 6 4 8
    Output:
        Before duplicate removal: [1, 5, 6, 4, 8, 9, 1, 2, 5, 2, 5, 3, 4, 5, 7, 8, 2, 1, 6, 4, 8]
        After duplicate removal: [1, 5, 6, 4, 8, 9, 2, 3, 7]

Time Complexity: O(n log(n))
Explanation: The algorithms only depends on the number of elemnts in the list
"""
