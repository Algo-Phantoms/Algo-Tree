/*
    Top K Frequent Elements
    * The following code has been implemented using unordered map and priority queue 
    * The unordered map is used for storing the frequency of each element
    * The priority queue is used to store the element along with their frequencies in pairs
    * The priority queue is implemented as a Min Heap to get the Top K Frequent elements
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) 
{
    vector <int> result;
    unordered_map<int, int> freq_map;

    for(size_t i = 0; i < nums.size(); ++i)
    {
        freq_map[nums[i]]++;    
        //increasing the stored frequency of the element by 1 when found
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_heap;

    for(auto it = freq_map.begin(); it != freq_map.end(); ++it)
    {
        min_heap.push({it->second, it->first});     
        //pushing the frequency and the element in pairs respectively
        if(min_heap.size() > k)
        {
            min_heap.pop();    
            //popping the element if the size of the priority queue exceeds k
        }
    }

    for(size_t i = 0; i < k; i++)
    {
        int x = min_heap.top().second;    
        //getting the element from the top 
        result.push_back(x);    
        //pushing the element into the new vector
        min_heap.pop();
    }
    return result;
}


int main()
{
    int k, n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<int> nums(n);
    cout << "Enter elements in the array: ";
    for(size_t i = 0;i < n; ++i)
    {
        cin>>nums[i];
    }

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top "<< k << " Frequent elements: ";

    for(size_t i = 0;i < k;++i)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
    Test Cases:
    * Case 1:
        Enter size of array: 6
        Enter k: 2
        Enter elements in the array: 1 1 1 3 3 2
        Top 2 Frequent elements: 3 1
    * Case 2:
        Enter size of array: 8
        Enter k: 2
        Enter elements in the array: 2 2 3 3 1 1 1 1
        Top 2 Frequent elements: 3 1


    Time Complexity : O(k log d + d)
    Space Complexity : O(d)
    where d is the number of unique elements in the vector

*/          
