 # Backtracking
 
Backtracking is an **improvement of the brute force approach**. It systematically searches for a
solution to a problem among all available options. In backtracking, we start with one possible
option out of many available options and try to solve the problem if we are able to solve the
problem with the selected move then we will print the solution else we will backtrack and select
some other option and try to solve it. If none if the options work out we will claim that there is no
solution for the problem.

Backtracking is a form of recursion. The usual scenario is that you are faced with a number of
options, and you must choose one of these. After you make your choice you will get a new set ofoptions; just what set of options you get depends on what choice you made. This procedure is repeated over and over until you reach a final state. If you made a good sequence of choices, your
final state is a goal state; if you didn’t, it isn’t.

Backtracking can be thought of as a **selective tree/graph traversal method.** The tree is a way of
representing some initial starting position (the root node) and a final goal state (one of the
leaves). Backtracking allows us to deal with situations in which a raw brute-force approach
would explode into an impossible number of options to consider. Backtracking is a sort of refined
brute force. At each node, we eliminate choices that are obviously not possible and proceed to
recursively check only those that have potential.

What’s interesting about backtracking is that we back up only as far as needed to reach a previous
decision point with an as-yet-unexplored alternative. In general, that will be at the most recent
decision point. Eventually, more and more of these decision points will have been fully explored,
and we will have to backtrack further and further. If we backtrack all the way to our initial state
and have explored all alternatives from there, we can conclude the particular problem is
unsolvable. 

## Questions :

* Permutation of a string ----> [C++](/Code/C++/permutation_of_a_string.cpp)
* Rat in a Maze ----> [C++](/Code/C++/rat_in_maze.cpp)
* N Queen Problem ----> [C++](/Code/C++/n_queen_problem.cpp)
* Sudoku Solver ----> [C++](/Code/C++/sudoku_solver.cpp) | [Java](/Code/Java/Sudoku_Solver.java)
