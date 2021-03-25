/*
Bucket Sort is a sorting technique that sorts the elements by first dividing the elements into several groups called buckets. The elements inside each bucket are sorted using any of the suitable sorting algorithms or recursively calling the same algorithm.

* Algorithm
     In the Bucket Sorting technique, the data items are distributed in a set of buckets. Each bucket can hold a similar type of data. After distributing, each bucket is sorted using another sorting algorithm. After that, all elements are gathered on the main list to get the sorted form.

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(float *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void bucketSort(float *array, int size) {
   vector<float> bucket[size];
   for(int i = 0; i<size; i++)  {
      bucket[int(size*array[i])].push_back(array[i]);
   }
   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end());
   }
   int index = 0;
   for(int i = 0; i<size; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n];
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Bucket Sorting: ";
   display(arr, n);
   bucketSort(arr, n);
   cout << "Array after Bucket Sorting: ";
   display(arr, n);
}


/* 
Test case : 
   INPUT:
            Enter the number of elements: 5
            Enter elements:
            0.22 0.45 0.79 0.01 0.69

   OUTPUT : 
            Array before Bucket Sorting:
            0.22 0.45 0.79 0.01 0.69
            Array after Bucket Sorting:
            0.01 0.22 0.45 0.69 0.79


  Worst complexity: O(n^2)
  Average complexity: O(n + k)
  Best complexity: O(n + k)
  Space complexity: O(nk)

*/