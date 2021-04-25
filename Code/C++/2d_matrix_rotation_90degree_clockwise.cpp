/*
Rotation of a 2D matrix by 90degrees in anticlockwise direction
Example: The given matrix is 
            1 2 3
            4 5 6
            7 8 9
        After rotation by 90 degree it will become
            7 4 1
            8 5 2
            9 6 3
    To achieve this-- 
    1. We take a transpose of the matrix which changes the matrix to
            1 4 7
            2 5 8
            3 6 9
    2. Then we take a reflection of the matrix along its middle column. So the matrix becomes
            7 4 1
            8 5 2
            9 6 3
    
*/ 
        
#include<bits/stdc++.h>
using namespace std;
#define int long long

//utility function to carry out the transpose of a 2d matrix
void transpose(vector<vector<int>>& v){
    int n = v.size();

    for(int i = 0 ; i < n ; i++){
        for(int j = i; j < v[i].size() ; j++){
            //swap is a C++ STL function
            swap(v[i][j], v[j][i]);                     
        }
    }
}

//utility function to take reflection of a 2d matrix along the column
void reflect(vector<vector<int>>& v){
    int n = v.size();

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < v[i].size() / 2 ; j++){
            swap(v[i][j],v[i][n-j-1]);                  
        }
    }
}

//helper function to rotate the matrix
void rotate(vector<vector<int>>& v){
    //transpose function call to carry out transpose of matrix
    transpose(v);                                    

    //reflect function call to
    reflect(v);                                               
}

//utility function to print the matrix
void print(vector<vector<int>>& v){       
    int n = v.size();

    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < v[i].size() ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

signed main(){
    int n;

    //input size of matrix
    cin>>n;                         

    //declaring a 2d vector and assigning n number of rows
    vector<vector<int>> v(n);       

    //input elemets of matrix
    for( int i = 0 ; i < n ; i++ ){
        //v[i] is a normal vector of capacity n so that n columns will be created
        v[i] = vector<int>(n);   

        for( int j = 0 ; j < n ; j++ ){
            cin>>v[i][j];
        }
    }                      

    rotate(v);
    cout<<endl;
    cout<<"Matrix rotated by 90degrees"<<endl;

    //print function call to print rotated matrix
    print(v);                       

    return 0;
    
}

/* 
Test Case:
Input:  
        4
        5 8 9 7 
        3 4 2 1
        7 6 5 4
        3 5 6 7

Output:
        Matrix rotated by 90degrees
        3 7 3 5 
        5 6 4 8 
        6 5 2 9 
        7 4 1 7 

Time Complexity: O(m*n) where m and n are no of rows and columns respectively
Space Complexity: O(1)

*/
