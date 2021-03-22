arr = [1, 2, 3, 4, 5, 6, 7]
d = 2
n =7

def array_rotation():
    arr = [1, 2, 3, 4, 5, 6, 7]
    d, n = 2, 7
    temp = []
    rest_arr = []
    for i in arr:
        if i == d or i < d:
            temp.append(i)
        else:
            rest_arr.append(i)

    rest_arr.extend(temp)
    print('rest arry =', rest_arr)

array_rotation()