/*
The Tower of Hanoi is a very famous mathematical problem. You have three rods and n disks. Initially all the n disks are stacked on one rod. The task is to take all those disks from one rod to some other rod following these rules:
1) Only one disk can be moved at a time.
2) There can be no disk mounted on top of a smaller disk.
3) A disk can be moved only if it is the stack's uppermost disk.

        |           |           |                   |           |           |       
       -|-          |           |                   |           |          -|-      
      --|--         |           |       ---->       |           |         --|--     
     ---|---        |           |                   |           |        ---|---    
    =========   =========   =========           =========   =========   =========   
		A			B			C					A			B			C

Program will print the source and destination to transfer each disks for all the steps in chronological order.
*/

#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char from_rod, char aux_rod, char to_rod)
{
	/*
		This function takes the number of disks and the names of the rods.
		The Idea is to shift one disk from the source to the destination.
		BUT,
		if there is already mutiple disk on the source	    then call the same function to put the extra disk on an auxiliary rod.
		AND,
		if there is already mutiple disk on the destination then call the same function to put the extra disk on an auxiliary rod.
	*/

	if (n == 1)
		cout << "Move a rod from the top of " << from_rod << " to the top of " << to_rod << '\n';
	else
	{
		tower_of_hanoi(n - 1, from_rod, to_rod, aux_rod);
		tower_of_hanoi(1, from_rod, aux_rod, to_rod);
		tower_of_hanoi(n - 1, aux_rod, from_rod, to_rod);
	}
}

int main()
{

	int n;
	// getting the number of disks initially
	cin >> n;				
	tower_of_hanoi(n, 'A', 'B', 'C');

	return 0;
}

/* 
 Test Case : 

 Input : 3
 
 Output : 
	Move a rod from the top of A to the top of C
	Move a rod from the top of A to the top of B
	Move a rod from the top of C to the top of B
	Move a rod from the top of A to the top of C
	Move a rod from the top of B to the top of A
	Move a rod from the top of B to the top of C
	Move a rod from the top of A to the top of C

 Time Complexity: O(2^n)
 Space Complexity: O(n)
*/