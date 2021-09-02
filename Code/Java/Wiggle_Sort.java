/*
	DESCRIPTION:
		Given an unsorted array nums, result would be reordering it such that nums[0] < nums[1] > nums[2] < nums[3]....
		Eg)
			Input: nums = [1, 3, 2, 2, 3, 1]
			Output: One possible answer is [2, 3, 1, 3, 1, 2]

		Language: Java

		Algorithm:
			Step 1) Sort array using efficient sorting algorithm(Quick sort is used here)
			Step 2) Initialise new array of same size n as array inputed by user
			Step 3) Initialise left=(n-1)/2, right=n-1
			Step 4) Initialise i=0
			Step 5) While i<n do steps 6 to 8 
			Step 6) If i is even, then assign arr[left] to new_arr[i], and decrease left by 1
			Step 7) Else if i is odd, then assign arr[right] to new_arr[i], and decrease right by 1
			Step 8) Increase i by 1
			Step 9) Return new_arr[] which is the required result
*/ 

import java.util.Scanner;

class Wiggle_Sort
{ 
	//function to swap two elements of array
    void swap(int arr[],int a, int b)
    {
        int temp = arr[a]; 
        arr[a] = arr[b]; 
        arr[b] = temp; 
    }

	//function to find partition for quick sort
	int partition(int arr[], int l, int r) 
	{
		int loc=l; 
		while(l<r)
		{
			while(arr[r]>=arr[loc] && loc<r)
			{
				r-=1;
			}
			if(arr[r]<arr[loc])
			{
				swap(arr,r,loc);
				loc=r;
				l+=1;
			}
			while(arr[l]<=arr[loc] && loc>l)
			{
				l+=1;
			}
			if(arr[l]>arr[loc])
			{
				swap(arr,l,loc);
				loc=l;
				r-=1;
			}
		}
		return loc;
	} 

	//function to do quick sort
	void quickSort(int arr[], int first, int last) 
	{ 
		if (first < last) 
		{ 
			int pi = partition(arr, first, last);
			quickSort(arr, first, pi-1); 
			quickSort(arr, pi+1, last); 
		}
	} 

	//function to perform wiggle sort
    void wiggleSort(int arr[])
    {
        int n=arr.length;
        int temp_arr[]= new int[n];
        int left=(n-1)/2;
		//left points to middle of array
        int right=n-1;
		//right points to end of array
        int i;

        //placing small nos in even indices and big nos in odd indices
        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {
                temp_arr[i]=arr[left];
                left--;
            }
           else
           {
                temp_arr[i]=arr[right];
                right--;
           }
        }

        //copy elements in temp_arr[] to arr[]
        for(i=0;i<n;i++)
        {
            arr[i]=temp_arr[i];  
        }
    }

	//function to print the array
	static void printArray(int arr[]) 
	{ 
		int n=arr.length;
		for (int i=0; i<n; ++i) 
			System.out.print(arr[i]+" "); 
		System.out.println(); 
	} 

	
	public static void main(String args[]) 
	{ 
        //Read array from user
		Scanner sc=new Scanner(System.in);
		System.out.println("Length of array to be sorted is:");
		int n=sc.nextInt();	
        int arr[]=new int[n];
		System.out.println("Enter array elements");	
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		
        //Sort array in ascending order using Quick SortO(n log(n))
		Wiggle_Sort ob = new Wiggle_Sort(); 
        ob.quickSort(arr, 0, n-1); 

        //Wiggle sort
        ob.wiggleSort(arr);

		//Print array
		System.out.println("Wiggle Sort done:"); 
		printArray(arr); 
	} 
} 

/*
	Test Case 1:
		Length of array to be sorted is:
		6
		Enter array elements
		1 5 1 1 6 4
		Wiggle Sort done:
		1 6 1 5 1 4 

	Test Case 2:
		Length of array to be sorted is:
		8
		Enter array elements
		1 9 9 12 5 8 56 0 2
		Wiggle Sort done:
		8 56 5 12 1 9 0 9 

	Time Complexity: O(n log(n))
	Space complexity: O(n)
*/