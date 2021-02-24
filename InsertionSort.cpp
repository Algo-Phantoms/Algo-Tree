//Insertion sort in cpp

#include <bits/stdc++.h> 
  
void iSort(int array[], int n) {
    
    int key;
    int j;
    
    for (int i = 1; i < n; i++) {  
        
        key = array[i];  
        j = i - 1;  
  
        while (j >= 0 && array[j] > key) {  
            
            array[j + 1] = array[j--];  
        }  
        
        array[j + 1] = key;  
    }  
}  
  
void printArray(int arr[], int size)  
{  
    std :: cout << "The array sorted using insertion sort is: ";
    for (int i = 0; i < size; i++) { 
        std :: cout << arr[i] << " ";
    }
    
    std :: cout << std :: endl; 
}  

int main()  
{  
    int length;
    
    std :: cout << "Enter the length of the array you want to sort: ";
    std :: cin >> length;
    
    int array[length];
    
    std :: cout << "Enter the numbers in the array: ";
    
    for(int i = 0; i < length; i++) {
        std :: cin >> array[i];
    }
  
    iSort(array, length);  
    printArray(array, length);  
  
    return 0;  
}  
