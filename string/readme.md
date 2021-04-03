# String

A char array is just that - an array of characters:

- If allocated on the stack (like in your example), it will always occupy eg. 256 bytes no matter how long the text it contains is
- If allocated on the heap (using malloc() or new char[]) you're responsible for releasing the memory afterwards and you will always have the overhead of a heap allocation.
- If you copy a text of more than 256 chars into the array, it might crash, produce ugly assertion messages or cause unexplainable (mis-)behavior somewhere else in your program.
- To determine the text's length, the array has to be scanned, character by character, for a \0 character.

A string is a class that contains a char array, but automatically manages it for you. Most string implementations have a built-in array of 16 characters (so short strings don't fragment the heap) and use the heap for longer strings.

<hr>

## Questions :

* Convert string to lowercase and uppercase ---->[C++](/Code/C++/string_to_lowercase_and_uppercase.cpp)
* Revere a string using Stack ---->[C++](/Code/C++/reverse_a_string_using_stack.cpp)
