/*

Staircase Search is used to search for a key in a 2D Array whose row and column elements are sorted.
	* The idea is to remove a row or a column in each comparison until an element is found. 
	* Searching is started from the top-right corner of the matrix and has three possible cases: 
		1. The key is greater than the current element, this means, that all the elements in the current row are smaller than the key. So, the row can be skipped and move to next row.
		2. The key is smaller than the current number, this means, that all the elements in the current column are greater than the key. So, the column can be skipped and move to previous column.
		3. The key is equal to the current number, this means, the key is found.
	* If the bounds of the 2D Array are reached, this means, the key is not found.
	
*/


#include <iostream>
#include <vector>

using namespace std;

void staircase_search(vector<vector<int>> matrix , int key) {

	bool is_found = false;
	int n = matrix.size();

	// To start the traversal of the matrix in top right corner
	int i = 0 , j = n - 1;

	// To search for a key until the indices satisfy the matrix bounds
	while (i <= n - 1 && j >= 0) {

		if (matrix[i][j] == key) {

			// If key is found
			cout << "Key found at : " << i << " " << j << endl;
			is_found = true;
			break;

		} else if (matrix[i][j] > key) {

			// If current element is greater than the key, then the current column can be skipped and move to previous column
			j--;

		} else {

			// If current element is lesser than th key, then the current row can be skipped and move to next row
			i++;

		}

	}

	// If the key is not found
	if (!is_found)
		cout << "Key not found" << endl;

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector <vector<int>> matrix(n , vector <int> (n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}

		int key;
		cin >> key;

		// Function Call to search for a key in the given matrix
		staircase_search(matrix , key);

	}

	return 0;
}

/*

Sample Input - 1:
	Input - 1:
		2
		4
		10 20 30 40
		15 25 35 45
		20 37 42 50
		25 39 47 55
		37
		2
		1 5
		3 10
		20

	Output - 1:
		Key found at : 2 1 
		Key not found

	Input - 2:
		2
		1
		10
		10
		3
		1 10 20
		5 12 30
		9 16 50
		5

	Output - 2:
		Key found at : 0 0
		Key found at : 1 0

Complexity Analysis:
	* Time Complexity - O(n)
	* Auxiliary Space Complexity - O(1)

*/