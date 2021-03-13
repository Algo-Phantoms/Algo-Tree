#include<bits/stdc++.h>
using namespace std;

/*Brute-force method*/
vector<vector<int>> two_sum1(int arr[], int n, int sum){
    vector<vector<int>> ans; /* this is a vector of vector for storing the all the valid pairs*/
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == sum){
                vector<int> vec; /*this vector is for storing the two elements which are making the given sum*/
                
                vec.push_back(arr[i]);
                vec.push_back(arr[j]);
                /* pushing both of the elements in the vector*/
                
                ans.push_back(vec) ; /* pushing the pair in the ans vector */
            }
            
        }
    }
    
    return ans;
    
}
/* NOTE: Time Complexity -> O(n ^ 2), 
         Space Complexity -> O(1)
*/
/* Example 1
n = 6, sum = -1
arr[] = {-1, 3, 4, -7, 6, 0}

ans = {{-1, 0}, {-7, 6}}
*/




/* Using Hashmap*/
vector<vector<int>> two_sum2(int arr[], int n, int sum){
    vector<vector<int>> ans; /* this is a vector of vector for storing the all the valid pairs*/
    
    unordered_set<int> s; /* Here using unordered_set because it does not require to sort the set 
                            so time complexity  decreases to O(n) from O(n * logn)*/
     
    for(int i = 0; i < n; i++){
        int required = sum - arr[i];
        
        if(s.find(required) != s.end()) /* if the remaining value is present in the unordere_set 
                                           then we can say that there is a pair {arr[i], required}*/
        {
             vector<int> vec; /*this vector is for storing the two elements which are making the given sum*/
                
             vec.push_back(arr[i]);
             vec.push_back(required);
             /* pushing both of the elements in the vector*/
                
             ans.push_back(vec) ; /* pushing the pair in the ans vector */
        }
        
        s.insert(arr[i]); /* inserting the current array element in the unordered_set*/
    }
    
    return ans;
}

/* NOTE: Time Complexity : O(n)
         Space Complexity : O(n)
*/

/*Example 2
n = 5, sum = 2
arr[] = {0, 3, -1, 4, 2}

1) first insert arr[0] into unordered_set S , S-> 0
2) insert arr[1] into S , S -> 0, 3
3) Now required = 2 - (-1) = 3 and 3 in present in the S, so push the pair {-1, 3} into the ans vector and insert arr[2] into S , S -> 0, 3, -1
4) insert arr[3] into S, S -> 0, 3, -1, 4
5) Now required = 2 - 2 = 0 and and 0 in present in the S, so push the pair {2, 0} into the ans vector and insert arr[4] into S , S -> 0, 3, -1, 4, 2

ans = {{-1, 3}, {2, 0}}

*/


/* Using sorting and Two-pointer method */
vector<vector<int>> two_sum3(int arr[], int n, int sum){
    vector<vector<int>> ans; /* this is a vector of vector for storing the all the valid pairs*/
    
    sort(arr, arr + n) ; /* sorting the array because array should be sorted for applying the two-pointer method*/
    /* O(n * logn) for sorting*/
    
    int left = 0, right = n - 1; /* taking left and right pointer , pointing to two extreme ends of the array*/
    
    
    while(left < right) /* this loop will run untill left < right */
    {
        if(arr[left] + arr[right] == sum) /* If we have found our sum*/
        {
             vector<int> vec; /*this vector is for storing the two elements which are making the given sum*/
                
             vec.push_back(arr[left]);
             vec.push_back(arr[right]);
             /* pushing both of the elements in the vector*/
                
            ans.push_back(vec) ; /* pushing the pair in the ans vector */
            
            /* increasing and decreasing left and right pointer respectively 
            because we have found our answer in this place so need to change our pointer*/
            left++; 
            right--;
        }
        else if(arr[left] + arr[right] > sum) /* it means we need to decrease the sum of (arr[left] and arr[right]) so decrease right pointer by one*/
        {
            right --;
        }
        else /* it means we need to increase the sum of (arr[left] and arr[right]) so increase left pointer by one*/
        {
            left ++;
        }
    }
    
    return ans;
}
/* NOTE: Time Complexity : O(n * logn)
         Space Complexity : O(1)
*/
/*Example: 3
n = 5, sum = 2
arr[] = {0, 3, -1, 4, 2}

array after sorting: arr[] = {-1, 0, 2, 3, 4}

left = 0, right = n - 1 = 5 -1 = 4;
arr[0] + arr[4] = (-1 + 4) = 3 (> sum) , so decrease right pointer by 1
right--;

left = 0, right = 3;
arr[0] + arr[3] = -1 + 3 = 2 (= sum), so put this pair {-1, 3} into the ans vector and change pointers
left++; right--;

left = 1, right = 2;
arr[1] + arr[2] = 0 + 2 = 2 (= sum) , so put this pair {0, 2} into the ans vector and change pointers
left++; right--;

left = 2, right = 1;
Now left > right , so exit from the while loop

ans = {{-1, 3}, {0, 2}}
*/




int main(){
    int n; /* size of the array*/
    cin >> n;
    
    int sum; /* this is the given sum*/
    cin >> sum;
    
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<vector<int>> res;  /* this vector of vector will store the answer returned by the function*/
    
    /*res = two_sum1(arr, n, sum); // this is the first approach to solve two sum*/
    
    res = two_sum2(arr, n, sum); /* this is the second approach using Hashmap */
        
    /*res = two_sum3(arr, n, sum); //  this is the 3rd approach using Two-pointer method*/
    
    
    /*printing the output*/
    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < 2; j++) /* running this loop two times because we have stored pairs in the vector*/
        {
            cout << res[i][j] <<" ";
        }
        cout << endl;
    }
}
