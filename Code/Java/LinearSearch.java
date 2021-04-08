 package array;
import java.util.Scanner;
public class LinearSearch {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("Enter the size of array: ");
		int size = scn.nextInt();
		int a[] = new int[size];
		System.out.print("Enter "+size+" elements of array: ");
		for(int i=0;i<size;i++)
		{
		    a[i] = scn.nextInt();
		}
		System.out.print("Enter the number which you want to search: ");
		int searched_num = scn.nextInt();
		int res = linearSearch(a,searched_num);
		if(res>=0) {
			System.out.println(searched_num+" is present at index "+res);
		}
		else {
			System.out.println(searched_num+" is not present in the given array");
		}
		

	}
	public static int linearSearch(int[] array, int num)
	{
	    for(int i=0;i<array.length;i++){
	        if(array[i]==num){
	            return i;
	        }
	    
	    }
	    return -1;
	}

}
/* TEST CASE 1
 * Input:
 * 5 (size of array)
 * 1 2 3 4 5(elements of an array)
 * 3(element which has to be searched in the given array)
 * 
 * Output:
 * 3 is present at index 2 
 * 
 * TEST CASE 2
 * Input:
 * 10
 * 1 2 5 6 34 78 23 90 4 29
 * 30
 * 

 */
