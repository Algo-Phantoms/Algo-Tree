#include <vector>
#include<bits/stdc++.h>
#include <iostream>

using namespace std;


int main() {
    int val;
    int carry = 0;       //Input the number whose factorial is to be calculated 
    cin >> val;
    vector <int> arr(10000, 0);  //The size of the vector should be more than the digits present 
    arr[0] = 1;                  //in the factorial of the number.  
    int k = 0;                         

    for(int i = 1; i <= val; i++) {
        for(int j = 0;j <= k; j++) {      
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while(carry) {        //The carries are forwarded in order to get the final result
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }   
    }
    for(int i = k; i >= 0; i--) {  //Each digit of the final answer is stored in a single index 
        cout << arr[i];            //of the vector    
    }
    cout << "\n";
    return 0;
}
