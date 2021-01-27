/*
    Heap sort purely make use of Heap Data Structures. Make sure you know that well enough before coming to Heap Sort.
    We know that Heap is a tree Data Structure maintaining some rules. We will use the fact that the root element of a maxHeap is always the largest element. So we will:
    1) Simply add all the element into the maxHeap
    2) Swap the largest element (i.e. root) with the last element of the array
    3) Remove that largest element from the array, because it is in its correct position now.
    2) Repeat the same procedure till one less size of the array, i.e. n-1.
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void buildHeap(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int idx = i; //current
        int parent = i / 2;
        while (idx > 1 and v[idx] > v[parent]) // building maxheap
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

bool minHeap = false;      //build max heap
bool compare(int a, int b) // a-current element, b-parent
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

void heapify(vector<int> &v, int ind, int size)
{
    int left = 2 * ind;
    int right = 2 * ind + 1;

    int min_idx = ind; //for pointing the idx
    int last = size - 1;

    //find the correct place for min_idx
    if (left <= last && compare(v[left], v[ind])) //compare with left if it is  smaller then min_idx will be left
    {
        min_idx = left;
    }
    if (right <= last && compare(v[right], v[min_idx])) // compare new min_idx with right
    {
        min_idx = right;
    }

    if (min_idx != ind)
    {
        swap(v[ind], v[min_idx]);
        heapify(v, min_idx, size);
    }
}

void heapsort(vector<int> &arr)
{

    buildHeap(arr);
    int n = arr.size(); // size of heap

    // remove n-1 elements from the heap
    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);
        //remove that element from the heap
        n--;                //shrinking heap size
        heapify(arr, 1, n); //O(log n)
    }
}

int main()
{

    vector<int> v;
    v.push_back(-1);
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    heapsort(v);
    print(v);
    return 0;
}

/* 
 Test Case : 

 Input :	7
			7 6 5 4 3 2 1 
 
 Output : 	1 2 3 4 5 6 7


 Input :    10
            39 43 6 -1 0 43 65 78 3 200

 Output :   -1 0 3 6 39 43 43 65 78 200

 Time Complexity: O(n.Logn)

 Space Complexity: O(1)
*/