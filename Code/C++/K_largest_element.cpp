//CPP Code For Finding K Largest Element In An Array In Ascending Order.
/*
             Approach
             ========
           
            We can efficiently implement this using a Min-Heap.
            
            1. We will create a min heap.
            2. We will traverse through all the elements of the array 
               and insert them into the min heap
            3. We are using a min heap and inverting the numbers, i.e. inserting -1*number.
            3. We are maintaining the heap at the size of k always.
            4. Pop extra elements if the size becomes greater than k.
            5. When we reach the end of the array then we will 
               print the value and pop the heap top till it becomes empty.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, k;
    vector<int> V;
    cout << "Enter the size of the array :";
    cin >> n;
    cout << "\nEnter the elements of the array :";
    for (i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        V.push_back(num);
    }
    cout << "\nEnter the value of K :";
    cin >> k;
    priority_queue<int> minHeap;
    for (auto v : V)
    {
        minHeap.push(-v);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    cout << "\nK largest array element in ascending order are : ";
    while (!minHeap.empty())
    {
        cout << -minHeap.top() << ", ";
        minHeap.pop();
    }
    return 0;
}

/*
           Time-Complexity: O(nlog(k))
           where n => size of the array , k => the number of largest elements to find
           
           Sample Input/Output
           =====================
           
           Sample Input 1 :
           
           5
           9 8 7 6 5
           3
           
           Sample Output 1 :
           
           Enter the size of the array :
           Enter the elements of the array :
           Enter the value of K :
           K largest array element in ascending order are : 7, 8, 9,
           
           Sample Input 2 :
           
           7
           19 8 17 6 15 0 3
           4
           
           Sample Output 2 :
           
           Enter the size of the array :
           Enter the elements of the array :
           Enter the value of K :
           K largest array element in ascending order are : 8, 15, 17, 18,
           
           Sample Input 3 :
           
           6
           7 10 4 3 20 15
           3
           
           Sample Output 3 :
           
           Enter the size of the array :
           Enter the elements of the array :
           Enter the value of K :
           K largest array element in ascending order are : 10, 15, 20,
*/
