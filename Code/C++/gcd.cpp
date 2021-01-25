/*
GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers is the largest number that divides both of them
*/

#include<iostream>
using namespace std;

int gcd(int a,int b){
   if(b==0){
        return a;
   }

   return gcd(b,a%b);
}

int main(){
  
  int n1,n2;
  cin >>n1 >> n2;

  cout<<gcd(n1,n2);
  return 0;
}


/* 
 Test case :

 Input : 6 9
 Output : 3

 Time Complexity: O(Log min(a, b))  
 Space Complexity: O(1)  
 */