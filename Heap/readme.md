# Heap

A heap is a tree with some special properties. The basic requirement of a heap is that the value of
a node must be ≥ (or ≤) than the values of its children. This is called **heap property**. A heap also
has the additional property that all leaves should be at h or h – 1 levels (where h is the height of
the tree) for some h > 0 (complete binary trees). That means heap should form a **complete binary tree**.

## Types of Heaps?

Based on the property of a heap we can classify heaps into two types:

* **Min heap:** The value of a node must be less than or equal to the values of its children
* **Max heap:** The value of a node must be greater than or equal to the values of its children

## Heapifying an Element

After inserting an element into heap, it may not satisfy the heap property. In that case we need to
adjust the locations of the heap to make it heap again. This process is called **heapifying**. In max-
heap, to heapify an element, we have to find the maximum of its children and swap it with the
current element and continue this process until the heap property is satisfied at every node.

## Questions :

* Heap Class ----> [C++](/Code/C++/heap_class.cpp) | [Java]() | [Python]()
* Heap Sort ----> [C++](/Code/C++/heap_sort.cpp)
* Merge K Sorted Arrays ----> [C++](/Code/C++/Merge_k_sorted_arrays.cpp)
* Sliding Window Problem ----> [C++] (/Code/C++/Sliding_window_Maximum.cpp)
* Top K Frequent Elements ----> [C++](/Code/C++/top_k_frequent_elements.cpp)
* K-ary Heap ----> [C++](/Code/C++/k_ary_heap.cpp)