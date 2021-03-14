/*
Problem:- Linear Search,Search a key element from multiple elements.
 */

import java.util.ArrayList;
import java.util.*;
class LinearSearch{
    public static void main(String[] args)
    {
        List<Integer>l=new ArrayList<Integer>();
        System.out.println("Enter the input");
        //use to take value
        for(int i=0;i<5;i++)
        {
            Scanner input = new Scanner(System.in);
            int a = input.nextInt();
            l.add(a);
        }
        System.out.println("Before Sorting:");
        System.out.println(l);
        System.out.println("Enter element");
        //Enter a userInput to find into the arrayList
        Scanner userInput=new Scanner(System.in);
        int val=userInput.nextInt();
       // arrayList value is not equal to key value shows element not found if equal show element found and index also
        if (!l.contains(val))
        {
            System.out.println("Element Not Found");
        }
        else
        {
            System.out.println("Element Found at index :-"+l.indexOf(val));
        }
    }
}
/*
-> Time Complexity :- O(n)
-> Space Complexity:- O(1)
Test Case:- 1
Enter the input
1
2
3
4
5
[1, 2, 3, 4, 5]
Enter element
5
Element Found at index :-4
Test Case:- 2
Enter the input
1
2
3
4
5
[1, 2, 3, 4, 5]
Enter element
1
Element Found at index :-0

 */