/*
Reversing individual words of a given string, using stack data structures
Algorithm / approach:
- We iterate through the string, character-by-character.
- If the current character is an alphabet or number, we push it into the stack.
- If not, if it's a space or newline character, it indicates the completion of a word. 
- Therefore, we pop out the stack unti it becomes empty.
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int size = 200, index = 0;
    char sentence[size], letter;
    stack <char> s;
    // stack to store characters of the string

    cout << "Enter the sentence:" << endl;
    cin.getline(sentence, size);
    
    do {
        letter = sentence[index ++];       
        if (!isspace(letter) && (letter != '\n') && (letter != '\0')) {
            s.push(letter);
            // pushing into the stack if the character is not a space or newline
        }
        else {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            // emptying the stack
            cout << letter;
        }
        
    } while (letter != '\0');
    cout << endl;
    return 0;
}

/* 
Sample Input1: Get me food
Sample Output1: teG em doof

Sample Input2: happy birthday
Sample Output2: yppah yadhtrib
*/

/*
Time complexity = O(n) [since each pop or push takes O(1) times]
Space Complexity = O(n)
*/