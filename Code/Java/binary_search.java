/*
 * This code is to implement the binary search algorithm.
 * 
 * Binary search is used to search a value in a sorted array
 * by repeatedly dividing the search interval in half and comparing
 * the value of the middle element to the value to be searched.
 * Based on the comparison, the first, last and mid values are updated,
 * by narrowing the interval.
 */

import java.util.*;

public class binary_search
{
    void main()
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter number of elements: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        
        int arr[] = new int[n];
        
        System.out.println("Enter elements in sorted order: ");
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = scanner.nextInt();
            scanner.nextLine();
        }
        
        System.out.println("Enter value to be searched: ");
        int value = scanner.nextInt();
        scanner.nextLine();
        
        int first = 0, last = n - 1, mid = 0, flag = 0;
        
        while(first < last)
        {
            mid = (first + last) / 2;
            
            if(value > arr[mid])
            {
                first = mid + 1;
                continue;
            }
            
            else if(value < arr[mid])
            {
                last = mid - 1;
                continue;
            }
            
            else if(value == arr[mid])
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
        {
            System.out.println("Value found");
        }
        else
        {
            System.out.println("Value not found");
        }
    }
}

/*
 * Test Cases-
 * 
 * 1.
 * Enter number of elements: 
 * 5
 * Enter elements in sorted order: 
 * 1
 * 4
 * 8
 * 10
 * 17
 * Enter value to be searched: 
 * 10
 * Value found
 * 
 * 2.
 * Enter number of elements: 
 * 5
 * Enter elements in sorted order: 
 * 1
 * 6
 * 9
 * 18
 * 55
 * Enter value to be searched: 
 * 1
 * Value found
 * 
 * 3.
 * Enter number of elements: 
 * 5
 * Enter elements in sorted order: 
 * 3
 * 6
 * 9
 * 10
 * 19
 * Enter value to be searched: 
 * 4
 * Value not found
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * where n is the number of elements in the array
 */
