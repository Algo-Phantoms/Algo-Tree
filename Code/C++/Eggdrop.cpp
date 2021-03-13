#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int eggTrialCount(int eggs, int floors) {
   int minTrial[eggs+1][floors+1];
   int result;

   for (int i = 1; i <= eggs; i++) {
      minTrial[i][1] = 1;
      minTrial[i][0] = 0;
   }

   for (int j = 1; j <= floors; j++)
      minTrial[1][j] = j;

   for (int i = 2; i <= eggs; i++) {
      for (int j = 2; j <= floors; j++) {
         minTrial[i][j] = INT_MAX;
         for (int k = 1; k <= j; k++) {
            result = 1 + max(minTrial[i-1][k-1], minTrial[i][j-k]);
            if (result < minTrial[i][j])
               minTrial[i][j] = result;
         }
      }
   }

   return minTrial[eggs][floors];
}

int main () {
   int egg, maxFloor;
   cout << "Enter number of eggs: "; cin >> egg;
   cout << "Enter max Floor: "; cin >> maxFloor;
   cout << "Minimum number of trials: " << eggTrialCount(egg, maxFloor);
}
