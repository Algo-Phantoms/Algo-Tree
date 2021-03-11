package JAVAlab2;
import java.util.Scanner;

public class Bubblesort
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no of elements in the array: ");
		int n=sc.nextInt();
		int[] number =new int[n];
		int temp=0;
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++)
		{
			number[i]=sc.nextInt();
		}
		for(int i=0; i < n; i++){  
            for(int j=1; j < (n-i); j++){  
                     if(number[j-1] > number[j]){  
                            //swap elements  
                            temp = number[j-1];  
                            number[j-1] = number[j];  
                            number[j] = temp;  
                    }  
                     
            }  
    }  
		System.out.println("The sorted array is: ");
		for(int p=0;p<number.length;p++)
		{
			System.out.println(number[p]+" ");
		}
	}
}

/*
    Test Cases:
    Input: 
Enter the no of elements in the array: 
5
Enter the elements
55
89
74
15
9
    Output:
The sorted array is: 
9 
15 
55 
74 
89 

    Input: 
Enter the no of elements in the array: 
7
Enter the elements
7
6
5
4
3
2
1
    Output:
The sorted array is: 
1 
2 
3 
4 
5 
6 
7 

    Time Complexity: O(n^2) (for Worst case)
    Space Complexity: O(1)
*/
