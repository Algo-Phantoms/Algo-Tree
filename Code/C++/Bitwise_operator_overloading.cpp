//C++ Code for Bitwise Operator Overloading

/*
      Approach
      =========
     1. We can used User-defined classes and enumerations that implement the requirements
        of BitmaskType are required to overload the bitwise arithmetic operators.
      
     2. operator&, operator|, operator^,and may optionally overload the shift operators operator<< operator>>.. 
        Overloaded bitwise operators should be non-members to allow for operands of different types
        , e.g. a fundamental type and a class type, or two unrelated class types.
      
     3. A non-const overload of the subscript operator should allow an object to be modified,
        i.e. should return a reference to member data.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class bitwise
{
    int a;

public:
    bitwise()
    {
    }
    bitwise(int a)
    {
        this->a = a;
    }
    void show()
    {
        cout << " = " << a << "\n";
    }
    bitwise operator&(bitwise b2)
    {
        bitwise temp;
        temp.a = a & b2.a;
        return temp;
    }
    bitwise operator|(bitwise b2)
    {
        bitwise temp;
        temp.a = a | b2.a;
        return temp;
    }
    bitwise operator^(bitwise b2)
    {
        bitwise temp;
        temp.a = a ^ b2.a;
        return temp;
    }
    bitwise operator>>(bitwise b2)
    {
        bitwise temp;
        temp.a = a >> b2.a;
        return temp;
    }
};
int main()
{
    int a, b;
    cout << "Enter 2 numbers:";
    cin >> a >> b;
    bitwise b1(a);
    bitwise b2(b);
    bitwise b3 = b1 & b2;
    bitwise b4 = b1 | b2;
    bitwise b5 = b1 ^ b2;
    bitwise b6 = (b1 >> b2);
    cout << "\nNUMBER 1 ";
    b1.show();
    cout << "NUMBER 2 ";
    b2.show();
    cout << "NUMBER1 & NUMBER2 ";
    b3.show();
    cout << "NUMBER1 | NUMBER2 ";
    b4.show();
    cout << "NUMBER1 ^ NUMBER2 ";
    b5.show();
    cout << "NUMBER1 >> NUMBER2 ";
    b6.show();
    return 0;
}

/*
      Time Complexity: O(1) 
      Space Complexity: O(1)
      
      Sample Input/Output
      =======================
      
      Sample Input : 1 
      10 20
      
      sample Output : 1
      
      Enter 2 numbers:
      NUMBER 1  = 10
      NUMBER 2  = 20
      NUMBER1 & NUMBER2  = 0
      NUMBER1 | NUMBER2  = 30
      NUMBER1 ^ NUMBER2  = 30
      NUMBER1 >> NUMBER2  = 0
      
      Sample Input : 2
      10 2
      
      sample Output : 2
      
      Enter 2 numbers:
      NUMBER 1  = 10
      NUMBER 2  = 2
      NUMBER1 & NUMBER2  = 2
      NUMBER1 | NUMBER2  = 10
      NUMBER1 ^ NUMBER2  = 8
      NUMBER1 >> NUMBER2  = 2
      
      Sample Input : 3
      5 7
      
      sample Output : 2
      
      Enter 2 numbers:
      NUMBER 1  = 5
      NUMBER 2  = 7
      NUMBER1 & NUMBER2  = 5
      NUMBER1 | NUMBER2  = 7
      NUMBER1 ^ NUMBER2  = 2
      NUMBER1 >> NUMBER2  = 0
      
      
      
*/
