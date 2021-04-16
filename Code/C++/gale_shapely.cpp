/* 
GALE-SHAPELY ALGORITHM

 */

/* 
PROBLEM STATEMENT: 
    We are given a set of N students and N hospitals. Every student ranks all hospitals in
    order of preference. Similarly, every hospital has a list of it's favourite candidates
    that they would like to admit.
    A stable admission is defined when there exists no pair of student and hospital such that
    they prefer each other more than their currently matched problem. 
    For a given list of students and hospitals with their preferences, it can be proved that 
    there always exists a stable admission. 
    Your task is to find that stable admission. 

*/

/* 
INPUT
    The first N lines containes the student's preferences. 
    
    The first number in each line is the student number and 
    the next N numbers in each line are his/her hospital 
    preferences. 

    The first number in the next N lines is the hospital number
    and the next N numbers in each line are the hospital's 
    student preferences. 

 */

/* 
OUTPUT 
    Print N lines, each denoting the student-hospital pair.
    The first number should denote the student number and the
    second number in that line should denote the matched hospital.

 */
#include<bits/stdc++.h> 
using namespace std;

// Pre-declaration of functions for better readability of the overall code
bool isntover(vector<int> &S,int N);
int getrank(vector<int> &hospital,int application,int n);
void match(int i,int h,vector<int> &student,vector<int> &hosp);
void solve(vector<int> *S,vector<int> *H,int n);

// Taking the user input of number of students/hospitals and their preferences
int main() {
        int n;
	    cin>>n;
        // Vectors containing their preferences, each of size n
	    vector<int> S[n],H[n];
	    int application;
	    for(int k=0;k<n;k++){
            cin>>application;
	        for(int h=0;h<n;h++){
	            cin>>application;
	            H[k].push_back(application);
	        }
	        reverse(H[k].begin(),H[k].end());
	    }
	    for(int k=0;k<n;k++){
	        cin>>application;
	        for(int h=0;h<n;h++){
	            cin>>application;
	            S[k].push_back(application);
	        }
	        reverse(S[k].begin(),S[k].end());
	    }
	    solve(S,H,n);
	return 0;
}
// Checks for availability of unmatched students
bool isntover(vector<int> &S,int N){
    if(find(S.begin(),S.end(),-1)==S.end())
        return false;
    else
        return true;
    
}
// Gets the rank of preference
int getrank(vector<int> &hospital,int application,int n){
    return n-(find(hospital.begin(),hospital.end(),application)-hospital.begin());
}

// Temporarily admits the student into the hospital (can also be the final admission)
void match(int i,int h,vector<int> &student,vector<int> &hosp){
    hosp[h]=i;
    student[i]=h;
}

// This is the Driver function
void solve(vector<int> *S,vector<int> *H,int n){
    vector<int> student;
    vector<int> hosp;
    for(int i=0;i<n;i++){
        student.push_back(-1);
        hosp.push_back(-1);
    }
    // While there is a unadmitted student
    while(isntover(student,n)){
        // Iterate over each student
        for(int i=0;i<n;i++){
            if(student[i]==-1){
                int h=S[i].back()-1;
                S[i].pop_back();
                // If the hospital has no student, it admits the current student
                if(hosp[h]==-1){
                    match(i,h,student,hosp);
                }
                else{
                    // If the hospital already has a student and gets a better student, it forms a new match
                    // The current admitted student is now without any hospital
                    if(getrank(H[h],i+1,n)<getrank(H[h],hosp[h]+1,n)){
                        student[hosp[h]]=-1;
                        match(i,h,student,hosp);
                    }
                }
            }
        }
    }
    // Print out the stable admissions 
    for(int i=0;i<n;i++){
        cout<<i+1<<' '<<student[i]+1<<endl;
    }
    
}
/* 
TEST CASES:
    1)  Input:  4
                1 4 3 1 2
                2 2 1 3 4
                3 1 3 4 2
                4 4 3 1 2
                1 3 2 4 1
                2 2 3 1 4
                3 3 1 2 4
                4 3 2 4 1
        
        Output: 1 3
                2 2
                3 1
                4 4

    2)  Input:  7
                1 3 4 2 1 6 7 5
                2 6 4 2 3 5 1 7
                3 6 3 5 7 2 4 1
                4 1 6 3 2 4 7 5
                5 1 6 5 3 4 7 2
                6 1 7 3 4 5 6 2
                7 5 6 2 4 3 7 1
                1 4 5 3 7 2 6 1
                2 5 6 4 7 3 2 1
                3 1 6 5 4 3 7 2
                4 3 5 6 7 2 4 1
                5 1 7 6 4 3 5 2
                6 6 3 7 5 2 4 1
                7 1 7 4 2 6 5 3

        Output: 1 4
                2 5
                3 1
                4 3
                5 7
                6 6
                7 2                   
 */

/* 
TIME COMPLEXITY:
    The time complexity of this algorithm is O(N^2)

SPACE COMPLEXITY: 
    The space complexity of this algorithm is also O(N^2)
 */