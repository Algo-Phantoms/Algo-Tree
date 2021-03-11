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
