/****************************************************************************************************************
You are given a sequence A1,A2,…,AN and you have to perform the following operation exactly X times:

Choose two integers i and j such that 1≤i<j≤N.
Choose a non-negative integer p.
Change Ai to Ai⊕2p, and change Aj to Aj⊕2p, where ⊕ denotes bitwise XOR.
Find the lexicographically smallest sequence which can be obtained by performing this operation exactly X times.

A sequence B1,B2,…,BN is said to be lexicographically smaller than a sequence C1,C2,…,CN if there is an index i such that Bi<Ci and for each valid j<i, Bj=Cj.
******************************************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, I, J;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];                                             //accept input
            }

        int i=0;
        while (i<=n-2 && x!= 0){
            if (a[i]>=1 || i==n-2){
            I = i;
            int P = 32 - __builtin_clz(a[i]) - 1;
            int binpow= 1<<P;
            for (int j = i+1; j < n;){
                int temp = a[j] ^ binpow;
                if( temp < a[j]|| j==n-1) {
                    J = j;
                    a[J] = a[J] ^ binpow;
                    a[I] = a[I] ^ binpow;
                    x--;
                    break;
                    }
                else j++;
                }
            }
        if (a[i]==0)
        i++;
        }

        
        if (x!=0 && x%2==1 && n==2){
            I = n-2;
            J = n-1;
            a[J] = a[J] ^ 1;
            a[I] = a[I] ^ 1;
        }


    for (int i = 0; i < n; i++){
        cout << a[i];                                                //give output
        if (i!=n-1)     cout << " ";
        }
        cout << endl;                                                //end of test case
    }
    return 0;
}
