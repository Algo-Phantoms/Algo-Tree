 # Recursion
 Any function which calls itself is called recursive. A recursive method solves a problem by
calling a copy of itself to work on a smaller problem. This is called the recursion step. The
recursion step can result in many more such recursive calls.
It is important to ensure that the recursion terminates. Each time the function calls itself with a
slightly simpler version of the original problem. The sequence of smaller problems must
eventually converge on the base case.

* Recursive algorithms have two types of cases, **recursive cases** and **base cases**.
* Every recursive function case must terminate at a base case.
* Generally, iterative solutions are more efficient than recursive solutions [due to the overhead of function calls].
* A recursive algorithm can be implemented without recursive function calls using a stack, but it’s usually more trouble than its worth. That means any problem that   can be solved recursively can also be solved iteratively.
* For some problems, there are no obvious iterative algorithms.
* Some problems are best suited for recursive solutions while others are not.

## Questions :

* Factorial ----> [C++](https://github.com/Algo-Phantoms/Algo-Tree/blob/main/Code/C%2B%2B/factorial.cpp) | [Java](/Code/Java/factorial.java)
* Fibonocci ----> [C++](https://github.com/Algo-Phantoms/Algo-Tree/blob/main/Code/C%2B%2B/fibonacci.cpp)
* Kth_Symbol_Grammar ----> [C++](https://github.com/Ayush12062000/Algo-Tree/blob/issue-645/Code/C%2B%2B/Kth_Symbol_Grammar.cpp)
* Phone Keypad ----> [C++](/Code/C++/phone_keypad.cpp)
* Tower of Hanoi ----> [C++](/Code/C++/tower_of_hanoi.cpp) | [Java] (/Code/Java/Tower_of_Hanoi.java)
* Generate all valid parantheses ----> [Java](/Code/Java/valid_parantheses.java)

