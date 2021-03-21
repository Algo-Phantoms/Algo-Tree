
def find_sub(a,b,n,m):
    if n==0:
        return True
    if m==0:
        return False
    if a[n-1]==b[m-1]:
        return find_sub(a,b,n-1,m-1)

    return find_sub(a,b,n,m-1)


if __name__=="__main__":
    a=input('Enter first string in which you want to check presence of another string as subsequence:')
    b=input('Second string which is to be checked: ')
    if find_sub(a,b,0,0):
        print("Yes! it is true that b is subsequence of a.")
    else:
        print("Nope!")