/*
left_rotation(arr, len) alters the int array of length len to shift every element of the array one position to it's left.
*/

#include <iostream>
using namespace std;

void left_rotation(int *arr, int len)
{
  //checks if arr is not empty
  if (len > 0)  
  {
    //saves the value of the first element
    int first_element = arr[0]; 

    for (int i = 0; i < len - 1; ++i)
    {
      // assigns the value of the right element to the left element 
      arr[i] = arr[i + 1];  
    }
    //assign the value of the first element to the last
    arr[len - 1] = first_element;
  }
}

int main(void)
{
  //dummy max length
  int arr[100]; 
  int i = 0;
  while (cin >> arr[i]) //Input
  {
    ++i;
  }

  left_rotation(arr, i); //function call

  for (int k = 0; k < i; ++k) // Output
  {
    cout << arr[k] << " ";
  }
  return 0;
}

/* 
	Test case :

	Input  : 1 2 3 4 5
	Output : 2 3 4 5 1


	Input  : -1 -5 -9 5 0
	Output : -5 -9 5 0 -1

	Time Complexity: O(n)  
	Space Complexity: O(1)  
 */