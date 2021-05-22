# String

A char array is just that - an array of characters:

- If allocated on the stack (like in your example), it will always occupy eg. 256 bytes no matter how long the text it contains is
- If allocated on the heap (using malloc() or new char[]) you're responsible for releasing the memory afterwards and you will always have the overhead of a heap allocation.
- If you copy a text of more than 256 chars into the array, it might crash, produce ugly assertion messages or cause unexplainable (mis-)behavior somewhere else in your program.
- To determine the text's length, the array has to be scanned, character by character, for a \0 character.

A string is a class that contains a char array, but automatically manages it for you. Most string implementations have a built-in array of 16 characters (so short strings don't fragment the heap) and use the heap for longer strings.

<hr>

## Questions :

* Longest Prefix Suffix Problem ---->[C++](/Code/C++/longest_prefix_suffix.cpp)
* Convert string to lowercase and uppercase ---->[C++](/Code/C++/string_to_lowercase_and_uppercase.cpp)
* Manacher's algorithm (finding the longest palindrome in a string) ----> [Java](/Code/Java/longPalindrome.java)
* Maximum occuring character in a string ---->[C++](/Code/C++/max_count.cpp)
* Number of deletions to make a string pallindrome ---->[Python](/string/Number_of_deletions_to_make_pallindrome.py)
* Print the decimal equivalent of a binary string ---->[C++](/Code/C++/binary_string_to_decimal.cpp)
* Reverse a string ---->[C++](/Code/C++/reverse_string.cpp) | [Java](/Code/Java/reverse_string.java)
* Revere a string using Stack ---->[C++](/Code/C++/reverse_a_string_using_stack.cpp)
* Reverse Individual Words in String ----> [Java](/Code/Java/revindivstring.java)
* Maximum occuring character in a string ---->[C++](/Code/C++/max_count.cpp)
* Checking for Anagram of two string ---->[Java](/Code/Java/Anagram.java)
