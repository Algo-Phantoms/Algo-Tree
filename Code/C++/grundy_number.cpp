/* For example a game starts with
 a pile of n stones, and the player to move may take any
 positive number of stones.
 The last player to move wins. To decide which player wins the game,
 Grundy number of the game is calculated

 The Grundy Number/ nimbers is equal to 0 for a game that is lost immediately by the first player
 and is equal to Mex of the nimbers of all possible next positions for any other game.
*/


#include<bits/stdc++.h>
using namespace std;

//‘Mex’ of a set of numbers is the smallest non-negative number not present in the set.
// Defining Function to calculate Mex of all the values in that set
int cal_Mex(unordered_set<int> Set);


// A function to Compute Grundy Number of 'n'
// This function may change depending on the game's condition
int Grundy_number(int n, int dp[])
{
	if (n == 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	unordered_set<int> Set;
	 // A Hash Table

	for (int i=0; i<n; i++)
			Set.insert(Grundy_number(i,dp));

	// Store the result
	dp[n] = cal_Mex (Set);
	return dp[n];
}


// A Function to calculate Mex of all the values in that set
int cal_Mex(unordered_set<int> Set)
{
	int Mex = 0;

	while (Set.find (Mex) != Set.end())
		Mex++;

	return (Mex);
}



int main()
{
	int n;
	cin>>n;

	//using Dynamic programming based approach
	int dp[n+1];

	//initially setting all elements of array dp to -1;
	memset (dp, -1, sizeof(dp));

	cout<<Grundy_number(n, dp);
}



/*
    Test Case 1:
        Input: 4
        Output: 4

    Test Case 2:
        Input: 8
        Output: 8


    Time complexity: O(n)

    Space complexity: O(n)

*/



