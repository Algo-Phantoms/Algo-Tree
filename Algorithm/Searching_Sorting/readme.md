# Sorting
	Sorting is an algorithm that arranges the elements of a list in a certain order [either ascending or
	descending]. The output is a permutation or reordering of the input.

## Why is Sorting Necessary?
	Sorting is one of the important categories of algorithms in computer science and a lot of research
	has gone into this category. Sorting can significantly reduce the complexity of a problem, and is
	often used for database algorithms and searches.

# Classification of Sorting Algorithms
Sorting algorithms are generally categorized based on the following parameters.

* **By Number of Comparisons :**
	In this method, sorting algorithms are classified based on the number of comparisons. For
	comparison based sorting algorithms, best case behavior is O(nlogn) and worst case behavior is
	O(n 2 ). Comparison-based sorting algorithms evaluate the elements of the list by key comparison
	operation and need at least O(nlogn) comparisons for most inputs.

* **By Number of Swaps :**
	In this method, sorting algorithms are categorized by the number of swaps (also called
	inversions).

* **By Memory Usage :**
	Some sorting algorithms are **in place** and they need O(1) or O(logn) memory to create
	auxiliary locations for sorting the data temporarily.

* **By Recursion :**
	Sorting algorithms are either recursive **quick sort** or non-recursive **selection sort, and insertion
	sort**, and there are some algorithms which use both **(merge sort)**.

* **By Stability :**
	Sorting algorithm is stable if for all indices i and j such that the key A[i] equals key A[j], if record
	R[i] precedes record R[j] in the original file, record R[i] precedes record R[j] in the sorted list.
	Few sorting algorithms maintain the relative order of elements with equal keys (equivalent
	elements retain their relative positions even after sorting).

* **By Adaptability :**
	With a few sorting algorithms, the complexity changes based on pre-sortedness [quick sort]: pre-
	sortedness of the input affects the running time. Algorithms that take this into account are known to
	be adaptive.
	
# Searching
Searching is one of the core computer science algorithms. We know that today’s computers store
a lot of information. To retrieve this information proficiently we need very efficient searching
algorithms. There are certain ways of organizing the data that improves the searching process.
That means, if we keep the data in proper order, it is easy to search the required element. Sorting
is one of the techniques for making the elements ordered.

## Types of Searching

Following are the types of searches which we will be discussing in this book.

* Unordered Linear Search ----> [C++](/Code/C++/Linear_search.cpp) 
* Sorted/Ordered Linear Search
* Binary Search
* Interpolation search
* Binary Search Trees 
* Symbol Tables and Hashing
* String Searching Algorithms: Tries, Ternary Search and Suffix Trees

## Questions :

* Binary Search ----> [Python](/Code/Python/Binary_Search.py)
* Book Allocation ----> [Java](/Code/Java/Book_Allocation.java)
* Bucket Sort ----> [Java](/Code/Java/Bucket_Sort.java)
* Counting Sort ----> [C++](/Code/C++/couting_sort.cpp)
* Cycle Sort ----> [C++](/Code/C++/cycle_sort.cpp)
* DNF SORT ----> [C++](Algorithm/Searching_Sorting/dnf_sort.cpp)
* Fibonacci Search ----> [C++](Algorithm/Searching_Sorting/fibonacci_search.cpp)
* Find peak element using binary search ----> [Python](/Code/Python/peak_element.py)
* Heap Sort ----> [C++](/Code/C++/heap_sort.cpp)
* Insertion Sort ----> [C++](/Code/C++/insertion_sort.cpp)
* Linear Search ----> [Python](/Code/Python/linearsearch.py)
* Merge Sort ----> [C++](/Code/C++/merge_sort.cpp)
* Number of times sorted array rotated ---->[C++](/Code/C++/no_of_rotation.cpp)
* Painter's Partition -->[C++](/Code/Python/Painter's_Partition.py)
* Quick Sort ----> [C++](/Code/C++/quick_sort.cpp)
* Rabin Karp Algorithm ----> [C++](/Code/C++/rabin_karp.cpp)
* Searching in sorted rotated array ----> [Java](/Code/Java/searching_in_sorted_rotated_array.java)
* Selection Sort ----> [C++](/Code/C++/selection_sort.cpp)
* Shell Sort ----> [C++](/Code/C++/shell_sort.cpp)
* Staircase Search ----> [C++](/Code/C++/staircase_search.cpp)
* Three Way Merge Sort ----> [C++](/Code/C++/three_way_merge_sort.cpp)
* Tim Sort ----> [C++](/Code/C++/tim_sort.cpp)
