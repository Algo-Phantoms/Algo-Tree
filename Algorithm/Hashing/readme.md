# Hashing
Hashing is a technique used for storing and retrieving information as quickly as possible. It is
used to perform optimal searches and is useful in implementing symbol tables.

## Why Hashing?
In the Trees chapter we saw that balanced binary search trees support operations such as insert,
delete and search in O(logn) time. In applications, if we need these operations in O(1), then
hashing provides a way. Remember that worst case complexity of hashing is still O(n), but it
gives O(1) on the average.

## HashTable ADT
The common operations for hash table are:

* **CreatHashTable:** Creates a new hash table.
* **HashSearch:** Searches the key in hash table.
* **Hashlnsert:** Inserts a new key into hash table.
* **HashDelete:** Deletes a key from hash table.
* **DeleteHashTable:** Deletes the hash table.

## Components of Hashing
Hashing has four key components:

* Hash Table
* Hash Functions
* Collisions
* Collision Resolution Techniques

## Hashing Techniques
There are two types of hashing techniques: static hashing and dynamic hashing

### Static Hashing
If the data is fixed then static hashing is useful. In static hashing, the set of keys is kept fixed and
given in advance, and the number of primary pages in the directory are kept fixed.

### Dynamic Hashing
If the data is not fixed, static hashing can give bad performance, in which case dynamic hashing is
the alternative, in which case the set of keys can change dynamically.

## Questions :

* Longest Subarray with sum k ----> [C++](/Code/C++/longest_subarray_with_sum_k.cpp)
* Rabin Karp Algorithm ----> [C++](/Code/C++/rabin_karp.cpp)
