package com.company;
import java.util.Scanner;
import  java.util.Map;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of indexes in array:");
        int num=sc.nextInt();  //Scanning number of elements
        int[] array = new int[num];  //Declaring an array to store elements.
        System.out.println("Enter the elements of the array:");
        for(int i=0;i<array.length;i++)
            array[i] = sc.nextInt();  //Scanning elements one by one
        System.out.print("Enter the target sum:");
        int target = sc.nextInt();   //Scanning target
        int[] result = twoSum(array,target);   //Calling the function twoSum() and storing the result in an array named "result"
        System.out.println("Required indices are:");
        for(int i=0;i<result.length;i++)
            System.out.println(result[i]+" ");  //Printing the result
    }

//This is the function which find the two indices,whose value add upto given target
        public static int[] twoSum(int[] nums, int target) {
        //Declaring an array to store the result(indices that add upto given target)
            int[]a= new int[2];
        //Using HashMap to store element as key and its index as value
        //Declaring HashMap "hm"
            Map<Integer,Integer>hm=new HashMap<Integer,Integer>();
        //Traversing the given array
            for(int i=0;i<nums.length;i++)
            {
                //Now current number is nums[i] so we need to calculate a number when added to current number gives target or not.
               //So calculate target-nums[i] which is the other number when added to nums[i] gives target
                int other=target-nums[i];
                // Checking if other is present in our hashmap or not and note that it should not be the same as current number index.
                if(hm.containsKey(other) && hm.get(other)!=i)
                {
                    //If other is present in hashmap then the two indices are i, hm.get(other). Store them in array and return that array.
                    a[0]=i;
                    a[1]=hm.get(other);
                    //Since each input have exactly one solution. So after getting the solution,we can apply break.
                    break;
                }
                else
                {
                    //If that number called "other" is not present in hashmap then add it to our hashmap.
                    hm.put(nums[i],i);
                }
            }
            //Return our final array
            return a;

        }
    }
    /*
    Input 1:
    5
    2 4 5 1 7
    8
    Output:
    4 3

    Input 2:
    4
    2 7 11 15
    9
    Output:1 0

    Time Complexity:O(n)
    Space Complexity:O(n)
     */
