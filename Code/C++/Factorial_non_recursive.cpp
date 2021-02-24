//Factorial of a number without recursion.

#include <iostream>  
 
int main() {
    
    int number;    
    
    std :: cout << "Enter a number whose factorial you want to get: ";    
    std :: cin >> number;
    
    if(number < 0) {
        std :: cout << "Please enter a non-negative number.";
        exit(0);
    }
    
    int factorial = 1;
    
    for(int i = 1; i <= number; i++)
    {    
        factorial *= i;    
    }    
    
    std :: cout << "Factorial of " << number << " is: " << factorial;
    std :: cout << std :: endl;
    
    return 0;  
}  
