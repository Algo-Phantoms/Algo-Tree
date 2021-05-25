#include <bits/stdc++.h>
using namespace std;


void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        // If we reached the end of the string, just check if the resulting expression is
       // valid or not and also if we have removed the total number of left and right
       // parentheses that we should have removed.
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        // Simply recurse one step further if the current character is not a parenthesis.
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }

        else {
        	 // Consider an opening bracket.
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }

            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }

        }

}

vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        // First, we find out the number of misplaced left and right parentheses.
        for(auto c : s) {
        	// Simply record the left one.
            if(c == '(') {
                ++left_removed;
            }
             // If we don't have a matching left, then this is a misplaced right, record it.
             // Decrement count of left parentheses because we have found a right
             // which CAN be a matching one for a left.
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
}

int main(){

	// Example 1 :
	string input1 = "()())()";
	vector<string> output1 = removeInvalidParentheses(input1);

	for(string str : output1){
		cout << str << " ";
	}
	cout << endl;

	// Example 2 :

	string input2 = "(a)())()";
	vector<string> output2 = removeInvalidParentheses(input2);

	for(string str : output2){
		cout << str << " ";
	}
	cout << endl;

	return 0;
}



// Test Cases : 

// Example 1:

// Input: s = "()())()"
// Output: ["(())()","()()()"]

// Example 2:

// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]

// Example 3:

// Input: s = ")("
// Output: [""]


// Time Comlexity : O(2 ^ N)
// Space Complexity : O(N)
// where N is the length of string
