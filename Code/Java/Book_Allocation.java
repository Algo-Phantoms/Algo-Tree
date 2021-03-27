/* Book Allocation Problem
Problem Statement: 
Provided "n" number of books and "m" number of students. Books are arranged in increasing number of its pages. Each student is assigned to read pages in consecutive order.
Assign books in such a manner that maximum number of pages each student get to read is minimum.
*/ 

import java.util.*;
import java.lang.*;
import java.io.*;

class Book_Allocation{   
    // function to check if "key" number of pages can be allocated or not
    public static boolean pageread(int a[], int n, int key, int m){
            int sum = 0;
            int cnt = 1;

            for(int j = 0; j < n; j++){
                
                // if number of pages is greater than key then it can't be allocated
                if (a[j] > key) return false; 
                
                // counting the number of students required to allocate "sum" number of pages
                if(sum + a[j] > key) {
                    cnt++;       // incrementing the number students 
                    sum = a[j];     //updating current number of pages in "sum"

                     if(cnt > m) return false;   //if count of students is greater than given students "m", then its not possible to allocate these many books to given students "m"
                }
                else{
                    sum += a[j];  // else update current number of pages
                }
            }
            return true;
    }
        //function to find the page distribution
    public static int binary_search( int a[], int n, int m){

            int ans = Integer.MAX_VALUE;
            // if students are greater than number of books then its impossible to allocate pages
            if(n < m) return -1;
        
            int sum = 0;
   
            //counting total number of pages
              for (int i = 0; i < n; i++) 
                     sum += a[i]; 

             int low = 0;
             int high = sum;
            // applying binary search for finding the minimum number of pages
            while(low <= high){
                int mid = (low+high) / 2;
            // checking if "mid" number of pages can be distributed as minimum possible pages
                if(pageread(a, n, mid, m) == true){
                    // if "mid" number of pages can be allocated then find minimum of current minimum pages and "mid"
                    ans = Math.min(ans, mid);
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            } 
            //return minimum possible answer
            return ans;
        }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in); 
        int n = 0; 
        int m = 0;
        n = sc.nextInt();   //number of books
        m = sc.nextInt();  // number of students

        int[] a = new int[n];  // array for page distribution of each book
        for(int i = 0 ; i < n; i++){
            a[i] = sc.nextInt();
        }
        int ans = binary_search(a, n, m); // ans stores the minimum number of pages each student got to read
        System.out.println("Minimum number of pages = " + ans);
    }
}

/* Test Case 1: 
            Input -
                6
                3
                13 28 34 40 57 85
            Output - 
                Minimum number of pages = 97
                

 Test Case 2:
            Input -
                 7
                 5
                 10 24 33 49 59 66 107
            Output -
                 Minimum number of pages = 107
                
            
Time complexity : O(n*log(sum)) -  n = number of books, sum = sum of the pages of all the books

Space complexity: O(1)
*/
