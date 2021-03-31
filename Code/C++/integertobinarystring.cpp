// this is a program  to change a integer to a binary string 
// it takes integer as an input and changes it to binary string 



#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;        

string decimalToBinary(ll n) 
{      
    string s = bitset<64> //finding the binary form of the number
    (n).to_string(); //stl used to convert a number into string 
      
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0"; 
} 


int main() {
    cout<<"Enter a decimal integer ";
    int N;
    cin>>N;
    cout<<"\nIts binary string is "<<decimalToBinary(N);
    return 0;
}


// time complexity of this is O(1)
// space complexity of this program is O(1)
// example input - 13
// example output - Its binary string is 1101
// second example - 19
// example output - Its binary string is 1001
