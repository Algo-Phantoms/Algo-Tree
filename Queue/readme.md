# Queue

A queue is an ordered list in which insertions are done at one end (rear) and
deletions are done at other end (front). The first element to be inserted is the first one to be
deleted. Hence, it is called **First in First out (FIFO) or Last in Last out (LILO) list**.

Similar to Stacks, special names are given to the two changes that can be made to a queue. When
an element is inserted in a queue, the concept is called **EnQueue**, and when an element is
removed from the queue, the concept is called **DeQueue**.

**DeQueueing** an empty queue is called **underflow** and **EnQueuing** an element in a full queue is
called **overflow**. Generally, we treat them as exceptions. As an example, consider the snapshot ofthe queue.

## Main Queue Operations

* **EnQueue(int data):** Inserts an element at the end of the queue.
* **DeQueue():** Removes and returns the element at the front of the queue.

## Auxiliary Queue Operations
* **Front():** Returns the element at the front without removing it.
* **QueueSize():** Returns the number of elements stored in the queue.
* **IsEmptyQueueQ:** Indicates whether no elements are stored in the queue or not.

## Direct Applications

* Operating systems schedule jobs (with equal priority) in the order of arrival (e.g., a print queue).
* Simulation of real-world queues such as lines at a ticket counter or any other first-
* come first-served scenario requires a queue.
* Multiprogramming.
* Asynchronous data transfer (file IO, pipes, sockets).
* Waiting times of customers at call center.
* Determining number of cashiers to have at a supermarket.

## Indirect Applications

* Auxiliary data structure for algorithms
* Component of other data structures

## Questions :

* Circular Queue Implementation ----> [Java](/Code/Java/CircularQueue.java) | [Python](/Code/Python/circular_queue.py)
* Implementation of Queue ----> [Python](/Code/Python/queue.py)
* Queue using Circular Linked List ----> [C++](/Code/C++/queue_using_circular_list.cpp)
* Queue using Stacks ----> [C++](/Code/C++/queue_using_stacks.cpp)
* Queue using Linkedlist ----> [C++](/Code/c++/Queue_all_operations_using_linkedlist.cpp)
* Circular Queue Implementation ----> [Java](/Code/Java/CircularQueue.java) | [Python](/Code/Python/circular_queue.py)