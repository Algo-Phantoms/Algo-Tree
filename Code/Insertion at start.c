#include <stdio.h>

#define MAX 5

void main() {
   int array[MAX] = {2, 3, 4, 5};
   int N = 4;       
   int i = 0;        
   int value = 1;    

   printf("Printing array before insertion −\n");
   
   for(i = 0; i < N; i++) {
      printf("array[%d] = %d \n", i, array[i]);
   }

     
   for(i = N; i >= 0; i--) {
      array[i+1] = array[i];
   }


   array[0] = value;


   N++;


   printf("Printing array after insertion −\n");
   
   for(i = 0; i < N; i++) {
      printf("array[%d] = %d\n", i, array[i]);
   }
}