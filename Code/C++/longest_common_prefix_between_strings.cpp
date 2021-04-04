// TO FIND THE LONGEST COMMON PREFIX BETWEEN A NUMBER OF STRINGS.

#include <bits/stdc++.h>
using namespace std;

//Tertiary function for comparision of strings character by character.
string fetch(string s1 , string s2){
    string out;
    int n1 = s1.length();
    int n2 = s2.length();
    //running parallel loop instead of nested to reduce time complexity,
    //and to avoid unresonable running loop for extra following characters.
    for(int i =0, j =0; i <= n1-1 && j <= n2-1 ; i++ , j++){
        if(s1[i] != s2[j]) break;
        out.push_back(s1[i]);
    }
    return(out);
}

//Secondary function  running it on individual 
string code(string arr[] , int n){

    string pref = arr[0];
    //Sending array elements to 'fetch' function one by one to scan the string by character.
    for(int i = 1; i <= n-1; i++){
        pref = fetch(pref , arr[i]);
    }
    return(pref);
}

//The driver Code.
int main(){
    //Taking all the required inputs from the user.
    cout<<"Enter the number of words\n";
    int len;
    cin>>len;
    string arr[len];
    cout<<"Enter the words now- \n";
    for(int i = 0; i < len; i++){
        cin>>arr[i];
    }

    //To obtain number of elements in array.
    int n = sizeof(arr) / sizeof(arr[0]);

    //using function 'code' to seperate the array elements for the search of prefix.
    string sol = code(arr , n);

    if(sol.length()) cout << "The Longest prefix is '" << sol <<"'.";
    else cout << "No common Prefix was found.";

return 0;
}