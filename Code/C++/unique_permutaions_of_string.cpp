/*
A string is given we have to generate all its possible permutations.
A permutation of the string is defined as a word that contains all the characters of the original string,
but in any order. The output should contain only unique words in lexicographically sorted order.

*/

#include <iostream>
#include<string>
#include<set>
using namespace std;

//function to generate all premutations
void permute(char *inp, int cur_Index, set<string> &ans) {
	//base case (end of string i.e. all palces filled)
	if (inp[cur_Index] == '\0') {
		ans.insert(string(inp));
		return;
	}

	//recursive case
	for (int j = cur_Index; inp[j] != '\0'; ++j)
	{
		//we will place every available charater at current_Index
		swap(inp[cur_Index], inp[j]);

		//solving sub problem
		permute(inp, cur_Index + 1, ans);

		//undo the changes made
		swap(inp[cur_Index], inp[j]);
	}
}


int main()
{

	//all the words will be stored in set
	//because set keeps only unique elements and stores elements in sorted order
	//hence iterating on set will give all unique words in lexicographically sorted order
	set<string> ans;

	//input the string
	cout << "Enter the String : ";
	char inp[10000];
	cin >> inp;

	//function to generate all premutations
	permute(inp, 0, ans);

	//Iterating over set
	cout << "\nAll Unique permutations of given string are : \n";
	for (auto cur : ans) {
		cout << cur << endl;
	}

	return 0;
}

/*
Test Case :
1.
Input : abc
Output :abc
		acb
		bac
		bca
		cab
		cba

2.
Input : aba
Output :aab
		aba
		baa

Time Complexity: O(n*n!) , where n is length of string
Space Complexity: O(n*n!) , where n is length of string

*/