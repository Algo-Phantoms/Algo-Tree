// Brian kernighan algorithm is the most efficient way to
// count number of set bits in integer.
// it is based on observation that on subtracting one from an integer
// will flip all the bits after the rightmost set bit and including the right-most set bit itself gets flipped.
// example:
// 6 is 0110 in binary representaion
// 5 is 0101 in binary representaion
// 4 is 0100 in binary representaion
// 3 is 0011 in binary representaion
// we observe that we will 5 from 6 if we flip all the bits to right of right-most set bit including itself.
// now  we observe that if we take bitwise and of 6 and 5
// 6 0110
// 5 0101
// ---------
//   0100
// So the idea is what if we repeat this again and again untill all the bits converted to unset bits or number converts to 0.
// In each turn every right-most set bit will get flipped .
// Count of set bits will be equal to number of turns/loops required to make number equal to 0.

#include <iostream>
using namespace std;
int SetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int num;
    cin >> num;
    cout << SetBits(num);
    return 0;
}
/* 
	Test case :

	Input : 6
	Output : 2

	Time complexity: O(log(n))
	Space Complexity: O(1)


 */
