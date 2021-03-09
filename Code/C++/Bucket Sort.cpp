#include <iostream>
#include <algorithm>	//For using sort function
#include <vector> 		//For using vector
using namespace std;
 
 
void bucketSort(float arr[], int n)
{
    vector<float> b[n];				//Creating bucket of dynamic size
    
    for (int i=0; i<n; i++)
    {
       int x = n*arr[i];
       b[x].push_back(arr[i]);
    }
 
    for (int i=0; i<n; i++)				//Sorting each bucket using sort()
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)			//Putting all the buckets together
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
int main()
{
    float arr[] = {0.1235, 0.2101, 0.4142, 0.0476, 0.2045, 0.315};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sorting\n";
    for (int i=0; i<n; i++)
    cout << arr[i] << " ";
    
    bucketSort(arr, n);				//Function calling
    
    cout << "\n\nAfter Sorting \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}


/*OUTPUT
Before Sorting
0.1235 0.2101 0.4142 0.0476 0.2045 0.315

After Sorting
0.0476 0.1235 0.2045 0.2101 0.315 0.4142
*/
